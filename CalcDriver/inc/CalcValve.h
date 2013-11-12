// CalcValve.h: interface for the CalcValve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCVALVE_H__521AA035_FC83_4E18_B345_2A4802DE3CF0__INCLUDED_)
#define AFX_CALCVALVE_H__521AA035_FC83_4E18_B345_2A4802DE3CF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcValve : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcValve();
	virtual ~CalcValve();
public:
	void LossType(int nValue);
	void KOrCv(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);
	void Type(int nValue);
	void ExitPressType(int nValue);
	void ExitPress(double dValue);

	int LossType();
	double KOrCv();
	int BasisAreaType();
	double BasisArea();
	int Type();
	int ExitPressType();
	double ExitPress();
private:
	int      m_nLossType;                       //损失模型0：流量系数模型，1：K系数模型
	double   m_dKOrCv;						    //K或Cv系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
	int		 m_nType;						    //类型(0：普通阀门，1：选中阀门为出口阀门)
	int      m_nExitPressType;					//出口压力类型0：水头1：压力
	double   m_dExitPress;					    //出口压力

public:
	CalcTransData m_TranData;

};

#endif // !defined(AFX_CALCVALVE_H__521AA035_FC83_4E18_B345_2A4802DE3CF0__INCLUDED_)
