// BreckerStrategy.cpp: implementation of the BreckerStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BreckerStrategy.h"
#include "EndListRef.h"
#include "GasProperty.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BreckerStrategy::BreckerStrategy()
{

}

BreckerStrategy::~BreckerStrategy()
{

}

BreckerStrategy* BreckerStrategy::Instance()
{
	static BreckerStrategy strategy;
	return &strategy;
}

void BreckerStrategy::Calc(EndListRef &jun,GasProperty &gas,double dCdAIn,double dCdAOut)
{   
	double dPress = 0;
	double dGasFlow = 0;
	double dSc = jun.Sc();
	double dSb = jun.Sb(); 
	if(gas.GasPress() > dSc/dSb)
	{//流入
		dPress = SonicInPress(jun,gas,dCdAIn);
		if(dPress/gas.GasPress()<=0.53)
		{
			dGasFlow = gas.Sonicin(dCdAIn);
		}
		else
		{
			dPress = SubsonicInPress(jun,gas,dCdAIn);
			dGasFlow = gas.SubSonicin(dCdAIn,dPress);
		}
	}
	else
	{
		dPress = SonicOutPress(jun,gas,dCdAOut);
		if(dPress/gas.GasPress()>=(1/0.53))
		{
			dGasFlow = gas.SonicOut(dCdAOut,dPress);
		}
		else
		{
			dPress = SubsonicOutPress(jun,gas,dCdAOut);
			dGasFlow = gas.SubSonicOut(dCdAOut,dPress);
		}
	}
	UpData(jun,gas,dGasFlow,dPress);
}

void BreckerStrategy::UpData(EndListRef &jun,GasProperty &gas,double dGasFlow,double dPress)
{
	double dT = MOCFluid::SetpTime();//时间步长
	double dOldV = jun.VaporVolume();//系统气体上一时刻体积
	double dGasMass = gas.GasMolMass();//气体摩尔质量
	double dOldGasFlow = gas.GasFlow();//气体上一时刻速度
	double dDetalGasMass = 0.5*dT*(dOldGasFlow+dGasFlow);
	if((dGasMass+dDetalGasMass)>0)
	{
		jun.StaticPressStrategy(dPress);
		double dV = dOldV+jun.DetalVaporVolume(0);
		ASSERT(dV>0);
		jun.VaporVolume(dV);
		gas.GasFlow(dGasFlow);
		gas.GasMolMass(dGasMass+dDetalGasMass);
	}
	else
	{
		gas.GasFlow(0);
		gas.GasMolMass(0);
		jun.Collapse();
		double dMass = jun.CollapseMass();
		jun.BranchStrategy(-dMass);
	}
}
double BreckerStrategy::SonicInPress(EndListRef &jun,GasProperty &gas,double dCdA)
{//流入气体
	double dT = MOCFluid::SetpTime();//时间步长
	double dOldV = jun.VaporVolume();//系统气体上一时刻体积
	double dDetalV = jun.OldDetalVaporVolume();//气体上一时段体积增加
	double dGasMass = gas.GasMolMass();//气体摩尔质量
	double dOldGasFlow = gas.GasFlow();//气体上一时刻速度
	double dNewGasFlow = gas.Sonicin(dCdA);//气体当前时刻速度
	double dDetalGasMass = 0.5*dT*(dOldGasFlow+dNewGasFlow);

	double dA = jun.Sb()/MOCFluid::Density();
	double dB = 2*dOldV/dT-jun.Sc()/MOCFluid::Density()+2*dDetalV/dT;
	double dC = -R*gas.LiquidTemp()*(2*gas.GasMolMass()/dT+2*dDetalGasMass/dT);

	double dTemp = pow(dB/dA,2)-4*dC/dA;
	double dPress = (-dB/dA+sqrt(fabs(dTemp)))/2;
	return dPress;
}

double BreckerStrategy::SubsonicInPress(EndListRef &jun,GasProperty &gas,double dCdA)
{
	double dFun =0;
	double dGrad = 0;
	double dPr=1;
	double dStep = 0.1;
	BOOL bFlag = TRUE;
	while(TRUE)
	{
		Calc(jun,gas,dCdA,dPr,TRUE,dFun,dGrad);
		if(dStep < 0.00001||fabs(dFun)<1E-2)
		{
			break;	 
		}
		if(dFun > 0)
		{
			if(!bFlag)
			{
				dStep = dStep / 2;
				bFlag = TRUE;	
			}
			dPr = dPr - dStep;
		}
		else
		{
			if(bFlag)
			{
				dStep = dStep / 2;
				bFlag = FALSE;	
			}
			dPr = dPr + dStep;
		}	
	}
	int n=0;
	while (n<100)
	{
		dPr = dPr -dFun/dGrad;
		Calc(jun,gas,dCdA,dPr,TRUE,dFun,dGrad);
		if(-1E-8<dFun&&dFun<1E-8)
			break;
		n++;
	}
	return dPr*gas.GasPress();
}

