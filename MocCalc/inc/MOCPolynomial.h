// MOCPolynomial.h: interface for the MOCPolynomial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPOLYNOMIAL_H__51E552DB_47AA_451C_AAAA_3AFBCB96E57B__INCLUDED_)
#define AFX_MOCPOLYNOMIAL_H__51E552DB_47AA_451C_AAAA_3AFBCB96E57B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcCurve;
#include "MOCTable.h"

class MOCPolynomial  
{
public:
	
	void Read(CalcCurve &curve);
	MOCPolynomial();
	virtual ~MOCPolynomial();
	
public:
	double GetY(MOCCurveData & data,double dX);
	int CurveType();
	int XAxisType();
	int YAxisType();
	double MaxX();
	int Order();
private:
	double GetY(double dX);
	int m_nCurveType;			//曲线类型: 曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）
	int m_nXAxisType;			//X轴参数类型数字标记
	int m_nYAxisType;			//Y轴参数类型数字标记
	double m_dMaxX;				//曲线自变量的坐标最大值
    int    m_nOrder;			//曲线拟合阶数
	double m_dPrame[5];		    //公式中的参数和常量a，b，c，d，e的值

};

#endif // !defined(AFX_MOCPOLYNOMIAL_H__51E552DB_47AA_451C_AAAA_3AFBCB96E57B__INCLUDED_)
