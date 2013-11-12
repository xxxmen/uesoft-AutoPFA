// ComponentStmOutMgr.h: interface for the ComponentStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTSTMOUTMGR_H__C8D99071_4800_4978_BC78_9D29598C9789__INCLUDED_)
#define AFX_COMPONENTSTMOUTMGR_H__C8D99071_4800_4978_BC78_9D29598C9789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JunStmOutMgr.h"
#include "PipeStmOutMgr.h"
class UnitSubSystem;
class OutputRefPersist;
class AFX_EXT_CLASS ComponentStmOutMgr  
{
public:
	void EmptyOut();
	PipeStmOutMgr& PipeOutMgr();
	JunStmOutMgr& JunOutMgr();
	ComponentStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~ComponentStmOutMgr();
	OutputRefPersist& OutPutData();
private:
	JunStmOutMgr m_junOutMgr;
	PipeStmOutMgr m_pipeOutMgr;
	OutputRefPersist &m_OutPutData;
};

#endif // !defined(AFX_COMPONENTSTMOUTMGR_H__C8D99071_4800_4978_BC78_9D29598C9789__INCLUDED_)
