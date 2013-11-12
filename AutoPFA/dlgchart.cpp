// dlgchart.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgchart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgChart dialog


DlgChart::DlgChart(double dX[],double dY[],int nDat,CWnd* pParent /*=NULL*/)
	: CDialog(DlgChart::IDD, pParent)
	,m_UEChart(m_MsChart)
{
	//{{AFX_DATA_INIT(DlgChart)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dX = dX;
	m_dY1 = dY;
	m_nDat = nDat;
	m_nNum = 1;
}

DlgChart::DlgChart(double dX[],double dY1[],double dY2[],int nDat,CWnd* pParent /*=NULL*/)
	: CDialog(DlgChart::IDD, pParent)
	,m_UEChart(m_MsChart)
{
	//{{AFX_DATA_INIT(DlgChart)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dX = dX;
	m_dY1 = dY1;
	m_dY2 = dY2;
	m_nDat = nDat;
	m_nNum = 2;
}

void DlgChart::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgChart)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MSCHART1, m_MsChart);
}


BEGIN_MESSAGE_MAP(DlgChart, CDialog)
	//{{AFX_MSG_MAP(DlgChart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgChart message handlers

BOOL DlgChart::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_UEChart.Init();
	m_UEChart.SetData(m_dX,m_dY1,m_nDat);
	if(m_nNum == 2)
	{
		m_UEChart.SetData(m_dX,m_dY2,m_nDat);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
