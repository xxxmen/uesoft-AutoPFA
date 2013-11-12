// AutoPFAView.cpp : implementation of the CAutoPFAView class
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "AutoPFADoc.h"
#include "AutoPFAView.h"
#include "ScenariManage.h"
#include "Scenario.h"
#include "ComponentManager.h"
#include "DlgWorkspaceRef.h"
#include "Manipulator.h"
#include "ZoomManipulator.h"
#include "PipeManipulator.h"
#include "DlgFind.h"
#include "DlgCScenarioManager.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView
HCURSOR CAutoPFAView::s_Cursor[23] = {NULL};
int     CAutoPFAView::s_ComopnentID[23] = {-1};

IMPLEMENT_DYNCREATE(CAutoPFAView, CScrollView)

BEGIN_MESSAGE_MAP(CAutoPFAView, CScrollView)
	//{{AFX_MSG_MAP(CAutoPFAView)
	ON_COMMAND(ID_MANAGER, OnManager)
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_WORKSPACEREF, OnWorkSpaceRef)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_COMMAND(ID_ZOOMIN, OnZoomIn)
	ON_COMMAND(ID_ZOOMOUT, OnZoomOut)
	ON_COMMAND(ID_ZOOMFIT, OnZoomFit)
	ON_COMMAND(ID_DELETE, OnDelete)
	ON_UPDATE_COMMAND_UI(ID_DELETE, OnUpdateDelete)
	ON_COMMAND(ID_REVERSE, OnReverse)
	ON_UPDATE_COMMAND_UI(ID_REVERSE, OnUpdateReverse)
	ON_COMMAND(ID_SHOWDATA, OnShowdata)
	ON_UPDATE_COMMAND_UI(ID_SHOWDATA, OnUpdateShowdata)
	ON_COMMAND(ID_DUPLICATE, OnDuplicate)
	ON_UPDATE_COMMAND_UI(ID_DUPLICATE, OnUpdateDuplicate)
	ON_COMMAND(ID_FIND, OnFind)
	ON_UPDATE_COMMAND_UI(ID_FIND, OnUpdateFind)
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_PALETTEPIPE, ID_PALETTESELCTZOOM, OnPalette)
	ON_UPDATE_COMMAND_UI_RANGE(ID_PALETTEPIPE, ID_PALETTESELCTZOOM, OnUpdatePalette)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView construction/destruction

CAutoPFAView::CAutoPFAView()
{
	// TODO: add construction code here
	s_Cursor[0] = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	s_Cursor[1] = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	s_Cursor[2] = AfxGetApp()->LoadCursor(IDC_BRANCH);
	s_Cursor[3] = AfxGetApp()->LoadCursor(IDC_RESERVIOR);
	s_Cursor[4] = AfxGetApp()->LoadCursor(IDC_ASSIGNFLOW);
	s_Cursor[5] = AfxGetApp()->LoadCursor(IDC_ASSIGNPRESS);
	s_Cursor[6] = AfxGetApp()->LoadCursor(IDC_AREACHANGE);
	s_Cursor[7] = AfxGetApp()->LoadCursor(IDC_RELIEF);
	s_Cursor[8] = AfxGetApp()->LoadCursor(IDC_TEEWYE);
	s_Cursor[9] = AfxGetApp()->LoadCursor(IDC_VALVE);
	s_Cursor[10] = AfxGetApp()->LoadCursor(IDC_CONTROL);
	s_Cursor[11] = AfxGetApp()->LoadCursor(IDC_CHECK);
	s_Cursor[12] = AfxGetApp()->LoadCursor(IDC_DEADEND);
	s_Cursor[13] = AfxGetApp()->LoadCursor(IDC_GASACCUM);
	s_Cursor[14] = AfxGetApp()->LoadCursor(IDC_SURGE);
	s_Cursor[15] = AfxGetApp()->LoadCursor(IDC_LIQUIDACCUM);
	s_Cursor[16] = AfxGetApp()->LoadCursor(IDC_BREAKER);
	s_Cursor[17] = AfxGetApp()->LoadCursor(IDC_SPRAY);
	s_Cursor[18] = AfxGetApp()->LoadCursor(IDC_PUMP);
	s_Cursor[19] = AfxGetApp()->LoadCursor(IDC_BEND);
	s_Cursor[20] = AfxGetApp()->LoadCursor(IDC_GENERAL);
	s_Cursor[21] = s_Cursor[0];
	s_Cursor[22] = s_Cursor[0];

	s_ComopnentID[0] = -1;
	s_ComopnentID[1] = Pipe::m_nTypeID;
    s_ComopnentID[2] = Branch::m_nTypeID;
	s_ComopnentID[3] = Reservoir::m_nTypeID;
	s_ComopnentID[4] = AssignedFlow::m_nTypeID;
	s_ComopnentID[5] = AssignedPressure::m_nTypeID;
	s_ComopnentID[6] = AreaChange::m_nTypeID;
	s_ComopnentID[7] = ReliefValve::m_nTypeID;
	s_ComopnentID[8] = TeeWye::m_nTypeID;
	s_ComopnentID[9] = Valve::m_nTypeID;
	s_ComopnentID[10] = ControlValve::m_nTypeID;
	s_ComopnentID[11] = CheckValve::m_nTypeID;
	s_ComopnentID[12] = DeadEnd::m_nTypeID;
	s_ComopnentID[13] = GasAccumulator::m_nTypeID;
	s_ComopnentID[14] = Surge::m_nTypeID;
	s_ComopnentID[15] = LiquidAccumulator::m_nTypeID;
	s_ComopnentID[16] = VacuumBreaker::m_nTypeID;
	s_ComopnentID[17] = SprayDischarge::m_nTypeID;
	s_ComopnentID[18] = Pump::m_nTypeID;
	s_ComopnentID[19] = Bend::m_nTypeID;
	s_ComopnentID[20] = General::m_nTypeID;
	s_ComopnentID[21] = 101;
	s_ComopnentID[22] = 102;
    m_curIndex = 0;
	m_pManipulator = NULL;
	m_pWorkSpaceRef = NULL;
	m_Scale = 1;

}

