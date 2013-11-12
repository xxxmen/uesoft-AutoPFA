// DlgOptProGress.cpp : implementation file
//

#include "stdafx.h"
#include "DlgOptProGress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOptProGress dialog


CDlgOptProGress::CDlgOptProGress(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOptProGress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOptProGress)
	m_strChildStep = _T("0");
	m_strParentStep = _T("0");
	//}}AFX_DATA_INIT
}

void CDlgOptProGress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOptProGress)
	DDX_Control(pDX, IDC_PROGRESS2, m_proParentStep);
	DDX_Control(pDX, IDC_PROGRESS1, m_proChildStep);
	DDX_Text(pDX, IDC_EDIT1, m_strChildStep);
	DDX_Text(pDX, IDC_EDIT2, m_strParentStep);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOptProGress, CDialog)
	//{{AFX_MSG_MAP(CDlgOptProGress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOptProGress message handlers

bool CDlgOptProGress::ProssMove(  int iKeyOfProgress, int iStep, int iPos )
{
	ASSERT( ( 0 <= iKeyOfProgress ) && ( 1 >= iKeyOfProgress ) );
	ASSERT( ( 0 <= iStep ) && ( 5000 >= iStep ) );
	ASSERT( ( -1 <= iPos ) && ( 15000 >= iPos ) );
	CProgressCtrl* pProgressCtrl = NULL;
	switch( iKeyOfProgress )
	{
	case 0: pProgressCtrl = &m_proChildStep;
		break;
	case 1: pProgressCtrl = &m_proParentStep;
		break;
	default: return false;
		break;
	}
	if( -1 != iPos )
	{
		pProgressCtrl->SetPos( iPos );
	}
	pProgressCtrl->OffsetPos( iStep );
	pProgressCtrl->StepIt();
	
	m_strChildStep.Format( _T("%d"), m_proChildStep.GetPos() );
	m_strParentStep.Format( _T("%d"), m_proParentStep.GetPos() );
	UpdateData( false );
	return true;
}

BOOL CDlgOptProGress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_proChildStep.SetRange32( 0, 10000 );
	m_proChildStep.SetPos( 0 );
	m_proChildStep.SetStep( 1 );
	m_proParentStep.SetRange32( 0, 500 );
	m_proParentStep.SetPos( 0 );
	m_proParentStep.SetStep( 1 );
	
	m_strChildStep = _T( "0" );
	m_strParentStep = _T( "0" );	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
