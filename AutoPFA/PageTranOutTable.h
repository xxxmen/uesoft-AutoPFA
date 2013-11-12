#if !defined(AFX_PAGETRANOUTTABLE_H__4703F017_F4CE_4B77_AFC0_02A241F64AF7__INCLUDED_)
#define AFX_PAGETRANOUTTABLE_H__4703F017_F4CE_4B77_AFC0_02A241F64AF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTranOutTable.h : header file
//
#include "PageOutTable.h"
#include "StationOut.h"
/////////////////////////////////////////////////////////////////////////////
// PageTranOutTable dialog
class TranOutStepDlg;

class PageTranOutTable : public PageOutTable
{
// Construction
public:
	PageTranOutTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTranOutTable)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTranOutTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Loading(OutMgr &mgr,OutAttrArray &Array,int nType );
	CString LookUp(int nAtrrKey,int nRow);
	virtual void ShowTranStepDlg();

	// Generated message map functions
	//{{AFX_MSG(PageTranOutTable)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	StationOut* GetAtStationOut(PipeTranOut* pPipeTranOut, int nType );
public:
	void SetTransientOutPutData( int index );
	void SetCurTranStep( int iStep );
	int GetCurTranStep();
private:
	OutMgr* m_OurMgr;
	OutAttrArray* m_pOutAttArry;
	int m_iTranMaxStep;
	int m_iCurTranStep;
	typedef CMap<int,int,StationStmOut*,StationStmOut*> StationStmOutMap;
	StationStmOutMap m_StaStmOutMap;
	TranOutStepDlg* m_pTranOutSteDlg;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETRANOUTTABLE_H__4703F017_F4CE_4B77_AFC0_02A241F64AF7__INCLUDED_)
