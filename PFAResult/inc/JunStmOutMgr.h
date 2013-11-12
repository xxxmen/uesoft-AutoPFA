// JunStmOutMgr.h: interface for the JunStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNSTMOUTMGR_H__B094D4D2_7CAD_4242_BB13_226513E0B14E__INCLUDED_)
#define AFX_JUNSTMOUTMGR_H__B094D4D2_7CAD_4242_BB13_226513E0B14E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JunStmOut.h"
#include "StmOutMgr.h"

class OutputRefPersist;
class AFX_EXT_CLASS JunStmOutMgr : public StmOutMgr  
{
public:
	
	JunStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~JunStmOutMgr();

private:
	void InitAttrArray();
	void InitAttrJun();
	ComponentStmOut* Creator();
	JunStmOutMgr(const JunStmOutMgr &ref);
	JunStmOutMgr& operator=(const JunStmOutMgr &ref);
};

#endif // !defined(AFX_JUNSTMOUTMGR_H__B094D4D2_7CAD_4242_BB13_226513E0B14E__INCLUDED_)
