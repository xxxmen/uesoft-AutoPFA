// PipeStmOutMgr.h: interface for the PipeStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPESTMOUTMGR_H__79944B7B_4F7F_4CFA_9078_7BF9F300FE27__INCLUDED_)
#define AFX_PIPESTMOUTMGR_H__79944B7B_4F7F_4CFA_9078_7BF9F300FE27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipeStmOut.h"
#include "StmOutMgr.h"
#include "OutPutSystem.h"

class OutputRefPersist;
class AFX_EXT_CLASS PipeStmOutMgr : public StmOutMgr
{
public:
	PipeStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~PipeStmOutMgr();

private:
	ComponentStmOut* Creator();
	void InitAttrArray();
		void InitAttrPipe();


	PipeStmOutMgr(const PipeStmOutMgr &ref);
	PipeStmOutMgr& operator=(const PipeStmOutMgr &ref);
	CString strTemp;

};

#endif // !defined(AFX_PIPESTMOUTMGR_H__79944B7B_4F7F_4CFA_9078_7BF9F300FE27__INCLUDED_)
