// PagePipeData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePipeData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePipeData dialog


PagePipeData::PagePipeData(CWnd* pParent /*=NULL*/)
	: PageComponentTable(pParent)
{
	//{{AFX_DATA_INIT(PagePipeData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PagePipeData::DoDataExchange(CDataExchange* pDX)
{
	PageComponentTable::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePipeData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(PagePipeData, PageComponentTable)
	//{{AFX_MSG_MAP(PagePipeData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePipeData message handlers



void PagePipeData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	PageComponentTable::LoadData(pUnitSys,pManager,pComponent);
}

Component* PagePipeData::GetComponent(int nKey)
{
	ASSERT(m_pManager != NULL);
	return m_pManager->LookUpPipe(nKey);
}
