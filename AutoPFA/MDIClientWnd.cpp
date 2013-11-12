// MDIClientWnd.cpp : implementation file
//

//文件: MDIClientWnd.cpp
//作者: 许朝
//时间: 2002.8

#include "stdafx.h"
#include "autopfa.h"
#include "MDIClientWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIClientWnd

CMDIClientWnd::CMDIClientWnd()
{
}

CMDIClientWnd::~CMDIClientWnd()
{
}


BEGIN_MESSAGE_MAP(CMDIClientWnd, CWnd)
	//{{AFX_MSG_MAP(CMDIClientWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
#ifdef _TEST
	ON_MESSAGE(WM_MDISETMENU,OnMDISetMenu)
#endif
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMDIClientWnd message handlers

void CMDIClientWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap bmp;
	BITMAP bm;
	bmp.LoadBitmap(IDB_MDICLIENT);
	bmp.GetObject(sizeof(bm),&bm);
	CRect & rcBox=*(CRect*)(&dc.m_ps.rcPaint);	//rcPaint表示要重画的区域
	CPoint poDraw;
	int iXCount,iYCount;
	
	poDraw.x=rcBox.left/bm.bmWidth * bm.bmWidth;
	iXCount =(rcBox.right-poDraw.x)/bm.bmWidth +  ((rcBox.right-poDraw.x) % bm.bmWidth == 0 ? 0 : 1);

	poDraw.y=rcBox.top/bm.bmHeight * bm.bmHeight;
	iYCount =(rcBox.bottom - poDraw.y)/bm.bmHeight + ((rcBox.bottom - poDraw.y) % bm.bmHeight == 0 ? 0 : 1);

	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap* oldbmp=dcMem.SelectObject(&bmp);
	
	for(int i=0;i<iYCount;i++)
	{
		int iXT=poDraw.x;
		for(int j=0;j<iXCount;j++)
		{
			dc.BitBlt(poDraw.x,poDraw.y,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
			poDraw.x+=bm.bmWidth;
		}
		poDraw.x=iXT;
		poDraw.y+=bm.bmHeight;
	}
	dcMem.SelectObject(oldbmp);
	bmp.DeleteObject();
	dcMem.DeleteDC();

/////////////////公司的标志/////////////////
	bmp.LoadBitmap(IDB_UESOFTCI);
	bmp.GetObject(sizeof(bm),&bm);
	CDC dcMem1;
	dcMem1.CreateCompatibleDC(&dc);
	CBitmap* oldbmp1=dcMem1.SelectObject(&bmp);
	oldbmp=dcMem1.SelectObject(&bmp);
	//这里的rcBox不能是先前的那个重画区域，而应该是整个客户区
	this->GetClientRect(&rcBox);
	if(rcBox.right>=bm.bmWidth)
	{
		poDraw.x = (rcBox.right-bm.bmWidth)/2;
		dc.BitBlt(poDraw.x,(rcBox.bottom-bm.bmHeight)/2,bm.bmWidth,bm.bmHeight,&dcMem1,0,0,SRCAND);
	}else
	{
		dc.StretchBlt(0,(rcBox.bottom-bm.bmHeight)/2,rcBox.right,bm.bmHeight,&dcMem1,0,0,bm.bmWidth,bm.bmHeight,SRCAND);
	}
	dcMem1.SelectObject(oldbmp1);
	bmp.DeleteObject();
	dcMem1.DeleteDC();
/////////////////////////

	CString strText;
	CString strData;
	strText.LoadString(IDS_MDICLIENTTEXT);
	
	CFont font;
	LOGFONT logfont;
	LOGFONT logfontData;
	memset(&logfont,0,sizeof(logfont));
	logfont.lfHeight=40;
	logfont.lfCharSet=ANSI_CHARSET;
	logfont.lfWeight=FW_EXTRABOLD;
	logfont.lfOutPrecision=OUT_STROKE_PRECIS;
	logfont.lfClipPrecision=CLIP_STROKE_PRECIS;
	logfont.lfQuality=PROOF_QUALITY;
	logfont.lfPitchAndFamily=FF_SWISS;
	logfont.lfItalic=TRUE;
	logfontData = logfont;
	logfontData.lfHeight = 20;
	font.CreateFontIndirect(&logfontData);
    dc.SelectObject(&font);
	CSize szDataText = dc.GetTextExtent(strData);
	CRect rcClient;
	this->GetClientRect(&rcClient);
	CPoint pointData;
    pointData.x=rcClient.right - szDataText.cx - 20;
	pointData.y=rcClient.bottom - szDataText.cy - 5;
	COLORREF crOld=dc.SetTextColor(GetSysColor(COLOR_BTNHIGHLIGHT));
	int iOldModel=dc.SetBkMode(TRANSPARENT);
	dc.TextOut(pointData.x,pointData.y,strData);
	pointData.Offset(1,1);
    dc.SetTextColor(RGB(16,30,122));
	dc.TextOut(pointData.x,pointData.y,strData);
	font.DeleteObject();
	//
	font.CreateFontIndirect(&logfont);
	CFont * oldFont=dc.SelectObject(&font);
	CSize sizeText=dc.GetTextExtent(strText);
	CPoint pointText;
	pointText.x=rcClient.right - sizeText.cx - 20;
	pointText.y=rcClient.bottom - sizeText.cy -szDataText.cy;
    dc.SetTextColor(GetSysColor(COLOR_BTNHIGHLIGHT));
	dc.TextOut(pointText.x,pointText.y,strText);
	pointText.Offset(2,2);

	dc.SetTextColor(RGB(16,30,122));
	dc.TextOut(pointText.x,pointText.y,strText);

	dc.SetTextColor(crOld);
	dc.SetBkMode(iOldModel);
	dc.SelectObject(oldFont);
	font.DeleteObject();
	// Do not call CWnd::OnPaint() for painting messages
}

