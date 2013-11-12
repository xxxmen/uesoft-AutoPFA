// OptControl.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "OptControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptControl dialog


COptControl::COptControl(CWnd* pParent /*=NULL*/)
	: CDialog(COptControl::IDD, pParent)
{
	EnableAutomation();
	m_iGroupBoxState = 31;         // 11111
	//{{AFX_DATA_INIT(COptControl)
	//}}AFX_DATA_INIT
}


void COptControl::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void COptControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptControl)
	DDX_Control(pDX, IDC_CHECK4, m_btnCheckFour);
	DDX_Control(pDX, IDC_CHECK3, m_btnCheckThree);
	DDX_Control(pDX, IDC_CHECK2, m_btnCheckTwo);
	DDX_Control(pDX, IDC_CHECK1, m_btnCheckOne);
	DDX_Control(pDX, IDC_COMBO1, m_cmbMethod);
	DDX_Control(pDX, IDC_EDIT7, m_MaxIniCost);
	DDX_Control(pDX, IDC_COMBO5, m_cmbITimeUnit);
	DDX_Control(pDX, IDC_COMBO4, m_cmbSTimeUnit);
	DDX_Control(pDX, IDC_COMBO3, m_cmbObj);
	DDX_Control(pDX, IDC_COMBO2, m_cmbEneCostUnit);
	DDX_Control(pDX, IDC_EDIT2, m_edtEneCostValue);
	DDX_Control(pDX, IDC_EDIT5, m_StaticText5);
	DDX_Control(pDX, IDC_EDIT4, m_StaticText4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptControl, CDialog)
	//{{AFX_MSG_MAP(COptControl)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, OnRadio8)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO9, OnRadio9)
	ON_BN_CLICKED(IDC_RADIO10, OnRadio10)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COptControl, CDialog)
	//{{AFX_DISPATCH_MAP(COptControl)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOptControl to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {4D2BC426-459C-45DA-AD79-957E5F31AC24}
static const IID IID_IOptControl =
{ 0x4d2bc426, 0x459c, 0x45da, { 0xad, 0x79, 0x95, 0x7e, 0x5f, 0x31, 0xac, 0x24 } };

BEGIN_INTERFACE_MAP(COptControl, CDialog)
	INTERFACE_PART(COptControl, IID_IOptControl, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptControl message handlers

void COptControl::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	m_cmbMethod.ResetContent();
	m_cmbMethod.AddString( _T( "现代罚函数法" ) );
	m_cmbMethod.AddString( _T( "改进的可行方向法" ) );
	m_cmbMethod.AddString( _T( "连续线性规划法" ) );
	m_cmbMethod.AddString( _T( "连续二次线性规划法" ) );
	m_cmbMethod.SetCurSel( 0 );
}

void COptControl::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_cmbMethod.ResetContent();
	m_cmbMethod.AddString( _T( "遗传算法" ) );
	m_cmbMethod.AddString( _T( "遗传算法-从连续MMFD开始" ) );
	m_cmbMethod.AddString( _T( "遗传算法-从连续MPM开始" ) );
	m_cmbMethod.AddString( _T( "遗传算法-从连续SLP开始" ) );
	m_cmbMethod.AddString( _T( "遗传算法-从连续SQP开始" ) );
	m_cmbMethod.SetCurSel( 0 );
}

void COptControl::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem( IDC_EDIT2 )->EnableWindow( false );
	GetDlgItem( IDC_COMBO2 )->EnableWindow( false );
}

