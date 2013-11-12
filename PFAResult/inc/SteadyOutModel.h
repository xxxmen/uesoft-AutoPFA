// SteadyOutModel.h: interface for the SteadyOutModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEADYOUTMODEL_H__B8A73B10_9CC1_4788_B095_1A3C9982140C__INCLUDED_)
#define AFX_STEADYOUTMODEL_H__B8A73B10_9CC1_4788_B095_1A3C9982140C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentStmOutMgr.h"
class UnitSubSystem;
 class OutputRefPersist;

class AFX_EXT_CLASS SteadyOutModel  
{
public:
	void CurTime(LPSYSTEMTIME lpSystemTime);
	CString CurTime();
	void OK(BOOL bOK);
	BOOL OK();
	void Iterations(int nIt);
	int Iterations();
	void EmptyOut();
	ComponentStmOutMgr& ComponentOutMgr();
	SteadyOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~SteadyOutModel();
	//OutputRefPersist& OutPutData();
private:
	ComponentStmOutMgr m_ComponentOutMgr;
	UnitSubSystem &m_unitsys;
	int m_iterations;
	BOOL m_bOK;
	CString m_strCurTime;
	OutputRefPersist &m_OutPutData;
};

#endif // !defined(AFX_STEADYOUTMODEL_H__B8A73B10_9CC1_4788_B095_1A3C9982140C__INCLUDED_)
