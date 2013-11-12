// DlgRawDataTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgRawDataTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgRawDataTable dialog


DlgRawDataTable::DlgRawDataTable(CWnd* pParent /*=NULL*/)
	: CDialog(DlgRawDataTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgRawDataTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgRawDataTable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgRawDataTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TABLE, m_table);
}


BEGIN_MESSAGE_MAP(DlgRawDataTable, CDialog)
	//{{AFX_MSG_MAP(DlgRawDataTable)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgRawDataTable message handlers

void DlgRawDataTable::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here	
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(1,1);
	if(m_table.GetSafeHwnd())
	{
		m_table.MoveWindow(rc);
	}
}

void DlgRawDataTable::InsertColumn(CString strName, CString strUnit)
{
	CString strHeader = GetHeader(strName,strUnit);
	m_table.InsertColumn(strHeader,DT_CENTER|DT_VCENTER);
}

CString DlgRawDataTable::GetHeader(CString strName, CString strUnit)
{
	return GetTitle(strName,strUnit);
}

void DlgRawDataTable::SetUnit(CString strUnit, int nCol)
{
	CString strHeader = m_table.GetItemText(0,nCol);
	CString strName;
	int nIndex = strHeader.Find(_T("\n"));
	if(nIndex != -1)
	{
		strName = strHeader.Left(nIndex);
		strHeader = GetHeader(strName,strUnit);
	}
	m_table.SetItemText(0,nCol,strHeader);
	m_table.RedrawCell(0,nCol);
}

void DlgRawDataTable::SetHeader(CString strName, CString strUnit, int nCol)
{
	CString strHeader = GetHeader(strName,strUnit);
	m_table.SetItemText(0,nCol,strHeader);
	m_table.RedrawCell(0,nCol);
}

void DlgRawDataTable::TableStatus(int nColWidth,int nColHeight)
{
	m_table.SetRowHeight(0,nColHeight);
	m_table.SetFixedRowCount();
	m_table.SetFixedColumnCount();
	m_table.EnableTitleTips(FALSE);
	for(int i=1;i<m_table.GetColumnCount();i++)
	{
		m_table.SetColumnWidth(i,nColWidth);
	}
}

void DlgRawDataTable::SetDataNum(int nNum)
{
	m_table.DeleteNonFixedRows();
	CString strText;
	for(int i=1; i<nNum+1; i++)
	{
		strText.Format(_T("%d"),i);
		m_table.InsertRow(strText);
	}
}


