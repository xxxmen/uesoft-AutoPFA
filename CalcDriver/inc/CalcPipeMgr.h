// CalcPipeMgr.h: interface for the CalcPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPIPEMGR_H__21E5CD98_4796_4A0A_9685_37B48F87B9DE__INCLUDED_)
#define AFX_CALCPIPEMGR_H__21E5CD98_4796_4A0A_9685_37B48F87B9DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcPipe.h"
#include "Iterator.h"

class AFX_EXT_CLASS CalcPipeMgr  
{
public:
	CalcPipeMgr();
	virtual ~CalcPipeMgr();
public:
	CalcPipe* CreatPipe();
	Iterator<CalcPipe>* CreateIt();
	friend ostream& operator<< (ostream &CalcOut,const CalcPipeMgr &ref);
private:
	typedef CList<CalcPipe*,CalcPipe*>PipeList;
	void DelList();
	CalcPipeMgr(const CalcPipeMgr &ref);
	CalcPipeMgr& operator=(const CalcPipeMgr &ref);
	PipeList m_pipeList;
};

#endif // !defined(AFX_CALCPIPEMGR_H__21E5CD98_4796_4A0A_9685_37B48F87B9DE__INCLUDED_)
