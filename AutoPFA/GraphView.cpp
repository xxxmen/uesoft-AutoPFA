// GraphView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "GraphView.h"
#include "AutoPFADoc.h"
#include "DlgSelGraphData.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GraphView

IMPLEMENT_DYNCREATE(GraphView, CFormView)

GraphView::GraphView()
	: CFormView(GraphView::IDD)
	,m_UEChart(m_MsChart)
{
	//{{AFX_DATA_INIT(GraphView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

GraphView::~GraphView()
{
}

void GraphView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GraphView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MSCHART1, m_MsChart);
}


BEGIN_MESSAGE_MAP(GraphView, CFormView)
	//{{AFX_MSG_MAP(GraphView)
	ON_WM_SIZE()
	ON_COMMAND(ID_SELGRAPHDATA, OnSelGraph)
	ON_UPDATE_COMMAND_UI(ID_SELGRAPHDATA, OnUpdateSelGraph)
	ON_COMMAND(ID_COPYDATA, OnCopyData)
	ON_UPDATE_COMMAND_UI(ID_COPYDATA, OnUpdateCopyData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GraphView diagnostics

#ifdef _DEBUG
void GraphView::AssertValid() const
{
	CFormView::AssertValid();
}

void GraphView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// GraphView message handlers
void GraphView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if(m_MsChart.GetSafeHwnd())
	{
		m_MsChart.MoveWindow(2,2,cx-10,cy-10);
	}
}

void GraphView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_UEChart.Init();
}

void GraphView::OnSelGraph() 
{
	// TODO: Add your command handler code here
	DlgSelGraphData dlg(*this,GetDocument()->m_OutModel);
	dlg.DoModal();
}

void GraphView::OnUpdateSelGraph(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetDocument()->m_OutModel.HasTranData());
}

void GraphView::OnCopyData() 
{
	// TODO: Add your command handler code here
	static TCHAR BASED_CODE szFilter[] = _T("Í¼±íÊý¾Ý(*.txt)|*.txt|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE,_T("txt"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
	if(IDOK == dlg.DoModal())
	{
		CStdioFile File;
		if(File.Open(dlg.GetPathName(),CFile::modeWrite|CFile::modeCreate|CFile::typeText))
		{
			m_UEChart.Save(File);
			File.Close();
		}
	}
}

void GraphView::OnUpdateCopyData(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_UEChart.HadData());
}
