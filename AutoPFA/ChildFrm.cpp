// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "ChildFrm.h"
#include "AutoPFAView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

static UINT BASED_CODE palette[] =
{
	// same order as in the bitmap 'palette.bmp'
	ID_PALETTEPIPE,   
	ID_PALETTEBRANCH ,    
	ID_PALETTERESERVOIR  ,   
	ID_PALETTEFLOW ,              
	ID_PALETTEPRESS ,                
	ID_PALETTEAREA   ,               
	ID_PALETTERELIEF  ,             
	ID_PALETTETEE    ,              
	ID_PALETTEVALVE   ,             
	ID_PALETTECONTROL ,           
	ID_PALETTECHECK  ,              
	ID_PALETTEEND  ,                 
	ID_PALETTEGAS    ,               
	ID_PALETTESURGE   ,              
	ID_PALETTELIQUID   ,             
	ID_PALETTEBREAKER  ,             
	ID_PALETTESPRAY  ,               
	ID_PALETTEPUMP ,                 
	ID_PALETTEBEND  ,              
	ID_PALETTEGENERAL ,
	ID_PALETTESELCTDRAW,
	ID_PALETTESELCTZOOM
};
/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//cs.lpszClass=::AfxRegisterWndClass(CS_NOCLOSE);
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX|WS_MAXIMIZE;

	return TRUE;
}
void CChildFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	GetMDIFrame()->OnUpdateFrameTitle(bAddToTitle);

	if ((GetStyle() & FWS_ADDTOTITLE) == 0)
		return;     // leave child window alone!

	CDocument* pDocument = GetActiveDocument();
	if (bAddToTitle)
	{
		TCHAR szText[256+_MAX_PATH];
		if (pDocument == NULL)
			lstrcpy(szText, m_strTitle);
		else
			lstrcpy(szText, pDocument->GetTitle());
		wsprintf(szText + lstrlen(szText),_T(" - %s "),_T("¹¤×÷Çø"));

		SetWindowText(szText);
	}
}
void CChildFrame::ActivateFrame(int nCmdShow)
{
	// TODO: Modify this function to change how the frame is activated.

	nCmdShow = SW_SHOWMAXIMIZED;
	CMDIChildWnd::ActivateFrame(nCmdShow);
}


/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_workSpaceBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_workSpaceBar.LoadToolBar(IDR_WORKSPACEBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;     // fail to create
	}
	
	m_workSpaceBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_workSpaceBar,AFX_IDW_DOCKBAR_TOP);
	// TODO: Add your specialized creation code here
	if (!CreatePaletteBar())
		return -1;
	return 0;
}

BOOL CChildFrame::CreatePaletteBar()
{
	if (!m_wndPaletBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED |
		CBRS_TOP | CBRS_TOOLTIPS, ID_PALETTEBAR) ||
		!m_wndPaletBar.LoadBitmap(IDB_PALETTE) ||
		!m_wndPaletBar.SetButtons(palette,
		sizeof(palette)/sizeof(UINT)))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;       // fail to create
	}
	CRect rc(0, 0, 0, 0);
	CSize sizeMax(0, 0);
	CToolBarCtrl& bar = m_wndPaletBar.GetToolBarCtrl();
	for (int nIndex = bar.GetButtonCount() - 1; nIndex >= 0; nIndex--)
	{
		bar.GetItemRect(nIndex, rc);
		
		rc.NormalizeRect();
		sizeMax.cx = __max(rc.Size().cx, sizeMax.cx);
		sizeMax.cy = __max(rc.Size().cy, sizeMax.cy);
	}
	sizeMax.cx += 12;
	sizeMax.cy += 14;
	m_wndPaletBar.SetSizes(sizeMax, CSize(28,28));
	m_wndPaletBar.SetWindowText(_T("Palette"));
	m_wndPaletBar.EnableDocking(CBRS_ALIGN_ANY );
	
	m_wndPaletBar.SetColumns(2);
	EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndPaletBar,AFX_IDW_DOCKBAR_LEFT);
	return TRUE;
}


BOOL CChildFrame::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CMDIChildWnd::DestroyWindow();
}

void CChildFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CView* pView=(CView*)this->GetWindow(GW_CHILD);
	if(pView && pView->IsKindOf(RUNTIME_CLASS(CAutoPFAView)))
	{
		CDocument* pDoc=pView->GetDocument();
		if(pDoc)
		{
			pDoc->SaveModified();
			pDoc->OnCloseDocument();
		}
	}
}
