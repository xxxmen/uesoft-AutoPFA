// MOCTrigerStrategyMgr.h: interface for the MOCTrigerStrategyMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSTRATEGYMGR_H__CC81F4AD_8FB1_49D2_839E_27C0436FA5EE__INCLUDED_)
#define AFX_MOCTRIGERSTRATEGYMGR_H__CC81F4AD_8FB1_49D2_839E_27C0436FA5EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTrigerStrategyFactory.h"
class MOCComponentMgr;
class MOCPipe;
class MOCJun;

class MOCTrigerStrategyMgr  
{
public:
	MOCTrigerStrategyMgr();
	virtual ~MOCTrigerStrategyMgr();
public:
	BOOL IsTriger(double dCurTime,double dStartTime);
	void EventType(int nValue);
	void ConditionType(int nValue);
	void Value(double dValue);
	void Port1(int nValue);
	void ComponentID1(int nValue);
	void Port2(int nValue);
	void ComponentID2(int nValue);
	void ModelMgr(MOCComponentMgr *pMgr);
	void TrigerTime(double dValue);
	void HasTranData(BOOL bHasData);

	MOCPipe* LookUpPipe(int nKey);
	MOCJun* LookUpJun(int nKey);
	int ConditionType();
	double Value();
	int Port1();
	int ComponentID1();
	int Port2();
	int ComponentID2();
	double TrigerTime();
	BOOL HasTranData();
private:
	MOCComponentMgr *m_pMgr;
	MOCTrigerStrategyFactory *m_factory;

	int m_nEventType;                //事件类型
	int m_nConditionType;			 //条件类型
	double	m_dValue;				 //值
	int m_nPort1;					 //管道入口触发事件为1；管道出口触发事件为2
	int m_nComponentID1;			 //触发事件的组件编号
	int m_nPort2;					 //管道入口触发事件为1；管道出口触发事件为2
	int m_nComponentID2;			 //触发事件的组件编号	
	double m_dTrigerTime;
	BOOL m_bHasTranData;
};

#endif // !defined(AFX_MOCTRIGERSTRATEGYMGR_H__CC81F4AD_8FB1_49D2_839E_27C0436FA5EE__INCLUDED_)
