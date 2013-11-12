// WhitoutInertia.cpp: implementation of the WhitoutInertia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WhitoutInertia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "PumpTransModelMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WhitoutInertia::WhitoutInertia()
{

}

WhitoutInertia::~WhitoutInertia()
{

}

void WhitoutInertia::CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet)
{
	double dRatio = mgr.GetTranData().GeTransY(dTime,dSpeedRatio,trans.StartTime());
	mgr.SetCurSpeedRatio(dRatio/100);
	mgr.CalcImpulse(nSet);
}
