// DlgBasisArea.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgBasisArea.h"
#include "AreaChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgBasisArea dialog


DlgBasisArea::DlgBasisArea(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgBasisArea::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbUnit(&m_EditValue)
{
	//{{AFX_DATA_INIT(DlgBasisArea)
	m_strValue = _T("");
	m_strUnit = _T("");
	//}}AFX_DATA_INIT
	m_nRefType = 0;
}


void DlgBasisArea::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgBasisArea)
	DDX_Control(pDX, IDC_EDIAORAREA, m_EditValue);
	DDX_Control(pDX, IDC_CMBDIAORAREAUNIT, m_cmbUnit);
	DDX_Control(pDX, IDC_CMBREFTYPE, m_cmbRefType);
	DDX_Text(pDX, IDC_EDIAORAREA, m_strValue);
	DDX_CBString(pDX, IDC_CMBDIAORAREAUNIT, m_strUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgBasisArea, BaseDlg)
	//{{AFX_MSG_MAP(DlgBasisArea)
	ON_CBN_SELCHANGE(IDC_CMBREFTYPE, OnSelchangeType)
	ON_CBN_SELCHANGE(IDC_CMBDIAORAREAUNIT, OnSelchangeCmbdiaorareaunit)
	ON_EN_CHANGE(IDC_EDIAORAREA, OnChangeEdiaorarea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgBasisArea message handlers

BOOL DlgBasisArea::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgBasisArea::InitAreaOrEleUnit()
{
	if(3== m_nRefType)
	{
		InitUnitCbo(m_UnitSys,Diameter,m_cmbUnit,m_strUnit);
	}
	else
	{
		InitUnitCbo(m_UnitSys,Area,m_cmbUnit,m_strUnit);
	}
	SetControlStatus();
}

void DlgBasisArea::Init(ArrayFlyWeight<3> &ref)
{
	InitTypeNum(m_nRefType,m_strValue,m_strUnit,ref);

	InitDataCmb(Jun::ms_BasisArea,4,m_cmbRefType,m_nRefType);
	InitAreaOrEleUnit();
	UpdateData(FALSE);
}

BOOL DlgBasisArea::UpData(ArrayFlyWeight<3> &ref)
{
 	UpdateData(TRUE);
	SetTypeNum(m_nRefType,m_strValue,m_strUnit,ref);
	return TRUE;
}

void DlgBasisArea::OnSelchangeType() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetCurKey(m_cmbRefType,m_nRefType);
	InitAreaOrEleUnit();
}

void DlgBasisArea::SetControlStatus()
{
	switch(m_nRefType) {
	case 0: 
	case 1: 
		m_EditValue.EnableWindow(FALSE);
		m_cmbUnit.EnableWindow(FALSE);
		break;
	default:
		m_EditValue.EnableWindow(TRUE);
		m_cmbUnit.EnableWindow(TRUE);
		break;
	}
}

void DlgBasisArea::UpUnit()
{
	double India = 0;
	int Index = m_cmbUnit.GetCurSel();
	if(CB_ERR == Index)
		return;
	m_cmbUnit.GetLBText(m_cmbUnit.GetCurSel(),m_strUnit);
	switch(m_nRefType){
	case 0: 
	case 1: 
		break;
	case 2:
		India = _tcstod(m_strValue, NULL );
		if(m_strUnit == _T("cm2"))
			India = India * 0.0001;
		else
			if(m_strUnit == _T("mm2"))
				India = India * 0.000001;
			else
				if(m_strUnit == _T("feet2"))
					India =India * 0.0929;
				else
					if(m_strUnit == _T("inches2"))
						India = India * 0.000645;
					break;
	case 3:
		India = _tcstod(m_strValue, NULL );
		if(m_strUnit == _T("cm"))
			India = India * 0.01;
		else
			if(m_strUnit == _T("mm"))
				India = India * 0.001;
			else
				if(m_strUnit == _T("feet"))
					India =India * 0.3048;
				else
					if(m_strUnit == _T("inches"))
						India = India * 0.0254;
					else
						if(m_strUnit == _T("microinches"))
							India = India * 2.54E-8;
						break;
	default:
		break;
	}
	m_BaseArea.Empty();
	m_BaseArea.Format(_T("%f"),India);
//	UpdateData( FALSE ) ;
}

void DlgBasisArea::OnSelchangeCmbdiaorareaunit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	UpUnit();
}

void DlgBasisArea::OnChangeEdiaorarea() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_EditValue.GetWindowText(m_strValue);
	UpUnit();
}
