// StmOutMgr.h: interface for the StmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STMOUTMGR_H__B3A83EE7_3125_4DA5_B37C_8285027B5CC4__INCLUDED_)
#define AFX_STMOUTMGR_H__B3A83EE7_3125_4DA5_B37C_8285027B5CC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "ComponentStmOut.h"
#include "OutMgr.h"

class OutputRefPersist;
class AFX_EXT_CLASS StmOutMgr:public OutMgr  
{
public:
	ComponentStmOut* CreatorComponent(int nKey);
	StmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~StmOutMgr();

protected:
	virtual ComponentStmOut* Creator()=0;
	virtual void InitAttrArray()=0;
};

#endif // !defined(AFX_STMOUTMGR_H__B3A83EE7_3125_4DA5_B37C_8285027B5CC4__INCLUDED_)