BOOL COptControl::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_PageOptContralTwo.Create( IDD_PAGEOPTCONTRALTWO, this );
	CRect Temp;
	GetDlgItem( IDC_STATIC15 )->GetWindowRect( &Temp );
	Temp += CRect( -2, -17, -5, -5 );
	m_PageOptContralTwo.MoveWindow( &Temp );
	m_PageOptContralTwo.ShowWindow( false );

	this->CheckRadioButton( IDC_RADIO1, IDC_RADIO4, IDC_RADIO1 );
    this->CheckRadioButton( IDC_RADIO7, IDC_RADIO8, IDC_RADIO7 );
	this->CheckRadioButton( IDC_RADIO9, IDC_RADIO10, IDC_RADIO9 );
	this->CheckRadioButton( IDC_RADIO5, IDC_RADIO6, IDC_RADIO5 );
	OnRadio1();
	OnRadio5();
	OnRadio7();
	
	m_cmbEneCostUnit.ResetContent();
	m_cmbEneCostUnit.AddString( _T( "kW/hr" ) );
	m_cmbEneCostUnit.AddString( _T( "W/hr" ) );
	m_cmbEneCostUnit.AddString( _T( "J" ) );
	m_cmbEneCostUnit.AddString( _T( "kJ" ) );
	m_cmbEneCostUnit.SetCurSel( 0 );

	m_cmbObj.ResetContent();
	m_cmbObj.AddString( _T( "经济成本" ) );
	m_cmbObj.AddString( _T( "工程参数" ) );
	m_cmbObj.SetCurSel( 0 );

	m_cmbSTimeUnit.ResetContent();
	m_cmbSTimeUnit.AddString( _T( "年" ) );
	m_cmbSTimeUnit.AddString( _T( "月" ) );
	m_cmbSTimeUnit.AddString( _T( "日" ) );
	m_cmbSTimeUnit.AddString( _T( "时" ) );
	m_cmbSTimeUnit.AddString( _T( "分" ) );
	m_cmbSTimeUnit.AddString( _T( "秒" ) );
	m_cmbSTimeUnit.SetCurSel( 0 );

	m_cmbITimeUnit.ResetContent();
	m_cmbITimeUnit.AddString( _T( "年" ) );
	m_cmbITimeUnit.AddString( _T( "月" ) );
	m_cmbITimeUnit.AddString( _T( "日" ) );
	m_cmbITimeUnit.AddString( _T( "时" ) );
	m_cmbITimeUnit.AddString( _T( "分" ) );
	m_cmbITimeUnit.AddString( _T( "秒" ) );
	m_cmbITimeUnit.SetCurSel( 0 );

	GetDlgItem( IDC_EDIT7 )->EnableWindow( false );	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptControl::OnRadio8() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem( IDC_EDIT2 )->EnableWindow( true );
	GetDlgItem( IDC_COMBO2 )->EnableWindow( true );
}

void COptControl::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	SetEnableGroupBox( 1 );
}

void COptControl::OnRadio9() 
{
	// TODO: Add your control notification handler code here
	
}

void COptControl::OnRadio10() 
{
	// TODO: Add your control notification handler code here
	
}

void COptControl::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	int iKeyOfSelChange = m_cmbObj.GetCurSel();
	switch( iKeyOfSelChange )
	{
	    case CB_ERR: return;
			break;
		case 0: GetDlgItem( IDC_CHECK1 )->EnableWindow( true );
			GetDlgItem( IDC_CHECK2 )->EnableWindow( true );
			GetDlgItem( IDC_CHECK3 )->EnableWindow( true );
			GetDlgItem( IDC_CHECK4 )->EnableWindow( true );
			m_PageOptContralTwo.ShowWindow( false );
			SetEnableGroupBox( 31 );                   // 11111
			break;
		case 1: GetDlgItem( IDC_CHECK1 )->EnableWindow( false );
			GetDlgItem( IDC_CHECK2 )->EnableWindow( false );
			GetDlgItem( IDC_CHECK3 )->EnableWindow( false );
			GetDlgItem( IDC_CHECK4 )->EnableWindow( false );
			m_PageOptContralTwo.ShowWindow( true );
			SetEnableGroupBox( 11 );                   // 01011
			break;
		default: ASSERT( false );
			break;
	}
}


void COptControl::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	if( ( 1 == m_btnCheckThree.GetCheck() ) || ( 1 == m_btnCheckFour.GetCheck() ) )
	{
		GetDlgItem( IDC_EDIT7 )->EnableWindow( true );
	}
	else
	{
		GetDlgItem( IDC_EDIT7 )->EnableWindow( false );
	}
}

