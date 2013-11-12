// DlgThreeTransSpecial.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgThreeTransSpecial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgThreeTransSpecial dialog


DlgThreeTransSpecial::DlgThreeTransSpecial(CWnd* pParent /*=NULL*/)
	: DlgTransSpecial(DlgThreeTransSpecial::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgThreeTransSpecial)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void DlgThreeTransSpecial::DoDataExchange(CDataExchange* pDX)
{
	DlgTransSpecial::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgThreeTransSpecial)
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgThreeTransSpecial, DlgTransSpecial)
	//{{AFX_MSG_MAP(DlgThreeTransSpecial)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgThreeTransSpecial message handlers

void DlgThreeTransSpecial::Init(const StrFlyWeight &ref)
{
	m_nSpecial = ref.GetnValue();
	UpdateData(FALSE);
}

BOOL DlgThreeTransSpecial::UpData(StrFlyWeight &ref)
{
	UpdateData(TRUE);
	ref.SetValue(m_nSpecial);
	return TRUE;
}
