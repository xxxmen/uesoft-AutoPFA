// CalcRelief.h: interface for the CalcRelief class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCRELIEF_H__DA86DA77_9AAF_4E88_82AB_04AEF14451F8__INCLUDED_)
#define AFX_CALCRELIEF_H__DA86DA77_9AAF_4E88_82AB_04AEF14451F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcCurve.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcRelief : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcRelief();
	virtual ~CalcRelief();
public:
	void Type(int nValue);
	void LossType(int nValue);
	void PressType(int nValue);
	void CrackPress(double dValue);
	void ExitPress(double dValue);
	void KOrCv(double dValue);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);

	int Type();
	int LossType();
	int PressType();
	double CrackPress();
	double ExitPress();
	double KOrCv();
	int BasisAreaType();
	double BasisArea();
private:
	int		 m_nType;							//类型(1:内部安全阀（internal relief）2:出口安全阀（exit relief）3:内嵌安全阀（inline relief）)
	int      m_nLossType;						//损失模型(0：流量系数模型，1：K系数模型3：变流量系数)
	double   m_dKOrCv;						    //K或Cv系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
	int      m_nPressType;					    //0. 绝对水头, 2. 水头差,  1、绝对压力, 3、压力差.
	double	 m_dCrackPress;				        //破裂的压力
	double   m_dExitPress;					    //出口压力
public:
	CalcCurve m_Curve;
	CalcTransData m_TranData;

};

#endif // !defined(AFX_CALCRELIEF_H__DA86DA77_9AAF_4E88_82AB_04AEF14451F8__INCLUDED_)
