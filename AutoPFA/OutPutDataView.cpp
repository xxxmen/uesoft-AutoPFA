// OutPutDataView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "OutPutDataView.h"
#include "AutoPFADoc.h"
#include "NetModel.h"
#include "PFAOutModel.h"
#include "Scenario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OutPutDataView

IMPLEMENT_DYNCREATE(OutPutDataView, CModelDataView)

OutPutDataView::OutPutDataView()
	: CModelDataView()
{
	//{{AFX_DATA_INIT(OutPutDataView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pPipeView = &m_PipeView;
	m_pJunView = &m_JunView;
	m_pGeneralView = &m_GeneralView;
}

OutPutDataView::~OutPutDataView()
{
}

void OutPutDataView::DoDataExchange(CDataExchange* pDX)
{
	CModelDataView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(OutPutDataView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(OutPutDataView, CModelDataView)
	//{{AFX_MSG_MAP(OutPutDataView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OutPutDataView diagnostics

#ifdef _DEBUG
void OutPutDataView::AssertValid() const
{
	CModelDataView::AssertValid();
}

void OutPutDataView::Dump(CDumpContext& dc) const
{
	CModelDataView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// OutPutDataView message handlers
void OutPutDataView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bMutex = ((CAutoPFADoc*)GetDocument())->OutMutex();
	if(bActivate && bMutex)
	{
		((CAutoPFADoc*)GetDocument())->OutMutex(FALSE);
		Scenario* pScenario = ((CAutoPFADoc*)GetDocument())->m_scenarioManager.GetCurScenario();
		PFAOutModel &outModel = ((CAutoPFADoc*)GetDocument())->m_OutModel; 
		UnitSubSystem *pUnitSys = &(((CAutoPFADoc*)GetDocument())->m_unitSystem);

		//ASSERT(pNetModel != NULL);
		m_GeneralView.LoadData( pScenario, outModel );
		m_PipeView.LoadData( pScenario, outModel, pUnitSys );
		m_JunView.LoadData( pScenario, outModel, pUnitSys );
	}
	CModelDataView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void OutPutDataView::OnInitialUpdate() 
{
	CModelDataView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
}
