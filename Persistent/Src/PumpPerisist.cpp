// PumpPerisist.cpp: implementation of the PumpPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PumpPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpPerisist::PumpPerisist()
{

}

PumpPerisist::~PumpPerisist()
{

}

Junperisist* PumpPerisist::CreatPump()
{
	//17
	PumpPerisist *pPump = new PumpPerisist;
	return pPump;
}
