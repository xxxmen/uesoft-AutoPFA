// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__4FFD5BBB_153C_4CAE_848E_90206AEBCF7D__INCLUDED_)
#define AFX_STDAFX_H__4FFD5BBB_153C_4CAE_848E_90206AEBCF7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT


#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <Afxtempl.h>
#include "ErrorStatus.h"
#include "ListFlyWeightImp.h"
#include <iostream>
#include <fstream>
#include <math.h>

typedef CString StdString;
#pragma warning(disable:4146 4995 4290 4786)

#include "PersistentHeader.h"

// #define _atoi atoi
// #define strtof atof
// #define strtod atof

template<>
AFX_INLINE UINT AFXAPI HashKey<CString>(CString key)
{
	DWORD nHashKey = 0;
	TCHAR* pChar = key.GetBuffer(10);
	TCHAR c = 0;

	for(int i = 0; i < key.GetLength(); i++)
	{
		c = pChar[i];
		nHashKey += c;
#ifdef _UNICODE
		if(i < 1)
		{
			nHashKey = nHashKey << 16;
		}
#else
		if(i < 3)
		{
			nHashKey = nHashKey << 8;
		}
#endif
	}
	return nHashKey;
}

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__4FFD5BBB_153C_4CAE_848E_90206AEBCF7D__INCLUDED_)
