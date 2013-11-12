// PageSurgeOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageSurgeOption.h"
#include "Surge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSurgeOption dialog


PageSurgeOption::PageSurgeOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageSurgeOption::IDD, pParent)
	,m_DlgInitGuess(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbHeight(&m_EditHeight)
{
	//{{AFX_DATA_INIT(PageSurgeOption)
	m_bInitHeight = FALSE;
	m_strHeightUnit = _T("");
	m_strHeight = _T("");
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageSurgeOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSurgeOption)
	DDX_Control(pDX, IDC_EINITHEIGHT, m_EditHeight);
	DDX_Control(pDX, IDC_CMBHEIGHT, m_cmbHeight);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Check(pDX, IDC_CHECKINITHEIGHT, m_bInitHeight);
	DDX_CBString(pDX, IDC_CMBHEIGHT, m_strHeightUnit);
	DDX_Text(pDX, IDC_EINITHEIGHT, m_strHeight);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSurgeOption, BaseDlg)
	//{{AFX_MSG_MAP(PageSurgeOption)
	ON_BN_CLICKED(IDC_CHECKINITHEIGHT, OnCheckInitHeight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSurgeOption message handlers

BOOL PageSurgeOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DlgInitGuess.Create(IDD_DLGINITPRESSGUESS,this);
	Combine(this,m_Box,m_DlgInitGuess);
	InitUnitCbo(m_UnitSys,Length,m_cmbHeight,m_strHeightUnit);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageSurgeOption::Init()
{
	int iType = 0;
	m_DlgInitGuess.Init(Jun::ms_InitGuess);
	InitTypeNum(iType,m_strHeight,m_strHeightUnit,Surge::ms_InitSurfaceH);
	if (0 == iType)
	{
		m_bInitHeight = FALSE;
	}
	else
	{
		m_bInitHeight = TRUE;
	}
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	if(m_nSpecial != 0)
		m_nSpecial -= 2;

	SetInitHeightStatus();
	UpdateData(FALSE);
}

BOOL PageSurgeOption::UpData()
{
	UpdateData(TRUE);
	if(m_nSpecial != 0)
		m_nSpecial += 2;
	SetTypeNum(m_bInitHeight,m_strHeight,m_strHeightUnit,Surge::ms_InitSurfaceH);
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	return m_DlgInitGuess.UpData(Jun::ms_InitGuess);
}


void PageSurgeOption::OnCheckInitHeight() 
{
	// TODO: Add your control notification handler code here
	m_bInitHeight = !m_bInitHeight;
	SetInitHeightStatus();
}

void PageSurgeOption::SetInitHeightStatus()
{
	m_EditHeight.EnableWindow(m_bInitHeight);
	m_cmbHeight.EnableWindow(m_bInitHeight);
}
