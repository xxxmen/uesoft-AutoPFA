// MOCPeriodic.cpp: implementation of the MOCPeriodic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPeriodic.h"
#include "CalcPeriodic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPeriodic::MOCPeriodic()
{
	m_bPeriodic = FALSE;		
	m_bChop = FALSE;			
	m_dFrequency = 0;		
	m_dAmplitude = 0;
}

MOCPeriodic::~MOCPeriodic()
{

}


void MOCPeriodic::Read(CalcPeriodic &periodic)
{
	m_bPeriodic = periodic.Periodic();		
	m_bChop = periodic.Chop();			
	m_dFrequency = periodic.Frequency();		
	m_dAmplitude = periodic.Amplitude();
}

void MOCPeriodic::Tran(PFUNTRAN pTran)
{
	m_dAmplitude = pTran(m_dAmplitude);
}

double MOCPeriodic::GetTransY(double dX)
{
	double dY = m_dAmplitude*sin(m_dFrequency*PI*dX);
	if(m_bChop)
		dY = fabs(dY);
	return dY;
}

BOOL MOCPeriodic::IsSelPeriodic()
{
	return m_bPeriodic;
}
