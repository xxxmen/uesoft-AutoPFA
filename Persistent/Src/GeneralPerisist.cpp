// GeneralPerisist.cpp: implementation of the GeneralPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GeneralPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GeneralPerisist::GeneralPerisist()
{

}

GeneralPerisist::~GeneralPerisist()
{

}

Junperisist* GeneralPerisist::CreatGeneral()
{
	//20
	GeneralPerisist *pGeneral = new GeneralPerisist;
	return pGeneral;
}
