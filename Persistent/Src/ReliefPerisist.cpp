// ReliefPerisist.cpp: implementation of the ReliefPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ReliefPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ReliefPerisist::ReliefPerisist()
{

}

ReliefPerisist::~ReliefPerisist()
{

}

Junperisist* ReliefPerisist::CreatRelief()
{
	//21
	ReliefPerisist *pRelief = new ReliefPerisist;
	return pRelief;
}
