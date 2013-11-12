#if !defined(AFX_OPTIMIZATIONPARAMETER_H__B170245F_4151_4F85_9808_725B1BFEFDA9__INCLUDED_)
#define AFX_OPTIMIZATIONPARAMETER_H__B170245F_4151_4F85_9808_725B1BFEFDA9__INCLUDED_

// Added by ClassView

#if _MSC_VER > 1000

#endif // _MSC_VER > 1000
// OptimizationParameter.h : header file
//


#include "AutoPFADoc.h"
#include "OptimitationConst.h"
#include "PFAOptimize.h"
#include "AutoPFA.h"
/////////////////////////////////////////////////////////////////////////////
// COptimizationParameter dialog

class COptimizationParameter : public CDialog
{
// Construction
public:
	bool OpenData(PFAOptimitationData& OptData);
	bool SaveData( PFAOptimitationData& OptData );
	COptimizationParameter(CWnd* pParent = NULL);   // standard constructor
	COptimizationParameter( CPFAOptimize* pOptimize );
	

// Dialog Data
	//{{AFX_DATA(COptimizationParameter)
	enum { IDD = IDD_DLGOPTPARAMETER };
	CTabCtrl	m_myTab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptimizationParameter)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptimizationParameter)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COptimizationParameter)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	PFAOptimitationData* pOptData;
	CPFAOptimize *m_pOptimize;
	COptimitationConst m_OptConstPage;
	void InitUnit();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIMIZATIONPARAMETER_H__B170245F_4151_4F85_9808_725B1BFEFDA9__INCLUDED_)
