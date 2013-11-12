// AreaChangeLossCalc.cpp: implementation of the AreaChangeLossCalc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "AreaChangeLossCalc.h"
#include "ILossCalcStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AreaChangeLossCalc::AreaChangeLossCalc()
{
	m_factory = LossCalcFactory::Instance();
	m_dAngel = 0;
	m_dAreaUp = 0;
	m_dAreaDown = 0;
	m_nType = 0;  
}

AreaChangeLossCalc::~AreaChangeLossCalc()
{

}

//int AreaChangeLossCalc::GetnRetype()const

int AreaChangeLossCalc::GetType()const
{
	int nType = 0;
	if(!IsDataOK())
		return nType;
	if(m_dAreaUp > m_dAreaDown)
	{
		if(m_nType==1)
		{
			nType = 6; //AbruptContractionStrategy
		}
		else
		{
			if(m_dAngel > 45)
			{
				nType = 4;//ConicalContraction90Strategy
			}
			else
			{
				nType = 3; //ConicalContraction45Strategy
			}
		}
	}
	else
	{
		if(m_nType==1)
		{
			nType = 5; //AbruptExpansionStrategy
		}
		else
		{
			if(m_dAngel > 45)
			{
				nType = 2;//ConicalExpansion90Strategy
			}
			else
			{
// 				if (m_nRetype ==2 || m_nRetype ==3)
// 					nType = 3;
// 				else
					nType = 1; //ConicalExpansion45Strategy
			}
		}
	}
	return nType;
}

double AreaChangeLossCalc::CalcK()
{
	double dK = 0;
	double temp = 0;
	if(IsDataOK())
	{
		ILossCalcStrategy *pStrategy = m_factory->CreatObject(GetType());
		switch (m_nRetype){
		case 0:
			m_BaseArea = 1.0;
			break;
		case 1:
			m_BaseArea = 1.0;
			temp = m_dAreaUp;
			m_dAreaUp = m_dAreaDown;
	 		m_dAreaDown = temp;
			break;
		case 2:
			if (m_dAreaUp > m_dAreaDown)
			{
				temp = m_dAreaUp;
				m_dAreaUp = m_dAreaDown;
				m_dAreaDown = temp;
			}
			m_BaseArea = pow(m_BaseArea/m_dAreaUp,2);
			break;
		case 3:
			if (m_dAreaUp > m_dAreaDown)
			{
				temp = m_dAreaUp;
				m_dAreaUp = m_dAreaDown;
				m_dAreaDown = temp;
			}
			m_BaseArea = PI*pow(m_BaseArea/2.0,2);
			m_BaseArea = pow(m_BaseArea/m_dAreaUp,2);
			break;
		default:
			break;
		}
		if(pStrategy != NULL)
		{
			dK = pStrategy->CalcK(*this);
		}
	}
	return dK;
}

BOOL AreaChangeLossCalc::IsDataOK()const
{
	if(-0.00001<m_dAreaUp && m_dAreaUp<0.00001)
		return FALSE;
	if(-0.00001<m_dAreaDown && m_dAreaDown<0.00001)
		return FALSE;
	return TRUE;
}
