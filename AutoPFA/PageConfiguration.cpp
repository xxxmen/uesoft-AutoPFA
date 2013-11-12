// PageConfiguration.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageConfiguration.h"
#include "Configuration.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageConfiguration dialog


PageConfiguration::PageConfiguration(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageConfiguration::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageConfiguration)
	m_strBEP = _T("");
	m_strEndFlow = _T("");
	m_strK = _T("");
	m_nCalc = 0;
	m_strBEPUnit = _T("");
	m_strFlowUnit = _T("");
	//}}AFX_DATA_INIT
	m_nFlowType = 0;
}


void PageConfiguration::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageConfiguration)
	DDX_Text(pDX, IDC_EBEP, m_strBEP);
	DDX_Text(pDX, IDC_EENDFLOW, m_strEndFlow);
	DDX_Text(pDX, IDC_EK, m_strK);
	DDX_Radio(pDX, IDC_RADIOCALCBEP, m_nCalc);
	DDX_Text(pDX, IDC_STATICBEPUNIT, m_strBEPUnit);
	DDX_Text(pDX, IDC_STATICFLOWUNIT, m_strFlowUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageConfiguration, BaseDlg)
	//{{AFX_MSG_MAP(PageConfiguration)
	ON_BN_CLICKED(IDC_RADIOCALCBEP, OnRadioCalcBEP)
	ON_BN_CLICKED(IDC_RADIOUSERBEP, OnRadioUserBEP)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageConfiguration message handlers

void PageConfiguration::OnRadioCalcBEP() 
{
	// TODO: Add your control notification handler code here
	m_nCalc = 0;
	m_strBEP.Empty();
	GetDlgItem(IDC_EBEP)->SetWindowText(_T(""));
	SetCalcStatus();
}

void PageConfiguration::OnRadioUserBEP() 
{
	// TODO: Add your control notification handler code here
	m_nCalc = 1;
	SetCalcStatus();
}

void PageConfiguration::Init(Configuration &ref)
{
	m_strBEP = ref.m_BEP.GetValue();
	if(m_strBEP.IsEmpty()||m_strBEP.CollateNoCase(_T("0"))==0)
	{
		m_nCalc = 0;
	}
	else
	{
		m_nCalc = 1;
	}
	m_strK = ref.m_Affiniity.GetValue();
	m_strEndFlow = ref.m_CurveEndFlow.GetValue(1);
	SetCalcStatus();
	UpdateData(FALSE);
}
BOOL PageConfiguration::UpData(Configuration &ref)
{
	UpdateData(TRUE);
	SetNum(m_strBEP,m_strBEPUnit,ref.m_BEP);
	SetTypeNum(m_nFlowType,m_strEndFlow,m_strFlowUnit,ref.m_CurveEndFlow);
	ref.m_Affiniity.SetValue(m_strK);
	return TRUE;
	
}
void PageConfiguration::SetCalcStatus()
{
	if(m_nCalc ==0)
	{
		GetDlgItem(IDC_EBEP)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_EBEP)->EnableWindow(TRUE);
	}
}

void PageConfiguration::SetBEPUnit(CString strUnit)
{
	m_strBEPUnit = strUnit;
	GetDlgItem(IDC_STATICBEPUNIT)->SetWindowText(strUnit);
}

void PageConfiguration::SetFlowUnit(int nType,CString strUnit)
{
	m_nFlowType = nType;
	m_strFlowUnit = strUnit;
	GetDlgItem(IDC_STATICFLOWUNIT)->SetWindowText(strUnit);
}
