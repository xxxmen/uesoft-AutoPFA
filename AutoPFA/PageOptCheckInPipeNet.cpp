// PageOptCheckInPipeNet.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageOptCheckInPipeNet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageOptCheckInPipeNet dialog


CPageOptCheckInPipeNet::CPageOptCheckInPipeNet(CWnd* pParent /*=NULL*/)
	: BaseDlg(CPageOptCheckInPipeNet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageOptCheckInPipeNet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPageOptCheckInPipeNet::CPageOptCheckInPipeNet( int& iSelect )
	: BaseDlg(CPageOptCheckInPipeNet::IDD)
{
	m_piSelect = &iSelect;
}

void CPageOptCheckInPipeNet::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageOptCheckInPipeNet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageOptCheckInPipeNet, BaseDlg)
	//{{AFX_MSG_MAP(CPageOptCheckInPipeNet)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CPageOptCheckInPipeNet::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	*m_piSelect = 1;
}

void CPageOptCheckInPipeNet::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	*m_piSelect = 2;
}

BOOL CPageOptCheckInPipeNet::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	( ( CButton* )GetDlgItem( IDC_RADIO1) )->SetCheck( 1 );
	if( NULL != m_piSelect)
	{
		*m_piSelect = 1;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
