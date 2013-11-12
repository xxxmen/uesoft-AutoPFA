// DlgOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgoption.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgOption dialog


DlgOption::DlgOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgOption::IDD, pParent)
	,m_DlgInitGuess(UnitSys)
{
	//{{AFX_DATA_INIT(DlgOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgOption)
	DDX_Control(pDX, IDC_BOX2, m_Box2);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgOption, BaseDlg)
	//{{AFX_MSG_MAP(DlgOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgOption message handlers

BOOL DlgOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DlgInitGuess.Create(IDD_DLGINITPRESSGUESS,this);
	Combine(this,m_Box1,m_DlgInitGuess);
	m_dlgDesignFactor.Create(IDD_DESIGNFACTOR,this);
	Combine(this,m_Box2,m_dlgDesignFactor);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL DlgOption::UpData(ArrayFlyWeight<3> &ref1,StrFlyWeight &ref2)
{
	m_DlgInitGuess.UpData(ref1);
	m_dlgDesignFactor.UpData(ref2);
	return TRUE;
}
void DlgOption::Init(ArrayFlyWeight<3> &ref1,StrFlyWeight &ref2)
{
	m_DlgInitGuess.Init(ref1);
	m_dlgDesignFactor.Init(ref2);
}

void DlgOption::SetDesignCaption(CString strCaption)
{
	m_dlgDesignFactor.SetDesignCaption(strCaption);
}
