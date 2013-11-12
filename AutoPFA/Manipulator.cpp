// Manipulator.cpp: implementation of the Manipulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Manipulator.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Manipulator::Manipulator()
{

}

Manipulator::~Manipulator()
{

}

BOOL Manipulator::DbClick(UnitSubSystem &UnitSys)
{
	return FALSE;
}

Manipulator* Manipulator::Clone()
{
	return NULL;
}

BOOL Manipulator::IsInClient(CPoint pt)
{
	CRect rc = Region(pt);
	if(rc.top>0&&rc.left>0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
