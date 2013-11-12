// PageCheck.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageCheck.h"
#include "CheckValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCheck dialog


PageCheckData::PageCheckData(CWnd* pParent /*=NULL*/)
	: PageJunData(pParent)
{
	//{{AFX_DATA_INIT(PageCheck)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageCheckData::DoDataExchange(CDataExchange* pDX)
{
	PageJunData::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCheck)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCheckData, PageJunData)
	//{{AFX_MSG_MAP(PageCheck)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCheck message handlers

void PageCheckData::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(pComponent->GetID()!= CheckValve::m_nTypeID)
	{
		return;
	}
    PageJunData::LoadData(pUnitSys,pManager,pComponent);
	// TODO: Add extra initialization here
}
