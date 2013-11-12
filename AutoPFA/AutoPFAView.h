// AutoPFAView.h : interface of the CAutoPFAView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOPFAVIEW_H__9D7B6719_9142_43CC_909A_388D70F7BF07__INCLUDED_)
#define AFX_AUTOPFAVIEW_H__9D7B6719_9142_43CC_909A_388D70F7BF07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Manipulator;
class CAutoPFADoc;
class WorkSpaceRef;

class CAutoPFAView : public CScrollView
{
protected: // create from serialization only
	CAutoPFAView();
	DECLARE_DYNCREATE(CAutoPFAView)

// Attributes
public:
	CAutoPFADoc* GetDocument();

// Operations
public:
	UINT m_curIndex;
	static HCURSOR s_Cursor[23];
	static int     s_ComopnentID[23];
	Manipulator *m_pManipulator;
	WorkSpaceRef *m_pWorkSpaceRef;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoPFAView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ZoomDocSize(double scale);
	void ZoomScrollSizes(const CRect &rc,BOOL bFit = TRUE);
	void ReSetDocSize();
	virtual ~CAutoPFAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoPFAView)
	afx_msg void OnManager();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnWorkSpaceRef();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnZoomFit();
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI* pCmdUI);
	afx_msg void OnReverse();
	afx_msg void OnUpdateReverse(CCmdUI* pCmdUI);
	afx_msg void OnShowdata();
	afx_msg void OnUpdateShowdata(CCmdUI* pCmdUI);
	afx_msg void OnDuplicate();
	afx_msg void OnUpdateDuplicate(CCmdUI* pCmdUI);
	afx_msg void OnFind();
	afx_msg void OnUpdateFind(CCmdUI* pCmdUI);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	afx_msg void OnPalette(UINT nID);
	afx_msg void OnUpdatePalette(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
private:
	void VptoDP(CPoint &point);
	void DPtoVP(CPoint &point);
private:
	void CreatZoomTool();
	double m_Scale;
	int m_xWindowExt;
	int m_yWindowExt;
	int m_xWindowOrg;
	int m_xViewOrg;
	int m_yWindowOrg;
	int m_yViewOrg;
	int m_xViewExt;
	int m_yViewExt;

};

#ifndef _DEBUG  // debug version in AutoPFAView.cpp
inline CAutoPFADoc* CAutoPFAView::GetDocument()
   { return (CAutoPFADoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOPFAVIEW_H__9D7B6719_9142_43CC_909A_388D70F7BF07__INCLUDED_)
