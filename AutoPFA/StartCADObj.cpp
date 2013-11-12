#include "stdafx.h"
#include "StartCADObj.h"
#include "UeRegEdit.h"
#include "ACAD.h"
IAcadApplication m_ObjAcadApp1 = NULL;
StartCADObj::StartCADObj(void)
{
}

StartCADObj::~StartCADObj(void)
{
}
CString vtos(_variant_t& v);
bool  vtob(	VARIANT &v);

void StartCADObj::StartUpCAD()
{
	CString m_strStartVersion = _T("");
	HRESULT hr = NOERROR;
	CLSID clsid;
	LPUNKNOWN pUnk = NULL;
	LPDISPATCH pDisp = NULL;

//	m_ObjAcadApp1.CreateDispatch(_T("AutoCAD.Application"));
	hr = ::CLSIDFromProgID(L"AutoCAD.Application", &clsid);

	if (SUCCEEDED(hr))
	{
		if(::GetActiveObject(clsid, NULL, &pUnk) == S_OK)
		{
			VERIFY(pUnk->QueryInterface(IID_IDispatch, (LPVOID*)
				&pDisp) == S_OK);
			m_ObjAcadApp1.AttachDispatch(pDisp);
			pUnk->Release();
		}
		else
		{
//			m_ObjAcadApp1.CreateDispatch(_T("AutoCAD.Application"));
			VERIFY(m_ObjAcadApp1.CreateDispatch(clsid) == TRUE);
		}
	}
	else
		AfxMessageBox(_T("Acad.Application is not registered!"));

	m_strStartVersion = m_ObjAcadApp1.GetVersion();

	//04以下版本不能用
	CString strCmp = _T("16");
	if( m_strStartVersion < strCmp )
	{
		AfxMessageBox(_T("请选择启动的版本！"));
		return;
	}
	else
	{	
		CString strArxFile;
		CString strArxPath;

		m_strStartVersion = "AutoCAD.Application."+m_strStartVersion.Left( 2 );
		if ( m_strStartVersion.Right(2) == _T("16") )
		{
				strArxFile = _T( "2004" );
		}
		else if ( m_strStartVersion.Right(2) == _T("17") )
		{
				strArxFile = _T( "2007" );
		}

		strArxPath = GetArxFilePath(strArxFile);
#if !defined NDEBUG
		strArxPath = "D:\\Uelib\\libd";
#endif
		
//		m_ObjAcadApp1.DetachDispatch();
//		m_ObjAcadApp1.SetSupportPath(m_ObjAcadApp1.GetSupportPath() + _T( ";" ) + strArxPath );

		m_ObjAcadApp1.SetVisible( TRUE );

		LPDISPATCH pDisp;
		IAcadPreferences IPrefers;
		pDisp=m_ObjAcadApp1.GetPreferences();
		IPrefers.AttachDispatch(pDisp); 	
		IAcadPreferencesFiles IPreFiles;
		pDisp=IPrefers.GetFiles(); 
		IPreFiles.AttachDispatch(pDisp); 
		CString sSupportPath = IPreFiles.GetSupportPath();
		CString sOldSupportPath = sSupportPath;
		CString strtemp = strArxPath;
		sSupportPath = sSupportPath + _T(";") + strtemp;
//		AfxMessageBox( sSupportPath );
		IPreFiles.SetSupportPath(sSupportPath);
		IPreFiles.DetachDispatch();
		IPrefers.DetachDispatch();

#if !defined NDEBUG
		m_ObjAcadApp1.LoadArx( _T("APPfaDrawTbComman10d.arx") );
#else
		m_ObjAcadApp1.LoadArx( _T("APPfaDrawTbComman10.arx") );
#endif
		
//		LPDISPATCH pDisp;	
		IAcadDocument acadDoc;
		// 获得当前文档和模型空间
		pDisp = m_ObjAcadApp1.GetActiveDocument();
		acadDoc.AttachDispatch(pDisp);
		acadDoc.SendCommand( _T( "Drawpfatbl\n" ) );

		//还原
		IPrefers;
		pDisp=m_ObjAcadApp1.GetPreferences();
		IPrefers.AttachDispatch(pDisp); 	
		pDisp=IPrefers.GetFiles(); 
		IPreFiles.AttachDispatch(pDisp); 
		IPreFiles.SetSupportPath(sOldSupportPath);
		IPreFiles.DetachDispatch();
		IPrefers.DetachDispatch();		
		
		m_ObjAcadApp1.DetachDispatch();
	}

}



