// dlgtolerance.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgtolerance.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTolerance dialog


DlgTolerance::DlgTolerance(UnitSubSystem &UnitSys,UnitTypeID ID,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgTolerance::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cbmAbsTol(&m_EditAbsTol)
{
	//{{AFX_DATA_INIT(DlgTolerance)
	m_nTolType = 1;
	m_strRelTol = _T("");
	m_strAbsTol = _T("");
	m_strAbsTolUnit = _T("");
	//}}AFX_DATA_INIT
	m_ID = ID;
}


void DlgTolerance::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTolerance)
	DDX_Control(pDX, IDC_EABSTOL, m_EditAbsTol);
	DDX_Control(pDX, IDC_CMBABSTOLUNIT, m_cbmAbsTol);
	DDX_Radio(pDX, IDC_RADIOABSTOL, m_nTolType);
	DDX_Text(pDX, IDC_ERELTOL, m_strRelTol);
	DDX_Text(pDX, IDC_EABSTOL, m_strAbsTol);
	DDX_CBString(pDX, IDC_CMBABSTOLUNIT, m_strAbsTolUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTolerance, BaseDlg)
	//{{AFX_MSG_MAP(DlgTolerance)
	ON_BN_CLICKED(IDC_RADIOABSTOL, OnRadioAbsTol)
	ON_BN_CLICKED(IDC_RADIOABSORREL, OnRadioAbsOrRel)
	ON_BN_CLICKED(IDC_RADIOABSANDREL, OnRadioAbsAndRel)
	ON_BN_CLICKED(IDC_RADIORELTOL, OnRadioRelTol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTolerance message handlers

BOOL DlgTolerance::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,m_ID,m_cbmAbsTol,m_strAbsTolUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


	
void DlgTolerance::Init(StrFlyWeight &type,NumFlyWeight &absTol,StrFlyWeight &RelTol)
{
	m_nTolType = type.GetnValue();
	InitNum(m_strAbsTol,m_strAbsTolUnit,absTol);
	m_strRelTol = RelTol.GetValue();
	AbsTolStatus();
	UpdateData(FALSE);
}

BOOL DlgTolerance::Updata(StrFlyWeight &type,NumFlyWeight &absTol,StrFlyWeight &RelTol)
{
	UpdateData(TRUE);
	type.SetValue(m_nTolType);
	SetNum(m_strAbsTol,m_strAbsTolUnit,absTol);
	RelTol.SetValue(m_strRelTol);
	return TRUE;
}

void DlgTolerance::AbsTolStatus()
{
	BOOL bEnable = TRUE;
	if(m_nTolType == 1)
	{
		bEnable = FALSE;
	}
	GetDlgItem(IDC_STATICABS)->EnableWindow(bEnable);
	GetDlgItem(IDC_EABSTOL)->EnableWindow(bEnable);
	m_cbmAbsTol.EnableWindow(bEnable);

	bEnable = TRUE;
	if(m_nTolType == 0)
	{
		bEnable = FALSE;
	}
	GetDlgItem(IDC_ERELTOL)->EnableWindow(bEnable);
}

void DlgTolerance::OnRadioAbsTol() 
{
	// TODO: Add your control notification handler code here
	m_nTolType = 0;
	AbsTolStatus();
}

void DlgTolerance::OnRadioAbsOrRel() 
{
	// TODO: Add your control notification handler code here
	m_nTolType = 2;
	AbsTolStatus();
}

void DlgTolerance::OnRadioAbsAndRel() 
{
	// TODO: Add your control notification handler code here
	m_nTolType = 3;
	AbsTolStatus();
}

void DlgTolerance::OnRadioRelTol() 
{
	// TODO: Add your control notification handler code here
	m_nTolType = 1;
	AbsTolStatus();
}
