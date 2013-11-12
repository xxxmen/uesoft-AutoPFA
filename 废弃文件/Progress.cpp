// Progress.cpp : implementation file
//

#include "stdafx.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgress dialog


CProgress::CProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CProgress::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CProgress)
	m_strChildStep = _T("0");
	m_strParentStep = _T("0");
	//}}AFX_DATA_INIT
}


void CProgress::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgress)
	DDX_Control(pDX, IDC_PROGRESS2, m_proParentStep);
	DDX_Control(pDX, IDC_PROGRESS1, m_proChildStep);
	DDX_Text(pDX, IDC_EDIT1, m_strChildStep);
	DDX_Text(pDX, IDC_EDIT2, m_strParentStep);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgress, CDialog)
	//{{AFX_MSG_MAP(CProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProgress, CDialog)
	//{{AFX_DISPATCH_MAP(CProgress)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IProgress to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EB392B2E-82AB-4831-92EC-39C4159FB7D1}
static const IID IID_IProgress =
{ 0xeb392b2e, 0x82ab, 0x4831, { 0x92, 0xec, 0x39, 0xc4, 0x15, 0x9f, 0xb7, 0xd1 } };

BEGIN_INTERFACE_MAP(CProgress, CDialog)
	INTERFACE_PART(CProgress, IID_IProgress, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgress message handlers

BOOL CProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_proChildStep.SetRange32( 0, 10000 );
	m_proChildStep.SetPos( 0 );
	m_proChildStep.SetStep( 1 );
	m_proParentStep.SetRange32( 0, 5000 );
	m_proParentStep.SetPos( 0 );
	m_proParentStep.SetStep( 1 );

	m_strChildStep = _T( "0" );
	m_strParentStep = _T( "0" );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


bool CProgress::ProssMove( int iKeyOfProgress, int iStep, int iPos )
{
	return false;
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

	m_strChildStep.Format( "%d", m_proChildStep.GetPos() );
	m_strParentStep.Format( "%d", m_proParentStep.GetPos() );
	UpdateData( true );
	//Invalidate( false );
	//ValidateRect( &CRect( 38, 39, 314, 52 ) );
	//ValidateRect( &CRect( 38, 86, 314, 99 ) );
	return true;
}