// void StartCADObj::StartUpCAD()
// {
// 	BOOL bGetApp=FALSE;
// 	AfxGetApp()->BeginWaitCursor();
// 	if(FAILED(m_ObjAcadApp.GetActiveObject(_T("AutoCAD.Application"))))
// 	{
// 		//没有得到对象
// 		if(FAILED(m_ObjAcadApp.CreateObject(_T("AutoCAD.Application"))))
// 		{
// 			AfxMessageBox( _T( "不能启动CAD" ) );
// 
// 			return;
// 		}
// 	}
// 	else
// 	{
// 		//得到对象
// 		bGetApp=TRUE;
// 	}
// 	BOOL bACADR14=FALSE;
// 	BOOL bACAD2000=FALSE;
// 	BOOL bACAD2004 = FALSE;
// 	BOOL bACAD2007 = FALSE;
// 	CString strAutoCADVer;
// 	strAutoCADVer= vtos(m_ObjAcadApp.GetPropertyByName(_T("Version")));
// 	if (strAutoCADVer.Left(2)==_T("15"))
// 	{
// 		bACAD2000 = TRUE;
// 	}
// 	else if ( strAutoCADVer.Left(2) == _T("16") )
// 	{
// 		bACAD2004 = TRUE;
// 	}
// 	else if ( strAutoCADVer.Left(2) == _T("17") )
// 	{
// 		bACAD2007 = TRUE;
// 	}
// 	else
// 	{
// 		AfxMessageBox( _T( "启动的CAD不支持该操作！" ) );
// 		return;
// 	}
// 
// 	if( bGetApp )
// 	{
// 	}
// 	else
// 	{
// 		_variant_t varBool;
// 		varBool.vt = VT_BOOL;
// 		varBool.boolVal=true;
// 		m_ObjAcadApp.PutPropertyByName(_T("Visible"),&varBool);	
// 	}
// 
// 	GetActiveAcadDoc( bACADR14 );
// 
// 	//begin
// 	WriteFileToCAD(m_ObjAcadDoc,m_strTabIndex );
// 
// 	CString strArxPath,strArxFile;	
// 
// 	if (bACAD2000)
// 	{
// 		strArxFile = "2002";
// 	}
// 	else if ( TRUE == bACAD2004 )
// 	{
// 		strArxFile = "2004";
// 	}
// 	else
// 	{
// 		strArxFile = "2007";
// 	}
//  	strArxPath = GetArxFilePath(strArxFile);
//  	DeleteSupportPath();
//  	AddSupportPath(strArxPath);
// 	strArxFile = strArxPath + ( "\\APPfaDrawTbCommand10.arx" );
// #if !defined NDEBUG
// 	strArxFile = "D:\\Uelib\\libd\\APPfaDrawTbCommand10d.arx";
// #endif
// 
// 	m_ObjAcadApp.Invoke(_T("LoadArx"),1,&_variant_t(strArxFile));
// 	m_ObjAcadApp.Invoke(_T("LoadArx"),1,&_variant_t(strArxFile));
// 	DeleteSupportPath();
// 	CMObject objDocument;
// 	objDocument = m_ObjAcadApp.GetPropertyByName(_T("ActiveDocument"));
// 	objDocument.Invoke(_T("SendCommand"), 2, &_variant_t("filedia\n"),&_variant_t("1\n") );
// //	objDocument.Invoke(_T("SendCommand"), 1, );
// 	objDocument.Invoke(_T("SendCommand"), 1, &_variant_t(strArxFile + _T("\n")));
// 	objDocument.Invoke(_T("SendCommand"), 1, &_variant_t("DrawPfaTbl\n"));	
// 	AfxGetApp()->EndWaitCursor();
// 
// }

void StartCADObj::SetTabIndex( CString tablIndex )
{
	m_strTabIndex = tablIndex;
}

CString StartCADObj::GetTabIndex()
{
	return m_strTabIndex;
}

CString StartCADObj::GetArxFilePath(CString strCADVersion)
{
	UeRegEdit reg( _T( "SOFTWARE\\长沙优易软件开发有限公司\\" ) );
	CString strSubKey = _T( "AutoPFA" );

	CString strVerInfo = _T( "" );

	//获得AutoPFA的安装路径
	strVerInfo = reg.GetRegKey( strSubKey,_T( "AutoPFA_Version" ),strVerInfo );
	if( strVerInfo.IsEmpty() )
	{
		return _T( "" );
	}

	if ( strVerInfo.Right( 1 ) != "\\" )
	{
		strVerInfo += "\\";
	}

	if ( strCADVersion == _T("2000") )
	{
		strVerInfo += "2002";
	}
	else
	{
		strVerInfo += strCADVersion;
	}

	return strVerInfo;
}

