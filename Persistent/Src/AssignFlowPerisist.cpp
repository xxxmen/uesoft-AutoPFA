// AssignFlowPerisist.cpp: implementation of the AssignFlowPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AssignFlowPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AssignFlowPerisist::AssignFlowPerisist()
{

}

AssignFlowPerisist::~AssignFlowPerisist()
{

}

Junperisist* AssignFlowPerisist::CreatAssignedFlow()
{
	//3
	AssignFlowPerisist *pFlow = new AssignFlowPerisist;
	return pFlow;
}
