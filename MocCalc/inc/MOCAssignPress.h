// MOCAssignPress.h: interface for the MOCAssignPress class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCASSIGNPRESS_H__8C3412A8_2DFD_4FA8_ADB1_95712A69841E__INCLUDED_)
#define AFX_MOCASSIGNPRESS_H__8C3412A8_2DFD_4FA8_ADB1_95712A69841E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCAssignPress : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCAssignPress();
	virtual ~MOCAssignPress();

private:
	void CalcStm();
	void CalcStm(double dPress);
	BOOL InitEndInfo();
	BOOL InitTranData(MOCComponentMgr &mgr);

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	ListImp<StrArray<4> >    m_PipeInfo;
	int						 m_nPressType;			//压力类型0：停滞压力1：静止压力
	double					 m_dPress;				//压力

	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCASSIGNPRESS_H__8C3412A8_2DFD_4FA8_ADB1_95712A69841E__INCLUDED_)
