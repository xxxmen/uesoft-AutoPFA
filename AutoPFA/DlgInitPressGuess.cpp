// DlgInitPressGuess.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlginitpressguess.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgInitPressGuess dialog


DlgInitPressGuess::DlgInitPressGuess(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgInitPressGuess::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbInitGuess(&m_EditGuess)
{
	//{{AFX_DATA_INIT(DlgInitPressGuess)
	m_strGuessUnit = _T("");
	m_strInitGuess = _T("");
	m_nPressType = -1;
	//}}AFX_DATA_INIT
}


void DlgInitPressGuess::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgInitPressGuess)
	DDX_Control(pDX, IDC_EINITGUESS, m_EditGuess);
	DDX_Control(pDX, IDC_CMBRESSUNIT, m_cmbInitGuess);
	DDX_CBString(pDX, IDC_CMBRESSUNIT, m_strGuessUnit);
	DDX_Text(pDX, IDC_EINITGUESS, m_strInitGuess);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgInitPressGuess, BaseDlg)
	//{{AFX_MSG_MAP(DlgInitPressGuess)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgInitPressGuess message handlers
void DlgInitPressGuess::Init(ArrayFlyWeight<3> &ref)
{
	InitTypeNum(m_nPressType,m_strInitGuess,m_strGuessUnit,ref);
	InitPressUnit();
	UpdateData(FALSE);
}

BOOL DlgInitPressGuess::UpData(ArrayFlyWeight<3> &ref)
{
	UpdateData(TRUE);
	SetTypeNum(m_nPressType,m_strInitGuess,m_strGuessUnit,ref);
	return TRUE;
}

void DlgInitPressGuess::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbInitGuess,m_strGuessUnit);
}

void DlgInitPressGuess::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}

void DlgInitPressGuess::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

