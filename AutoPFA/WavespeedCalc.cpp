// WavespeedCalc.cpp: implementation of the WavespeedCalc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "WavespeedCalc.h"
#include "ISupportStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WavespeedCalc::WavespeedCalc()
{
	m_factory = SupportStrategyFactory::Instance();
	m_nSupportType = 0;		
	m_dK = 0;				
	m_dDen = 0;			
	m_dE = 0;				
	m_dDia = 0;			
	m_de = 0;			
	m_dC1 = 0;			
	m_du = 0;
}

WavespeedCalc::~WavespeedCalc()
{

}

double WavespeedCalc::CalcC1()
{
	ISupportStrategy *pStrategy = m_factory->CreatObject(m_nSupportType);
	double dC1=0;
	if(pStrategy != NULL)
	{
		dC1 = pStrategy->GetC1(*this);
	}
	else
	{
		dC1 = m_dC1;
	}
	
	if(dC1<0)
		dC1 = 0;
	return dC1;
}


double WavespeedCalc::GetWave(double dC1)
{
	double dWave = 0;
	m_dC1 = dC1;
	if(m_dK>0 && m_dDen>0 && m_dDia>0 && m_dE>0 && m_de>0 && m_du>0 &&m_dC1>0)
	{
		dWave = (m_dK/m_dDen)/(1+m_dC1*((m_dK/m_dE))*(m_dDia/m_de));
		if(dWave<0)
			dWave=0;
		dWave = sqrt(dWave);
	}
	return dWave;
}

double WavespeedCalc::GetWave(double dC1,CString strUnit)
{
	double dOut = 0;
	TransformFromStd(dOut,strUnit,GetWave(dC1));
	return dOut;
}
