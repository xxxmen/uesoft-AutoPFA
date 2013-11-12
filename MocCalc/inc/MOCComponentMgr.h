// MOCComponentMgr.h: interface for the MOCComponentMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCOMPONENTMGR_H__89D129B9_8FAE_4D9E_9C22_151FFCDFB829__INCLUDED_)
#define AFX_MOCCOMPONENTMGR_H__89D129B9_8FAE_4D9E_9C22_151FFCDFB829__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCJunMgr.h"
#include "MOCPipeMgr.h"
#include "MOCCalcMgr.h"

class CalcDriverMgr;
class ComponentStmOutMgr;
class ComponentTranOutMgr;

class MOCComponentMgr  
{
public:
	MOCPipe* LookUpPipe(int nKey);
	MOCJun* LookUpJun(int nKey);
	BOOL InitTransModel();
	void Result(ComponentStmOutMgr &out);
	void Result(ComponentTranOutMgr &out,int nStep);
	void CalcImpulse(MOCTrans &trans,double dTime);
	void CalcStm(MOCSteady &Steady);
	BOOL Read(CalcDriverMgr &data);
	BOOL InitComponentNet();
	MOCComponentMgr();
	virtual ~MOCComponentMgr();
private:
	MOCJunMgr m_JunMgr;
	MOCPipeMgr m_PipeMgr;
};

#endif // !defined(AFX_MOCCOMPONENTMGR_H__89D129B9_8FAE_4D9E_9C22_151FFCDFB829__INCLUDED_)
