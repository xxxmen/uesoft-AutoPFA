// PageFitLoss.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageFitLoss.h"
#include "Pipe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageFitLoss dialog


PageFitLoss::PageFitLoss(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageFitLoss::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageFitLoss)
	m_strLocalK = _T("");
	//}}AFX_DATA_INIT
}


void PageFitLoss::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageFitLoss)
	DDX_Text(pDX, IDC_EFITLOSS, m_strLocalK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageFitLoss, BaseDlg)
	//{{AFX_MSG_MAP(PageFitLoss)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageFitLoss message handlers
void PageFitLoss::Init()
{
	m_strLocalK = Pipe::ms_LocalK.GetValue();
	UpdateData(FALSE);
}

BOOL PageFitLoss::UpData()
{
	UpdateData(TRUE);
	Pipe::ms_LocalK.SetValue(m_strLocalK);
	return TRUE;
}
