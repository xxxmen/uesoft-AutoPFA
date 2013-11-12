// MOCPumpModel.cpp: implementation of the MOCPumpModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPumpModel.h"
#include "MOCFluid.h"
#include "CalcPump.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPumpModel::MOCPumpModel()
{
	m_bAntiReverse = 0;		
	m_bExitCheck = 0;		
	m_dCloseVel = 0;
	m_dReOpenPress = 0;			  	
	m_bSelSubmerge = 0;       
	m_dSuctionPress = 0;
	m_dMassFlow = 0;
	m_dTranRisePress = 0;
	m_bExitCheckOpen = TRUE;
}

MOCPumpModel::~MOCPumpModel()
{

}

void MOCPumpModel::Read(CalcPump *pData)
{
	m_bAntiReverse = pData->AntiReverse();		
	m_bExitCheck = pData->ExitCheck();		
	m_dCloseVel = pData->CloseVel();
	m_dReOpenPress = pData->ReOpenPress();
	if(0==pData->ReOpenPressType())
		m_dReOpenPress = MOCFluid::TranHGLToPress(m_dReOpenPress);
	m_bSelSubmerge = pData->SelSubmerge();       
	m_dSuctionPress = pData->SuctionPress();
	if(0==pData->SubmergePressType())
		m_dSuctionPress = MOCFluid::TranHGLToPress(m_dSuctionPress);
}

double MOCPumpModel::Calc(EndListRef &jun,double dPress)
{
	if(!IsSubmerge())
	{
		return jun.FixRiseStrategy(dPress);
	}
	else
	{
		return jun.FixRiseStrategy(m_dSuctionPress,dPress);
	}
}

double MOCPumpModel::CalcMass(EndListRef &jun,double dPress)
{
	if(!IsSubmerge())
	{
		return jun.FixRiseMass(dPress);
	}
	else
	{
		return jun.FixRiseMass(m_dSuctionPress,dPress);
	}
}
void MOCPumpModel::CalcStm(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{
	if(nSet > 0)
	{
		m_dMassFlow = CalcParall(jun,config,dSpeedRatio,nSet);
	}
	else
	{
		m_dMassFlow =  CalcSerise(jun,config,dSpeedRatio,abs(nSet));
	}
}

double MOCPumpModel::CalcSerise(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{//压力上升相加
	double dOldMass = m_dMassFlow;
	double dPress = (config.GetPress(dOldMass/dSpeedRatio)*nSet)*pow(dSpeedRatio,2);
	//改善收敛
	double dNewMass = CalcMass(jun,dPress);
	dPress = (config.GetPress((dNewMass+dOldMass)/2.0/dSpeedRatio)*nSet)*pow(dSpeedRatio,2);
	return Calc(jun,dPress);
}

double MOCPumpModel::CalcParall(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{//流量相加
	double dOldMass = m_dMassFlow;
	double dPress = config.GetPress(dOldMass/dSpeedRatio)*pow(dSpeedRatio,2);
	//改善收敛
	double dNewMass = CalcMass(jun,dPress)/nSet;
 	dPress = config.GetPress((dNewMass+dOldMass)/2.0/dSpeedRatio)*pow(dSpeedRatio,2);
	return Calc(jun,dPress)/nSet;
}


void MOCPumpModel::CalcImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{
	if(nSet > 0)
	{
		m_dMassFlow = CalcParallImpulse(jun,config,dSpeedRatio,nSet);
	}
	else
	{
		m_dMassFlow =  CalcSeriseImpulse(jun,config,dSpeedRatio,abs(nSet));
	}
}

void MOCPumpModel::CalcQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress)
{
	if(nSet > 0)
	{
		CalcParallQH(jun,config,dSpeedRatio,nSet,dOldMass,dMass,dPress);
	}
	else
	{
		CalcSeriseQH(jun,config,dSpeedRatio,abs(nSet),dOldMass,dMass,dPress);
	}
}

//计算公式采用的杨开林著电站与泵站中的水力瞬变及调节P70
void MOCPumpModel::CalcSeriseQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress)
{
	double dOldPress = (config.GetPress(dOldMass / dSpeedRatio)*nSet)*pow(dSpeedRatio,2);
	double dNewMass = 0;
	double dNewPress = 0;
	double dTol =0;
	do 
	{//这个算法的迭代速度还可以
		dNewMass = CalcMass(jun,dOldPress);
		dMass = (dNewMass+dOldMass)/2.0;
		dOldMass = dNewMass;
		dNewPress = (config.GetPress(dMass / dSpeedRatio)*nSet)*pow(dSpeedRatio,2);
		dTol = fabs((dNewPress-dOldPress)/dNewPress);
		dOldPress = dNewPress;
	} while(dTol>1E-6||fabs((dNewPress-dOldPress))>1E-3);
	dPress = dNewPress/nSet;
}
double MOCPumpModel::CalcSeriseImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{
	double dMass = 0;
	CalcSeriseQH(jun,config,dSpeedRatio,nSet,m_dMassFlow,dMass,m_dTranRisePress);
	return CalcImpulse(jun,m_dTranRisePress*nSet,dMass);
}
void MOCPumpModel::CalcParallQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress)
{
	double dOldPress = config.GetPress(dOldMass/dSpeedRatio)*pow(dSpeedRatio,2);
	double dNewMass = 0;
	double dNewPress = 0;
	double dTol =0;
	do 
	{//这个算法的迭代速度还可以
		dNewMass = CalcMass(jun,dOldPress)/ nSet;
		dMass = (dNewMass+dOldMass)/2.0;
		dOldMass = dNewMass;
		dNewPress = config.GetPress(dMass/dSpeedRatio)*pow(dSpeedRatio,2);
		dTol = fabs((dNewPress-dOldPress)/dNewPress);
		dOldPress = dNewPress;
	} while(dTol>1E-6||fabs((dNewPress-dOldPress))>1E-3);
	dPress = dNewPress;
}

