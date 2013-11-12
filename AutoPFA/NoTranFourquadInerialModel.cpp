// NoTranFourquadInerialModel.cpp: implementation of the NoTranFourquadInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "NoTranFourquadInerialModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NoTranFourquadInerialModel::NoTranFourquadInerialModel(DlgInerailTrans &ref)
:m_dlgTrans(ref)
{

}

NoTranFourquadInerialModel::~NoTranFourquadInerialModel()
{

}

BOOL NoTranFourquadInerialModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void NoTranFourquadInerialModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
	m_dlgTrans.EnableSpecial(FALSE);
	m_dlgTrans.EnableEvent(FALSE);
	m_dlgTrans.EnableUnit(FALSE);
	m_dlgTrans.ShowInitPage(0,FALSE);
	m_dlgTrans.ShowInitPage(1,FALSE);
	m_dlgTrans.ShowFB(FALSE);
	m_dlgTrans.SetInitCurSel(2);
	m_dlgTrans.ShowDataPage(1,FALSE);
	m_dlgTrans.SetDataCurSel(0);
}
