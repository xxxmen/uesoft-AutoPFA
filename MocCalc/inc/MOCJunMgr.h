// MOCJunMgr.h: interface for the MOCJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCJUNMGR_H__2FD55A84_9313_4362_8F69_5964C52C0AB0__INCLUDED_)
#define AFX_MOCJUNMGR_H__2FD55A84_9313_4362_8F69_5964C52C0AB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCJun.h"
#include "MOCJunFactory.h"

class CalcJunMgr;
class MOCPipeMgr;
class JunStmOutMgr;
class JunTranOutMgr;
class MOCComponentMgr;

typedef CMap<int,int,MOCJun*,MOCJun*> JunMap;
class MOCJunMgr  
{
public:
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitTranData(MOCComponentMgr& mgr);
	void Result(JunStmOutMgr &out);
	void Result(JunTranOutMgr &out,int nStep);
	void CalcStm();
	BOOL InitLinkInfo(MOCPipeMgr &mgr);
	void Empty();
	MOCJun* LookUp(int nKey);
	MOCJun* CreatJun(int nType,int nKey);
	Iterator<MOCJun>* CreatIterator();
	BOOL Read(CalcJunMgr &data);
	MOCJunMgr();
	virtual ~MOCJunMgr();

private:
	MOCJunMgr(const MOCJunMgr &ref);
	MOCJunMgr& operator=(const MOCJunMgr &ref);
	JunMap m_junMap;
	MOCJunFactory *m_pFactory;
};

#endif // !defined(AFX_MOCJUNMGR_H__2FD55A84_9313_4362_8F69_5964C52C0AB0__INCLUDED_)
