// JunTranOutMgr.h: interface for the JunTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNTRANOUTMGR_H__E0F36FB8_05AC_4513_94C8_A70372A8EF70__INCLUDED_)
#define AFX_JUNTRANOUTMGR_H__E0F36FB8_05AC_4513_94C8_A70372A8EF70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TranOutMgr.h"
class OutputRefPersist;
class AFX_EXT_CLASS JunTranOutMgr:public TranOutMgr
{
public:
	void InitAttrArray();
	void EmptyOut();
	ComponentTranOut* Creator();
	JunTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~JunTranOutMgr();

private:
	ComponentStmOut* LookUpMaxMin(int nKey,int nSubKey);
	JunTranOutMgr(const JunTranOutMgr &ref);
	JunTranOutMgr& operator=(const JunTranOutMgr &ref);
};

#endif // !defined(AFX_JUNTRANOUTMGR_H__E0F36FB8_05AC_4513_94C8_A70372A8EF70__INCLUDED_)
