// MOCAssignFlow.h: interface for the MOCAssignFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCASSIGNFLOW_H__1EE43EE1_C3FE_42CC_807D_884B5A890EC6__INCLUDED_)
#define AFX_MOCASSIGNFLOW_H__1EE43EE1_C3FE_42CC_807D_884B5A890EC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCAssignFlow : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCAssignFlow();
	virtual ~MOCAssignFlow();

private:
	BOOL InitEndInfo();
	
private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitTranData(MOCComponentMgr &mgr);
	void UpdataEnd();
	void CalcStm();
	void CalcStm(double dFlow,double dPress);
	double   m_dK;						//损失系数K值
	double   m_dFlow;				    //大小
	double   m_dInitPress;				//初始化压力
	int      m_bSelInitPress;           //恒定流量为0的初始化压力（0，没有选，1选中）

	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCASSIGNFLOW_H__1EE43EE1_C3FE_42CC_807D_884B5A890EC6__INCLUDED_)
