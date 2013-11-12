// FilePreviewDlgArea.cpp : implementation file
//

#include "stdafx.h"
#include "FilePreviewDlgArea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilePreviewDlgArea
#include "FilePreviewDlg.h"

CFilePreviewDlgArea::CFilePreviewDlgArea()
{
	RegisterWindowClass();
}

CFilePreviewDlgArea::~CFilePreviewDlgArea()
{
}


BEGIN_MESSAGE_MAP(CFilePreviewDlgArea, CWnd)
	//{{AFX_MSG_MAP(CFilePreviewDlgArea)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFilePreviewDlgArea message handlers

BOOL CFilePreviewDlgArea::RegisterWindowClass()
{
    WNDCLASS wndcls;
    //HINSTANCE hInst = AfxGetInstanceHandle();
   HINSTANCE hInst = AfxGetResourceHandle();

    if (!(::GetClassInfo(hInst, _T("FilePreviewDlgArea"), &wndcls)))
    {
        // otherwise we need to register a new class
        wndcls.style            = CS_OWNDC | CS_SAVEBITS | CS_HREDRAW | CS_VREDRAW ;
        wndcls.lpfnWndProc      = ::DefWindowProc;
        wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
        wndcls.hInstance        = hInst;
        wndcls.hIcon            = NULL;
        wndcls.hCursor          = AfxGetApp()->LoadCursor(IDC_ARROW);
        wndcls.hbrBackground    = NULL;
        wndcls.lpszMenuName     = NULL;
        wndcls.lpszClassName    = _T("FilePreviewDlgArea");

        if (!AfxRegisterClass(&wndcls))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}

void CFilePreviewDlgArea::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CString strFileName = m_pParentDlg->GetPathName();
    if ( !m_pParentDlg->CheckFileName( strFileName ) )
    {
		strFileName.Empty();
    }

	if( strFileName.IsEmpty() )
	{
		CBrush brush(RGB(6,164,249));
		CRect rcClient ;
		GetClientRect(&rcClient);
		dc.FillRect(rcClient,&brush);
		COLORREF crOldBk=dc.SetBkColor(RGB(6,164,249));
		COLORREF crOldText=dc.SetTextColor(RGB(0,0,0));
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		CString str;
		str.LoadString(IDS_NOSOUCEFILE);
		dc.TextOut( rcClient.Width()/2 ,rcClient.Height()/2-tm.tmHeight/2,str,str.GetLength() );
		dc.SetBkColor(crOldBk);
		dc.SetTextColor(crOldText);
		brush.DeleteObject();
	}
	else
	{
		m_pParentDlg->Draw(&dc);//»æÍ¼
	}
}
