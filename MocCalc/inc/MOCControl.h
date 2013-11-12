// MOCControl.h: interface for the MOCControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCONTROL_H__065120DB_784A_45A2_99FA_8F4F7CF48C89__INCLUDED_)
#define AFX_MOCCONTROL_H__065120DB_784A_45A2_99FA_8F4F7CF48C89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCControl : public MOCJun  
{
public:
	int ValveStatus();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCControl();
	virtual ~MOCControl();

private:
	BOOL InitEndInfo();
	void CalcStm();
	BOOL InitTranData(MOCComponentMgr &mgr);
	virtual void CalculateK();

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	void FixStatus(double dControlValue);
	void Action(int nType,double dKOrCv);
	void SwitchStatus(double dKOrCv,double dControlValue);
	void FullOpenValve(double dKOrCv);
	void CloseValve();
	void PressControl(EndInfo *pControlEnd,EndInfo *pEnd,double dControlValue);
	void FlowControl(EndInfo *pControlEnd,double dFlow);
	void CalcPDCV(double dControlValue);
	void CalcFCV(double dControlValue);
	void CalcPSV(double dControlValue);
	void CalcPRV(double dControlValue);
	double GetCvFromCvTable();
	int m_nType;								//阀门类型0：PRV 1：PSV 2：FCV 3：PDCV
	int m_nAlwayControl;						//稳定状态总是控制0：没有选择 1：选择
	int m_nUpInsuffic;							//上游压力不足表现0：全部打开 1：关闭
	int m_nDownExcess;							//下游压力超过表现0：全部打开 1：关闭
                        				        //控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
	int m_nPressType;							//0：停滞压力1：静态压力
	double m_dControlValue;						//控制点参数值
	int	   m_nLossType;						    //损失模型(0：流量系数模型，1：K系数模型 -2：使用系数表的值)
	double m_dKOrCv;							//K或Cv系数值
	ListImp<StrArray<3> > m_CvTable;
	int     m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double  m_dBasisArea;						//面积哦or直径

	int m_nValveStatus;

	MOCTranData m_tranData;
	MOCTranData m_fialTranData;
};

#endif // !defined(AFX_MOCCONTROL_H__065120DB_784A_45A2_99FA_8F4F7CF48C89__INCLUDED_)
