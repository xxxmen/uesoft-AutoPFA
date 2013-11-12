// CheckPerisist.cpp: implementation of the CheckPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CheckPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CheckPerisist::CheckPerisist()
{

}

CheckPerisist::~CheckPerisist()
{

}

Junperisist* CheckPerisist::CreatCheckValve()
{
	//10
	CheckPerisist *pCheck = new CheckPerisist;
	return pCheck;
}