double MOCPumpModel::CalcParallImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet)
{
	double dMass = 0;
	CalcParallQH(jun,config,dSpeedRatio,nSet,m_dMassFlow,dMass,m_dTranRisePress);
	return CalcImpulse(jun,m_dTranRisePress,dMass)/nSet;
}

//瞬变流还需要考虑止回阀门
//dPress  压力增加
//dMass   流量
double MOCPumpModel::CalcImpulse(EndListRef &jun,double dPress,double dMass)
{
	if(IsExitCheck())
	{
		if(m_bExitCheckOpen)
		{//止回阀当前打开
			if(dMass<m_dCloseVel)
			{//小于关闭流量止回阀关闭
				m_bExitCheckOpen = FALSE;
				jun.FlowStrategy(0);
				return 0;
			}
		}
		else
		{//超过打开压力则打开止回阀
			
			if(m_dReOpenPress>dPress||dMass<m_dCloseVel)
			{//止回阀关闭
				jun.FlowStrategy(0);
				return 0;
			}
			m_bExitCheckOpen = TRUE;
		}
	}
	return Calc(jun,dPress);
}


double MOCPumpModel::GetPower(MOCPumpConfig &config,double dSpeedRatio,double dMass,double dPress)
{
	if(dMass<0)
		dMass=0;
	return config.GetPower(dMass/dSpeedRatio)*pow(dSpeedRatio,3);
}
double MOCPumpModel::GetTorque(MOCPumpConfig &config,double dSpeedR,double dSpeed,double dMass,double dPress)
{
	if(fabs(dSpeed)<1E-6)
		return 0;
	double dPower = GetPower(config,dSpeed/dSpeedR,dMass,dPress);
	return (30*dPower/(dSpeed*PI));
}


double MOCPumpModel::MassFlow()
{
	return m_dMassFlow;
}
void MOCPumpModel::MassFlow(double dMass,int nSet)
{
	if(nSet>0)
		dMass = dMass/nSet;
	m_dMassFlow = dMass;
}
void MOCPumpModel::RisePress(double dRisePress,int nSet)
{
	if(nSet<0)
		dRisePress = dRisePress/abs(nSet);
	m_dTranRisePress = dRisePress;
}
double MOCPumpModel::RisePress()
{
	return m_dTranRisePress;
}


double MOCPumpModel::SunBpm(EndListRef &jun)
{
	return jun.SunBpm();
}

double MOCPumpModel::SunCpm(EndListRef &jun)
{
	double dSc = jun.SunCpm();
	if(IsSubmerge())
	{
		dSc = m_dSuctionPress + dSc;
	}
	return dSc;	
}
