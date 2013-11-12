// PageGeneral.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGeneral.h"
#include "General.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGeneral dialog


PageGeneralData::PageGeneralData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageGeneral)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageGeneralData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGeneral)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGeneralData, PageJunData)
	//{{AFX_MSG_MAP(PageGeneral)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGeneral message handlers

void PageGeneralData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= General::m_nTypeID)
	{
		return;
	}
    PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here
}
