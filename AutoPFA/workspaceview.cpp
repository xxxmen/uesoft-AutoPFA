// workspaceview.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "workspaceview.h"
#include "ComponentManager.h"
#include "NetModel.h"
#include "AutoPFADoc.h"
#include "Scenario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WorkSpaceView

IMPLEMENT_DYNCREATE(WorkSpaceDataView, CModelDataView)

WorkSpaceDataView::WorkSpaceDataView()
	: CModelDataView()
{
	//{{AFX_DATA_INIT(WorkSpaceView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pPipeView = &m_PipeView;
	m_pJunView = &m_JunView;
	m_pGeneralView = &m_GeneralView;
}

WorkSpaceDataView::~WorkSpaceDataView()
{
}

void WorkSpaceDataView::DoDataExchange(CDataExchange* pDX)
{
	CModelDataView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WorkSpaceView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WorkSpaceDataView, CModelDataView)
	//{{AFX_MSG_MAP(WorkSpaceView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WorkSpaceView diagnostics

#ifdef _DEBUG
void WorkSpaceDataView::AssertValid() const
{
	CModelDataView::AssertValid();
}

void WorkSpaceDataView::Dump(CDumpContext& dc) const
{
	CModelDataView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// WorkSpaceView message handlers
void WorkSpaceDataView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bMutex = ((CAutoPFADoc*)GetDocument())->Mutex();
	if(bActivate && bMutex)
	{
		((CAutoPFADoc*)GetDocument())->Mutex(FALSE);
		NetModel* pNetModel = ((CAutoPFADoc*)GetDocument())->m_scenarioManager.GetCurScenario()->GetNetModel();
		ComponentManager *pManager = ((CAutoPFADoc*)GetDocument())->m_scenarioManager.GetCurScenario()->GetCompManager();
		UnitSubSystem *pUnitSys = &(((CAutoPFADoc*)GetDocument())->m_unitSystem);
		ASSERT(pNetModel != NULL);
		ASSERT(pManager != NULL);
		m_GeneralView.LoadData(pNetModel);
		m_PipeView.LoadData(pUnitSys,pManager);
		m_JunView.LoadData(pUnitSys,pManager);
	}
	CModelDataView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
