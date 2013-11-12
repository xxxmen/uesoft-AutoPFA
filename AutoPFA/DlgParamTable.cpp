// DlgParamTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgParamTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgParamTable dialog


DlgParamTable::DlgParamTable(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgParamTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgParamTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgParamTable::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgParamTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TABLE, m_table);
}


BEGIN_MESSAGE_MAP(DlgParamTable, BaseDlg)
	//{{AFX_MSG_MAP(DlgParamTable)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgParamTable message handlers

void DlgParamTable::OnSize(UINT nType, int cx, int cy) 
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




BOOL DlgParamTable::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitTable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgParamTable::InitTable()
{
	m_table.InsertColumn(_T(" "));
	m_table.InsertRow(_T("a"));
	m_table.InsertRow(_T("b"));
	m_table.InsertRow(_T("c"));
	m_table.InsertRow(_T("d"));
	m_table.InsertRow(_T("e"));
	m_table.SetFixedRowCount();
	m_table.SetFixedColumnCount();
	m_table.SetEditable(FALSE);
	m_table.EnableTitleTips(FALSE);
}

void DlgParamTable::SetParam(double dParam[],int nNum,int nCol)
{
	CString strText;
	strText.Empty();
    int i;
	for( i=1;i<6;i++)
	{
		m_table.SetItemText(i,nCol,strText);
	}
	
	for(i=1;i<nNum+1;i++)
	{
		strText.Format(_T("%.20f"),dParam[i-1]);
		strText.TrimRight(_T('0'));
	    strText.TrimRight(_T('.'));
		m_table.SetItemText(i,nCol,strText);
	}
	m_table.RedrawColumn(nCol);
}
