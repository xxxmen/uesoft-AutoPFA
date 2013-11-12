// TabSheet.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "TabSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabSheet

CTabSheet::CTabSheet()
{
	m_nNumOfPages = 0;
	m_nCurrentPage = 0;
}

CTabSheet::~CTabSheet()
{
}


BEGIN_MESSAGE_MAP(CTabSheet, CTabCtrl)
	//{{AFX_MSG_MAP(CTabSheet)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabSheet message handlers
BOOL CTabSheet::AddPage(UINT nID, CDialog *pDialog,UINT ID,BOOL bShow)
{
	CString strTitle;
	strTitle.LoadString(nID);
	return AddPage(strTitle,pDialog,ID,bShow);
}
BOOL CTabSheet::AddPage(CString title, CDialog *pDialog,UINT ID,BOOL bShow)
{
	if( MAXPAGE == m_nNumOfPages )
		return FALSE;

	m_nNumOfPages++;

	m_pPages[m_nNumOfPages-1] = pDialog;
	m_IDD[m_nNumOfPages-1] = ID;
	m_Title[m_nNumOfPages-1] = title;
	m_bShow[m_nNumOfPages-1] = bShow;

	return TRUE;
}

void CTabSheet::SetRect()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);
	//根据坐标判断tab的位置(只考虑top,bottom）
	int nCenterX = (tabRect.bottom - tabRect.top)/2;
	int nCenterY = (tabRect.right - tabRect.left)/2;
	if(itemRect.left<nCenterY && itemRect.top<nCenterX)
	{
		nX=itemRect.left;
		nY=itemRect.bottom+1;
		nXc=tabRect.right-itemRect.left-2;
	    nYc=tabRect.bottom-nY-2;
	}
	else
	{
		nX=itemRect.left;
		nY=tabRect.top+1;
		nXc=tabRect.right-itemRect.left-2;
	    nYc=tabRect.bottom-(tabRect.bottom-itemRect.top)-2;
	}
	
	for( int nCount=0; nCount < m_nNumOfPages; nCount++ )
		m_pPages[nCount]->MoveWindow(nX, nY, nXc, nYc);

}

void CTabSheet::Show()
{
	int i;
	for( i=0; i < m_nNumOfPages; i++ )
	{
		m_pPages[i]->Create( m_IDD[i], this );
		if(m_bShow[i])
			InsertItem( i, m_Title[i] );
	}

	m_pPages[0]->ShowWindow(SW_SHOW);
	for( i=1; i < m_nNumOfPages; i++)
		m_pPages[i]->ShowWindow(SW_HIDE);

	SetRect();

}

void CTabSheet::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CTabCtrl::OnLButtonDown(nFlags, point);
	int nIndex = PageIndex(GetCurFocus());
	if(m_nCurrentPage != nIndex)
	{
		m_pPages[m_nCurrentPage]->ShowWindow(SW_HIDE);
        m_nCurrentPage = nIndex;
		m_pPages[m_nCurrentPage]->ShowWindow(SW_SHOW);
		m_pPages[m_nCurrentPage]->SetFocus();
	}
}

int CTabSheet::SetCurSel(int nItem)
{
	if( nItem < 0 || nItem >= m_nNumOfPages)
		return -1;

	int ret = m_nCurrentPage;
	m_pPages[m_nCurrentPage]->ShowWindow(SW_HIDE);
	m_nCurrentPage = nItem;
	m_pPages[m_nCurrentPage]->ShowWindow(SW_SHOW);
	//m_pPages[m_nCurrentPage]->SetFocus();
	CTabCtrl::SetCurSel(ItemIndex(nItem));

	return ret;
}

int CTabSheet::GetCurSel()
{
	return PageIndex(CTabCtrl::GetCurSel());
}

void CTabSheet::ShowPage(int nItem,BOOL bShow)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < m_nNumOfPages);
	if (m_bShow[nItem] && !bShow)
	{
		DeleteItem(ItemIndex(nItem));
		m_pPages[nItem]->ShowWindow(SW_HIDE);
	}
	
	if (!m_bShow[nItem] && bShow)
	{
		InsertItem(ItemIndex(nItem), m_Title[nItem]);
	}
	
	m_bShow[nItem] = bShow;
	RedrawWindow();
}

int CTabSheet::PageIndex(int nItem)
{//由当前tab的item得到page的索引
	if( nItem < 0 || nItem >= m_nNumOfPages)
		return 0;
	int nIndex = -1;
	int i;
	for( i=0;i<m_nNumOfPages;i++)
	{
		if(m_bShow[i])
		{
			nIndex++;
			if(nIndex==nItem)
				break;
		}
	}
	return i;
}

int CTabSheet::ItemIndex(int nPage)
{//由page的索引得到tab的item;
	if( nPage < 0 || nPage >= m_nNumOfPages)
		return 0;
	int nItem = 0;
	for(int i=0;i<nPage;i++)
	{
		if(m_bShow[i])
		{
			nItem++;
		}
	}
	return nItem;
}

void CTabSheet::SetItemTitle(UINT nID,int nPage)
{
	CString strText;
	strText.LoadString(nID);
	TCITEM item;
	item.mask = TCIF_TEXT;
	item.pszText = strText.GetBuffer(0);
	m_Title[nPage] = strText;
	if(m_bShow[nPage])
		SetItem(ItemIndex(nPage),&item);
}
