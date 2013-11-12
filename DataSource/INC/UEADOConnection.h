// UEADOConnection.h: interface for the UEADOConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UEADOCONNECTION_H__B6FBF718_F845_44FD_99F2_CE643E881F4F__INCLUDED_)
#define AFX_UEADOCONNECTION_H__B6FBF718_F845_44FD_99F2_CE643E881F4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class UEADOConnection  
{
public:
	UEADOConnection();
	virtual ~UEADOConnection();
	_RecordsetPtr ExecuteSelect( const char* szSql );
	void Open( const char* szDataSource );
private:
	_ConnectionPtr m_conPtr;
};

#endif // !defined(AFX_UEADOCONNECTION_H__B6FBF718_F845_44FD_99F2_CE643E881F4F__INCLUDED_)
