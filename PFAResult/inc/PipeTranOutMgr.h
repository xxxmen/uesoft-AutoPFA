// PipeTranOutMgr.h: interface for the PipeTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPETRANOUTMGR_H__E2BE207E_7B11_4BAD_BC46_A3DEA531A67F__INCLUDED_)
#define AFX_PIPETRANOUTMGR_H__E2BE207E_7B11_4BAD_BC46_A3DEA531A67F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TranOutMgr.h"

class AFX_EXT_CLASS PipeTranOutMgr:public TranOutMgr  
{
public:
	OutAttrArray& GetStationArray();
	OutAttrArray& GetMaxMinArray();
	void InitMaxMin();
	virtual void EmptyOut();
	void InitAttrArray();
	ComponentTranOut* Creator();
	PipeTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~PipeTranOutMgr();

private:
	ComponentStmOut* LookUpMaxMin(int nKey,int nSubKey);
	PipeTranOutMgr(const PipeTranOutMgr &ref);
	PipeTranOutMgr& operator=(const PipeTranOutMgr &ref);
	OutAttrArray m_StationAttrArray; //支持多文档的话就不用用静态成员。
	OutAttrArray m_MaxMinArray;
};

#endif // !defined(AFX_PIPETRANOUTMGR_H__E2BE207E_7B11_4BAD_BC46_A3DEA531A67F__INCLUDED_)
