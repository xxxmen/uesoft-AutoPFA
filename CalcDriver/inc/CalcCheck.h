// CalcCheck.h: interface for the CalcCheck class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCHECK_H__82A5102B_D397_4F9D_86E9_BA884AD2ABDA__INCLUDED_)
#define AFX_CALCCHECK_H__82A5102B_D397_4F9D_86E9_BA884AD2ABDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcCheck : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcCheck();
	virtual ~CalcCheck();
public:
	void LossType(int nValue);
	void KOrCv(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);
	void ReOpenPressType(int nValue);
	void ReOpenPress(double dValue);
	void CloseVel(double dValue);
	
	int LossType();
	double KOrCv();
	int BasisAreaType();
	double BasisArea();
	int ReOpenPressType();
	double ReOpenPress();
	double CloseVel();
private:
	int    m_nLossType;						    //损失模型0：流量系数模型，1：K系数模型			                                           
	double m_dKOrCv;					        //K或Cv系数值
    int    m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double m_dBasisArea;						//面积哦or直径
	int    m_nReOpenPressType;					//重新打开阀门Delta(压力或水头)0：水头1：压力
	double m_dReOpenPress;					    //压力值	
	double m_dCloseVel;					        //关闭阀门的最小正向速度\速度单位

public:
	CalcTransData m_TranData;
};

#endif // !defined(AFX_CALCCHECK_H__82A5102B_D397_4F9D_86E9_BA884AD2ABDA__INCLUDED_)
