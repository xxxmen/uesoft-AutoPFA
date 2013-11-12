// ComponentTranOut.cpp: implementation of the ComponentTranOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComponentTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentTranOut::ComponentTranOut()
{
}

ComponentTranOut::~ComponentTranOut()
{
}

Iterator<ComponentStmOut>* ComponentTranOut::CreatMaxMinIterator()
{
	return m_MaxMinStation.CreatIterator();
}

