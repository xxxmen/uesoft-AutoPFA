#if !defined(AFX_DLGSECTIONPIPE_H__8B8587F4_6FBF_45BC_8CE1_9E323280CB1B__INCLUDED_)
#define AFX_DLGSECTIONPIPE_H__8B8587F4_6FBF_45BC_8CE1_9E323280CB1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgsectionpipe.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSectionPipe dialog
#include "GridCtrl.h"
class NetModel;

class DlgSectionPipe : public CDialog
{
// Construction
public:
	
	BOOL Init();
	DlgSectionPipe(UnitSubSystem &UnitSys,NetModel* pNetModel,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSectionPipe)
	enum { IDD = IDD_DLGSECETION };
	BOOL	m_bSearch;
	BOOL	m_bSort;
	CString	m_strMaxSection;
	CString	m_strMinSection;
	int		m_nKey;
	float	m_fTimeStep;
	float	m_fPctIncrement;
	float	m_fMaxError;
	float	m_fIdealSection;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSectionPipe)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	NetModel    *m_pNetModel;
	CGridCtrl	m_Search;
	CGridCtrl	m_Section;
	UnitSubSystem &m_UnitSys;
	
	// Generated message map functions
	//{{AFX_MSG(DlgSectionPipe)
	virtual BOOL OnInitDialog();
	afx_msg void OnSearch();
	afx_msg void OnUpdataTable();
	virtual void OnOK();
	afx_msg void OnSelchangeMaxSection();
	afx_msg void OnSelchangeMinSection();
	afx_msg void OnChangeMaxError();
	afx_msg void OnChangeIncrement();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DelTableData();
	void UpData();
	void UpdataResult(float fValue);
	void InitResult();
	void InitSearchHeader();
	void InitSectionHeader();
	void InitSectionData(ListImp<StrArray<8> > &table);
	void InitSearchData(ListImp<StrArray<5> > &table);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSECTIONPIPE_H__8B8587F4_6FBF_45BC_8CE1_9E323280CB1B__INCLUDED_)
