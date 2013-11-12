// CaclFuild.cpp: implementation of the CaclFuild class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CaclFuild.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcFuild::CalcFuild()
{
	m_dTemperature = 0;				
	m_dDensity     = 0;						
	m_dViscosity   = 0;					
	m_dBulkModulus = 0;				
	m_dVaporPressure = 0;			
	m_dAtmosphericPressure = 0;		
    m_dGravity = 0;						
	m_dReTransLam = 0;				
	m_dReTransTurb = 0;					
}

CalcFuild::~CalcFuild()
{

}


ostream& operator<<(ostream &CalcOut,const CalcFuild &ref)
{
	CalcOut<<ref.m_dTemperature<<s_Separator
		   <<ref.m_dDensity<<s_Separator
		   <<ref.m_dViscosity<<s_Separator
		   <<ref.m_dBulkModulus<<s_Separator
		   <<ref.m_dVaporPressure<<s_Separator
		   <<ref.m_dAtmosphericPressure<<s_Separator
		   <<ref.m_dGravity<<s_Separator
		   <<ref.m_dReTransLam<<s_Separator
		   <<ref.m_dReTransTurb<<endl;	   
	return CalcOut;
}

void CalcFuild::Temperature(double dValue)
{
	m_dTemperature = dValue;
}
/*------------------------------------------------*/
void CalcFuild::Density(double dValue)
{
	m_dDensity = dValue;
}
/*------------------------------------------------*/
void CalcFuild::Viscos(double dValue)
{
	m_dViscosity = dValue;
}
/*------------------------------------------------*/
void CalcFuild::Modulus(double dValue)
{
	m_dBulkModulus = dValue;
}
/*------------------------------------------------*/
void CalcFuild::VaporPress(double dValue)
{
	m_dVaporPressure = dValue;
}
/*------------------------------------------------*/
void CalcFuild::AtmosphericPress(double dValue)
{
	m_dAtmosphericPressure = dValue;
}
/*------------------------------------------------*/
void CalcFuild::Gravity(double dValue)
{
	m_dGravity = dValue;
}
/*------------------------------------------------*/
void CalcFuild::ReTransLam(double dValue)
{
	m_dReTransLam = dValue;
}
/*------------------------------------------------*/
void CalcFuild::ReTransTurb(double dValue)
{
	m_dReTransTurb = dValue;
}
/*------------------------------------------------*/


double CalcFuild::Temperature()const
{
	return m_dTemperature;
}
/*------------------------------------------------*/
double CalcFuild::Density()const
{
	return m_dDensity;
}
/*------------------------------------------------*/
double CalcFuild::Viscos()const
{
	return m_dViscosity;
}
/*------------------------------------------------*/
double CalcFuild::Modulus()const
{
	return m_dBulkModulus;
}
/*------------------------------------------------*/
double CalcFuild::VaporPress()const
{
	return m_dVaporPressure;
}
/*------------------------------------------------*/
double CalcFuild::AtmosphericPress()const
{
	return m_dAtmosphericPressure;
}
/*------------------------------------------------*/
double CalcFuild::Gravity()const
{
	return m_dGravity;
}
/*------------------------------------------------*/
double CalcFuild::ReTransLam()const
{
	return m_dReTransLam;
}
/*------------------------------------------------*/
double CalcFuild::ReTransTurb()const
{
	return m_dReTransTurb;
}
/*------------------------------------------------*/