// MOCGeneral.h: interface for the MOCGeneral class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCGENERAL_H__EA2A860F_5B82_48CC_A07E_950D9FE3F54E__INCLUDED_)
#define AFX_MOCGENERAL_H__EA2A860F_5B82_48CC_A07E_950D9FE3F54E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCPolynomial.h"

class MOCGeneral : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCGeneral();
	virtual ~MOCGeneral();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void ImpulseRCurve();
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	void StmRCurve();
	double CalcRCurve(double dPress);
	double CalcMass(double dPress);
	double GetCurPress(double dX);
	double GetCurK();
	int      m_nLossType;                       //1：K系数恒定，2：K系数变化，3：阻力曲线
	double   m_dK;								//K系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
	MOCPolynomial m_Polynomial;
	double m_dCurMass;
};

#endif // !defined(AFX_MOCGENERAL_H__EA2A860F_5B82_48CC_A07E_950D9FE3F54E__INCLUDED_)
