// dlgtwotransspecial.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgtwotransspecial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTwoTransSpecial dialog


DlgTwoTransSpecial::DlgTwoTransSpecial(CWnd* pParent /*=NULL*/)
	: DlgTransSpecial(DlgTwoTransSpecial::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgTwoTransSpecial)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void DlgTwoTransSpecial::DoDataExchange(CDataExchange* pDX)
{
	DlgTransSpecial::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTwoTransSpecial)
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTwoTransSpecial, DlgTransSpecial)
	//{{AFX_MSG_MAP(DlgTwoTransSpecial)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTwoTransSpecial message handlers

void DlgTwoTransSpecial::Init(const StrFlyWeight &ref)
{
	m_nSpecial = ref.GetnValue();
	UpdateData(FALSE);
}

BOOL DlgTwoTransSpecial::UpData(StrFlyWeight &ref)
{
	UpdateData(TRUE);
	ref.SetValue(m_nSpecial);
	return TRUE;
}

void DlgTwoTransSpecial::Enable(BOOL bEnable)
{
	GetDlgItem(IDC_RADIONONE)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOIGNORE)->EnableWindow(bEnable);
}
