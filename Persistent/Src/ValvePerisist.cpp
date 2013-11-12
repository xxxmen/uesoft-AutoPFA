// ValvePerisist.cpp: implementation of the ValvePerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ValvePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ValvePerisist::ValvePerisist()
{

}

ValvePerisist::~ValvePerisist()
{

}

Junperisist* ValvePerisist::CreatValve()
{
	//8
	ValvePerisist *pValve = new ValvePerisist;
	return pValve;
}
