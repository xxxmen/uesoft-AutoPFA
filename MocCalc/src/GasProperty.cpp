// GasProperty.cpp: implementation of the GasProperty class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasProperty.h"
#include "CalcBrecker.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasProperty::GasProperty()
{
	m_dLiquidTemp = 0;				
	m_dGasWeight = 0;				
	m_dCpCv = 0;                        
	m_dGasTemp = 0;						
	m_dGasPress = 0;				  
	m_dGasMass = 0;	
	m_dOldGasFlow = 0;
}

GasProperty::~GasProperty()
{

}

void GasProperty::Read(CalcBrecker &Data)
{
	m_dLiquidTemp = Data.LiquidTemp();
	if(0==Data.LiquidTempType())
		m_dLiquidTemp = MOCFluid::Temperature();
	m_dGasWeight = Data.GasWeight();				
	m_dCpCv = Data.CpCv();                        
	m_dGasTemp = Data.GasTemp();						
	m_dGasPress = Data.GasPress();				  
	m_dGasMass = Data.GasMass();	
}

double GasProperty::LiquidTemp()
{
	return m_dLiquidTemp;
}

double GasProperty::r()
{
	return m_dCpCv;
}

double GasProperty::GasTemp()
{
	return m_dGasTemp;
}

double GasProperty::GasPress()
{
	return m_dGasPress;
}

double GasProperty::GasMolMass()
{
	return m_dGasMass/m_dGasWeight;
}
void GasProperty::GasMolMass(double dMass)
{
	m_dGasMass = m_dGasWeight*dMass;
}
double GasProperty::GasFlow()
{
	return m_dOldGasFlow;
}

void GasProperty::GasFlow(double dGasFlow)
{
	m_dOldGasFlow = dGasFlow;
}
double GasProperty::GasInitVolume(double dPress)
{
	return GasMolMass()*R*LiquidTemp()/dPress;
}
double GasProperty::Sonicin(double dCdAin)
{
	return Sonic(dCdAin,m_dGasTemp,m_dGasPress);
}
double GasProperty::SonicOut(double dCdAOut,double dPress)
{
	return -Sonic(dCdAOut,m_dLiquidTemp,dPress);
}
double GasProperty::Sonic(double dCdA,double dT,double dPress)
{
	double dTemp1 = (dCdA*dPress)/sqrt(R*dT);
	double dTemp2 = 1+(m_dCpCv-1)/2;
	double dTemp3 = 0.5*(1+m_dCpCv)/(1-m_dCpCv);
	return dTemp1*sqrt(m_dCpCv)*pow(dTemp2,dTemp3);
}

double GasProperty::SubSonicin(double dCdAin,double dPress)
{
	double dTemp1 = (dCdAin*m_dGasPress)/sqrt(R*m_dGasTemp);
	double dTemp2 = 2*m_dCpCv/(m_dCpCv-1);
	double dTemp3 = pow(dPress/m_dGasPress,2/m_dCpCv)-pow(dPress/m_dGasPress,(m_dCpCv+1)/m_dCpCv);
	return dTemp1*sqrt(dTemp2*dTemp3);
}
double GasProperty::SubSonicOut(double dCdAOut,double dPress)
{
	double dTemp1 = (dCdAOut*dPress)/sqrt(R*m_dLiquidTemp);
	double dTemp2 = 2*m_dCpCv/(m_dCpCv-1);
	double dTemp3 = pow(dPress/m_dGasPress,-2/m_dCpCv)-pow(dPress/m_dGasPress,-(m_dCpCv+1)/m_dCpCv);
	return -dTemp1*sqrt(dTemp2*dTemp3);
}
double GasProperty::SubSonicInC1(double dCdAin)
{
	double dTemp1 = dCdAin*m_dGasPress*m_dLiquidTemp;
	double dTemp2 = 2*m_dCpCv*R/(m_dCpCv-1)/m_dGasTemp;
	return dTemp1*sqrt(dTemp2);
}
double GasProperty::SubSonicOutC1(double dCdAOut)
{
	double dTemp1 = dCdAOut*m_dGasPress;
	double dTemp2 = 2*m_dCpCv*R*m_dGasTemp/(m_dCpCv-1);
	return dTemp1*sqrt(dTemp2);
}

double GasProperty::a()
{
	return 2/m_dCpCv;
}
double GasProperty::b()
{
	return (m_dCpCv+1)/m_dCpCv;
}