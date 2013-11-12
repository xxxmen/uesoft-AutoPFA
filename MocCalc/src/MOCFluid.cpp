// MOCFluid.cpp: implementation of the MOCFluid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCFluid.h"
#include "CaclFuild.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
double MOCFluid::m_dTemperature=0;				
double MOCFluid::m_dDensity=0;					
double MOCFluid::m_dViscosity=0;				
double MOCFluid::m_dBulkModulus=0;					
double MOCFluid::m_dVaporPressure=0;				
double MOCFluid::m_dAtmosphericPressure=0;		
double MOCFluid::m_dGravity=0;						
double MOCFluid::m_dReTransLam=0;					
double MOCFluid::m_dReTransTurb=0;
BOOL MOCFluid::m_bVapor = FALSE;
double MOCFluid::m_dSetpTime=1;	
BOOL MOCFluid::m_bVariableR=FALSE;				
MOCFluid::MOCFluid()
{

}

MOCFluid::~MOCFluid()
{

}

BOOL MOCFluid::Read(CalcFuild &data)
{
	m_dTemperature = data.Temperature();				
	m_dDensity     = data.Density();						
	m_dViscosity   = data.Viscos();					
	m_dBulkModulus = data.Modulus();				
	m_dVaporPressure = data.VaporPress();			
	m_dAtmosphericPressure = data.AtmosphericPress();		
    m_dGravity = data.Gravity();						
	m_dReTransLam = data.ReTransLam();				
	m_dReTransTurb = data.ReTransTurb();	
	m_bVapor = FALSE;
	return TRUE;
}


double MOCFluid::Temperature()
{
	return m_dTemperature;
}
/*------------------------------------------------*/
double MOCFluid::Density()
{
	return m_dDensity;
}
/*------------------------------------------------*/
double MOCFluid::Viscos()
{
	return m_dViscosity/m_dDensity;
}
/*------------------------------------------------*/
double MOCFluid::Modulus()
{
	return m_dBulkModulus;
}
/*------------------------------------------------*/
double MOCFluid::VaporPress()
{
	return m_dVaporPressure;
}
/*------------------------------------------------*/
double MOCFluid::AtmosphericPress()
{
	return m_dAtmosphericPressure;
}
/*------------------------------------------------*/
double MOCFluid::Gravity()
{
	return m_dGravity;
}
/*------------------------------------------------*/
double MOCFluid::ReTransLam()
{
	return m_dReTransLam;
}
/*------------------------------------------------*/
double MOCFluid::ReTransTurb()
{
	return m_dReTransTurb;
}

double MOCFluid::TranHToPress(double dH)
{
	return Density()*Gravity()*dH;
}
double MOCFluid::TranHGLToPress(double dH)
{
	return TranHToPress(dH)+m_dAtmosphericPressure;
}
double MOCFluid::TranPressToHGL(double dPress)
{
	return (dPress-m_dAtmosphericPressure)/Density()/Gravity();
}
double MOCFluid::TranPressToH(double dPress)
{
	return dPress/Density()/Gravity();
}
double MOCFluid::TranQToMass(double dQ)
{
	return Density()*dQ;
}
//计算本结点出，入口动压变化,只要是交接处管道出入口静压都要减去该动压损失
double MOCFluid::CalcPressLoss(double dMass,double dArea)
{
	double dV = dMass/Density()/dArea;
	return 0.5*Density()*pow(dV,2);
}

double MOCFluid::TranMassToQ(double dMass)
{
	return dMass / Density();
}

BOOL MOCFluid::IsVaporModel()
{
	return m_bVapor;
}
void MOCFluid::VaporModel(BOOL bVapor)
{
	m_bVapor = bVapor;
}
BOOL MOCFluid::IsVariableR()
{
	return m_bVariableR;
}
void MOCFluid::VariableR(BOOL bVariableR)
{
	m_bVariableR = bVariableR;
}
void MOCFluid::SetpTime(double dt)
{
	m_dSetpTime = dt;
}
double MOCFluid::SetpTime()
{
	return m_dSetpTime;
}
double MOCFluid::TranMassToV(double dMass)
{
	return TranMassToQ(dMass)*m_dSetpTime;
}
double MOCFluid::TranVToMass(double dVolume)
{
	return TranQToMass(dVolume/m_dSetpTime);
}

	