BOOL StartCADObj::WriteFileToCAD(CMObject &refDoc, CString strDrawFileName)
{
	if( strDrawFileName.IsEmpty() )
		return FALSE;

	refDoc.Invoke(_T("SetVariable"),
		2,
		&_variant_t(_T("USERS5")),
		&_variant_t(strDrawFileName) );

	return TRUE ;

}
void StartCADObj::GetActiveAcadDoc(BOOL bAcadR14)
{
	try
	{
		CString strTmp,strTmp2; 
		_variant_t tmpvar;
		if(bAcadR14)
		{
			//AutoCAD R14
			m_ObjAcadDoc=m_ObjAcadApp.GetPropertyByName(_T("ActiveDocument"));
			m_ObjAcadDoc.Invoke0(_T("Open"));
		}
		else
		{
			//AutoCAD 2000
			int count,i;
			CMObject acadDocs;
			CMObject objTmp;
			acadDocs=m_ObjAcadApp.GetPropertyByName(_T("Documents"));
			count=(long)acadDocs.GetPropertyByName(_T("Count"));
			bool bf=false;
			for(i=count-1;i>=0;i--)
			{
				m_ObjAcadDoc=acadDocs.Invoke(_T("Item"),1,&_variant_t((long)i));
				strTmp=vtos(m_ObjAcadDoc.Invoke(_T("GetVariable"),1,&_variant_t(_T("DWGPREFIX"))));
				//user::AddDirSep(strTmp);
				strTmp2=vtos(m_ObjAcadDoc.Invoke(_T("GetVariable"),1,&_variant_t(_T("DWGNAME"))));
				strTmp.MakeLower();strTmp2.MakeLower();
				if(vtob(m_ObjAcadDoc.GetPropertyByName(_T("Active"))))
				{
					//if((strTmp==tmpPath && strTmp2 == _T("helper.dwg")))
					//	bf=true;
				}
				//else if((strTmp==tmpPath && strTmp2 == _T("helper.dwg")))
				//{
				//	m_ObjAcadDoc.Invoke(_T("Close"),1,&_variant_t(false));
				//}
				else 
				{
					m_ObjAcadDoc.Invoke(_T("Close"),1,&_variant_t(true));
				}
			}
			m_ObjAcadDoc=m_ObjAcadApp.GetPropertyByName(_T("ActiveDocument"));
			//m_ObjAcadDoc.Invoke(_T("SetVariable"),2,&_variant_t(_T("SDI")),&_variant_t((long)0));
			if(bf==false)
			{
				m_ObjAcadDoc.Invoke0(_T("Save"));
				//tmpvar=_variant_t(strTmp);
				m_ObjAcadDoc.Invoke0(_T("Open"));
				//m_ObjAcadDoc.Invoke0(_T("Open",1,&tmpvar));
			}
		}
	}
	catch(CException *e)
	{
		e->Delete();
		AfxMessageBox(_T("Exception"));
	}
	catch(...)
	{
		AfxMessageBox(_T("Exception"));
	}
}

void StartCADObj::DeleteSupportPath()
{
	CString strPath;
	CString strLeft;
	CString strRight;
	CString strInsPath = _T("长沙优易软件");
	CMObject ObjAcadApp;
	if(SUCCEEDED(ObjAcadApp.GetActiveObject(_T("AutoCAD.Application"))))
	{	
		CMObject ObjAcadAppPreferencesFiles;
		CMObject ObjPreferences;
		ObjPreferences=ObjAcadApp.GetPropertyByName(_T("Preferences"));
		ObjAcadAppPreferencesFiles=ObjPreferences.GetPropertyByName(_T("Files"));


		_variant_t varAllPah;
		varAllPah = ObjAcadAppPreferencesFiles.GetPropertyByName( _T("SupportPath") );  //获得SupportPath搜索路径

		CString strAllPath = varAllPah.bstrVal;
		strInsPath.MakeUpper();
		int pos = strAllPath.Find( _T(";") );
		strRight = strAllPath;
		while ( pos != -1 )
		{
			strLeft = strRight.Left( pos + 1 );
			strRight = strRight.Mid( pos + 1 );
			CString strLeftTmp = strLeft;
			strLeftTmp.MakeUpper();
			if ( strLeftTmp.Find( strInsPath ) == -1 )
			{
				strPath += strLeft;
			}
			pos = strRight.Find( _T(";") );
		}

		CString strRightTmp = strRight;
		strRightTmp.MakeUpper();
		if ( strRightTmp.Find( strInsPath ) == -1 )
		{
			strPath += strRight;
		}
		if( strPath.Right( 1 ) == _T(";") )
			strPath = strPath.Left( strPath.GetLength() -1 );
		_variant_t varSupportPath;
#ifdef UNICODE
		varSupportPath.SetString( ConvertUnicodeToAnsi(strPath) );
#else
		varSupportPath.SetString( strPath );
#endif
		ObjAcadAppPreferencesFiles.PutPropertyByName(_T("SupportPath"),&varSupportPath);
	}
}

