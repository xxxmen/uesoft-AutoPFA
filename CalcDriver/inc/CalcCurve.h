// CalcCurve.h: interface for the CalcCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCURVE_H__2FBC8CD9_0E97_495C_8BC7_34EF993ECC24__INCLUDED_)
#define AFX_CALCCURVE_H__2FBC8CD9_0E97_495C_8BC7_34EF993ECC24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcCurve  
{
public:
	CalcCurve();
	virtual ~CalcCurve();
public:
	void CurveType(int nValue);
	void XAxisType(int nValue);
	void YAxisType(int nValue);
	void MaxX(double dValue);
	void Order(int nValue);
	void A(double dValue);
	void B(double dValue);
	void C(double dValue);
	void D(double dValue);
	void E(double dValue);
	int CurveType();
	int XAxisType();
	int YAxisType();
	double MaxX();
	int Order();
	void Prame(double dPrame[])const;//
	friend	ostream& operator<< (ostream &CalcOut,const CalcCurve &ref);
private:
	int m_nCurveType;			//曲线类型: 曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）
	int m_nXAxisType;			//X轴参数类型数字标记
	int m_nYAxisType;			//Y轴参数类型数字标记
	double m_dMaxX;				//曲线自变量的坐标最大值
    int    m_nOrder;			//曲线拟合阶数
	double m_dPrame[5];		//公式中的参数和常量a，b，c，d，e的值
};

#endif // !defined(AFX_CALCCURVE_H__2FBC8CD9_0E97_495C_8BC7_34EF993ECC24__INCLUDED_)
