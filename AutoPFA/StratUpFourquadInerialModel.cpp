// StratUpFourquadInerialModel.cpp: implementation of the StratUpFourquadInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "StratUpFourquadInerialModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StratUpFourquadInerialModel::StratUpFourquadInerialModel(DlgInerailTrans &ref)
:m_dlgTrans(ref)
{

}

StratUpFourquadInerialModel::~StratUpFourquadInerialModel()
{

}

BOOL StratUpFourquadInerialModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void StratUpFourquadInerialModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
	m_dlgTrans.TimeEvent(FALSE);
	m_dlgTrans.SetInitCurSel(0);
	m_dlgTrans.SetDataCurSel(0);
}
