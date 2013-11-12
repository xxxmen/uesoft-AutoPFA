// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C48F0A4D_EE89_48DC_A6E8_EED9BABFEEC9__INCLUDED_)
#define AFX_STDAFX_H__C48F0A4D_EE89_48DC_A6E8_EED9BABFEEC9__INCLUDED_

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

#include <gemat3d.h>
#include <gevec3d.h>
#include <gevec2d.h>
#include <gepnt2d.h>
#include <gepnt3d.h>
#include <geplane.h>

#include "SetCompKeyPt.h"
#include <Afxtempl.h>
#include <math.h>
#include "ListFlyWeightImp.h"


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

template<class T> void DelMap(CMap<int,int,T*,T*>& map)
{
	POSITION pos = map.GetStartPosition();
	T *temp = NULL;
	int nKey;
	while(pos)
	{
		map.GetNextAssoc(pos,nKey,temp);
		delete temp;
	}
	map.RemoveAll();
}

template<class T> T* LookMap(CMap<int,int,T*,T*>& map,int nKey)
{
	T *temp = NULL;
	map.Lookup(nKey,temp);
	return temp;
}

template<class T> int CreatKey(CMap<int,int,T*,T*>& map)
{
	T *temp = NULL;
	int nKey = 1;
	while(map.Lookup(nKey,temp))
		nKey++;
	return nKey;
}
AcGePoint3d Tran3dTo2d(AcGePoint3d &pt);
#include <string>

#ifdef UNICODE
typedef std::wstring UeStdString;
#define UELPCSTR LPCWSTR
#else
typedef std::string UeStdString;
#define UELPCSTR LPCTSTR
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C48F0A4D_EE89_48DC_A6E8_EED9BABFEEC9__INCLUDED_)