BOOL CMDIClientWnd::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	//return CWnd::OnEraseBkgnd(pDC);
}

void CMDIClientWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	this->RedrawWindow();
}
#ifdef _TEST
LRESULT CMDIClientWnd::OnMDISetMenu(WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu=(HMENU)(DWORD)wParam;
	if(hMenu)
	{
		HMENU hSubMenu=::GetSubMenu(hMenu,2);
		if(hSubMenu)
		{
			MENUITEMINFO MenuInfo;
			MenuInfo.cbSize=sizeof(MenuInfo);
			MenuInfo.fMask=MIIM_ID;
			::GetMenuItemInfo(hSubMenu,0,TRUE,&MenuInfo);
			if(MenuInfo.wID==IDM_SASTATIC || MenuInfo.wID==IDM_SADYNAMIC)
			{
				int Count=::GetMenuItemCount(hSubMenu);
				BOOL bFind=FALSE;
				for(int i=0;i<Count;i++)
				{
					::GetMenuItemInfo(hSubMenu,i,TRUE,&MenuInfo);
					if(MenuInfo.wID==IDM_SANOTUSEDLL)
					{
						bFind=TRUE;
						break;
					}
				}
				if(!bFind)
				{
					HMENU hTest=::LoadMenu(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_MENU_TEST));
					if(hTest)
					{
						HMENU hSubTest=::GetSubMenu(hTest,0);
						if(hSubTest)
						{
							MenuInfo.fMask=MIIM_ID|MIIM_TYPE;
							MenuInfo.fType=MFT_STRING;
							TCHAR szText[256];
							MenuInfo.dwTypeData=szText;
							MenuInfo.cch=255;
							::GetMenuItemInfo(hSubTest,0,TRUE,&MenuInfo);
							::InsertMenuItem(hSubMenu,2,TRUE,&MenuInfo);
							
						}
						::DestroyMenu(hTest);
					}
				}
			}
		}
	}
	return DefWindowProc(WM_MDISETMENU,wParam,lParam);
}
#endif
