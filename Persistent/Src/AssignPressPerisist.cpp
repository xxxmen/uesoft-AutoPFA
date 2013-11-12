// AssignPressPerisist.cpp: implementation of the AssignPressPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AssignPressPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AssignPressPerisist::AssignPressPerisist()
{

}

AssignPressPerisist::~AssignPressPerisist()
{

}

Junperisist* AssignPressPerisist::CreatAssignedPressure()
{
	//4
	AssignPressPerisist *pPress = new AssignPressPerisist;
	return pPress;
}

ListImp<StrArray<4> >& AssignPressPerisist::PipeInfoToStd()
{
	CString strUnit = DistanceUnit();
	m_PipeInfo.TranToStd(3,strUnit);
	return m_PipeInfo.GetData();
}