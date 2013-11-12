// AreaChangePerisist.cpp: implementation of the AreaChangePerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AreaChangePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AreaChangePerisist::AreaChangePerisist()
{

}

AreaChangePerisist::~AreaChangePerisist()
{

}

Junperisist* AreaChangePerisist::CreatAreaChange()
{
	//5
	AreaChangePerisist *pAreaChange = new AreaChangePerisist;
	return pAreaChange;
}
