// CalcBend.h: interface for the CalcBend class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBEND_H__05A8DCD6_E9CD_4F13_A084_E2DE4E02F783__INCLUDED_)
#define AFX_CALCBEND_H__05A8DCD6_E9CD_4F13_A084_E2DE4E02F783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcBend : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcBend();
	virtual ~CalcBend();
    void K(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);

	double K();
	int BasisAreaType();
	double BasisArea();
private:
	double  m_K;								//K系数值
	int     m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double  m_dBasisArea;						//面积哦or直径

};

#endif // !defined(AFX_CALCBEND_H__05A8DCD6_E9CD_4F13_A084_E2DE4E02F783__INCLUDED_)
