// MOCTriger.h: interface for the MOCTriger class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGER_H__38AB7FC2_56FC_4363_A88D_4CBC58102C1D__INCLUDED_)
#define AFX_MOCTRIGER_H__38AB7FC2_56FC_4363_A88D_4CBC58102C1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTable.h"
#include "CalcTable.h"
#include "MOCTrigerStrategyMgr.h"

class CalcTriger;

class MOCTriger  
{
public:
	BOOL TrigerStatus(double dTime,double dStart);
	double GetTransY(double dX);
	void Triger(BOOL bTriger);
	BOOL IsTriger();
	double GetTransY(double dX,double dStmY);
	void Init(MOCComponentMgr &mgr);
	void InitFixTrans(MOCComponentMgr &mgr,int nKey,int nEventType,int nConditionType);
	double GetTransY(double dX,double dStmY,double dStart);
	void Tran(PFUNTRAN2 pTran,double d);
	void Tran(PFUNTRAN pTran);
	void Read(CalcTriger &triger,TransTable &table);
	void Repeat(BOOL bValue);
	MOCTriger();
	virtual ~MOCTriger();

private:
	BOOL HasData();

private:
	int m_nEventType;                //事件类型
	int m_nConditionType;			 //条件类型
	double	m_dValue;				 //值
	int m_nPort1;					 //管道入口触发事件为1；管道出口触发事件为2
	int m_nComponentID1;			 //触发事件的组件编号
	int m_nPort2;					 //管道入口触发事件为1；管道出口触发事件为2
	int m_nComponentID2;			 //触发事件的组件编号	

	BOOL m_bRepeat;					//0：瞬变重复没选中，1选中：
	DataTable m_table;
	MOCTrigerStrategyMgr m_mgr;
	BOOL m_bTriger;
};

#endif // !defined(AFX_MOCTRIGER_H__38AB7FC2_56FC_4363_A88D_4CBC58102C1D__INCLUDED_)
