// SprayPerisist.cpp: implementation of the SprayPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SprayPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SprayPerisist::SprayPerisist()
{

}

SprayPerisist::~SprayPerisist()
{

}

Junperisist* SprayPerisist::CreatSpray()
{
	//16
	SprayPerisist *pSpray = new SprayPerisist;
	return pSpray;
}

ListImp<StrArray<4> >& SprayPerisist::PipeInfoToStd()
{
	CString strUnit = DistanceUnit();
	m_PipeInfo.TranToStd(3,strUnit);
	return m_PipeInfo.GetData();
}
