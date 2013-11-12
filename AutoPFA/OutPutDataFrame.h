#if !defined(AFX_OUTPUTDATAFRAME_H__B3237433_7D7C_4004_9CFE_6A5585264A04__INCLUDED_)
#define AFX_OUTPUTDATAFRAME_H__B3237433_7D7C_4004_9CFE_6A5585264A04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutPutDataFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutPutDataFrame frame
#include "ModelDataFrame.h"

class COutPutDataFrame : public CModelDataFrame
{
	DECLARE_DYNCREATE(COutPutDataFrame)
protected:
	COutPutDataFrame();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutPutDataFrame)
	//}}AFX_VIRTUAL
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
// Implementation
protected:
	virtual ~COutPutDataFrame();

	// Generated message map functions
	//{{AFX_MSG(COutPutDataFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDATAFRAME_H__B3237433_7D7C_4004_9CFE_6A5585264A04__INCLUDED_)
