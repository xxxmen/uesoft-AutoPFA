// dlgbend.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgbend.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgBend dialog


DlgBend::DlgBend(UnitSubSystem &UnitSys,ComponentManager &manager,Bend *pBend,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pBend,pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_manager(manager)
{
	//{{AFX_DATA_INIT(DlgBend)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgBend::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgBend)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgBend, DlgJun)
	//{{AFX_MSG_MAP(DlgBend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgBend message handlers

BOOL DlgBend::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRBEND);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage(_T("ÍäÍ·Ä£ÐÍ"),&m_page1,IDD_PAGEBENDMODEL);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void DlgBend::Init()
{
	// TODO: Add extra initialization here
	Component *pTemp = NULL;
	CStringArray ms_India; 
	int nID = 0;
	CString strID;
	CString InPipeArea;
	CString OutPipeArea;
	DlgJun::Init();
	m_DlgEle.Init();
	IteratorPtr<int> IdItPtr(Jun::ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		strID.Format(_T("%d"),abs(nID));
		if(nID > 0)
		{
			InPipeArea.Format(_T("%f"),m_manager.GetPipeArea(_ttoi(strID)));
		}
		else
		{
			OutPipeArea.Format(_T("%f"),m_manager.GetPipeArea(_ttoi(strID)));
		}
	}
	ms_India.Add(InPipeArea);
	ms_India.Add(OutPipeArea);
	m_page1.Init(ms_India);
	ms_India.RemoveAll();

}

void DlgBend::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
}

void DlgBend::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
