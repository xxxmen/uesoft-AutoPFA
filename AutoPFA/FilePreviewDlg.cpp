// FilePreviewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FilePreviewDlg.h"

#include "MainFrm.h"
#include "AutoPFA.h"
#include "AutoPFADoc.h"
#include "ScenariManage.h"
#include "Scenario.h"
/*#include "OutFunction.h"*/

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilePreviewDlg

extern double GetAt(CString StrText,int i);

IMPLEMENT_DYNAMIC(CFilePreviewDlg, CFileDialogEx)

CFilePreviewDlg::CFilePreviewDlg(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialogEx(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	m_ofn.hInstance=AfxGetResourceHandle();
	m_ofn.Flags |= OFN_EXPLORER | OFN_ENABLETEMPLATE;
	m_ofn.lpTemplateName=MAKEINTRESOURCE(IDD_PREVIEW);
	//m_ofn.lpstrFilter =lpszFilter;
	m_Area.m_pParentDlg=this;
	//{{AFX_DATA_INIT(CFilePreviewDlg)
	//}}AFX_DATA_INIT
}


BEGIN_MESSAGE_MAP(CFilePreviewDlg, CFileDialogEx)
	//{{AFX_MSG_MAP(CFilePreviewDlg)
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CFilePreviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFilePreviewDlg)
	DDX_Control(pDX,IDC_PREVIEW_AREA,m_Area);
	//}}AFX_DATA_MAP
}




void CFilePreviewDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CFileDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

BOOL CFilePreviewDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	LPOFNOTIFY pOfn=(LPOFNOTIFY)lParam;
	switch(pOfn->hdr.code)
	{
	case CDN_SELCHANGE:
		GetDlgItem(IDC_PREVIEW_AREA)->Invalidate();
		break;
	case CDN_FOLDERCHANGE :
		break;
		return TRUE;
	}
 	return CFileDialogEx::OnNotify(wParam, lParam, pResult);
}

BOOL CFilePreviewDlg::OnInitDialog() 
{
	CFileDialogEx::OnInitDialog();
	return TRUE;  
}

void CFilePreviewDlg::Draw(CDC* pDC)
{
	ScenariManage m_scenarioManager;
	WorkSpaceRef  m_workSpaceRef;
	PersistentMgr m_PersistentMgr;
	PersistentModel GlobalModel;
	CWnd *pWnd=GetDlgItem(IDC_PREVIEW_AREA);

	try
	{
		BOOL bRet = TRUE;
		//	PersistentModel model;
		CString strPathName = GetPathName();
		ErrorStatus::FileError error= m_PersistentMgr.Read( strPathName,GlobalModel);
		if(error == ErrorStatus::eFileOK)
		{
			bRet = m_scenarioManager.Read(GlobalModel.GetScenarioPersist());
		}
		if ( !bRet )
		{
			return;
		}
		
		CRect rect;
		pWnd->GetWindowRect(&rect);
		
		CRect rectSmallView( 0 , 0 , 0 , 0 );
		m_scenarioManager.GetCurScenario()->GetCompManager()->GetSmallViewRect( rectSmallView );
		int nWidth = rectSmallView.Width() ;
		int nHeight = rectSmallView.Height() ;
		
		
		// create compatible DC
		CDC memDc;
		memDc.CreateCompatibleDC(pDC);
		
		// create compatible Bitmap
		CBitmap memBitmap;
		memBitmap.CreateCompatibleBitmap( pDC, nWidth, nHeight);
		
		// select compatible bitmap in compatible dc
		memDc.SelectObject( &memBitmap );
		
		//set backColor
		CBrush brush(RGB(255,255,255));
		memDc.FillRect( CRect( 0, 0, nWidth, nHeight ),&brush);
		
		//draw Graphs
		m_scenarioManager.GetCurScenario()->GetCompManager()->Draw(&memDc, m_workSpaceRef );
		
		BITMAP strBitmap;
		memBitmap.GetBitmap(&strBitmap);
		pDC->StretchBlt( 0, 0, rect.Width(), rect.Height(), &memDc, 0, 0, strBitmap.bmWidth, strBitmap.bmHeight, SRCCOPY);
		
	}
	catch (CMemoryException* e)
	{
		
	}
	catch (CFileException* e)
	{
	}
	catch (CException* e)
	{
	}
}

BOOL FileExists(LPCTSTR lpszPathName)
{
	DWORD att=::GetFileAttributes(lpszPathName);
	if(att==0xFFFFFFFF || ((att & FILE_ATTRIBUTE_DIRECTORY)!=0) ) return FALSE;
	return TRUE;
	
}

BOOL CFilePreviewDlg::CheckFileName( const CString& strFileName )
{
	CString strFileNameTemp = strFileName;
	CString strText;
	
	if ( !FileExists( strFileNameTemp ) )
	{
		return FALSE;
	}
	
	int iIndex = strFileNameTemp.ReverseFind('.');
	strText=strFileNameTemp.Mid(iIndex);
	strText.MakeLower();
	
	if ( strText == _T(".imp") || strText == _T(".fth") || strText == _T(".pcf"))
	{
		return TRUE;
	}
	return FALSE;
}