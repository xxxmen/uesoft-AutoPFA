// PagePipeGraph.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePipeGraph.h"
#include "TranOutMgr.h"
#include "PipeTranOut.h"
#include "UeSoftChart.h"
#include "GraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePipeGraph dialog


PagePipeGraph::PagePipeGraph(CWnd* pParent /*=NULL*/)
	: PageGraph(pParent)
{
	//{{AFX_DATA_INIT(PagePipeGraph)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PagePipeGraph::DoDataExchange(CDataExchange* pDX)
{
	PageGraph::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePipeGraph)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PagePipeGraph, PageGraph)
	//{{AFX_MSG_MAP(PagePipeGraph)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePipeGraph message handlers

void PagePipeGraph::InitData(OutMgr &mgr, OutAttrArray &Array)
{
	InitAttr(Array);
	PipeTranOut *pOut = NULL;
	ComponentStmOut *pStmOut = NULL;
	StationOut *pStation = NULL;
	int nCount = mgr.GetCount();
	int n=0;
	int i=0;
	CString strText;
	while (n<nCount)
	{//排序
		pStmOut = mgr.LookUp(i++);
		if(pStmOut != NULL)
		{
			strText.Format(_T("%d(管道)"),i-1);
			HTREEITEM hitem = InsertItem(strText,i-1);
			pOut = dynamic_cast<PipeTranOut*>(pStmOut);
			ASSERT(pOut != NULL);
			pStation = pOut->GetStationOut();
			ASSERT(pStation != NULL);
			IteratorPtr<StationStmOut> iteratorPtr(pStation->CreatIterator());
			for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
			{
				pStmOut = &iteratorPtr->CurrentItem();
// 				strText.Format(_T("位置(%d)"),pStmOut->Key())
// 				InsertItem(strText,pStmOut->Key(),hitem);
				strText.Format(_T("位置(%d)"),pStmOut->GetnValue(29));
				InsertItem(strText,pStmOut->GetnValue(29),hitem);//在StationStmOut类中Key()只是管子的Key。在这里取位置作为关键字。

			}
			n++;
		}
	}
}


BOOL PagePipeGraph::OnInitDialog() 
{
	PageGraph::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	m_list.GetWindowRect(rc);
	m_list.InsertColumn(0,_T("管道"),LVCFMT_LEFT,rc.Width()/2);
	m_list.InsertColumn(1,_T("位置"),LVCFMT_LEFT,rc.Width()/2);
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PagePipeGraph::ShowData(TranOutMgr &mgr,GraphView &view)
{
	UpdateData(TRUE);
	UeSoftChart &chart = view.GetChart();
	chart.Category(5);
	chart.Init();
	chart.SetXAXisTitle(m_pArray->GetAt(9).GetAxisTitle());
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
	int nKey2=0;
	double *pArrayX = NULL;
	double *pArrayY = NULL;
	ComponentStmOut *pStmOut = NULL;
	ComponentTranOut *pOut = NULL;
	CString strColTitle;
	for(int i=0;i<nRow;i++)
	{
		nKey1 = _ttoi(m_list.GetItemText(i,0));
		nKey2 = _ttoi(m_list.GetItemText(i,1));
		strColTitle.Format(_T("%d--%d"),nKey1,nKey2);
		pStmOut = mgr.LookUp(nKey1);
		ASSERT(pStmOut != NULL);
		pOut = dynamic_cast<ComponentTranOut*>(pStmOut);
		if(pArrayX==NULL)
		{
			pArrayX = new double[pOut->GetArrayNum()];
			pArrayY = new double[pOut->GetArrayNum()];
			pOut->GetArrayData(pArrayX,nKey2,m_pArray->GetAt(9));
		}
		pOut->GetArrayData(pArrayY,nKey2,attr);
		chart.SetSortData(pArrayX,pArrayY,pOut->GetArrayNum());
		chart.SetColTitle(strColTitle,i+1);
	}
	delete [] pArrayX;
	delete [] pArrayY;
}