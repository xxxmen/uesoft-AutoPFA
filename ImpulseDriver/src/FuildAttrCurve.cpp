// FuildAttrCurve.cpp: implementation of the FuildAttrCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FuildAttrCurve.h"
#include "UeChartHeader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "RowObjectFace.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuildAttrCurve::FuildAttrCurve()
{
	m_dPrame[0] = 0;
	m_dPrame[1] = 0;
	m_dPrame[2] = 0;
	m_dPrame[3] = 0;
	m_dPrame[4] = 0;
}

FuildAttrCurve::~FuildAttrCurve()
{

}

CString FuildAttrCurve::Init(CString strData)
{
	RowObjectFace<6> data;
	strData = data.InitData(strData);
	data.GetData(m_strUnit,0);
	data.GetData(m_dPrame[0],1);
	data.GetData(m_dPrame[1],2);
	data.GetData(m_dPrame[2],3);
	data.GetData(m_dPrame[3],4);
	data.GetData(m_dPrame[4],5);
	return strData;
}

CString FuildAttrCurve::GetUnit()
{
	return m_strUnit;
}

double FuildAttrCurve::GetY(double dX)
{
	double dY = 0;
	PolyValve(m_dPrame,5,dX,dY);
	return dY;
}
