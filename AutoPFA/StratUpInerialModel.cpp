// StratUpInerialModel.cpp: implementation of the StratUpInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "StratUpInerialModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StratUpInerialModel::StratUpInerialModel(DlgInerailTrans &ref)
:m_dlgTrans(ref)
{

}

StratUpInerialModel::~StratUpInerialModel()
{

}

BOOL StratUpInerialModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void StratUpInerialModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
	m_dlgTrans.TimeEvent(FALSE);
	m_dlgTrans.ShowDataPage(0,FALSE);
	m_dlgTrans.SetInitCurSel(0);
	m_dlgTrans.SetDataCurSel(1);
}
