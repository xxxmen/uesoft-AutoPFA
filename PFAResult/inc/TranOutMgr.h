// TranOutMgr.h: interface for the TranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANOUTMGR_H__C517B75C_C107_4992_BE37_02E1B45D94C8__INCLUDED_)
#define AFX_TRANOUTMGR_H__C517B75C_C107_4992_BE37_02E1B45D94C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "OutMgr.h"

class ComponentTranOut;
class OutputRefPersist;
class UnitSubSystem;

class AFX_EXT_CLASS TranOutMgr:public OutMgr    
{
public:
	virtual ComponentStmOut* LookUpMaxMin(int nKey,int nSubKey)=0;
	void TimeStep(double dTime);
	ComponentStmOut* CreatorComponent(int nKey);
	TranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~TranOutMgr();

protected:
	virtual ComponentTranOut* Creator()=0;
	virtual void InitAttrArray()=0;
	double m_TimeStep;
};

#endif // !defined(AFX_TRANOUTMGR_H__C517B75C_C107_4992_BE37_02E1B45D94C8__INCLUDED_)
