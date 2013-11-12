// PageValveModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageValveModel.h"
#include "Valve.h"
#include "CurveWrapper.h"
#include "DlgValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageValveModel dialog


PageValveModel::PageValveModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageValveModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbExitPress(&m_EditExitPress)
{
	//{{AFX_DATA_INIT(PageValveModel)
	m_bCheckExit = FALSE;
	m_strCvOrK = _T("");
	m_strExitPress = _T("");
	m_nHandBook = 1;
	m_nLossType = 0;
	m_nPressType = 0;
	m_strExitPressUnit = _T("");
	//}}AFX_DATA_INIT
}


void PageValveModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageValveModel)
	DDX_Control(pDX, IDC_EEXITPRESS, m_EditExitPress);
	DDX_Control(pDX, IDC_ECVORK, m_EditCvOrK);
	DDX_Control(pDX, IDC_CMBHANDBOOK, m_cmbHandBook);
	DDX_Control(pDX, IDC_CMBEXITPRESS, m_cmbExitPress);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_Check(pDX, IDC_CHECKEXIT, m_bCheckExit);
	DDX_Text(pDX, IDC_ECVORK, m_strCvOrK);
	DDX_Text(pDX, IDC_EEXITPRESS, m_strExitPress);
	DDX_Radio(pDX, IDC_RADIOHANDBOOK, m_nHandBook);
	DDX_Radio(pDX, IDC_RADIOCONSTCV, m_nLossType);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_CBString(pDX, IDC_CMBEXITPRESS, m_strExitPressUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageValveModel, BaseDlg)
	//{{AFX_MSG_MAP(PageValveModel)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOCONSTCV, OnRadioConstCv)
	ON_BN_CLICKED(IDC_RADIOCONSTK, OnRadioConstK)
	ON_BN_CLICKED(IDC_CHECKEXIT, OnCheckExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageValveModel message handlers

BOOL PageValveModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageValveModel::Init()
{
	m_dlgBasisArea.Init(Valve::ms_BasisArea);
	CurveWrapper wrapper(Valve::ms_Curve);
	m_nLossType = wrapper.GetLossType();
	InitTypeNum(m_nPressType,m_strExitPress,m_strExitPressUnit,Valve::ms_ExitPress);
	m_strCvOrK = Valve::ms_KOrCv.GetValue();
	m_bCheckExit = abs(Valve::ms_Type.GetnValue());
	ExitPressSatus();
	InitPressUnit();
	SetLossStatus();
	UpdateData(FALSE);
}

BOOL PageValveModel::UpData()
{
	UpdateData(TRUE);
	m_dlgBasisArea.UpData(Valve::ms_BasisArea);
	CurveWrapper wrapper(Valve::ms_Curve);
	wrapper.SetLossType(m_nLossType);
	SetTypeNum(m_nPressType,m_strExitPress,m_strExitPressUnit,Valve::ms_ExitPress);
	Valve::ms_KOrCv.SetValue(m_strCvOrK);
	Valve::ms_Type.SetValue(m_bCheckExit);
	return TRUE;
}

void PageValveModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}

void PageValveModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageValveModel::OnRadioConstCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType =0;
	SetLossStatus();
}

void PageValveModel::OnRadioConstK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType =1;
	SetLossStatus();
}

void PageValveModel::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbExitPress,m_strExitPressUnit);
}

void PageValveModel::SetLossStatus()
{
	CString strText;
	if(m_nLossType==0)
	{//流量系数模型
		strText.LoadString(IDS_STRCONSTCV);
	}
	else if(m_nLossType==1)
	{//K系数模型
		strText.LoadString(IDS_STRCONSTK);
	}
	GetDlgItem(IDC_STATICCVORK)->SetWindowText(strText);
	DlgValve *pValve = dynamic_cast<DlgValve*>(GetParent()->GetParent());
	pValve->ChangeType(strText);
}

void PageValveModel::OnCheckExit() 
{
	// TODO: Add your control notification handler code her
	m_bCheckExit = !m_bCheckExit;
	ExitPressSatus();

}

void PageValveModel::ExitPressSatus()
{
	GetDlgItem(IDC_RADIOHEAD)->EnableWindow(m_bCheckExit);
	GetDlgItem(IDC_RADIOPRESS)->EnableWindow(m_bCheckExit);
	GetDlgItem(IDC_STATICEXIT)->EnableWindow(m_bCheckExit);
	m_EditExitPress.EnableWindow(m_bCheckExit);
	m_cmbExitPress.EnableWindow(m_bCheckExit);
}

CString PageValveModel::LossString()
{
	CString strRet;
	GetDlgItem(IDC_STATICCVORK)->GetWindowText(strRet);
	return strRet;
}