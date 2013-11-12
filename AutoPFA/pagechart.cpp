// pagechart.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagechart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageChart dialog


PageChart::PageChart(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageChart::IDD, pParent)
	,m_UEChart(m_MsChart)
{
	//{{AFX_DATA_INIT(PageChart)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageChart::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageChart)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MSCHART1, m_MsChart);
	
}


BEGIN_MESSAGE_MAP(PageChart, BaseDlg)
	//{{AFX_MSG_MAP(PageChart)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageChart message handlers


BOOL PageChart::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageChart::OnSize(UINT nType, int cx, int cy) 
{
	BaseDlg::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if(m_MsChart.GetSafeHwnd())
	{
		m_MsChart.MoveWindow(2,2,cx-10,cy-10);
	}
}


