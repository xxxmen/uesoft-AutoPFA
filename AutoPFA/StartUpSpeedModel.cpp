// StartUpSpeedModel.cpp: implementation of the StartUpSpeedModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "StartUpSpeedModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StartUpSpeedModel::StartUpSpeedModel(DlgInerailTrans &ref)
:m_dlgTrans(ref)
{

}

StartUpSpeedModel::~StartUpSpeedModel()
{

}

BOOL StartUpSpeedModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void StartUpSpeedModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
	m_dlgTrans.TimeEvent(TRUE);
	m_dlgTrans.EnableUnit(FALSE);
	m_dlgTrans.ShowInitPage(0,FALSE);
	m_dlgTrans.ShowInitPage(1,FALSE);
	m_dlgTrans.ShowFB(FALSE);
	m_dlgTrans.SetInitCurSel(2);
	m_dlgTrans.SetDataCurSel(0);
}