CAutoPFAView::~CAutoPFAView()
{
	
}

void CAutoPFAView::OnPalette(UINT nID)
{
	m_curIndex = nID - ID_PALETTE_BASE + 1;
	if(nID == ID_PALETTESELCTZOOM)
	{
		CreatZoomTool();
	}
}

void CAutoPFAView::OnUpdatePalette(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck((UINT)(ID_PALETTE_BASE + m_curIndex -1) == pCmdUI->m_nID);
}

BOOL CAutoPFAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView drawing

void CAutoPFAView::OnDraw(CDC* pDC)
{
	CAutoPFADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDoc->m_scenarioManager.GetCurScenario()->GetCompManager()->Draw(pDC,pDoc->m_workSpaceRef);
	if(m_pManipulator != NULL)
		m_pManipulator->DrawMark(pDC,*m_pWorkSpaceRef);
}

void CAutoPFAView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	m_pWorkSpaceRef = &GetDocument()->m_workSpaceRef;
	ReSetDocSize();
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView printing

BOOL CAutoPFAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAutoPFAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAutoPFAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView diagnostics

#ifdef _DEBUG
void CAutoPFAView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAutoPFAView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CAutoPFADoc* CAutoPFAView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoPFADoc)));
	return (CAutoPFADoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAView message handlers




BOOL CAutoPFAView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(nHitTest==HTCLIENT)
	{
		SetCursor(s_Cursor[m_curIndex]);
		return TRUE;
	}
	else
	{
		return CScrollView::OnSetCursor(pWnd, nHitTest, message);
	}
}

void CAutoPFAView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CScrollView::OnPrepareDC(pDC, pInfo);
	pDC->SetMapMode(MM_ANISOTROPIC);
	CPoint ptVpOrg(0, 0);
	ptVpOrg = -GetDeviceScrollPosition();
	pDC->SetViewportOrg(ptVpOrg);
	int xLogPixPerInch = pDC->GetDeviceCaps(LOGPIXELSX);
	int yLogPixPerInch = pDC->GetDeviceCaps(LOGPIXELSY);
	pDC->SetWindowExt(xLogPixPerInch,yLogPixPerInch);
	pDC->SetViewportExt( (int)(xLogPixPerInch*m_Scale),
		                 (int)(yLogPixPerInch*m_Scale));
	m_xWindowExt = xLogPixPerInch;
	m_yWindowExt = yLogPixPerInch;
	m_xWindowOrg = 0;
	m_xViewOrg = ptVpOrg.x;
	m_yWindowOrg = 0;
	m_yViewOrg = ptVpOrg.y;
	m_xViewExt = xLogPixPerInch*m_Scale;
	m_yViewExt = yLogPixPerInch*m_Scale;

	CAutoPFADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFont Font;
	Font.CreateFontIndirect(&pDoc->m_workSpaceRef.GetFont());
	pDC->SelectObject(&Font);
    pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextAlign(TA_CENTER);
}

