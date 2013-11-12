// TransOutModel.h: interface for the TransOutModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSOUTMODEL_H__A8B0B19F_3AA3_43AE_810B_468F70D61477__INCLUDED_)
#define AFX_TRANSOUTMODEL_H__A8B0B19F_3AA3_43AE_810B_468F70D61477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentTranOutMgr.h"
class UnitSubSystem;
class OutputRefPersist;
class AFX_EXT_CLASS TransOutModel  
{
public:
	BOOL HasData();
	ComponentTranOutMgr& ComponentOutMgr();
	void EmptyOut();
	TransOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~TransOutModel();
//	OutputRefPersist& GetOutPutData();
private:
	ComponentTranOutMgr m_Mgr;
	UnitSubSystem &m_unitsys;
	OutputRefPersist &m_OutPutData;
};

#endif // !defined(AFX_TRANSOUTMODEL_H__A8B0B19F_3AA3_43AE_810B_468F70D61477__INCLUDED_)
