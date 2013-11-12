// DlgGraphRef.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgGraphRef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGraphRef dialog


DlgGraphRef::DlgGraphRef(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgGraphRef::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgGraphRef)
	//}}AFX_DATA_INIT
	m_nJunSize = 1;
}


void DlgGraphRef::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGraphRef)
	DDX_Control(pDX, IDC_RADIO75, m_Radio75);
	DDX_Control(pDX, IDC_RADIO50, m_Radio50);
	DDX_Control(pDX, IDC_RADIO25, m_Radio25);
	DDX_Control(pDX, IDC_CBOTHICH, m_pipeThick);
	DDX_Control(pDX, IDC_RADIO100, m_Radio100);
	DDX_Control(pDX, IDC_STATIC1, m_Bitmap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGraphRef, BaseDlg)
	//{{AFX_MSG_MAP(DlgGraphRef)
	ON_BN_CLICKED(IDC_RADIO25, OnRadio25)
	ON_BN_CLICKED(IDC_RADIO50, OnRadio50)
	ON_BN_CLICKED(IDC_RADIO75, OnRadio75)
	ON_BN_CLICKED(IDC_RADIO100, OnRadio100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGraphRef message handlers

BOOL DlgGraphRef::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strText;
	for(int i=1;i<11;i++)
	{
		strText.Format(_T("%d"),i);
		m_pipeThick.InsertString(i-1,strText);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGraphRef::OnRadio25() 
{
	// TODO: Add your control notification handler code here
	m_bitmap.DeleteObject();
    m_bitmap.LoadBitmap(IDB_RESVIOR25);
	m_Bitmap.SetBitmap(m_bitmap);
	m_nJunSize = 25;
	UnCheck();
	m_Radio25.SetCheck(1);
}

void DlgGraphRef::OnRadio50() 
{
	// TODO: Add your control notification handler code here
	m_bitmap.DeleteObject();
    m_bitmap.LoadBitmap(IDB_RESVIOR50);
	m_Bitmap.SetBitmap(m_bitmap);
	m_nJunSize = 50;
	UnCheck();
	m_Radio50.SetCheck(1);
}

void DlgGraphRef::OnRadio75() 
{
	// TODO: Add your control notification handler code here
	m_bitmap.DeleteObject();
    m_bitmap.LoadBitmap(IDB_RESVIOR75);
	m_Bitmap.SetBitmap(m_bitmap);
	m_nJunSize = 75;
	UnCheck();
	m_Radio75.SetCheck(1);
}

void DlgGraphRef::OnRadio100() 
{
	// TODO: Add your control notification handler code here
	m_bitmap.DeleteObject();
    m_bitmap.LoadBitmap(IDB_RESVIOR);
	m_Bitmap.SetBitmap(m_bitmap);
	m_nJunSize = 100;
	UnCheck();
	m_Radio100.SetCheck(1);
}

void DlgGraphRef::Init(WorkSpaceRef &ref)
{
	m_pWorkSpaceRef = &ref;
	m_nJunSize = ref.GetJunSize();
	switch(m_nJunSize)
	{
	case 100:
		OnRadio100();
		break;
	case 50:
		OnRadio50();
		break;
	case 75:
		OnRadio75();
		break;
	case 25:
		OnRadio25();
		break;
	default:
		OnRadio100();
		break;
	}
	m_pipeThick.SetCurSel(ref.GetPipeThick()-1);
}

BOOL DlgGraphRef::Updata()
{
	m_pWorkSpaceRef->SetJunSize(m_nJunSize);
	m_pWorkSpaceRef->SetPipeThick(m_pipeThick.GetCurSel()+1);
	return TRUE;
}

void DlgGraphRef::UnCheck()
{
	m_Radio100.SetCheck(0);
	m_Radio50.SetCheck(0);
	m_Radio75.SetCheck(0);
	m_Radio25.SetCheck(0);
}
