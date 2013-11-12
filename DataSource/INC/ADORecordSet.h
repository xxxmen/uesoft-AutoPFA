// ADORecordSet.h: interface for the ADORecordSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__B275E72E_6637_4961_9C66_4FEEE867319D__INCLUDED_)
#define AFX_ADORECORDSET_H__B275E72E_6637_4961_9C66_4FEEE867319D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ado.h"
#include <COMUTIL.H>

class AFX_EXT_CLASS ADORecordSet  
{
public:
	ADORecordSet(_RecordsetPtr m_pRecordset);
	ADORecordSet();
	virtual ~ADORecordSet();

public:
	void Delete();
	
	BOOL GetBool(const CString& strIndex) const;
	CString GetString(const CString& strIndex) const;
	FLOAT GetFloat(const CString& strIndex) const;
	DOUBLE GetDouble(const CString& strIndex) const;
	LONG GetLong(const CString& strIndex) const;
	short GetShort(const CString& strIndex) const;
	_variant_t Get_variant_t(const CString& strIndex) const;
	
	void NewRecord();
	
	void SetBool(const CString& strIndex, bool bValue);
	void SetString(const CString& strIndex, const CString& strValue);
	void SetFloat(const CString& strIndex, FLOAT fValue);
	void SetDouble(const CString& strIndex, DOUBLE dbValue);
	void SetLong(const CString& strIndex, LONG nValue);
	void SetShort(const CString& strIndex, SHORT nValue);
	void Set_variant_t(const CString& strIndex,_variant_t vr);
	
	void BatchUpdate();
	BOOL Update();
	
	void MovePrevious();
	void MoveLast();
	void MoveNext();
	void MoveFirst();
	
	BOOL IsEOF() const;
	BOOL IsBOF() const;
	BOOL IsEmpty() const;
	void Close();
	
	INT GetRecordCount() const;


private:
	_RecordsetPtr m_pRecordset;//包装了_Recordset的智能指针

};

#endif // !defined(AFX_ADORECORDSET_H__B275E72E_6637_4961_9C66_4FEEE867319D__INCLUDED_)
