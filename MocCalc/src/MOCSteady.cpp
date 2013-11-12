// MOCSteady.cpp: implementation of the MOCSteady class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCSteady.h"
#include "CaclSteady.h"
#include "MOCFluid.h"
#include "MOCComponentMgr.h"
#include "SteadyOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCSteady::MOCSteady()
{		
	m_PresTolType = 0;
	m_PresAbsTol = 0;		
	m_PresRelTol = 0;	  
	m_FlowTolType = 0;
	m_FlowAbsTol = 0;	
	m_FlowRelTol = 0;	
	m_FlowRelaxation = 0;
	m_PresRelaxation = 0;
    m_MaxIterations = 0;
	m_bOk = TRUE;
}

MOCSteady::~MOCSteady()
{

}

BOOL MOCSteady::Read(CalcSteady &data)
{
	m_PresTolType = data.PresTolType();
	m_PresAbsTol = data.PresAbsTol();
	if(data.PresAbsTolType()==0)
	{
		m_PresAbsTol = MOCFluid::TranHGLToPress(m_PresAbsTol);
	}	
	m_PresRelTol = data.PresRelTol();	  
	m_FlowTolType = data.FlowTolType();
	m_FlowAbsTol = data.FlowAbsTol();
	if(data.FlowAbsTolType()==0)
	{
		m_FlowAbsTol = MOCFluid::TranQToMass(m_FlowAbsTol);
	}
	m_FlowRelTol = data.FlowRelTol();
	m_FlowRelaxation = data.FlowRelaxation();
	m_PresRelaxation = data.PresRelaxation();
    m_MaxIterations = data.MaxIterations();
	return TRUE;
}

void MOCSteady::CalcStm(MOCComponentMgr &mgr,SteadyOutModel &model)
{
	int i = 0;
	do {
		m_bOk = TRUE;
		mgr.CalcStm(*this);
		i++;
	} while(i<m_MaxIterations && !m_bOk);
	Result(model,i);
	mgr.Result(model.ComponentOutMgr());
}

void MOCSteady::CheckFlow(double dOld, double &dNew)
{
	BOOL bOk = FALSE;
	BOOL bAbs = CheckAbs(dOld,dNew,m_FlowAbsTol);	//0，绝对公差；
	BOOL bRel = CheckRel(dOld,dNew,m_FlowRelTol);	//1, 相对公差；
	Relaxation(dOld,dNew,m_FlowRelaxation);			//使用松弛因子；
	switch(m_PresTolType) 
	{
	case 0:
		bOk = bAbs;
		break;
	case 1:
		bOk = bRel;
		break;
	case 2:
		bOk = (bAbs || bRel);
		break;
	case 3:
		bOk = (bAbs && bRel);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	if(!bOk)
		m_bOk = bOk;
}

void MOCSteady::CheckPress(double dOld, double &dNew)
{
	BOOL bOk = FALSE;
	BOOL bAbs = CheckAbs(dOld,dNew,m_PresAbsTol);
	BOOL bRel = CheckRel(dOld,dNew,m_PresRelTol);
	Relaxation(dOld,dNew,m_PresRelaxation);
	switch(m_FlowTolType) 
	{
	case 0:
		bOk = bAbs;
		break;
	case 1:
		bOk = bRel;
		break;
	case 2:
		bOk = (bAbs || bRel);
		break;
	case 3:
		bOk = (bAbs && bRel);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	if(!bOk)
		m_bOk = bOk;
}

BOOL MOCSteady::CheckAbs(double dOld, double dNew,double dEps)
{
	double dTemp = fabs(dNew-dOld);
	if(dTemp < dEps)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL MOCSteady::CheckRel(double dOld, double dNew,double dEps)
{
	double dTemp = fabs((dNew-dOld));
	if(dTemp < dEps*fabs(dNew))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


void MOCSteady::Relaxation(double dOld, double &dNew, double dRax)
{
	double dTemp = dNew-dOld;
	dNew = dOld + dTemp*dRax;
}

void MOCSteady::Result(SteadyOutModel &model,int n)
{
	SYSTEMTIME sysTime;
	::GetSystemTime(&sysTime);
	model.CurTime(&sysTime);
	model.Iterations(n);
	model.OK(m_bOk);
}
