// ControlPerisist.cpp: implementation of the ControlPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ControlPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlPerisist::ControlPerisist()
{

}

ControlPerisist::~ControlPerisist()
{

}

Junperisist* ControlPerisist::CreatControlValve()
{
	//9
	ControlPerisist *pControl = new ControlPerisist;
	return pControl;
}