double BreckerStrategy::SonicOutPress(EndListRef &jun,GasProperty &gas,double dCdA)
{//流出气体，考虑体积必须大于等于0
	double dT = MOCFluid::SetpTime();//时间步长
	double dOldV = jun.VaporVolume();//系统气体上一时刻体积
	double dDetalV = jun.OldDetalVaporVolume();//气体上一时段体积增加
	double dGasMass = gas.GasMolMass();//气体摩尔质量
	double dOldGasFlow = gas.GasFlow();//气体上一时刻速度
	double dNewGasFlow = gas.SonicOut(dCdA,1);//气体当前时刻速度除内压力

	double dA = jun.Sb()/MOCFluid::Density();
	double dB = 2*dOldV/dT-jun.Sc()/MOCFluid::Density()+2*dDetalV/dT-dNewGasFlow*R*gas.LiquidTemp();
	double dC = -R*gas.LiquidTemp()*(2*gas.GasMolMass()/dT+dOldGasFlow);

	double dTemp = pow(dB/dA,2)-4*dC/dA;
	double dPress = (-dB/dA+sqrt(fabs(dTemp)))/2;
	return dPress;
}

double BreckerStrategy::SubsonicOutPress(EndListRef &jun,GasProperty &gas,double dCdA)
{
	double dFun =0;
	double dGrad = 0;
	double dPr=1;
	double dStep = 0.1;
	BOOL bFlag = TRUE;
	while(TRUE)
	{
		Calc(jun,gas,dCdA,dPr,FALSE,dFun,dGrad);
		if(dStep < 0.00001||fabs(dFun)<1E-2)
		{
			break;	 
		}
		if(dFun > 0)
		{
			if(!bFlag)
			{
				dStep = dStep / 2;
				bFlag = TRUE;	
			}
			dPr = dPr - dStep;
		}
		else
		{
			if(bFlag)
			{
				dStep = dStep / 2;
				bFlag = FALSE;	
			}
			dPr = dPr + dStep;
		}	
	}
	int n=0;
	while (n<100)
	{
		dPr = dPr -dFun/dGrad;
		Calc(jun,gas,dCdA,dPr,FALSE,dFun,dGrad);
		if(-1E-8<dFun&&dFun<1E-8)
			break;
		n++;
	}
	return dPr*gas.GasPress();
}

void BreckerStrategy::Calc(EndListRef &jun,GasProperty &gas,double dCdA,double dPr,BOOL bIn,double &dFun,double &dGrad)
{
	double dT = MOCFluid::SetpTime();//时间步长
	double dOldV = jun.VaporVolume();//系统气体上一时刻体积
	double dDetalV = jun.OldDetalVaporVolume();//气体上一时段体积增加
	double dOldGasFlow = gas.GasFlow();//气体上一时刻速度
	double dA = gas.a();
	double dB = gas.b();
	double dC1 = 0;
	if(bIn)
	{
		dC1 = -gas.SubSonicInC1(dCdA);
	}
	else
	{
		dA = -dA;
		dB = -dB;
		dC1 = gas.SubSonicOutC1(dCdA);
	}
	double dC2 = jun.Sb()*pow(gas.GasPress(),2)/MOCFluid::Density();
	double dC3 = gas.GasPress()*(2*dOldV/dT-jun.Sc()/MOCFluid::Density()+2*dDetalV/dT);
	double dC4 = -R*gas.LiquidTemp()*(2*gas.GasMolMass()/dT+dOldGasFlow);
	double dTemp1 = pow(dPr,dA)-pow(dPr,dB);
	double dTemp2 = dA*pow(dPr,dA-1)-dB*pow(dPr,dB-1);
	if(bIn)
	{
		dFun  = dC1*pow(fabs(dTemp1),0.5)+dC2*pow(dPr,2)+dC3*dPr+dC4;
		dGrad = 0.5*dC1*pow(fabs(dTemp1),-0.5)*dTemp2 + 2*dC2*dPr + dC3;
	}
	else
	{
		dFun  = dC1*pow(fabs(dTemp1),0.5)+dC2*dPr+dC3+dC4/dPr;
		dGrad = 0.5*dC1*dPr*pow(fabs(dTemp1),-0.5)*dTemp2 + dC2 + dC4/pow(dPr,2);
	}
}