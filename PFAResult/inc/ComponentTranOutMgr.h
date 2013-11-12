// ComponentTranOutMgr.h: interface for the ComponentTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTTRANOUTMGR_H__597AE7D7_E6E1_4688_8BB4_6899006CC35A__INCLUDED_)
#define AFX_COMPONENTTRANOUTMGR_H__597AE7D7_E6E1_4688_8BB4_6899006CC35A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipeTranOutMgr.h"
#include "JunTranOutMgr.h"

class UnitSubSystem;
class OutputRefPersist;
class AFX_EXT_CLASS ComponentTranOutMgr  
{
public:
	BOOL IsEmpty();
	void TimeStep(double dTime);
	void EmptyOut();
	PipeTranOutMgr& PipeOutMgr();
	JunTranOutMgr& JunOutMgr();
	ComponentTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~ComponentTranOutMgr();

private:
	JunTranOutMgr m_junOutMgr;
	PipeTranOutMgr m_pipeOutMgr;
};

#endif // !defined(AFX_COMPONENTTRANOUTMGR_H__597AE7D7_E6E1_4688_8BB4_6899006CC35A__INCLUDED_)
