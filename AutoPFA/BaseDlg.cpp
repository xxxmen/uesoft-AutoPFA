// BaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "BaseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BaseDlg dialog
BaseDlg::BaseDlg(UINT ID,CWnd* pParent /*=NULL*/)
: CDialog(ID, pParent)
{
	//{{AFX_DATA_INIT(UeBaseDialog)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

// BaseDlg::BaseDlg(CWnd* pParent /*=NULL*/)
// 	: CDialog(ID, pParent)
// {
// 	//{{AFX_DATA_INIT(BaseDlg)
// 		// NOTE: the ClassWizard will add member initialization here
// 	//}}AFX_DATA_INIT
// }


void BaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BaseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BaseDlg, CDialog)
	//{{AFX_MSG_MAP(BaseDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BaseDlg message handlers
BOOL BaseDlg::PreTranslateMessage(MSG* pMsg) 
{
	if( pMsg->message == WM_KEYDOWN && ( pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN ) )
	{
		CWnd* pParent = GetParent();
		if (pParent)
		{
			return pParent->PreTranslateMessage(pMsg);
		}
		//return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}