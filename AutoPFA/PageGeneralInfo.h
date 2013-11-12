#if !defined(AFX_PAGEGENERALINFO_H__F23AE91B_C4ED_4134_AF7D_A62B5C32A3ED__INCLUDED_)
#define AFX_PAGEGENERALINFO_H__F23AE91B_C4ED_4134_AF7D_A62B5C32A3ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGeneralInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageGeneralInfo dialog
#include "PageDataList.h"
class NetModel;
class ScenarioObject;
class PFAOutModel;

class PageGeneralInfo : public PageDataList
{
// Construction
public:
	void LoadData(PFAOutModel &outModel);
	void LoadData(NetModel *pNetModel);
	PageGeneralInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGeneralInfo)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGeneralInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageGeneralInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Load(ScenarioObject* pObject);
	void Load(ComponentManager &Manager);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERALINFO_H__F23AE91B_C4ED_4134_AF7D_A62B5C32A3ED__INCLUDED_)
