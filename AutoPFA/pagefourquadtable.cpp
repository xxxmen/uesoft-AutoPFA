// pagefourquadtable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagefourquadtable.h"
#include "dlgchart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageFourQuadTable dialog


PageFourQuadTable::PageFourQuadTable(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageFourQuadTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageFourQuadTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageFourQuadTable::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageFourQuadTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TABLE, m_list);
}


BEGIN_MESSAGE_MAP(PageFourQuadTable, BaseDlg)
	//{{AFX_MSG_MAP(PageFourQuadTable)
	ON_BN_CLICKED(IDC_BCAHET, OnBChart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageFourQuadTable message handlers

BOOL PageFourQuadTable::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitListHeader();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageFourQuadTable::InitListHeader()
{
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T(" ½Ç¶È "));
    m_list.InsertColumn(_T("FH"));
	m_list.InsertColumn(_T("FB"));
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount();
	m_list.SetColumnCount(3);
	m_list.SetColumnWidth(1,70);
	m_list.SetColumnWidth(2,70);
}

void PageFourQuadTable::Init(TransDataTable<3> &table,int num)
{
	ShowFB();
	InitRow(num);
	InitTable(table,m_list);
	UpdateData(FALSE);
}

BOOL PageFourQuadTable::UpData(TransDataTable<3> &table)
{
	UpdateData(TRUE);
	UpDataTable(table,m_list);
	return TRUE;
}

void PageFourQuadTable::InitRow(int Num)
{
	m_list.DeleteNonFixedRows();
	if(Num < 1)
		return;
	CString strText;
	float fStep = 360.0/(Num);
	for(int i=0; i<Num+1; i++)
	{
		strText.Format(_T("%.2f"),i*fStep);
		m_list.InsertRow(strText);
	}
	m_list.Refresh();
}

void PageFourQuadTable::ShowFB(BOOL bShow)
{
	int nWidth = 0;
	if(bShow)
	{
		nWidth = 70;
	}
	m_list.SetColumnWidth(2,nWidth);
}



void PageFourQuadTable::OnBChart() 
{
	// TODO: Add your control notification handler code here
	TransDataTable<3> table;
	UpDataTable(table,m_list);
	int dat = table.m_Data.GetCount();
	if(dat > 0)
	{
		double dX[100] = {0};
		double dY1[100] = {0};
		double dY2[100] = {0};
		table.m_Data.GetData().ToDuoble(dX,0);
		table.m_Data.GetData().ToDuoble(dY1,1);
		table.m_Data.GetData().ToDuoble(dY2,2);
		DlgChart dlgChart(dX,dY1,dY2,dat);
		dlgChart.DoModal();
	}
}
