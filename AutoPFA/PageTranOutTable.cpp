// PageTranOutTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTranOutTable.h"
#include "TranOutMgr.h"
#include "ComponentTranOut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTranOutTable dialog


PageTranOutTable::PageTranOutTable(CWnd* pParent /*=NULL*/)
	: PageOutTable(pParent)
{
	//{{AFX_DATA_INIT(PageTranOutTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_OurMgr = NULL;
	m_pOutAttArry = NULL;
	m_pTranOutSteDlg = NULL;
}


void PageTranOutTable::DoDataExchange(CDataExchange* pDX)
{
	PageOutTable::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTranOutTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTranOutTable, PageOutTable)
	//{{AFX_MSG_MAP(PageTranOutTable)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTranOutTable message handlers

CString PageTranOutTable::LookUp(int nAtrrKey,int nRow)
{
	if ( NULL != m_OurMgr )
	{
		StationStmOut* pCurStmOut = LookMap(m_StaStmOutMap,nRow );
		return pCurStmOut->GetValue(nAtrrKey);
	}
	else
	{
		int nKey = 0;
		int nSubKey = 0;
		ComponentStmOut *pStmOut = NULL;
		nKey = _ttoi(m_table.GetCell(nRow,0)->GetText());
		nSubKey = _ttoi(m_table.GetCell(nRow,1)->GetText());
		pStmOut = dynamic_cast<TranOutMgr*>(m_pOutMgr)->LookUpMaxMin(nKey,nSubKey);
		ASSERT(pStmOut != NULL);
		return pStmOut->GetValue(nAtrrKey);
	}
}

#include "PipeTranOut.h"
#include "StationStmOut.h"
void PageTranOutTable::Loading(OutMgr &mgr, OutAttrArray &Array, int nType)
{
	ComponentTranOut *pOut = NULL;
	ComponentStmOut *pStmOut = NULL;
	int nCount = mgr.GetCount();
	int n=0;
	int i=0;
	if ( nType == 2 )
	{
		while (n<nCount)
		{//排序
			pStmOut = mgr.LookUp(i++);
			if(pStmOut != NULL)
			{
				pOut = dynamic_cast<ComponentTranOut*>(pStmOut);
				ASSERT(pOut != NULL);
				IteratorPtr<ComponentStmOut> iteratorPtr(pOut->CreatMaxMinIterator());
				for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
				{
					pStmOut = &iteratorPtr->CurrentItem();
					HasData(TRUE);
					InitTableData(Array,pStmOut);
				}
				n++;
			}
		}	
	}
	if ( nType == 1 )
	{
		m_pOutAttArry = &Array;
		m_OurMgr = &mgr;
		m_iCurTranStep = 0;
		SetTransientOutPutData( m_iCurTranStep );
	}
}

StationOut* PageTranOutTable::GetAtStationOut(PipeTranOut* pPipeTranOut, int nType )
{
	int index = 0;
	IteratorPtr<StationOut> iteratorPtr(pPipeTranOut->CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		if ( index == nType )
		{		
			return &(iteratorPtr->CurrentItem());
		}
		index++ ;
	}
	return NULL;
}

void PageTranOutTable::SetTransientOutPutData( int index )
{
	m_table.DeleteAllItems();
	InitTableHeader(*m_pOutAttArry);
	m_StaStmOutMap.RemoveAll();
	int nKey = 1;
	int nCount = m_OurMgr->GetCount();
	int n=0;
	int i=0;
	ComponentStmOut *pStmOut = NULL;

	while (n<nCount)
	{//排序
		pStmOut = m_OurMgr->LookUp(i++);
		PipeTranOut* pPipeTranOut = NULL;
		StationOut* pStationOut = NULL;
		if(pStmOut != NULL)
		{
			pPipeTranOut = dynamic_cast<PipeTranOut*>(pStmOut);
			ASSERT(pPipeTranOut != NULL);
			StationOut* pFirstStaOut = GetAtStationOut( pPipeTranOut, index );//pPipeTranOut->GetLastStationOut();
			if ( pFirstStaOut != NULL )
			{			
				m_iTranMaxStep = pPipeTranOut->GetArrayNum()-1;//从0 开始
				StationStmOut* pCurStaStmOut = NULL;
				IteratorPtr<StationStmOut> iteratorPtr(pFirstStaOut->CreatIterator());
				for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
				{
					pCurStaStmOut = &iteratorPtr->CurrentItem();
					HasData(TRUE);
					m_StaStmOutMap.SetAt(nKey++,pCurStaStmOut);
					InitTableData(*m_pOutAttArry,pCurStaStmOut);
				}
			}
			n++;
		}
	}
}

#include "TranOutStepDlg.h"
void PageTranOutTable::ShowTranStepDlg()
{
// 	if ( NULL != m_OurMgr )
// 	{
// 		TranOutStepDlg temp;
// 		temp.SetTranStep(m_iCurTranStep);
// 		temp.SetMaxTranStep(m_iTranMaxStep);
// 		temp.SetCurTranOutTbl( this );
// 		if ( temp.DoModal() == IDOK )
// 		{
// 			if ( m_iCurTranStep != temp.GetTranStep() )
// 			{	
// 				m_iCurTranStep= temp.GetTranStep();
// 				if(m_iCurTranStep > m_iTranMaxStep )
// 				{
// 					AfxMessageBox( _T("不合法的迭代次数值！") );
// 				}
// 				else
// 				{
// 					SetTransientOutPutData( m_iCurTranStep );
// 				}
// 			}
// 		}
// 	}
	if ( NULL != m_OurMgr )
	{
		delete m_pTranOutSteDlg;
		m_pTranOutSteDlg = new TranOutStepDlg;
		m_pTranOutSteDlg->SetTranStep(m_iCurTranStep);
		m_pTranOutSteDlg->SetMaxTranStep(m_iTranMaxStep);
		m_pTranOutSteDlg->SetCurTranOutTbl( this );
		m_pTranOutSteDlg->Create( IDD_TRAN_STEP );
		m_pTranOutSteDlg->ShowWindow(TRUE );
		m_pTranOutSteDlg->Check();
	
	}
}

void PageTranOutTable::SetCurTranStep( int iStep )
{
	m_iCurTranStep = iStep;
}

int PageTranOutTable::GetCurTranStep()
{
	return m_iCurTranStep;
}