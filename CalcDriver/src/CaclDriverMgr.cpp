// CaclDriverMgr.cpp: implementation of the CaclDriverMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CaclDriverMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcDriverMgr::CalcDriverMgr()
{

}

CalcDriverMgr::~CalcDriverMgr()
{

}

BOOL CalcDriverMgr::Save(ofstream &stream)
{
	stream<<m_Steady.AnalysisType()<<endl
		  <<m_fluid
		  <<m_Steady
		  //<<m_Trans
		  <<m_pipeMgr
		  <<m_junMgr;
	return TRUE;
}


CalcFuild& CalcDriverMgr::GetFuild()
{
	return m_fluid;
}

CalcSteady& CalcDriverMgr::GetSteady()
{
	return m_Steady;
}

CalcTrans& CalcDriverMgr::GetTrans()
{
	return m_Trans;
}

CalcPipeMgr& CalcDriverMgr::GetPipeMgr()
{
	return m_pipeMgr;
}

CalcJunMgr& CalcDriverMgr::GetJunMgr()
{
	return m_junMgr;
}