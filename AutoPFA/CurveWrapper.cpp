// CurveWrapper.cpp: implementation of the CurveWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "CurveWrapper.h"
#include "pagechart.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CurveWrapper::CurveWrapper(ArrayFlyWeight<13> &Curve)
:m_Curve(Curve)
{

}

CurveWrapper::~CurveWrapper()
{

}

int CurveWrapper::GetLossType()
{
	return m_Curve.GetnValue();
}

void CurveWrapper::SetLossType(int nType)
{
	m_Curve.SetValue(nType);
}

/*--------------------------------------------------*/
int CurveWrapper::GetYAxisType()
{
	return m_Curve.GetnValue(1);
}

void CurveWrapper::SetYAxisType(int nType)
{
	m_Curve.SetValue(nType,1);
}

/*--------------------------------------------------*/
CString CurveWrapper::GetYAxisUnit()
{
	return m_Curve.GetValue(2);
}

void CurveWrapper::SetYAxisUnit(CString strUnit)
{
	m_Curve.SetValue(strUnit,2);
}

/*--------------------------------------------------*/
int CurveWrapper::GetXAxisType()
{
	return m_Curve.GetnValue(3);
}

void CurveWrapper::SetXAxisType(int nType)
{
	m_Curve.SetValue(nType,3);
}

/*--------------------------------------------------*/
CString CurveWrapper::GetXAxisUnit()
{
	return m_Curve.GetValue(4);
}

void CurveWrapper::SetXAxisUnit(CString strUnit)
{
	m_Curve.SetValue(strUnit,4);
}
/*--------------------------------------------------*/
double CurveWrapper::MaxValue()
{
	return m_Curve.GetfValue(5);
}

void CurveWrapper::MaxValue(double dValue)
{
	m_Curve.SetValue(float(dValue),5);
}
/*--------------------------------------------------*/
int CurveWrapper::CurveType()
{
	return m_Curve.GetnValue(6);
}

void CurveWrapper::CurveType(int nType)
{
	m_Curve.SetValue(nType,6);
}
/*--------------------------------------------------*/
int CurveWrapper::PrameNum()
{
	return m_Curve.GetnValue(7);
}

void CurveWrapper::PrameNum(int nType)
{
	m_Curve.SetValue(nType,7);
}
/*--------------------------------------------------*/
void CurveWrapper::GetPrame(double dPrame[])
{
	for(int i=0;i<5;i++)
	{
		dPrame[i] = m_Curve.GetfValue(i+8);
	}
}
/*--------------------------------------------------*/
void CurveWrapper::SetPrame(double dPrame[])
{
	for(int i=0;i<5;i++)
	{
		m_Curve.SetValue(float(dPrame[i]),i+8);
	}
}

void CurveWrapper::InitChart(PageChart &Page,TransDataTable<2> &rawData)
{
	Page.GetChart().Init();
	
	if(rawData.IsEmpty())
		return;
	double dMax = MaxValue();
	int nType = CurveType();
	int nNum = PrameNum();
	if( nType==1)
	{
		double dParme[5];
		GetPrame(dParme);
		Page.GetChart().SetData(dParme,nNum,0,dMax);
	}
	else if(nType == 2)
	{
		double dX[100] = {0};
		double dY[100] = {0};
		
		int dat = rawData.Data().GetCount();
		rawData.m_Data.GetData().ToDuoble(dX,0);
		rawData.m_Data.GetData().ToDuoble(dY,1);
		Page.GetChart().SetData(dX,dY,dat);
	}
}