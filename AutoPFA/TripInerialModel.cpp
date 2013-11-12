// TripInerialModel.cpp: implementation of the TripInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "TripInerialModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TripInerialModel::TripInerialModel(DlgInerailTrans &ref)
:m_dlgTrans(ref)
{

}

TripInerialModel::~TripInerialModel()
{

}

BOOL TripInerialModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void TripInerialModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
	m_dlgTrans.TimeEvent(FALSE);
	m_dlgTrans.ShowDataPage(0,FALSE);
	m_dlgTrans.SetInitCurSel(0);
}
