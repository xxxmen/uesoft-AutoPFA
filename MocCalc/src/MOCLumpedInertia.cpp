// MOCLumpedInertia.cpp: implementation of the MOCLumpedInertia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCLumpedInertia.h"
#include "CalcOrifice.h"
#include "CalcShortPipe.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCLumpedInertia::MOCLumpedInertia()
{
	m_bOrificeModel = 0;				
	m_dInFlowCD = 0;			
	m_dOutFlowCD = 0;			
	m_dOrificeArea = 0;
	m_bShortPipeModel = 0;				
	m_dFriction = 0;		
	m_dShortPipeArea = 0;			
	m_dInDia = 0;			
	m_dLen = 0;				
	m_dEle = 0;	
}

MOCLumpedInertia::~MOCLumpedInertia()
{

}

BOOL MOCLumpedInertia::Read(CalcOrifice &orifice,CalcShortPipe &shortPipe)
{
	m_bOrificeModel = orifice.Model();				
	m_dInFlowCD = orifice.InFlowCD();			
	m_dOutFlowCD = orifice.OutFlowCD();			
	m_dOrificeArea = orifice.Area();
	m_bShortPipeModel = shortPipe.Model();				
	m_dFriction = shortPipe.Friction();		
	m_dShortPipeArea = shortPipe.Area();			
	m_dInDia = shortPipe.InDia();			
	m_dLen = shortPipe.Len();				
	m_dEle = shortPipe.Ele();
	return TRUE;
}
/*-----------------------------------------------*/
//  dPOld1    元件底面的压强
//  dPOld3    元件与管系连接点的压强
//  dMassOld  从元件流入管系的质量流量
/*-----------------------------------------------*/

double MOCLumpedInertia::CalcC1(double dPOld1,double dPOld3,double dMassOld)
{
	if(m_bOrificeModel==0&&m_bShortPipeModel==0)
		return 0;
	double dA = 2*MOCFluid::Density()*MOCFluid::Gravity()*m_dEle;
	double dB = (2*m_dLen)/(m_dShortPipeArea*MOCFluid::SetpTime());
	return (dPOld3-dPOld1-dA*m_bShortPipeModel-dB*dMassOld*m_bShortPipeModel);
}

double MOCLumpedInertia::CalcC2(double dMassOld,BOOL bInSys)
{
	if(m_bOrificeModel==0&&m_bShortPipeModel==0)
		return 0;
	double dCD = 0;
	if(bInSys)
	{
		dCD = m_dOutFlowCD;
	}
	else
	{
		dCD = m_dInFlowCD;
	}
	double dA =(m_dFriction*m_dLen)/(MOCFluid::Density()*m_dInDia*pow(m_dShortPipeArea,2));
	double dB =(2*m_dLen)/(m_dShortPipeArea*MOCFluid::SetpTime());
	double dC = 0;
	if(m_bOrificeModel==1)
		dC =1/(MOCFluid::Density()*pow(m_dOrificeArea,2)*pow(dCD,2));
	return (dA*fabs(dMassOld)*m_bShortPipeModel+dB*m_bShortPipeModel+dC*fabs(dMassOld));
}

BOOL MOCLumpedInertia::IsOrifice()
{
	if(m_bOrificeModel ==1)
		return TRUE;
	return FALSE;
}

double MOCLumpedInertia::EleChange()
{
	if(m_bShortPipeModel==0)
		return 0;
	return m_dEle;
}

double MOCLumpedInertia::ElePress()
{
	return	MOCFluid::TranHToPress(EleChange());
}