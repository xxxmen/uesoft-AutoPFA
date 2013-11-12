// MOCPipeMgr.h: interface for the MOCPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPIPEMGR_H__68180276_C2DB_41F5_8EAC_500930681708__INCLUDED_)
#define AFX_MOCPIPEMGR_H__68180276_C2DB_41F5_8EAC_500930681708__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCPipe.h"
#include "Iterator.h"
class CalcPipeMgr;
class PipeStmOutMgr;
class PipeTranOutMgr;

typedef CMap<int,int,MOCPipe*,MOCPipe*> PipeMap;
class MOCPipeMgr  
{
public:
	void InitPipeEnd();
	EndInfo* LookPipeEnd(int nKey);
	void Empty();
	BOOL Read(CalcPipeMgr &data);
	MOCPipe* LookUp(int nKey);
	MOCPipe* CreatPipe(int nKey);
	Iterator<MOCPipe>* CreatIterator();
	MOCPipeMgr();
	virtual ~MOCPipeMgr();

public:
	void CalcStm();
	void Result(PipeStmOutMgr &out);
	void CalcImpulse(MOCTrans &trans);
	void Result(PipeTranOutMgr &out,int nStep);
	BOOL InitStation();
	void CheckTol(MOCSteady &Steady);
private:
	MOCPipeMgr(const MOCPipeMgr &ref);
	MOCPipeMgr& operator=(const MOCPipeMgr &ref);
	PipeMap m_pipeMap;
};

#endif // !defined(AFX_MOCPIPEMGR_H__68180276_C2DB_41F5_8EAC_500930681708__INCLUDED_)
