// BranchPerisist.cpp: implementation of the BranchPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BranchPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BranchPerisist::BranchPerisist()
{

}

BranchPerisist::~BranchPerisist()
{

}

Junperisist* BranchPerisist::CreatBranch()
{
	//1
	BranchPerisist *pBranch = new BranchPerisist;
	return pBranch;
}

ListImp<StrArray<4> >& BranchPerisist::PipeInfoToStd()
{
	CString strUnit = DistanceUnit();
	m_PipeInfo.TranToStd(3,strUnit);
	return m_PipeInfo.GetData();
}