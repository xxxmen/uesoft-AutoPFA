// PageSurgeData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageSurgeData.h"
#include "Surge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSurgeData dialog


PageSurgeData::PageSurgeData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageSurgeData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageSurgeData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSurgeData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSurgeData, PageJunData)
	//{{AFX_MSG_MAP(PageSurgeData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSurgeData message handlers

void PageSurgeData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= Surge::m_nTypeID)
	{
		return;
	}
    PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here

}