void CAutoPFAView::OnMouseMove(UINT nFlags, CPoint point) 
{


	// TODO: Add your message handler code here and/or call default
	if(m_pManipulator != NULL)
	{
		CClientDC dc(this);
		OnPrepareDC(&dc);
		DPtoVP(point);
		m_pManipulator->Move(nFlags,point,&dc);
	}
	CScrollView::OnMouseMove(nFlags, point);



}

void CAutoPFAView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();
	if(m_pManipulator != NULL)
	{
		DPtoVP(point);
		m_pManipulator->UpClick(nFlags,point);
		ReSetDocSize();
	}
	else
	{
		Invalidate();
	}
	CScrollView::OnLButtonUp(nFlags, point);

	//ReleaseCapture();
}

void CAutoPFAView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	DPtoVP(point);
	if(m_pManipulator != NULL
		&&m_pManipulator->IsManipulator(point)
		&&m_curIndex == 0 || m_curIndex == 22)
	{
		//操作对象不变
	}
	else
	{
		ComponentManager *pManager = GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager();
		m_pManipulator = pManager->CreatManipulator(s_ComopnentID[m_curIndex],point,m_pWorkSpaceRef->GetJunSize());
		GetDocument()->SetModifiedFlag();
	}
	if(m_pManipulator != NULL)
	{
		m_pManipulator->DownClick(nFlags,point);
	}
//	if(MK_LBUTTON+MK_CONTROL != nFlags)
//	{
//		m_curIndex = 0;
//	}
	



	m_curIndex = 0;
	SetCapture();
	CScrollView::OnLButtonDown(nFlags, point);
	//SetCapture();
}

void CAutoPFAView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnShowdata();
	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CAutoPFAView::OnWorkSpaceRef() 
{
	// TODO: Add your command handler code here
	DlgWorkspaceRef dlg(GetDocument()->m_workSpaceRef);
	if(IDOK ==dlg.DoModal())
	{
		Invalidate();
	}
}

BOOL CAutoPFAView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	//CScrollView::OnEraseBkgnd(pDC);
	CAutoPFADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	/*
    wndbkBrush.CreateSolidBrush(RGB(128,128,128));
    wndbkBrush.DeleteObject();
    */

	CBrush wndbkBrush;
    wndbkBrush.CreateSolidBrush(pDoc->m_workSpaceRef.GetbkColor());
	FillOutsideRect(pDC,&wndbkBrush);//把组件范围外的区域也刷成客户区域背景颜色，这样看起来不会闪屏
	CRect rc(CPoint(0,0),GetTotalSize());
    pDC->FillRect(rc, &wndbkBrush);
	wndbkBrush.DeleteObject();
    return TRUE;
}

void CAutoPFAView::DPtoVP(CPoint &point)
{
	point.x = (point.x-m_xViewOrg)*m_xWindowExt/m_xViewExt+m_xWindowOrg;
	point.y = (point.y-m_yViewOrg)*m_yWindowExt/m_yViewExt+m_yWindowOrg;
}
void CAutoPFAView::VptoDP(CPoint &point)
{
	point.x = (point.x-m_xWindowOrg)*m_xViewExt/m_xWindowExt+m_xViewOrg;
	point.y = (point.y-m_yWindowOrg)*m_yViewExt/m_yWindowExt+m_yViewOrg;
}

void CAutoPFAView::ReSetDocSize()
{
	CRect rc;
	CRect rcDoc(GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager()->GetRect());
	CSize szTol(rcDoc.right,rcDoc.bottom);
	GetClientRect(rc);
	CSize szView = rc.Size();
	szTol.cx += 300;
	szTol.cy += 200;
	if(szTol.cx<szView.cx)
		szTol.cx = szView.cx;
    if(szTol.cy<szView.cy)
		szTol.cy = szView.cy;
	szTol.cx *= m_Scale;
	szTol.cy *= m_Scale;
	SetScrollSizes(MM_TEXT,szTol);
	Invalidate();
}

