// CalcGeneral.h: interface for the CalcGeneral class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCGENERAL_H__2E6ECEDD_0220_48C6_A9D7_DD8B9B09D63B__INCLUDED_)
#define AFX_CALCGENERAL_H__2E6ECEDD_0220_48C6_A9D7_DD8B9B09D63B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcCurve.h"

class AFX_EXT_CLASS CalcGeneral : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcGeneral();
	virtual ~CalcGeneral();

public:
	void LossType(int nValue);
	void K(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);
	
	int LossType();
	double K();
	int BasisAreaType();
	double BasisArea();
private:
	int      m_nLossType;                       //1：K系数恒定，2：K系数变化，3：阻力曲线
	double   m_dK;								//K系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
public:
	CalcCurve m_Curve;
};

#endif // !defined(AFX_CALCGENERAL_H__2E6ECEDD_0220_48C6_A9D7_DD8B9B09D63B__INCLUDED_)