// 功能：Unicode -> Ansi
// 输入：UNICODE字符串
// 输出：相应的ANSI字符串
// 备注：本函数下次调用释放上次调用分配的内存，要完全清除内存请使用ConvertUnicodeToAnsi(NULL);
//		请确保调用结果使用完毕后才再次调用本函数。
char* StartCADObj::ConvertUnicodeToAnsi( IN const wchar_t* pwUNICODE )
{
	static char* s_pChar = NULL;

	delete[] s_pChar;
	s_pChar = NULL;

	if( pwUNICODE == NULL )
	{
		return NULL;
	}

	//get the length then and buffer
	int nLength = ::WideCharToMultiByte( CP_ACP, 0, pwUNICODE, -1, NULL, 0, NULL, NULL );
	s_pChar = new char[ nLength*sizeof(char) ];

	//do convert
	::WideCharToMultiByte( CP_ACP, 0, pwUNICODE, -1, s_pChar, nLength, NULL, NULL );
	return s_pChar;
}

void StartCADObj::AddSupportPath(const CString &strInsPath)
{
	CMObject m_ObjAcadAppPreferencesFiles;
	CMObject ObjPreferences;
	ObjPreferences=m_ObjAcadApp.GetPropertyByName(_T("Preferences"));
	m_ObjAcadAppPreferencesFiles=ObjPreferences.GetPropertyByName(_T("Files"));


	_variant_t varAllPah;
	varAllPah = m_ObjAcadAppPreferencesFiles.GetPropertyByName( _T("SupportPath") );  //获得SupportPath搜索路径

	CString strAllPath = varAllPah.bstrVal;
	if( strAllPath.Find( strInsPath ) == -1 )  //判断是否已经添加
	{	
		//	//Find 操作失败       
		if( strAllPath.Right( 1 ) != _T(";"))
			strAllPath += _T(";");
		strAllPath += strInsPath;
		//strAllPath = _T("");
		_variant_t varSupportPath;
#ifdef UNICODE
		varSupportPath.SetString( ConvertUnicodeToAnsi(strAllPath) );
#else
		varSupportPath.SetString( strAllPath );
#endif
		m_ObjAcadAppPreferencesFiles.PutPropertyByName(_T("SupportPath"),&varSupportPath);

	}
}

CString vtos(_variant_t& v)
{
	CString ret;
	switch(v.vt)
	{
	case VT_NULL:
	case VT_EMPTY:
		ret="";
		break;
	case VT_BSTR:
		ret=V_BSTR(&v);
		break;
	case VT_R4:
		ret.Format(_T("%g"), (double)V_R4(&v));
		break;
	case VT_R8:
		ret.Format(_T("%g"),V_R8(&v));
		break;
	case VT_I2:
		ret.Format(_T("%d"),(int)V_I2(&v));
		break;
	case VT_I4:
		ret.Format(_T("%d"),(int)V_I4(&v));
		break;
	case VT_BOOL:
		ret=(V_BOOL(&v) ? _T("True") : _T("False"));
		break;
	}
	ret.TrimLeft();ret.TrimRight();
	return ret;
}
bool  vtob(	VARIANT &v)
{
	switch(v.vt)
	{
	case VT_BOOL:
		return (bool)V_BOOL(&v);
	case VT_I2:
		return (bool)V_I2(&v);
	case VT_I4:
		return (bool)V_I4(&v);
	case VT_R4:
		return (bool)V_R4(&v);
	case VT_R8:
		return (bool)V_R8(&v);
	}
	return false;
}