void COptControl::OnCheck4() 
{
	// TODO: Add your control notification handler code here
	if( ( 1 == m_btnCheckThree.GetCheck() ) || ( 1 == m_btnCheckFour.GetCheck() ) )
	{
		GetDlgItem( IDC_EDIT7 )->EnableWindow( true );
	}
	else
	{
		GetDlgItem( IDC_EDIT7 )->EnableWindow( false );
	}
}

bool COptControl::SetEnableGroupBox( int iGroupBox )
{
	int iState = 0;
	bool bFlag = true;
	if( m_iGroupBoxState == iGroupBox )        // 没有状态变化
	{
		return false;
	}
	
	iState = iGroupBox & 1;                    // 00001,第一个窗口
	if( iState != ( m_iGroupBoxState & 1 ) )
	{

	}

	iState = iGroupBox & 2;                     // 00010 ，第二个窗口
	if( iState != ( m_iGroupBoxState & 2 ) )
	{
		bFlag = ( iState == 2 );
		GetDlgItem( IDC_STATIC2 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO5 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO6 )->EnableWindow( bFlag );
		GetDlgItem( IDC_COMBO1 )->EnableWindow( bFlag );			
	}

	iState = iGroupBox & 4;                    // 00100 ，第三个窗口
	if( iState != ( m_iGroupBoxState & 4 ) )
	{
		bFlag = ( iState == 4 );
		GetDlgItem( IDC_STATIC4 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO7 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO8 )->EnableWindow( bFlag );
		GetDlgItem( IDC_EDIT2 )->EnableWindow( bFlag );
		GetDlgItem( IDC_COMBO2 )->EnableWindow( bFlag );
	}

	iState = iGroupBox & 8;                    // 01000
	if( iState != ( m_iGroupBoxState & 8 ) )
	{
		bFlag = ( iState == 8 );
		GetDlgItem( IDC_STATIC6 )->EnableWindow( bFlag );	
		GetDlgItem( IDC_COMBO3 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO9 )->EnableWindow( bFlag );
		GetDlgItem( IDC_RADIO10 )->EnableWindow( bFlag );	
		GetDlgItem( IDC_STATIC15 )->EnableWindow( bFlag );
		GetDlgItem( IDC_CHECK1 )->EnableWindow( bFlag );
		GetDlgItem( IDC_CHECK2 )->EnableWindow( bFlag );
		GetDlgItem( IDC_CHECK3 )->EnableWindow( bFlag );
		GetDlgItem( IDC_CHECK4 )->EnableWindow( bFlag );
		m_PageOptContralTwo.EnableWindow( bFlag );
	}

	iState = iGroupBox & 16;                    // 10000
	if( iState != ( m_iGroupBoxState & 16 ) )
	{
		bFlag = ( iState == 16 );
		GetDlgItem( IDC_STATIC7 )->EnableWindow( bFlag );
		GetDlgItem( IDC_EDIT3 )->EnableWindow( bFlag );
		GetDlgItem( IDC_COMBO4 )->EnableWindow( bFlag );
		GetDlgItem( IDC_EDIT4 )->EnableWindow( bFlag );
		GetDlgItem( IDC_EDIT5 )->EnableWindow( bFlag );
		GetDlgItem( IDC_COMBO5 )->EnableWindow( bFlag );
		GetDlgItem( IDC_EDIT7 )->EnableWindow( bFlag );
	}

	m_iGroupBoxState = iGroupBox;        // 存储状态
	return true;
}

void COptControl::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	SetEnableGroupBox( 29 );    // 11101
}

void COptControl::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	SetEnableGroupBox( 31 );     // 11111
	OnRadio5();
	GetDlgItem( IDC_RADIO6 )->EnableWindow( false );
}

void COptControl::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	SetEnableGroupBox( 31 );     // 11111
	GetDlgItem( IDC_RADIO6 )->EnableWindow( true );	
}
