// AssignPressPage1.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "AssignPressPage1.h"
#include "AssignedPressure.h"
#include "DlgAssigPress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AssignPressPage1 dialog


AssignPressPage1::AssignPressPage1(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(AssignPressPage1::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbPressUnit(&m_EditPress)
{
	//{{AFX_DATA_INIT(AssignPressPage1)
	m_strPressUnit = _T("");
	m_strPress = _T("");
	m_nPressType = 0;
	//}}AFX_DATA_INIT
}


void AssignPressPage1::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AssignPressPage1)
	DDX_Control(pDX, IDC_EPRESS, m_EditPress);
	DDX_Control(pDX, IDC_CMBPRESSUNIT, m_cmbPressUnit);
	DDX_CBString(pDX, IDC_CMBPRESSUNIT, m_strPressUnit);
	DDX_Text(pDX, IDC_EPRESS, m_strPress);
	DDX_Radio(pDX, IDC_RADIOSTAG, m_nPressType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AssignPressPage1, BaseDlg)
	//{{AFX_MSG_MAP(AssignPressPage1)
	ON_BN_CLICKED(IDC_RADIOSTAG, OnRadioStag)
	ON_BN_CLICKED(IDC_RADIOSTATIC, OnRadioStatic)
	ON_CBN_SELCHANGE(IDC_CMBPRESSUNIT, OnSelchangePressunit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AssignPressPage1 message handlers

BOOL AssignPressPage1::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Pressure,m_cmbPressUnit,m_strPressUnit);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void AssignPressPage1::OnRadioStag() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	DlgAssigPress *pAssigPress = dynamic_cast<DlgAssigPress*>(GetParent()->GetParent());
	pAssigPress->ChangePressType(PressType(),PressString());
}

void AssignPressPage1::OnRadioStatic() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	DlgAssigPress *pAssigPress = dynamic_cast<DlgAssigPress*>(GetParent()->GetParent());
	pAssigPress->ChangePressType(PressType(),PressString());
}

void AssignPressPage1::Init()
{
	InitTypeNum(m_nPressType,m_strPress,m_strPressUnit,AssignedPressure::ms_Pressure);
	UpdateData(FALSE);
}

BOOL AssignPressPage1::UpData()
{
	UpdateData(TRUE);
	SetTypeNum(m_nPressType,m_strPress,m_strPressUnit,AssignedPressure::ms_Pressure);
	return TRUE;
}

void AssignPressPage1::OnSelchangePressunit() 
{
	// TODO: Add your control notification handler code here
	DlgAssigPress *pAssigPress = dynamic_cast<DlgAssigPress*>(GetParent()->GetParent());
	pAssigPress->ChangeUnit(PressUnit());
}

UnitTypeID AssignPressPage1::PressType()
{
	return Pressure;
}

CString AssignPressPage1::PressUnit()
{
	return GetCmbText(m_cmbPressUnit);
}

CString AssignPressPage1::PressString()
{
	CString strRet;
	if(0 == m_nPressType)
	{
		strRet = _T("÷Õ÷π—π¡¶");
	}
	else
	{
		strRet = _T("æ≤Ã¨—π¡¶");
	}
	return strRet;
}

