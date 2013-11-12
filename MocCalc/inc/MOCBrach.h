// MOCBrach.h: interface for the MOCBrach class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCBRACH_H__F3CB8B26_4692_434C_9F0B_7B0D9785454A__INCLUDED_)
#define AFX_MOCBRACH_H__F3CB8B26_4692_434C_9F0B_7B0D9785454A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCBrach : public MOCJun  
{
public:
	void UpdataEnd();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCBrach();
	virtual ~MOCBrach();

private:
	void CalcStm();
	void CalcStm(double dFlow);
	BOOL InitEndInfo();
	BOOL InitTranData(MOCComponentMgr &mgr);

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	ListImp<StrArray<4> >     m_PipeInfo;
	double		              m_dImposeFlow;				    //Á÷Á¿Öµ

	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCBRACH_H__F3CB8B26_4692_434C_9F0B_7B0D9785454A__INCLUDED_)
