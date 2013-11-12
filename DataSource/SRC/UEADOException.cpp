// UEADOException.cpp: implementation of the UEADOException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UEADOException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UEADOException::UEADOException():m_Error(0)
{
	
}

UEADOException::~UEADOException()
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

void UEADOException::Delete()
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

StdString UEADOException::Description()
{
	_bstr_t tmp = this->m_Error.Description();
	const char* strtmp = tmp;
	return StdString(strtmp);
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

void UEADOException::ReportError()
{
	::AfxMessageBox(this->Description());	
}

UEADOException::UEADOException(HRESULT hr):m_Error(hr)
{
	
}

UEADOException::UEADOException(_com_error& er):m_Error(er)
{

}
