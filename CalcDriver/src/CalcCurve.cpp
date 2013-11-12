// CalcCurve.cpp: implementation of the CalcCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcCurve.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcCurve::CalcCurve()
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

CalcCurve::~CalcCurve()
{

}

ostream& operator<< (ostream &CalcOut,const CalcCurve &ref)
{
	CalcOut<<ref.m_nCurveType<<s_Separator;
	if(ref.m_nCurveType==0)
		return CalcOut;
	if(ref.m_nCurveType==1)
	{
		CalcOut<<ref.m_dMaxX<<s_Separator
		       <<ref.m_nOrder<<s_Separator;
		for(int i=0;i<=ref.m_nOrder;i++)
		{
		    CalcOut<<ref.m_dPrame[i]<<s_Separator;
		}	   
	}	   
	return CalcOut;
}

/*------------------------------------------------*/
void CalcCurve::CurveType(int nValue)
{
	m_nCurveType = nValue;
}
/*------------------------------------------------*/
void CalcCurve::XAxisType(int nValue)
{
	m_nXAxisType = nValue;
}
/*------------------------------------------------*/
void CalcCurve::YAxisType(int nValue)
{
	m_nYAxisType = nValue;
}
/*------------------------------------------------*/
void CalcCurve::MaxX(double dValue)
{
	m_dMaxX = dValue;
}
/*------------------------------------------------*/
void CalcCurve::Order(int nValue)
{
	m_nOrder = nValue;
}
/*------------------------------------------------*/
void CalcCurve::A(double dValue)
{
	m_dPrame[0] = dValue;
}
/*------------------------------------------------*/
void CalcCurve::B(double dValue)
{
	m_dPrame[1] = dValue;
}
/*------------------------------------------------*/
void CalcCurve::C(double dValue)
{
	m_dPrame[2] = dValue;
}
/*------------------------------------------------*/
void CalcCurve::D(double dValue)
{
	m_dPrame[3] = dValue;
}
/*------------------------------------------------*/
void CalcCurve::E(double dValue)
{
	m_dPrame[4] = dValue;
}

int CalcCurve::CurveType()
{
	return m_nCurveType;
}
int CalcCurve::XAxisType()
{
	return m_nXAxisType;
}
int CalcCurve::YAxisType()
{
	return m_nYAxisType;
}
double CalcCurve::MaxX()
{
	return m_dMaxX;
}
int CalcCurve::Order()	
{
	return m_nOrder;
}
void CalcCurve::Prame(double dPrame[])const
{
	for(int i=0;i<5;i++)
	{
		dPrame[i] = m_dPrame[i]; 
	}
}
