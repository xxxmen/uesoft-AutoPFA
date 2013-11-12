// DlgShortPipe.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgShortPipe.h"
#include "ShortPipeWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgShortPipe dialog


DlgShortPipe::DlgShortPipe(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgShortPipe::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbAreaUnit(&m_EditArea)
	,m_cmbEleUnit(&m_EditEle)
	,m_cmbInDiaUnit(&m_EditInDia)
	,m_cmbLenUnit(&m_EditLen)
{
	//{{AFX_DATA_INIT(DlgShortPipe)
	m_bModel = FALSE;
	m_strAreaUnit = _T("");
	m_strEleUnit = _T("");
	m_strInDiaUnit = _T("");
	m_strLenUnit = _T("");
	m_strArea = _T("");
	m_strEle = _T("");
	m_strFriction = _T("");
	m_strInDia = _T("");
	m_strLen = _T("");
	//}}AFX_DATA_INIT
}


void DlgShortPipe::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgShortPipe)
	DDX_Control(pDX, IDC_ELEN, m_EditLen);
	DDX_Control(pDX, IDC_EINDIA, m_EditInDia);
	DDX_Control(pDX, IDC_EFRICTION, m_EditFriction);
	DDX_Control(pDX, IDC_EELECHANFE, m_EditEle);
	DDX_Control(pDX, IDC_EAREA, m_EditArea);
	DDX_Control(pDX, IDC_CMBLEN, m_cmbLenUnit);
	DDX_Control(pDX, IDC_CMBINDIA, m_cmbInDiaUnit);
	DDX_Control(pDX, IDC_CMBELECHANGE, m_cmbEleUnit);
	DDX_Control(pDX, IDC_CMBAREA, m_cmbAreaUnit);
	DDX_Check(pDX, IDC_CHECKPIPE, m_bModel);
	DDX_CBString(pDX, IDC_CMBAREA, m_strAreaUnit);
	DDX_CBString(pDX, IDC_CMBELECHANGE, m_strEleUnit);
	DDX_CBString(pDX, IDC_CMBINDIA, m_strInDiaUnit);
	DDX_CBString(pDX, IDC_CMBLEN, m_strLenUnit);
	DDX_Text(pDX, IDC_EAREA, m_strArea);
	DDX_Text(pDX, IDC_EELECHANFE, m_strEle);
	DDX_Text(pDX, IDC_EFRICTION, m_strFriction);
	DDX_Text(pDX, IDC_EINDIA, m_strInDia);
	DDX_Text(pDX, IDC_ELEN, m_strLen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgShortPipe, BaseDlg)
	//{{AFX_MSG_MAP(DlgShortPipe)
	ON_BN_CLICKED(IDC_CHECKPIPE, OnCheckPipe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgShortPipe message handlers

BOOL DlgShortPipe::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbInDiaUnit,m_strInDiaUnit);
	InitUnitCbo(m_UnitSys,Area,m_cmbAreaUnit,m_strAreaUnit);
	InitUnitCbo(m_UnitSys,Length,m_cmbLenUnit,m_strLenUnit);
	InitUnitCbo(m_UnitSys,Length,m_cmbEleUnit,m_strEleUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgShortPipe::Init(ArrayFlyWeight<10> &ref)
{
	ShortPipeWrapper wrapper(ref);
	m_bModel = wrapper.GetModel();
	m_strFriction = wrapper.GetFriction();
	wrapper.GetDia(m_strInDia,m_strInDiaUnit);
	wrapper.GetArea(m_strArea,m_strAreaUnit);
	wrapper.GetLen(m_strLen,m_strLenUnit);
	wrapper.GetEleChange(m_strEle,m_strEleUnit);
	ModelStatus();
	UpdateData(FALSE);
}

BOOL DlgShortPipe::UpData(ArrayFlyWeight<10> &ref)
{
	UpdateData(TRUE);
	ShortPipeWrapper wrapper(ref);
	wrapper.SetModel(m_bModel);
	wrapper.SetFriction(m_strFriction);
	wrapper.SetDia(m_strInDia,m_strInDiaUnit);
	wrapper.SetArea(m_strArea,m_strAreaUnit);
	wrapper.SetLen(m_strLen,m_strLenUnit);
	wrapper.SetEleChange(m_strEle,m_strEleUnit);
	return TRUE;
}

void DlgShortPipe::OnCheckPipe() 
{
	// TODO: Add your control notification handler code here
	m_bModel = !m_bModel;
	ModelStatus();
	UpdateData(FALSE);
}

void DlgShortPipe::ModelStatus()
{
	m_EditLen.EnableWindow(m_bModel);
	m_EditInDia.EnableWindow(m_bModel);
	m_EditFriction.EnableWindow(m_bModel);
	m_EditEle.EnableWindow(m_bModel);
	m_EditArea.EnableWindow(m_bModel);
	m_cmbLenUnit.EnableWindow(m_bModel);
	m_cmbInDiaUnit.EnableWindow(m_bModel);
	m_cmbEleUnit.EnableWindow(m_bModel);
	m_cmbAreaUnit.EnableWindow(m_bModel);
	if(!m_bModel)
	{
		m_strArea.Empty();
		m_strEle.Empty();
		m_strFriction.Empty();
		m_strInDia.Empty();
		m_strLen.Empty();
	}
}
