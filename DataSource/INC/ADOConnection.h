// ADOConnection.h: interface for the ADOConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONNECTION_H__CCD19567_19DB_43E9_9DDD_C8C8E2341815__INCLUDED_)
#define AFX_ADOCONNECTION_H__CCD19567_19DB_43E9_9DDD_C8C8E2341815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADORecordSet.h"
#include <COMUTIL.H>

typedef ADORecordSet* ADORecordSetPtr;

class AFX_EXT_CLASS ADOConnection  
{
public:
	void Close();
	BOOL IsOpen();
	BOOL ExecuteNoSelectSQL(const CString &strSQL);
    ADORecordSetPtr ExecuteSelectSQL(const CString &strSQL);
	_RecordsetPtr ExecuteSelectSQL(const CString &strSQL,short nMode);
	void Open(const CString& strCource);
	LONG BeginTrans();
	BOOL GetConnectionptr( _ConnectionPtr& pConnect );
	ADOConnection();
	virtual ~ADOConnection();
private:
	_ConnectionPtr *m_pConn;
 	_ConnectionPtr &m_pConnection;

	CString m_StrCurDBType;
};


#endif // !defined(AFX_ADOCONNECTION_H__CCD19567_19DB_43E9_9DDD_C8C8E2341815__INCLUDED_)
