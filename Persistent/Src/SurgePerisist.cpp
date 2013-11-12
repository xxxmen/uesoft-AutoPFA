// SurgePerisist.cpp: implementation of the SurgePerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SurgePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SurgePerisist::SurgePerisist()
{

}

SurgePerisist::~SurgePerisist()
{

}

Junperisist* SurgePerisist::CreatSurge()
{
	//24
	SurgePerisist *pSurge = new SurgePerisist;
	return pSurge;
}

ListImp<StrArray<4> >& SurgePerisist::PipeInfoToStd()
{
	CString strUnit = DistanceUnit();
	m_PipeInfo.TranToStd(3,strUnit);
	return m_PipeInfo.GetData();
}