// ADOException.cpp: implementation of the ADOException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ADOException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOException::ADOException():m_Error(0)
{

}

ADOException::~ADOException()
{

}

/*************************************************
  Function:       Delete
  Description:    删除异常对象本身
  Calls:          操作符delete
  Called By:      该类对象
  Table Accessed: 无
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void ADOException::Delete()
{
	delete this;
}


/*************************************************
  Function:       Description
  Description:    获取对该异常的描述信息
  Calls:          _com_error方法Description
  Called By:      该类对象
  Table Accessed: 无
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         描述信息字符串
  Others:         
*************************************************/

CString ADOException::Description()
{
	_bstr_t tmp = this->m_Error.Description();
	const char* strtmp = tmp;
	return CString(strtmp);
}


/*************************************************
  Function:       ReportError
  Description:    向用户报告异常。
  Calls:          全局函数AfxMessageBox
  Called By:      该类对象
  Table Accessed: 无
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void ADOException::ReportError()
{
	::AfxMessageBox(this->Description());	
}

ADOException::ADOException(HRESULT hr):m_Error(hr)
{
	
}

ADOException::ADOException(_com_error& e):m_Error(e)
{

}

