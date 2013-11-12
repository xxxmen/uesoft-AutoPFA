// PageViscosModel.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageViscosModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageViscosModel dialog


PageViscosModel::PageViscosModel(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageViscosModel::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageViscosModel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageViscosModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageViscosModel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageViscosModel, BaseDlg)
	//{{AFX_MSG_MAP(PageViscosModel)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageViscosModel message handlers
