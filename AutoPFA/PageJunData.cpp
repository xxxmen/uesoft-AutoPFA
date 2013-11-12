// PageJunData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageJunData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageJunData dialog


PageJunData::PageJunData(CWnd* pParent /*=NULL*/)
	: PageComponentTable(pParent)
{
	//{{AFX_DATA_INIT(PageJunData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bHasData = FALSE;
}


void PageJunData::DoDataExchange(CDataExchange* pDX)
{
	PageComponentTable::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageJunData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageJunData, PageComponentTable)
	//{{AFX_MSG_MAP(PageJunData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageJunData message handlers

void PageJunData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	PageComponentTable::LoadData(pUnitSys,pManager,pComponent);
}





Component* PageJunData::GetComponent(int nKey)
{
	ASSERT(m_pManager != NULL);
	return m_pManager->LookUpJun(nKey);
}
