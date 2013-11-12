// PageDeadEndData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageDeadEndData.h"
#include "DeadEnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndData dialog


PageDeadEndData::PageDeadEndData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageDeadEndData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageDeadEndData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageDeadEndData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageDeadEndData, PageJunData)
	//{{AFX_MSG_MAP(PageDeadEndData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndData message handlers

void PageDeadEndData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= DeadEnd::m_nTypeID)
	{
		return;
	}
    PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here
}
