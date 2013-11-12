// MOCDeadEnd.h: interface for the MOCDeadEnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCDEADEND_H__79217959_4BB9_4387_ABCA_23C1565E00F0__INCLUDED_)
#define AFX_MOCDEADEND_H__79217959_4BB9_4387_ABCA_23C1565E00F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"

class MOCDeadEnd : public MOCJun  
{
public:	
	void UpdataEnd();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCDeadEnd();
	virtual ~MOCDeadEnd();

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitEndInfo();
	void CalcStm();
};

#endif // !defined(AFX_MOCDEADEND_H__79217959_4BB9_4387_ABCA_23C1565E00F0__INCLUDED_)