void CAutoPFAView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	ReSetDocSize();
	// TODO: Add your message handler code here
	
}

void CAutoPFAView::ZoomScrollSizes(const CRect &rc,BOOL bFit )//调整窗口可视区域使得大小和rc相当
{
	CRect rcView;
	GetClientRect(&rcView);
	CSize szTol(rc.Size());
	CPoint Org(rc.left,rc.top);
	CSize szDoc;
	double dDocX;
	double dDocY;
    szDoc = GetTotalSize();
    dDocX = szDoc.cx / m_Scale;
	dDocY = szDoc.cy / m_Scale;
	if(bFit)
	{
		if(szTol.cx<rcView.Size().cx)
		{
			szTol.cx = rcView.Size().cx;
		}
		if(szTol.cy<rcView.Size().cy)
		{
			szTol.cy = rcView.Size().cy;
		}
	}
    float x= float(rcView.Size().cx)/(szTol.cx);
    float y= float(rcView.Size().cy)/(szTol.cy);
	if(x>y)
		m_Scale = y;
	else
        m_Scale = x;
	
	szDoc.cx = m_Scale * dDocX;
	szDoc.cy = m_Scale * dDocY;
	if(szDoc.cx <= rcView.Size().cx)
	{
		Org.x = 0;
	}
	if(szDoc.cy <= rcView.Size().cy)
	{
		Org.y = 0;
	}
	Org.x = m_Scale* (Org.x);
    Org.y = m_Scale* (Org.y);
	SetScrollSizes(MM_TEXT,szDoc);
	ScrollToPosition(Org);
	Invalidate();
}

void CAutoPFAView::OnZoomIn() 
{
	// TODO: Add your command handler code here
	ZoomDocSize(0.8);
}

void CAutoPFAView::OnZoomOut() 
{
	// TODO: Add your command handler code here
	ZoomDocSize(1.2);
}

void CAutoPFAView::OnZoomFit() 
{
	// TODO: Add your command handler code here
	CRect rc = GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager()->GetRect();
	rc.top    -= 16;
	rc.left   -= 16;
	rc.bottom += 16;
	rc.right  += 16;
	ZoomScrollSizes(rc);
}

void CAutoPFAView::ZoomDocSize(double scale)//按scale比率放大或缩小图形
{
    CSize szDoc = GetTotalSize();
	m_Scale  *= scale;
	szDoc.cx *= scale;
	szDoc.cy *= scale;
	SetScrollSizes(MM_TEXT,szDoc);
	Invalidate();
}

void CAutoPFAView::CreatZoomTool()
{
	m_pManipulator = ZoomManipulator::Instance(this);
}

void CAutoPFAView::OnDelete() 
{
	// TODO: Add your command handler code here
	if(m_pManipulator != NULL)
	{
		Manipulator *pManipulator = m_pManipulator;
		if(IDCANCEL ==AfxMessageBox(IDS_DELCOMPONENT,MB_OKCANCEL))
		   return;
		pManipulator->Delete();
		m_pManipulator = NULL;
		Invalidate();
		GetDocument()->SetModifiedFlag();
	}
}

void CAutoPFAView::OnUpdateDelete(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bFlag = FALSE;
    if(m_pManipulator != NULL)
	{
		int nType = m_pManipulator->CetTypeID();
		if(nType==1 || nType==2 || nType ==3)
		{
			bFlag = TRUE;
		}
	}
	pCmdUI->Enable(bFlag);
}

void CAutoPFAView::OnReverse() 
{
	// TODO: Add your command handler code here
	if(m_pManipulator != NULL)
	{
		PipeManipulator *pManipulator = dynamic_cast<PipeManipulator*>(m_pManipulator);
		pManipulator->Reverse();
		Invalidate();
		GetDocument()->SetModifiedFlag();
	}
}

void CAutoPFAView::OnUpdateReverse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bFlag = FALSE;
    if(m_pManipulator != NULL)
	{
		int nType = m_pManipulator->CetTypeID();
		if(nType==1)
		{
			bFlag = TRUE;
		}
	}
	pCmdUI->Enable(bFlag);
}

