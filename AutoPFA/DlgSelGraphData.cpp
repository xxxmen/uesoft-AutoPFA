// DlgSelGraphData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgSelGraphData.h"
#include "PFAOutModel.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSelGraphData dialog


DlgSelGraphData::DlgSelGraphData(GraphView &view,PFAOutModel &out,CWnd* pParent /*=NULL*/)
	: CDialog(DlgSelGraphData::IDD, pParent)
	,m_view(view)
	,m_out(out)
{
	//{{AFX_DATA_INIT(DlgSelGraphData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgSelGraphData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSelGraphData)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSelGraphData, CDialog)
	//{{AFX_MSG_MAP(DlgSelGraphData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSelGraphData message handlers

void DlgSelGraphData::OnOK() 
{
	// TODO: Add extra validation here
	if(m_tab.GetCurSel()==0)
		m_pipeData.ShowData(m_out.TransOut().ComponentOutMgr().PipeOutMgr(),m_view);
	if(m_tab.GetCurSel()==1)
		m_junData.ShowData(m_out.TransOut().ComponentOutMgr().JunOutMgr(),m_view);
	CDialog::OnOK();
}

BOOL DlgSelGraphData::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRPIPE,&m_pipeData,IDD_PAGEGRAPH);
	m_tab.AddPage(IDS_STRJUN,&m_junData,IDD_PAGEGRAPH);
	m_tab.Show();
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSelGraphData::Init()
{
	PipeTranOutMgr &outMgr = m_out.TransOut().ComponentOutMgr().PipeOutMgr();
	JunTranOutMgr &junMgr = m_out.TransOut().ComponentOutMgr().JunOutMgr();
	m_pipeData.InitData(outMgr,outMgr.GetStationArray());
	m_junData.InitData(junMgr,junMgr.GetArray());
}

