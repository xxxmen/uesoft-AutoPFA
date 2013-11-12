// OutPutDataFrame.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "OutPutDataFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutPutDataFrame

IMPLEMENT_DYNCREATE(COutPutDataFrame, CModelDataFrame)

COutPutDataFrame::COutPutDataFrame()
{
}

COutPutDataFrame::~COutPutDataFrame()
{
}


BEGIN_MESSAGE_MAP(COutPutDataFrame, CModelDataFrame)
	//{{AFX_MSG_MAP(COutPutDataFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutPutDataFrame message handlers
void COutPutDataFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	GetMDIFrame()->OnUpdateFrameTitle(bAddToTitle);

	if ((GetStyle() & FWS_ADDTOTITLE) == 0)
		return;     // leave child window alone!

	CDocument* pDocument = GetActiveDocument();
	if (bAddToTitle)
	{
		TCHAR szText[256+_MAX_PATH];
		if (pDocument == NULL)
			lstrcpy(szText, m_strTitle);
		else
			lstrcpy(szText, pDocument->GetTitle());
		wsprintf(szText + lstrlen(szText),_T(" - %s "),_T("文本结果"));

		SetWindowText(szText);
	}
}