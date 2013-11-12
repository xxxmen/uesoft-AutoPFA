#if !defined(AFX_WORKSPACEDATAFRAME_H__CEE63928_24C0_4BCF_B7DE_7D576CEB1C0A__INCLUDED_)
#define AFX_WORKSPACEDATAFRAME_H__CEE63928_24C0_4BCF_B7DE_7D576CEB1C0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkSpaceDataFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceDataFrame frame
#include "ModelDataFrame.h"

class CWorkSpaceDataFrame : public CModelDataFrame
{
	DECLARE_DYNCREATE(CWorkSpaceDataFrame)
protected:
	CWorkSpaceDataFrame();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkSpaceDataFrame)
	//}}AFX_VIRTUAL
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
// Implementation
protected:
	virtual ~CWorkSpaceDataFrame();

	// Generated message map functions
	//{{AFX_MSG(CWorkSpaceDataFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKSPACEDATAFRAME_H__CEE63928_24C0_4BCF_B7DE_7D576CEB1C0A__INCLUDED_)
