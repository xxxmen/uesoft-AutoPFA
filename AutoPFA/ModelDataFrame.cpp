// ModelDataFrame.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "ModelDataFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelDataFrame

IMPLEMENT_DYNCREATE(CModelDataFrame, CMDIChildWnd)

CModelDataFrame::CModelDataFrame()
{
}

CModelDataFrame::~CModelDataFrame()
{
}


BEGIN_MESSAGE_MAP(CModelDataFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CModelDataFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelDataFrame message handlers

BOOL CModelDataFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	//cs.lpszClass=::AfxRegisterWndClass(CS_NOCLOSE);
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	
	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX| WS_MAXIMIZEBOX|WS_MINIMIZE;
	
	return TRUE;
}


BOOL CModelDataFrame::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CMDIChildWnd::DestroyWindow();
}

int CModelDataFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if (!m_wndDlgBar.Create(this, IDD_DLGMODELDATA,
		CBRS_TOP|CBRS_TOOLTIPS|CBRS_FLYBY, IDD_DLGMODELDATA))
	{
		TRACE0("Failed to create DlgBar\n");
		return -1;      // fail to create
	}
	CComboBox* pCbmBox = (CComboBox*)m_wndDlgBar.GetDlgItem(IDC_CMBSHOWTYPE);
	pCbmBox->SetCurSel(0);
	return 0;
}

int CModelDataFrame::GetCurSelShow()
{
	CComboBox* pCbmBox = (CComboBox*)m_wndDlgBar.GetDlgItem(IDC_CMBSHOWTYPE);
	return pCbmBox->GetCurSel();
}

void CModelDataFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	this->ShowWindow(SW_MINIMIZE);
	return;
}
