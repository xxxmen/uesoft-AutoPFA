// PageTransientData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTransientData.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTransientData dialog


PageTransientData::PageTransientData(CWnd* pParent /*=NULL*/)
	: PageDataList(pParent)
{
	//{{AFX_DATA_INIT(PageTransientData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void PageTransientData::DoDataExchange(CDataExchange* pDX)
{
	PageDataList::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTransientData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTransientData, PageDataList)
	//{{AFX_MSG_MAP(PageTransientData)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTransientData message handlers

BOOL PageTransientData::OnInitDialog() 
{
	PageDataList::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	m_list.InsertColumn(0,_T(""),LVCFMT_LEFT,200);
	m_list.InsertColumn(1,_T(""));
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void PageTransientData::LoadData(ComponentManager *pManager)
{
	m_list.DeleteAllItems();
	Transient *pTransient = NULL;
	Component *pComponent = NULL;
	Jun *pJun = NULL;
	CString strText;
	IteratorPtr<Component> iteratorPtr(pManager->CreatJunIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pComponent = &iteratorPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>(pComponent);
		ASSERT(pJun != NULL);
		pTransient = pJun->GetTransient();
		if(NULL != pTransient)
		{
			strText.Format(_T("J%d(%s)"),pComponent->GetKey(),pComponent->GetName());
			m_list.InsertItem(m_list.GetItemCount(),_T(""));
			m_list.InsertItem(m_list.GetItemCount(),strText);
			if(!pTransient->m_Trans1Table.IsEmpty())
				InitListData(pTransient->m_Trans1Table);
			if(!pTransient->m_Trans2Table.IsEmpty())
				InitListData(pTransient->m_Trans2Table);
		}
	}
}

void PageTransientData::InitListData(TransDataTable<2> &ref)
{
	int nRow = m_list.GetItemCount();
	m_list.InsertItem(nRow,ref.Unit().GetValue());
	m_list.SetItemText(nRow,1,ref.Unit().GetValue(1));
	nRow++;
	StrArray<2> array;
	IteratorPtr<StrArray<2> > IdItPtr(ref.Data().CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array = IdItPtr->CurrentItem();
		m_list.InsertItem(nRow,array.Data());
		m_list.SetItemText(nRow,1,array.Data(1));
		nRow++;
	}
}

void PageTransientData::OnSize(UINT nType, int cx, int cy) 
{
	PageDataList::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	if(m_list.GetSafeHwnd())
	{
		m_list.SetColumnWidth(1,rc.Width()-210);
	}
}
