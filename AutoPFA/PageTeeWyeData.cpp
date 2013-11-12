// PageTeeWyeData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTeeWyeData.h"
#include "TeeWye.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeData dialog


PageTeeWyeData::PageTeeWyeData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageTeeWyeData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageTeeWyeData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTeeWyeData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTeeWyeData, PageJunData)
	//{{AFX_MSG_MAP(PageTeeWyeData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeData message handlers

void PageTeeWyeData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= TeeWye::m_nTypeID)
	{
		return;
	}
    PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here

}
