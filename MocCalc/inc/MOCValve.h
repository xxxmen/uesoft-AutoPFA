// MOCValve.h: interface for the MOCValve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCVALVE_H__17AC9243_0B66_45A9_998F_9D13EF8CF849__INCLUDED_)
#define AFX_MOCVALVE_H__17AC9243_0B66_45A9_998F_9D13EF8CF849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCValve : public MOCJun  
{
public:
	void UpdataEnd();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCValve();
	virtual ~MOCValve();

private:
	void CalcStm();
	void CalcStmK(double dK);
	void CalcStmCv(double dCv);
	BOOL InitEndInfo();

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitTranData(MOCComponentMgr &mgr);
	int      m_nLossType;                       //损失模型0：流量系数模型，1：K系数模型
	double   m_dKOrCv;						    //K或Cv系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
	int		 m_nType;						    //类型(0：普通阀门，1：选中阀门为出口阀门)
	double   m_dExitPress;					    //出口压力

	double   m_dOutFlow;                       //出口阀门流出的流量

	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCVALVE_H__17AC9243_0B66_45A9_998F_9D13EF8CF849__INCLUDED_)
