// DlgChangeUnit.cpp : implementation file
//

#include "stdafx.h"

#include "DlgChangeUnit.h"
#include "OutDataAttr.h"
#include "UnitSubSystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgChangeUnit dialog


DlgChangeUnit::DlgChangeUnit(OutDataAttr &attr,CWnd* pParent /*=NULL*/)
	: CDialog(DlgChangeUnit::IDD, pParent)
	,m_outAttr(attr)
{
	//{{AFX_DATA_INIT(DlgChangeUnit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgChangeUnit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgChangeUnit)
	DDX_Control(pDX, IDC_LISTUNIT, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgChangeUnit, CDialog)
	//{{AFX_MSG_MAP(DlgChangeUnit)
	//ON_LBN_DBLCLK(IDC_LISTUNIT, OnListBoxDBClick)
	ON_NOTIFY( LBN_DBLCLK,IDC_LISTUNIT,OnListBoxDBClick )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgChangeUnit message handlers

void DlgChangeUnit::OnOK() 
{
	// TODO: Add extra validation here
	int nIndex = m_list.GetCurSel();
	if(LB_ERR == nIndex)
		return;
	CString strText;
	m_list.GetText(nIndex,strText);
	m_outAttr.Unit(strText);
	CDialog::OnOK();
}

BOOL DlgChangeUnit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_list.ResetContent();
	SymbolArray array;
	UnitSubSystem &system = m_outAttr.UnitSys();
	UnitTypeID id = m_outAttr.UnitType();
	CString m_strCurSymbol = m_outAttr.Unit();
	system.FindSymbolArray(id,array);
	for(int i=0;i<array.GetSize();i++)
	{
		m_list.AddString(array.GetAt(i));
	}
	m_list.SelectString(-1,m_strCurSymbol);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgChangeUnit::OnListBoxDBClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	OnOK();
	*pResult = 0;
}