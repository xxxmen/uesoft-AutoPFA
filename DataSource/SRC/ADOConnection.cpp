// ADOConnection.cpp: implementation of the ADOConnection class.
/************************************************************************
版本: 8.0  开发时间: 2008/12/18  作者: denglb 评审人:
功能:     实现对数据库的操作                                                         
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/

#include "stdafx.h"
#include "ADOConnection.h"
#include "ADOException.h"
#include <afx.h>
#include <io.h>
#include <SYS/STAT.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConnection::ADOConnection():m_pConnection(*m_pConn),m_pConn(new _ConnectionPtr)
{

}

ADOConnection::~ADOConnection()
{
	this->Close();
}

void ADOConnection::Open(const CString &strCource)
{
	HRESULT hr;
	try
	{
		CoInitialize(NULL); 
		hr = this->m_pConnection.CreateInstance(_T("ADODB.Connection")/*__uuidof(Connection)*/);
		if (SUCCEEDED(hr))
		{
			hr = m_pConnection->Open(_bstr_t( _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=") + strCource ),_T(""),_T(""),-1);
			/*******************************************
				HRESULT Connection15::Open ( _bstr_t ConnectionString, _bstr_t UserID, _bstr_t Password, long Options )
				ConnectionString为连接字串,UserID是用户名, Password是登陆密码,Options是连接选项,用于指定Connection对象对数据的更新许可权,
				Options可以是如下几个常量:
				adModeUnknown:缺省。当前的许可权未设置
				adModeRead:只读
				adModeWrite:只写
				adModeReadWrite:可以读写
				adModeShareDenyRead:阻止其它Connection对象以读权限打开连接
				adModeShareDenyWrite:阻止其它Connection对象以写权限打开连接
				adModeShareExclusive:阻止其它Connection对象以读写权限打开连接
				adModeShareDenyNone:阻止其它Connection对象以任何权限打开连接

				我们给出一些常用的连接方式供大家参考:
				(1)通过JET数据库引擎对ACCESS2000数据库的连接

				m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\test.mdb","","",adModeUnknown);

			**********************************************/
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox( e.Description() );
	}
}

/*************************************************
  Function:       ExecuteSelectSQL
  Description:    执行需要返回记录集的操作
  Calls:          ADO方法CreateInstance，Open
  Called By:      该类对象
  Table Accessed: 当前打开表
  Table Updated:  当前打开表
  Input:          无
  Output:         无
  Return:         UERecordsetPtr
  Others:         
*************************************************/

ADORecordSetPtr ADOConnection::ExecuteSelectSQL(const CString &strSQL)
{
	try
	{	
		_RecordsetPtr m_pRecordset;
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(_bstr_t(strSQL)
							,(IDispatch*)(*m_pConn)
							,adOpenDynamic
							,adLockOptimistic
							,adCmdText);

		return new ADORecordSet(m_pRecordset);
	}
	catch (_com_error e)
	{
		AfxMessageBox( e.Description() );
	}

	return NULL;
}

_RecordsetPtr ADOConnection::ExecuteSelectSQL(const CString &strSQL,short nMode)
{
	try
	{	
		_RecordsetPtr m_pRecordset;
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(_bstr_t(strSQL)
			,(IDispatch*)m_pConnection
			,adOpenDynamic
			,adLockOptimistic
			,adCmdText);
		
		return m_pRecordset;
	}
	catch (_com_error e)
	{
		AfxMessageBox( e.Description() );
	}
	return NULL;//暂时代码 
}
/*************************************************
  Function:       ExecuteNoSelectSQL
  Description:    执行不需要返回记录集的操作
  Calls:          ADO方法Execute
  Called By:      该类对象
  Table Accessed: 当前打开表
  Table Updated:  当前打开表
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

BOOL ADOConnection::ExecuteNoSelectSQL(const CString &strSQL)
{
//	STATBEGIN ( ExecuteNoSelectSQL );
	try
	{
		//_variant_t RecordsAffected;
		//为什么删除一个空表、建立一个已经存在的表，程序都会崩溃啊！！这样不很麻烦？？？
		//有没有建表，删表的需求呢？？！
		_variant_t RecordsAffected;
		m_pConnection->Execute(_bstr_t(strSQL),NULL,adCmdText);
		ULONG iInfluence = (long)RecordsAffected;
	}
	catch (_com_error e)
	{
		//#ifndef NDEBUG
		
		CFile file;
		if ( file.Open( _T ( "C:\\SQL.err" ), CFile::modeReadWrite | CFile::modeNoTruncate ) )
		{
			
			
			SYSTEMTIME time;
			::GetLocalTime( &time );
			
			CString strTemp;
			strTemp.Format( _T("(%d-%d-%d-%d-%d )"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute );
			
			strTemp = strSQL + strTemp + _T ( "\r\n" );
			
			file.SeekToEnd();
			file.Write( strTemp, strTemp.GetLength() );
			
			file.Close();
		}	
		
		throw e;
	}
//	STATEND;
	return FALSE;
}

/*************************************************
  Function:       BeginTrans
  Description:    启动新事务
  Calls:          
  Called By:      该类对象
  Input:          无
  Output:         无
  Return:         LONG
  Others:         
*************************************************/

LONG ADOConnection::BeginTrans()
{
	LONG lResult = 0;
	try
	{
		m_pConnection->BeginTrans();
	}
	catch ( _com_error e ) 
	{
		throw  e;
	}
	return lResult;
}

/*************************************************
  Function:       Close
  Description:    关闭与ADO数据库的连接
  Calls:          ADO方法Close
  Called By:      该类对象
  Table Accessed: 无
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void ADOConnection::Close()
{
	try
	{
		if(m_pConnection->State != adStateClosed)
			{
				m_pConnection->Close();
				CoUninitialize();//添加于2006-11.9
			}
			m_pConnection = NULL; 
		//	delete m_pConn;
	}
	catch (_com_error e)
	{
		throw new ADOException(e);
	}
}

BOOL ADOConnection::IsOpen()
{
	if( m_pConnection == NULL || m_pConnection->State == adStateClosed )
	{
		return FALSE;
	}
	return TRUE;
}

BOOL ADOConnection::GetConnectionptr( _ConnectionPtr& pConnect )
{
	pConnect = m_pConnection;
	return TRUE;
}