// MOCStation.cpp: implementation of the MOCStation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCStation.h"
#include "BrachJunStrategy.h"
#include "MOCTrans.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCStation::MOCStation()
:m_InEnd(INJUN)
,m_OutEnd(OUTJUN)
{
	m_EndList.AddEnd(&m_InEnd);
	m_EndList.AddEnd(&m_OutEnd);
}

MOCStation::~MOCStation()
{
}

int MOCStation::Key()
{
	return m_nKey;
}

void MOCStation::Key(int nKey)
{
	m_nKey = nKey;
}

void MOCStation::SetMass(double dMass)
{
	m_InEnd.SetMass(dMass);
	m_OutEnd.SetMass(dMass);
}


void MOCStation::SetPress(double dPress)
{
	m_InEnd.SetPress(dPress);
	m_OutEnd.SetPress(dPress);
}

void MOCStation::SetZ(double dZ)
{
	m_InEnd.SetZ(dZ);
	m_OutEnd.SetZ(dZ);
}

MOCStation* MOCStation::Creator()
{
	return new MOCStation;
}

void MOCStation::SetArea(double dArea)
{
	m_InEnd.Area(dArea);
	m_OutEnd.Area(dArea);
}

EndInfo* MOCStation::GetInEnd()
{
	return &m_InEnd;
}

EndInfo* MOCStation::GetOutEnd()
{
	return &m_OutEnd;
}

double MOCStation::GetBp()
{
	return m_InEnd.GetBpm();
}

double MOCStation::GetBm()
{
	return m_OutEnd.GetBpm();
}

double MOCStation::GetCp()
{
	return m_InEnd.GetCpm();
}

double MOCStation::GetCm()
{
	return m_OutEnd.GetCpm();
}

void MOCStation::CalcImpulse(MOCTrans &trans)
{
	m_EndList.BranchStrategy(0);
}


