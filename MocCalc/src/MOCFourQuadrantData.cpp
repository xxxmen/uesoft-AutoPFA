// MOCFourQuadrantData.cpp: implementation of the MOCFourQuadrantData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCFourQuadrantData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCFourQuadrantData::MOCFourQuadrantData()
{
	m_nAngelType = 0;
}

MOCFourQuadrantData::~MOCFourQuadrantData()
{

}

void MOCFourQuadrantData::AngleType(int nValue)
{
	m_nAngelType = nValue;
}

void MOCFourQuadrantData::FH(const ListImp<StrArray<2> > &ref)
{
	m_tableFH.SetData(ref);
}

void MOCFourQuadrantData::FB(const ListImp<StrArray<2> > &ref)
{
	m_tableFB.SetData(ref);
}

double MOCFourQuadrantData::GetFH(double dAngel)
{
	return m_tableFH.GetValue(dAngel);
}

double MOCFourQuadrantData::GetFB(double dAngel)
{
	return m_tableFB.GetValue(dAngel);
}

double MOCFourQuadrantData::CalcAngel(double da, double dv)
{
	double dAngel = 0;
	if(0== m_nAngelType)
	{
		dAngel = atan2(dv,da);
		if(dv>0&&da<0)
			dAngel += PI;
		return ((PI + dAngel)*180/PI);
	}
	else
	{
		dAngel = atan2(da,dv);
		if(da<0)
			dAngel += PI*2;
		return (dAngel*180/PI);
	}
}

double MOCFourQuadrantData::GetFH(double da,double dv)
{
	return GetFH(CalcAngel(da,dv));
}

double MOCFourQuadrantData::GetFB(double da,double dv)
{
	return GetFB(CalcAngel(da,dv));
}


