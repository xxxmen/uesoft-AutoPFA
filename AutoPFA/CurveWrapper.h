// CurveWrapper.h: interface for the CurveWrapper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURVEWRAPPER_H__A0EBF073_F061_4171_807F_7B6B6D8CD23C__INCLUDED_)
#define AFX_CURVEWRAPPER_H__A0EBF073_F061_4171_807F_7B6B6D8CD23C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ArrayFlyWeight.h"
#include "TransDataTable.h"
class PageChart;

class CurveWrapper  
{
public:
	void SetLossType(int nType);
	int GetLossType();
	void SetYAxisType(int nType);
	int GetYAxisType();
	void SetYAxisUnit(CString strUnit);
	CString GetYAxisUnit();
	void SetXAxisType(int nType);
	int GetXAxisType();
	void SetXAxisUnit(CString strUnit);
	CString GetXAxisUnit();
	void MaxValue(double dValue);
	double MaxValue();
	void CurveType(int nType);
	int CurveType();
	void PrameNum(int nNum);
	int PrameNum();
	void GetPrame(double dPrame[]);
	void SetPrame(double dPrame[]);
	void CurveWrapper::InitChart(PageChart &Page,TransDataTable<2> &rawData);
	CurveWrapper(ArrayFlyWeight<13> &Curve);
	virtual ~CurveWrapper();

private:
	ArrayFlyWeight<13>& m_Curve;		//损失模型(0：流量系数模型，1：K系数模型3：变流量系数)
										//Y轴参数类型数字标记[]
										//Y轴参数单位[]
										//X轴参数类型数字标记[]
										//X轴参数单位[]
										//x的最大取值[]
										//曲线类型[曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）]
										//公式中参数和常量的个数[]
										//公式中的参数和常量a，b，c，d，e的值[]

};

#endif // !defined(AFX_CURVEWRAPPER_H__A0EBF073_F061_4171_807F_7B6B6D8CD23C__INCLUDED_)