void CAutoPFAView::OnShowdata() 
{
	// TODO: Add your command handler code here
	if(m_pManipulator != NULL)
	{
		Manipulator *pManipulator = m_pManipulator;
		if(m_pManipulator->DbClick(GetDocument()->m_unitSystem))
		{
			GetDocument()->SetModifiedFlag();
		}
		m_pManipulator = pManipulator;
		Invalidate();
	}
}

void CAutoPFAView::OnUpdateShowdata(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bFlag = FALSE;
    if(m_pManipulator != NULL)
	{
		int nType = m_pManipulator->CetTypeID();
		if(nType==1 || nType==2)
		{
			bFlag = TRUE;
		}
	}
	pCmdUI->Enable(bFlag);
}

void CAutoPFAView::OnDuplicate() 
{
	// TODO: Add your command handler code here
	if(m_pManipulator != NULL)
	{
		m_pManipulator = m_pManipulator->Clone();
		ReSetDocSize();
		GetDocument()->SetModifiedFlag();
	}
}

void CAutoPFAView::OnUpdateDuplicate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bFlag = FALSE;
    if(m_pManipulator != NULL)
	{
		int nType = m_pManipulator->CetTypeID();
		if(nType==1 || nType==2|| nType ==3)
		{
			bFlag = TRUE;
		}
	}
	pCmdUI->Enable(bFlag);
}

void CAutoPFAView::OnFind() 
{
	// TODO: Add your command handler code here
	ComponentManager *pManager = GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager();
	DlgFind dlg(*pManager);
	if(IDOK == dlg.DoModal())
	{
		Component *pComponent = pManager->LookUp(dlg.m_nObjectType,dlg.m_nObjectKey);
		if(pComponent != NULL)
		{
			m_pManipulator = pComponent->CreatManipulator(pManager,m_pWorkSpaceRef->GetJunSize());
		}
		else
		{
			m_pManipulator = NULL;
		}
		Invalidate();
	}
}

void CAutoPFAView::OnUpdateFind(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}



void CAutoPFAView::OnManager() 
{
	// TODO: Add your command handler code here
	DlgCScenarioManager dlg(GetDocument()->m_scenarioManager);
	dlg.DoModal();
	//工况切换时操作的组件改变
	m_pManipulator = NULL;
}

void CAutoPFAView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(bActivate)
	{
		Invalidate();
		GetDocument()->Mutex(TRUE);
	}
	m_pManipulator = NULL;
	CScrollView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}




BOOL CAutoPFAView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	CSize szPreDoc;
	szPreDoc = GetTotalSize();//取得文档大小
	CPoint ptPre = pt;
	//DPtoVP(ptPre);
	if(zDelta < 0)
	{
        ZoomDocSize(1.2);
	}
	else
	{
		ZoomDocSize(0.8);
	}

	/*
	CSize szNowDoc;
	szNowDoc = GetTotalSize();
	CPoint ptNow;
	ptNow.x = (double)szNowDoc.cx / (double)szPreDoc.cx * (double)ptPre.x;
	ptNow.y = (double)szNowDoc.cy / (double)szPreDoc.cy * (double)ptPre.y;
	//DPtoVP(ptNow);
	CPoint ptPointMove(ptNow.x - ptPre.x, ptNow.y -ptPre.y);
	//DPtoVP(ptPointMove);
	ComponentManager* pComponentManager = GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager();
	CRect rc = GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager()->GetRect();
	ptPointMove.x = ((rc.left - ptPointMove.x - 16) > 0 ? ptPointMove.x : 0) - 16;
	ptPointMove.y = ((rc.top - ptPointMove.y - 16) > 0 ? ptPointMove.y : 0) - 16;
	if(ptPointMove.x <= 0 || ptPointMove.y <= 0)
	{
		return FALSE;
	}
	Jun* pJun = NULL;
	IteratorPtr<Component> JunItPtr(pComponentManager->CreatJunIterator());
	for(JunItPtr->Fist();!JunItPtr->IsDone();JunItPtr->Next())
    {
	    pJun = dynamic_cast<Jun*>(&JunItPtr->CurrentItem());
		CPoint ptJun(pJun->CenterPt());
		ptJun.x += ptPointMove.x;
		ptJun.y += ptPointMove.y;
		pJun->ChangePosition(pComponentManager, ptJun, m_pWorkSpaceRef->GetJunSize());
	}
	*/
	//GetClientRect(&rcView);

	return TRUE;
}

