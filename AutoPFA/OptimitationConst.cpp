// OptimitationConst.cpp : implementation file
//

#include "stdafx.h"
#include "OptimitationConst.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptimitationConst dialog


COptimitationConst::COptimitationConst(CWnd* pParent /*=NULL*/)
	: BaseDlg(COptimitationConst::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(COptimitationConst)
	m_dA = 0.0;
	m_dB = 0.0;
	m_dAlfa = 0.0;
	m_dPipeCost = 0.0;
	m_dK = 0.0;
	m_dM = 0.0;
	m_dN = 0.0;
	m_dP = 0.0;
	m_dT = 0.0;
	m_dEconomyK = 0.0;
	//}}AFX_DATA_INIT
}


void COptimitationConst::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	BaseDlg::OnFinalRelease();
}

void COptimitationConst::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptimitationConst)
	DDX_Text(pDX, IDC_EDIT1, m_dA);
	DDX_Text(pDX, IDC_EDIT2, m_dB);
	DDX_Text(pDX, IDC_EDIT3, m_dAlfa);
	DDX_Text(pDX, IDC_EDIT4, m_dPipeCost);
	DDX_Text(pDX, IDC_EDIT5, m_dK);
	DDX_Text(pDX, IDC_EDIT7, m_dM);
	DDX_Text(pDX, IDC_EDIT8, m_dN);
	DDX_Text(pDX, IDC_EDIT9, m_dP);
	DDX_Text(pDX, IDC_EDIT10, m_dT);
	DDX_Text(pDX, IDC_EDIT11, m_dEconomyK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptimitationConst, BaseDlg)
	//{{AFX_MSG_MAP(COptimitationConst)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COptimitationConst, BaseDlg)
	//{{AFX_DISPATCH_MAP(COptimitationConst)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOptimitationConst to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {B1204BA5-11BF-445A-9A30-EA4644839C6A}
static const IID IID_IOptimitationConst =
{ 0xb1204ba5, 0x11bf, 0x445a, { 0x9a, 0x30, 0xea, 0x46, 0x44, 0x83, 0x9c, 0x6a } };

BEGIN_INTERFACE_MAP(COptimitationConst, BaseDlg)
	INTERFACE_PART(COptimitationConst, IID_IOptimitationConst, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptimitationConst message handlers

BOOL COptimitationConst::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

bool COptimitationConst::OpenData(PFAOptimitationData& OptData)
{ 
	ASSERT( NULL != &OptData );

	m_dA = OptData.GetAModulus();
	m_dB = OptData.GetBModulus();
	m_dAlfa = OptData.GetAlfaModulus();
	m_dPipeCost = m_dA + pow( fabs( m_dB ), m_dAlfa );
	m_dK = OptData.GetKModulus();
	m_dM = OptData.GetMModulus();
	m_dN = OptData.GetNModulus();
	m_dP = OptData.GetRepairModulus() * 100.0;
	m_dT = OptData.GetDisinvestmentTime();
	m_dEconomyK = OptData.GetWorkExpenditure();
	UpdateData( false );
	return true;
}


bool COptimitationConst::SaveData(PFAOptimitationData& OptData)
{
	ASSERT( NULL != &OptData );

	UpdateData( true );	
	if( !( ( m_dA > 0 ) && ( m_dB > 0 ) && ( m_dAlfa > 0 ) && ( m_dK > 0 ) && ( m_dM > 0 ) && ( m_dN > 0 )
		&& ( m_dP > 0 ) && ( m_dT > 0 ) && ( m_dEconomyK > 0 ) ) )
	{
		CString strTemp = _T( "参数必须为正，请重新输入!" );
		AfxMessageBox( strTemp );
		return false;
	}

	OptData.SetAModulus( m_dA );
    OptData.SetBModulus( m_dB );
	OptData.SetAlfaModulus( m_dAlfa );
	OptData.SetKModulus( m_dK );
	OptData.SetMModulus( m_dM );
	OptData.SetNModulus( m_dN );
	OptData.SetRepairModulus( m_dP / 100.0 );
    OptData.SetDisinvestmentTime( m_dT );
	OptData.SetWorkExpenditure( m_dEconomyK );
	
	return true;
}
