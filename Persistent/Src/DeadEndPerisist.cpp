// DeadEndPerisist.cpp: implementation of the DeadEndPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DeadEndPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DeadEndPerisist::DeadEndPerisist()
{

}

DeadEndPerisist::~DeadEndPerisist()
{

}

Junperisist* DeadEndPerisist::CreatDeadEnd()
{
	//11
	DeadEndPerisist *pDeadEnd = new DeadEndPerisist;
	return pDeadEnd;
}
