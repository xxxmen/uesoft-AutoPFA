// UEADOConnection.cpp: implementation of the UEADOConnection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\INC\UEADOConnection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UEADOConnection::UEADOConnection()
{

}

UEADOConnection::~UEADOConnection()
{

}

_RecordsetPtr UEADOConnection::ExecuteSelect( const char* szSql )
{
	try
	{	
		_RecordsetPtr m_pRecordset;
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(_bstr_t(szSql)
							,(IDispatch*)m_conPtr
							,adOpenDynamic
							,adLockOptimistic
							,adCmdText);

#ifndef NDEBUG	
	CFile file;
	if ( file.Open( _T ( "C:\\SQL.ini" ), CFile::modeReadWrite | CFile::modeNoTruncate ) )
	{
		
		
		SYSTEMTIME time;
		::GetLocalTime( &time );
		
		CString strTemp;
		strTemp.Format( "(%d-%d-%d-%d-%d )", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute );
		
		strTemp = szSql + strTemp + _T ( "\r\n" );
		
		file.SeekToEnd();
		file.Write( strTemp.GetBuffer( 1 ), strTemp.GetLength() );
		
		
		file.Close();
	}
#endif
		return m_pRecordset;
	}
	catch (_com_error e)
	{
		CFile file;
		if ( file.Open( _T ( "C:\\SQL.err" ), CFile::modeReadWrite | CFile::modeNoTruncate ) )
		{
			
			
			SYSTEMTIME time;
			::GetLocalTime( &time );
			
			CString strTemp;
			strTemp.Format( "(%d-%d-%d-%d-%d )", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute );
			
			strTemp = szSql + strTemp + _T ( "\r\n" );
			
			file.SeekToEnd();
			file.Write( strTemp.GetBuffer( 1 ), strTemp.GetLength() );
			
			
			file.Close();
		}
		AfxMessageBox( e.Description() );
	}

	return NULL;
}

void UEADOConnection::Open( const char* szDataSource )
{
	HRESULT hr;//
	try
	{
		CoInitialize(NULL); 
		hr = this->m_conPtr.CreateInstance("ADODB.Connection"/*__uuidof(Connection)*/);
		char szDb[0xff] = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
		strcat( szDb, szDataSource );
		if (SUCCEEDED(hr))
		{
			hr = m_conPtr->Open(_bstr_t( szDb ),"","",-1);
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