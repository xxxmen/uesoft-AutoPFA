// dlgtransspecial.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgtransspecial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTransSpecial dialog


DlgTransSpecial::DlgTransSpecial(UINT nIDTemplate,CWnd* pParent /*=NULL*/)
	: BaseDlg(nIDTemplate,pParent)
{
	//{{AFX_DATA_INIT(DlgTransSpecial)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgTransSpecial::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTransSpecial)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTransSpecial, BaseDlg)
	//{{AFX_MSG_MAP(DlgTransSpecial)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTransSpecial message handlers
