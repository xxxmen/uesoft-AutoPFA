// PageStmOutTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageStmOutTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageStmOutTable dialog


PageStmOutTable::PageStmOutTable(CWnd* pParent /*=NULL*/)
	: PageOutTable(pParent)
{
	//{{AFX_DATA_INIT(PageStmOutTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageStmOutTable::DoDataExchange(CDataExchange* pDX)
{
	PageOutTable::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageStmOutTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageStmOutTable, PageOutTable)
	//{{AFX_MSG_MAP(PageStmOutTable)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageStmOutTable message handlers

CString PageStmOutTable::LookUp(int nAtrrKey,int nRow)
{
	int nKey = 0;
	ComponentStmOut *pStmOut = NULL;
	nKey = _ttoi(m_table.GetCell(nRow,0)->GetText());
	pStmOut = m_pOutMgr->LookUp(nKey);
	ASSERT(pStmOut != NULL);
	return pStmOut->GetValue(nAtrrKey);
}

void PageStmOutTable::Loading(OutMgr &mgr, OutAttrArray &Array, int nType)
{
	ComponentStmOut *pStmOut = NULL;
	IteratorPtr<ComponentStmOut> iteratorPtr(mgr.CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pStmOut = &iteratorPtr->CurrentItem();
		if(0==nType || nType==pStmOut->Type())
		{
			HasData(TRUE);
			InitTableData(Array,pStmOut);
		}	
	}	
}
