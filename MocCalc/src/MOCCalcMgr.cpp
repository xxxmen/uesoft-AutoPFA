// MOCCalcMgr.cpp: implementation of the MOCCalcMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCCalcMgr.h"
#include "CaclDriverMgr.h"
#include "MOCComponentMgr.h"
#include "PFAOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCCalcMgr::MOCCalcMgr()
{
	m_AnalysisType = 0;
}

MOCCalcMgr::~MOCCalcMgr()
{

}

BOOL MOCCalcMgr::Read(CalcDriverMgr &data)
{
	m_AnalysisType = data.GetSteady().AnalysisType();
	if(!m_MOCSteady.Read(data.GetSteady()))
	{
		return FALSE;
	}
	if(!m_MOCTrans.Read(data.GetTrans()))
	{
		return FALSE;
	}
	return TRUE;
}



void MOCCalcMgr::Calc(MOCComponentMgr &mgr,PFAOutModel &model)
{
	CalcStm(mgr,model.SteadyOut());
	if(m_AnalysisType==0)
		CalcImpulse(mgr,model.TransOut());
}

void MOCCalcMgr::CalcStm(MOCComponentMgr &mgr,SteadyOutModel &model)
{
	m_MOCSteady.CalcStm(mgr,model);
}

void MOCCalcMgr::CalcImpulse(MOCComponentMgr &mgr,TransOutModel &model)
{
	m_MOCTrans.CalcImpulse(mgr,model);
}


