// DlgOneEle.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgOneEle.h"
#include "Jun.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgOneEle dialog


DlgOneEle::DlgOneEle(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgOneEle::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbEle(&m_EditEle)
{
	//{{AFX_DATA_INIT(DlgOneEle)
	m_strEle = _T("");
	m_strEleUnit = _T("");
	//}}AFX_DATA_INIT
}


void DlgOneEle::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgOneEle)
	DDX_Control(pDX, IDC_EJUNELE, m_EditEle);
	DDX_Control(pDX, IDC_CMBElEUNIT, m_cmbEle);
	DDX_Text(pDX, IDC_EJUNELE, m_strEle);
	DDX_CBString(pDX, IDC_CMBElEUNIT, m_strEleUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgOneEle, BaseDlg)
	//{{AFX_MSG_MAP(DlgOneEle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgOneEle message handlers

BOOL DlgOneEle::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbEle,m_strEleUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgOneEle::Init()
{
	InitNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
	UpdateData(FALSE);
}

BOOL DlgOneEle::UpData()
{
	UpdateData(TRUE);
	SetNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
    SetNum(m_strEle,m_strEleUnit,Jun::ms_OutletEle);
	return TRUE;
}
