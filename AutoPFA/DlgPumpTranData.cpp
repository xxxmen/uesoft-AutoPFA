// DlgPumpTranData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgPumpTranData.h"
#include "UnitSubSystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPumpTranData dialog


DlgPumpTranData::DlgPumpTranData(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgPumpTranData::IDD, pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(DlgPumpTranData)
	m_strUnit = _T("");
	//}}AFX_DATA_INIT
	m_strUnit1 = _T("");
}


void DlgPumpTranData::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPumpTranData)
	DDX_Control(pDX, IDC_CMBTORQUE, m_cmbTorqueUnit);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_CBString(pDX, IDC_CMBTORQUE, m_strUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPumpTranData, BaseDlg)
	//{{AFX_MSG_MAP(DlgPumpTranData)
	ON_CBN_SELCHANGE(IDC_CMBTORQUE, OnSelchangeTorque)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPumpTranData message handlers

BOOL DlgPumpTranData::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRFOURQUAD,&m_page1,IDD_FOURQUADTABLE);
	m_tab.AddPage(IDS_STRSTARTDATA,&m_page2,IDD_TRANSTABLE);
	m_tab.Show();
	m_page2.ShowCheck(SW_HIDE);
	InitUnitCbo(m_UnitSys,Torque,m_cmbTorqueUnit,m_strUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPumpTranData::Init(PumpTransient &ref)
{
	CString strTemp;
	strTemp = ref.m_Trans1Table.m_Unit.GetValue(1);
	if(!strTemp.IsEmpty()&&strTemp.CollateNoCase(_T("None")) != 0)
		m_strUnit = strTemp;
	Show(TRUE);
	m_page2.RemoveData();
	int num = ref.FourQuadrantData().GetnValue(1);
	m_page1.Init(ref.m_FourquadTable,num);
	m_page2.Init(ref.m_Trans1Table);
	UpdateData(FALSE);
}

BOOL DlgPumpTranData::UpData(PumpTransient &ref)
{
	UpdateData(TRUE);
	ref.m_Trans1Table.m_Unit.SetValue("Precent");
	ref.m_Trans1Table.m_Unit.SetValue(m_strUnit,1);
	m_page1.UpData(ref.m_FourquadTable);
	m_page2.UpData(ref.m_Trans1Table);

	ref.m_Trans1Table.m_Unit.SetValue(m_strUnit1);
	ref.m_Trans1Table.m_Unit.SetValue(m_strUnit,1);
	return TRUE;
}

void DlgPumpTranData::ShowPage(int nIndex,BOOL bShow)
{
	m_tab.ShowPage(nIndex,bShow);
}

void DlgPumpTranData::SetCurSel(int nCur)
{
	m_tab.SetCurSel(nCur);
}

void DlgPumpTranData::Show(BOOL bEnable)
{
	CString strType1;
	CString strType;
	int nCmdShow = 0;
	if(bEnable)
	{
		nCmdShow   = SW_SHOW;
		strType1   = _T("转速");
		strType    = _T("转矩");
		m_strUnit1 = _T("Percent");
		m_strUnit  = m_UnitSys.FindCurSymbol(Torque);
	}
	else
	{
		nCmdShow   = SW_HIDE;
		strType1   = _T("时间");
		strType    = _T("转速");
		m_strUnit1 = _T("Seconds");
		m_strUnit  = _T("Percent");
		
	}
	m_page2.SetTableHeader(strType1,m_strUnit1,1);
	m_page2.SetTableHeader(strType,m_strUnit,2);
	GetDlgItem(IDC_STATICUNIT)->ShowWindow(nCmdShow);
	GetDlgItem(IDC_CMBTORQUE)->ShowWindow(nCmdShow);
}

void DlgPumpTranData::OnSelchangeTorque() 
{
	// TODO: Add your control notification handler code here
	m_strUnit = GetCmbText(m_cmbTorqueUnit);
	m_page2.SetTableHeader(_T("转矩"),m_strUnit,2);
}


