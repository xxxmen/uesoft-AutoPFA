// ReservoirPerisist.cpp: implementation of the ReservoirPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ReservoirPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ReservoirPerisist::ReservoirPerisist()
{

}

ReservoirPerisist::~ReservoirPerisist()
{

}

Junperisist* ReservoirPerisist::CreatReservoir()
{
	//2
	ReservoirPerisist *pReservior = new ReservoirPerisist;
	return pReservior;
}

inline ListImp<StrArray<6> >& ReservoirPerisist::PipeInfoToStd()
{
	CString strUnit = m_EleOrDepthUnit.Data(1);
	m_PipeInfo.TranToStd(5,strUnit);
	return m_PipeInfo.GetData();
}