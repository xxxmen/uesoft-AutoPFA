// CalcPeriodic.cpp: implementation of the CalcPeriodic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPeriodic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPeriodic::CalcPeriodic()
{
	m_bPeriodic = 0;		
	m_bChop = 0;			
	m_dFrequency = 0;		
	m_dAmplitude = 0;	
}

CalcPeriodic::~CalcPeriodic()
{

}

ostream& operator<< (ostream &CalcOut,const CalcPeriodic &ref)
{
	CalcOut<<ref.m_bPeriodic<<s_Separator
		   <<ref.m_bChop<<s_Separator
		   <<ref.m_dFrequency<<s_Separator
		   <<ref.m_dAmplitude<<s_Separator;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcPeriodic::Periodic(int nValue)
{
	m_bPeriodic = abs(nValue);
}
/*------------------------------------------------*/
void CalcPeriodic::Chop(int nValue)
{
	m_bChop = abs(nValue);
}
/*------------------------------------------------*/
void CalcPeriodic::Frequency(double dValue)
{
	m_dFrequency = dValue;
}
/*------------------------------------------------*/
void CalcPeriodic::Amplitude(double dValue)
{
	m_dAmplitude = dValue;
}

////////////////////////////////////////
/*------------------------------------------------*/
BOOL CalcPeriodic::Periodic()
{
	if(m_bPeriodic==1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/*------------------------------------------------*/
BOOL CalcPeriodic::Chop()
{
	if(m_bChop==1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/*------------------------------------------------*/
double CalcPeriodic::Frequency()
{
	return m_dFrequency;
}
/*------------------------------------------------*/
double CalcPeriodic::Amplitude()
{
	return m_dAmplitude;
}