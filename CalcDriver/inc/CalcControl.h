// CalcControl.h: interface for the CalcControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCONTROL_H__9A7646C0_FF43_4423_A8A1_267A525A37F7__INCLUDED_)
#define AFX_CALCCONTROL_H__9A7646C0_FF43_4423_A8A1_267A525A37F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcControl : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcControl();
	virtual ~CalcControl();

public:
	void Type(int nValue);
	void AlwayControl(int nValue);
	void UpInsuffic(int nValue);
	void DownExcess(int nValue);
	void ControlType(int nValue);
	void PressType(int nValue);
	void ControlValue(double dValue);
	void LossType(int nValue);
	void KOrCv(double dValue);
	void CvTable(const ListImp<StrArray<3> >& ref);
	void BasisAreaType(int nValue);
	void BasisArea(double dValue);

	int Type();
	int AlwayControl();
	int UpInsuffic();
	int DownExcess();
	int ControlType();
	int PressType();
	double ControlValue();
	int LossType();
	double KOrCv();
	ListImp<StrArray<3> >& CvTable();
	int BasisAreaType();
	double BasisArea();

private:
	int m_nType;								//阀门类型0：PRF 1：PSV 2：FCV 3：PDCV
	int m_nAlwayControl;						//稳定状态总是控制0：没有选择 1：选择
	int m_nUpInsuffic;							//上游压力不足表现0：全部打开 1：关闭
	int m_nDownExcess;							//下游压力超过表现0：全部打开 1：关闭
    int m_nControlType;					        //控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
	int m_nPressType;							//0：停滞压力1：静态压力
	double m_dControlValue;						//控制点参数值
	int	   m_nLossType;						    //损失模型(0：流量系数模型，1：K系数模型 -2：使用系数表的值)
	double m_dKOrCv;							//K或Cv系数值
	CalcTable<3> m_CvTable;

	int     m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double  m_dBasisArea;						//面积哦or直径

public:
	CalcTransData m_TranData;	
	CalcTransData m_FailTranData;
};

#endif // !defined(AFX_CALCCONTROL_H__9A7646C0_FF43_4423_A8A1_267A525A37F7__INCLUDED_)
