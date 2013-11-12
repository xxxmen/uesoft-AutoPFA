// MOCPolynomial.cpp: implementation of the MOCPolynomial class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPolynomial.h"
#include"CalcCurve.h"
#include "UeChartHeader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPolynomial::MOCPolynomial()
{
	m_nCurveType = 0;		
	m_nXAxisType = 0;	
	m_nYAxisType = 0;		
	m_dMaxX = 0;			
    m_nOrder = 0;		
	m_dPrame[0] = 0;
	m_dPrame[1] = 0;
	m_dPrame[2] = 0;
	m_dPrame[3] = 0;
	m_dPrame[4] = 0;
}

MOCPolynomial::~MOCPolynomial()
{

}

void MOCPolynomial::Read(CalcCurve &curve)
{
	m_nCurveType = curve.CurveType();		
	m_nXAxisType = curve.XAxisType();	
	m_nYAxisType = curve.YAxisType();		
	m_dMaxX = curve.MaxX();			
    m_nOrder = curve.Order();		
	curve.Prame(m_dPrame);
}

double MOCPolynomial::GetY(double dX)
{
	double dY = 0;
	PolyValve(m_dPrame,m_nOrder,dX,dY);
	return dY;
}

int MOCPolynomial::CurveType()
{
	return m_nCurveType;
}
int MOCPolynomial::XAxisType()
{
	return m_nXAxisType;
}
int MOCPolynomial::YAxisType()
{
	return m_nYAxisType;
}
double MOCPolynomial::MaxX()
{
	return m_dMaxX;
}
int MOCPolynomial::Order()	
{
	return m_nOrder;
}



double MOCPolynomial::GetY(MOCCurveData &data, double dX)
{
	if(CurveType()==1)
	{
		return GetY(dX);
	}
	else
	{
		return data.GetValue(dX);
	}
}
