// PageJunGraph.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageJunGraph.h"
#include "TranOutMgr.h"
#include "JunTranOut.h"
#include "UeSoftChart.h"
#include "GraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageJunGraph dialog


PageJunGraph::PageJunGraph(CWnd* pParent /*=NULL*/)
	: PageGraph(pParent)
{
	//{{AFX_DATA_INIT(PageJunGraph)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageJunGraph::DoDataExchange(CDataExchange* pDX)
{
	PageGraph::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageJunGraph)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageJunGraph, PageGraph)
	//{{AFX_MSG_MAP(PageJunGraph)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageJunGraph message handlers

BOOL PageJunGraph::OnInitDialog() 
{
	PageGraph::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CRect rc;
	m_list.GetWindowRect(rc);
	m_list.InsertColumn(0,_T(""),LVCFMT_LEFT,0);
	m_list.InsertColumn(1,_T("节点"),LVCFMT_LEFT,rc.Width());
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageJunGraph::InitData(OutMgr &mgr, OutAttrArray &Array)
{
	InitAttr(Array,1);
	JunTranOut *pOut = NULL;
	ComponentStmOut *pStmOut = NULL;
	int nCount = mgr.GetCount();
	int n=0;
	int i=0;
	CString strText;
	HTREEITEM hitem = InsertItem(_T("连接元件"),0);
	while (n<nCount)
	{//排序
		pStmOut = mgr.LookUp(i++);
		if(pStmOut != NULL)
		{
			strText.Format(_T("%d(%s)"),i-1,pStmOut->Name());
			InsertItem(strText,i-1,hitem);
			n++;
		}
	}
}

void PageJunGraph::ShowData(TranOutMgr &mgr, GraphView &view)
{
	UpdateData(TRUE);
	UeSoftChart &chart = view.GetChart();
	chart.Category(5);
	chart.Init();
	chart.SetXAXisTitle(m_pArray->GetAt(1).GetAxisTitle());
	m_pArray->GetAt(1).Unit(m_strXUnit);
	int nIndex = m_box.GetCurSel();
	if(nIndex == LB_ERR)
		return;
	nIndex = m_box.GetItemData(nIndex);
	OutDataAttr &attr = m_pArray->GetAt(nIndex);
	attr.Unit(m_strYUnit);
	chart.SetYAXisTitle(attr.GetAxisTitle());
	int nRow = m_list.GetItemCount();
	int nKey1=0;
	double *pArrayX = NULL;
	double *pArrayY = NULL;
	ComponentStmOut *pStmOut = NULL;
	ComponentTranOut *pOut = NULL;
	CString strColTitle;
	for(int i=0;i<nRow;i++)
	{
		nKey1 = _ttoi(m_list.GetItemText(i,1));
		strColTitle.Format(_T("%d"),nKey1);
		pStmOut = mgr.LookUp(nKey1);
		ASSERT(pStmOut != NULL);
		pOut = dynamic_cast<ComponentTranOut*>(pStmOut);
		if(pArrayX==NULL)
		{
			pArrayX = new double[pOut->GetArrayNum()];
			pArrayY = new double[pOut->GetArrayNum()];
			pOut->GetArrayData(pArrayX,nKey1,m_pArray->GetAt(0));
		}
		pOut->GetArrayData(pArrayY,nKey1,attr);
		chart.SetSortData(pArrayX,pArrayY,pOut->GetArrayNum());
		chart.SetColTitle(strColTitle,i+1);
	}
	delete [] pArrayX;
	delete [] pArrayY;
}
