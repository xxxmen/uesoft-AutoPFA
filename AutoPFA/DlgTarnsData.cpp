// DlgTarnsData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgTarnsData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTarnsData dialog


DlgTarnsData::DlgTarnsData(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgTarnsData::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgTarnsData)
	m_nValueType = -1;
	//}}AFX_DATA_INIT
	m_strType = _T("");
	m_strUnit = _T("");
}


void DlgTarnsData::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTarnsData)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Radio(pDX, IDC_RADIOABS, m_nValueType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTarnsData, BaseDlg)
	//{{AFX_MSG_MAP(DlgTarnsData)
	ON_BN_CLICKED(IDC_RADIOABS, OnRadioAbs)
	ON_BN_CLICKED(IDC_RADIOREL, OnRadioRel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTarnsData message handlers

BOOL DlgTarnsData::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRFRISTTRANS,&m_page1,IDD_TRANSTABLE);
	m_tab.AddPage(IDS_STRSECONDTRANS,&m_page2,IDD_TRANSTABLE);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgTarnsData::Init(Transient &ref,CString strType,CString strUnit)
{
	m_nValueType = ref.ValueType().GetnValue();
	m_strType = strType;
	m_strUnit = strUnit;
	CString strHeader = GetHeader();
	m_page1.Init(ref.Repeat1(),ref.m_Trans1Table,strHeader);
	m_page2.Init(ref.Repeat2(),ref.m_Trans2Table,strHeader);
	UpdateData(FALSE);
}

BOOL DlgTarnsData::UpData(Transient &ref)
{
	UpdateData(TRUE);
	ref.m_ValueType.SetValue(m_nValueType);
	ref.m_Trans1Table.m_Unit.SetValue("seconds");
	ref.m_Trans2Table.m_Unit.SetValue("seconds");
	ref.m_Trans1Table.m_Unit.SetValue(m_strUnit,1);
	ref.m_Trans2Table.m_Unit.SetValue(m_strUnit,1);
	m_page1.UpData(ref.m_Repeat1,ref.m_Trans1Table);
	m_page2.UpData(ref.m_Repeat2,ref.m_Trans2Table);
	return TRUE;
}

void DlgTarnsData::OnRadioAbs() 
{
	// TODO: Add your control notification handler code here
	m_nValueType = 0;
	m_page1.SetTableHeader(GetHeader());
	m_page2.SetTableHeader(GetHeader());
}

void DlgTarnsData::OnRadioRel() 
{
	// TODO: Add your control notification handler code here
	m_nValueType = 1;
	m_page1.SetTableHeader(GetHeader());
	m_page2.SetTableHeader(GetHeader());
}

CString DlgTarnsData::GetHeader()
{
	CString strRet;
	if(0 == m_nValueType)
	{
		strRet = m_strType;
		if(!m_strUnit.IsEmpty())
		{
			strRet += _T("\n(") + m_strUnit + _T(")");
		}
	}
	else
	{
		strRet = _T("%") + m_strType + _T("\n") + _T("ºã¶¨Á÷");
	}
	return strRet;
}

void DlgTarnsData::SetType(CString strType)
{
	m_strType = strType;
	m_page1.SetTableHeader(GetHeader());
	m_page2.SetTableHeader(GetHeader());
}

void DlgTarnsData::SetUnit(CString strUnit)
{
	m_strUnit = strUnit;
	m_page1.SetTableHeader(GetHeader());
	m_page2.SetTableHeader(GetHeader());
}

void DlgTarnsData::ChangeName(UINT nID1, UINT nID2)
{
	m_tab.SetItemTitle(nID1,0);
	m_tab.SetItemTitle(nID2,1);
}
