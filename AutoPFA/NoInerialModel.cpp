// NoInerialModel.cpp: implementation of the NoInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "NoInerialModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NoInerialModel::NoInerialModel(DlgNoInerialTrans &ref)
:m_dlgTrans(ref)
{

}

NoInerialModel::~NoInerialModel()
{

}

BOOL NoInerialModel::UpData(PumpTransient &ref)
{
	m_dlgTrans.UpData(ref);
	return TRUE;
}

void NoInerialModel::Init(PumpTransient &ref)
{
	m_dlgTrans.Init(ref);
}
