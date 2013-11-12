// DlgOptCheckIn.cpp : implementation file
/************************************************************************
版本: 8.0  开发时间: 2008/06  作者: COM 

功能: 导入数据到管网中,还没有完成  
                                                        
输入:   
                                                            
输出:   
                                                           
< 修改人 >    < 时间 >     < 版本 >        < 描述 > 
COM           2008/06       8.0.0          创建                                                                              
************************************************************************/


#include "stdafx.h"
#include "autopfa.h"
#include "DlgOptCheckIn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOptCheckIn dialog


CDlgOptCheckIn::CDlgOptCheckIn(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOptCheckIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOptCheckIn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDlgOptCheckIn::CDlgOptCheckIn( int& iSelect )
	: CDialog(CDlgOptCheckIn::IDD),m_PagePipeNet( iSelect )
{
	m_piSelect = &iSelect;
}



void CDlgOptCheckIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOptCheckIn)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOptCheckIn, CDialog)
	//{{AFX_MSG_MAP(CDlgOptCheckIn)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOptCheckIn message handlers

BOOL CDlgOptCheckIn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_PagePipeNet.Create( IDD_PAGEOPTCHECKIN_PIPENET, this );
	CRect ClientRect;
	GetWindowRect( &ClientRect );
	ClientRect += CRect( 15, 60, 0, 0 );
	ClientRect.left = 22;
	ClientRect.top = 100;
	ClientRect.right = ClientRect.left + 230;
	ClientRect.bottom = ClientRect.top + 75;
	m_PagePipeNet.MoveWindow( &ClientRect );
	m_PagePipeNet.ShowWindow( SW_SHOW );
	m_PagePipeNet.EnableWindow( true );

	( ( CButton* )GetDlgItem( IDC_RADIO1) )->SetCheck( 1 );   // 默认选定管网
	                                                                   
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgOptCheckIn::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_PagePipeNet.ShowWindow( SW_SHOW );
}

void CDlgOptCheckIn::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_PagePipeNet.ShowWindow( SW_HIDE );
}
