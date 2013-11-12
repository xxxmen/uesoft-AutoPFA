// PageControlOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageControlOption.h"
#include "Jun.h"
#include "ControlValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageControlOption dialog


PageControlOption::PageControlOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageControlOption::IDD, pParent)
	,m_dlgOption(UnitSys)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PageControlOption)
	m_nSpecial = -1;
	m_strAreaUnit = _T("");
	//}}AFX_DATA_INIT
}


void PageControlOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageControlOption)
	DDX_Control(pDX, IDC_CMBAREAUNIT, m_cmbAreaUnit);
	DDX_Control(pDX, IDC_CVDATA, m_CvBox);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	DDX_CBString(pDX, IDC_CMBAREAUNIT, m_strAreaUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageControlOption, BaseDlg)
	//{{AFX_MSG_MAP(PageControlOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageControlOption message handlers

BOOL PageControlOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	m_CvData.Create(IDD_RAWDATATABLE,this);
	Combine(this,m_CvBox,m_CvData);
	m_CvData.InsertColumn(_T(" "),_T(""));
	m_CvData.InsertColumn(_T("打开百分比"),_T(""));
	m_CvData.InsertColumn(_T("Cv"),_T(""));
	m_CvData.InsertColumn(_T("有效面积"),_T(""));
	m_CvData.TableStatus(73,20);
	m_CvData.SetDataNum(100);

	InitUnitCbo(m_UnitSys,Area,m_cmbAreaUnit,m_strAreaUnit);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageControlOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	CString strUnit = ControlValve::ms_KorCvData.Unit().GetValue(2);
	if(!strUnit.IsEmpty()&&strUnit.CollateNoCase(_T("None")) != 0)
		m_strAreaUnit = strUnit;
	m_CvData.Init(ControlValve::ms_KorCvData);
	UpdateData(FALSE);
}

BOOL PageControlOption::UpData()
{
	UpdateData(TRUE);
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	ControlValve::ms_KorCvData.m_Unit.SetValue(m_strAreaUnit,2);
	m_CvData.UpData(ControlValve::ms_KorCvData);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

