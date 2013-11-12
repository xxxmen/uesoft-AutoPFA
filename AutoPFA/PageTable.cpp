// PageTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTable.h"
#include "dlgchart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTable dialog


PageTable::PageTable(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageTable)
	m_bRepeat = FALSE;
	//}}AFX_DATA_INIT
	m_bEnable = TRUE;
}


void PageTable::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTable)
	DDX_Check(pDX, IDC_CHECKREPEAT, m_bRepeat);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TABLE, m_list);
}


BEGIN_MESSAGE_MAP(PageTable, BaseDlg)
	//{{AFX_MSG_MAP(PageTable)
	ON_BN_CLICKED(IDC_BCHART, OnBchart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTable message handlers

void PageTable::InitList(CString strHeader)
{
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T(" "));
	m_list.InsertColumn(_T("Ê±¼ä\n(seconds)"),DT_CENTER|DT_VCENTER);
	m_list.InsertColumn(strHeader,DT_CENTER|DT_VCENTER);
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount();
	m_list.SetColumnCount(3);
	m_list.SetRowHeight(0,40);
	m_list.SetColumnWidth(1,70);
	m_list.SetColumnWidth(2,80);

	SetTableStatus(m_bEnable);
}

void PageTable::Init(const StrFlyWeight &Repeat,TransDataTable<2> &table,CString strHeader)
{
	m_bRepeat = abs(Repeat.GetnValue());
	
	InitList(strHeader);
	InitTable(table,m_list);
	UpdateData(FALSE);
}

BOOL PageTable::UpData(StrFlyWeight &Repeat,TransDataTable<2> &table)
{
	UpdateData(TRUE);
	Repeat.SetValue(m_bRepeat);
	UpDataTable(table,m_list);
	return TRUE;
}
void PageTable::Init(TransDataTable<2> &table)
{
	InitTable(table,m_list);
	UpdateData(FALSE);
}

BOOL PageTable::UpData(TransDataTable<2> &table)
{
	UpdateData(TRUE);
	UpDataTable(table,m_list);
	return TRUE;
}
void PageTable::SetTableHeader(CString strName,CString strUnit,int nCol)
{
	CString strHeader = strName +_T("\n(") + strUnit+_T(")");
	SetTableHeader(strHeader,nCol);
}

void PageTable::SetTableHeader(CString strHeader,int nCol)
{
	m_list.SetItemText(0,nCol,strHeader);
	m_list.RedrawCell(0,nCol);
}

BOOL PageTable::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageTable::ShowCheck(int nCmdShow)
{
	GetDlgItem(IDC_CHECKREPEAT)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_BCHART)->ShowWindow(nCmdShow);
}

void PageTable::EnableTable(BOOL bEnable)
{
	if(m_bEnable == bEnable)
		return;
	m_bEnable = bEnable;
	SetTableStatus(m_bEnable);
}

void PageTable::SetTableStatus(BOOL bEnable)
{
	if (bEnable)
	{
		CString strText;
		for(int i=1; i<101; i++)
		{
			strText.Format(_T("%d"),i);
			m_list.InsertRow(strText);
		}
	}
	else
	{
		m_list.DeleteNonFixedRows();
	}
}



void PageTable::RemoveData()
{
	m_list.DeleteNonFixedRows();
	SetTableStatus(TRUE);
}

void PageTable::OnBchart() 
{
	// TODO: Add your control notification handler code here
	TransDataTable<2> table;
	UpDataTable(table,m_list);
	int dat = table.m_Data.GetCount();
	if(dat > 0)
	{
		double dX[100] = {0};
		double dY[100] = {0};
		table.m_Data.GetData().ToDuoble(dX,0);
		table.m_Data.GetData().ToDuoble(dY,1);
		DlgChart dlgChart(dX,dY,dat);
		dlgChart.DoModal();
	}
}
