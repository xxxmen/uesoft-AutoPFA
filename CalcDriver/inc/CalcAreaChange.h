// CalcAreaChange.h: interface for the CalcAreaChange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCAREACHANGE_H__B9677E7A_B3CB_476A_8B0D_E4F9C8703770__INCLUDED_)
#define AFX_CALCAREACHANGE_H__B9677E7A_B3CB_476A_8B0D_E4F9C8703770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcAreaChange : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcAreaChange();
	virtual ~CalcAreaChange();

public:
	void Type(int nValue);
	void Angle(double dValue);
	void K(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);

	double K();
	int BasisAreaType();
	double BasisArea();

private:
	int     m_Type;								//异径管类型（0：圆锥，1：圆柱，2：用户定义）
	double  m_Angle;							//角度
	double  m_K;								//K系数值
	int     m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double  m_dBasisArea;						//面积哦or直径
};



#endif // !defined(AFX_CALCAREACHANGE_H__B9677E7A_B3CB_476A_8B0D_E4F9C8703770__INCLUDED_)
