// ADOException.h: interface for the ADOException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOEXCEPTION_H__BDC8C791_8518_4E7D_919F_28D04D3B8485__INCLUDED_)
#define AFX_ADOEXCEPTION_H__BDC8C791_8518_4E7D_919F_28D04D3B8485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Exception.h"

class ADOException : Exception 
{
public:
	ADOException();
	virtual ~ADOException();
public:
	ADOException(_com_error& e);
	ADOException(HRESULT hr);
	void ReportError();
	CString Description();
	void Delete();

private:
	_com_error m_Error;

};

#endif // !defined(AFX_ADOEXCEPTION_H__BDC8C791_8518_4E7D_919F_28D04D3B8485__INCLUDED_)
