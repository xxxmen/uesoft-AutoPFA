// ModelDataView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "ModelDataView.h"
#include "ModelDataFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelDataView

IMPLEMENT_DYNCREATE(CModelDataView, CFormView)

CModelDataView::CModelDataView()
	: CFormView(CModelDataView::IDD)
{
	//{{AFX_DATA_INIT(CModelDataView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nCurShow = 0;
	m_pPipeView = NULL;
	m_pJunView = NULL;
	m_pGeneralView = NULL;
}

CModelDataView::~CModelDataView()
{
}

void CModelDataView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModelDataView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModelDataView, CFormView)
	//{{AFX_MSG_MAP(CModelDataView)
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_CMBSHOWTYPE, OnSelChangeShow)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelDataView diagnostics

#ifdef _DEBUG
void CModelDataView::AssertValid() const
{
	CFormView::AssertValid();
}

void CModelDataView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CModelDataView message handlers

void CModelDataView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	TabStatus();
}

void CModelDataView::OnSelChangeShow()
{
	m_nCurShow = ((CModelDataFrame*)GetParentFrame())->GetCurSelShow();
	if (m_nCurShow == CB_ERR)
		return;
	TabStatus();
	
}

void CModelDataView::TabStatus()
{
	//left, top, right, and bottom
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(1,1);
	if(!m_pGeneralView->GetSafeHwnd()
	||!m_pPipeView->GetSafeHwnd()
	||!m_pJunView->GetSafeHwnd())
	{
		return;
	}
	int nHeight = rc.Height();
	CRect rcTwo1(rc.left,rc.top,rc.right,rc.bottom-nHeight/2);
	CRect rcTwo2(rc.left,rc.top+nHeight/2,rc.right,rc.bottom);
	CRect rcThree1(rc.left,rc.top,rc.right,rc.bottom-nHeight*2/3);
	CRect rcThree2(rc.left,rc.top+nHeight/3,rc.right,rc.bottom-nHeight/3);
	CRect rcThree3(rc.left,rc.top+nHeight*2/3,rc.right,rc.bottom);
	m_pGeneralView->ShowWindow(SW_SHOW);
	m_pPipeView->ShowWindow(SW_SHOW);
	m_pJunView->ShowWindow(SW_SHOW);
	switch(m_nCurShow) {
	case 0:
		m_pGeneralView->MoveWindow(rcThree1);
		m_pPipeView->MoveWindow(rcThree2);
		m_pJunView->MoveWindow(rcThree3);
		break;
	case 1:
		m_pGeneralView->ShowWindow(SW_HIDE);
		m_pPipeView->MoveWindow(rcTwo1);
		m_pJunView->MoveWindow(rcTwo2);
		break;
    case 2:
		m_pGeneralView->ShowWindow(SW_HIDE);
		m_pPipeView->MoveWindow(rc);
		m_pJunView->ShowWindow(SW_HIDE);
		break;
	case 3:
		m_pGeneralView->ShowWindow(SW_HIDE);
		m_pPipeView->ShowWindow(SW_HIDE);
		m_pJunView->MoveWindow(rc);
		break;
	case 4:
		m_pGeneralView->MoveWindow(rc);
		m_pPipeView->ShowWindow(SW_HIDE);
		m_pJunView->ShowWindow(SW_HIDE);
		break;
	default:
		ASSERT(FALSE);
	}
}

void CModelDataView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	TabStatus();

	// TODO: Add your specialized code here and/or call the base class
	
}


int CModelDataView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_pGeneralView->Create(IDD_DLGTABVIEW,this);
	m_pJunView->Create(IDD_DLGTABVIEW,this);
	m_pPipeView->Create(IDD_DLGTABVIEW,this);
	return 0;
}



BOOL CModelDataView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CFormView::PreTranslateMessage(pMsg);
}
