// PageAreaChangeData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageAreaChangeData.h"
#include "AreaChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeData dialog


PageAreaChangeData::PageAreaChangeData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageAreaChangeData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageAreaChangeData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageAreaChangeData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageAreaChangeData, PageJunData)
	//{{AFX_MSG_MAP(PageAreaChangeData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeData message handlers

void PageAreaChangeData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= AreaChange::m_nTypeID)
	{
		return;
	}
	PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here

}
