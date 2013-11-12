
/************************************************************************
功能：响应嵌套对话框消息，如果用户按下Esc或者Enter按钮不隐藏嵌套的对话框
使用方法：嵌套对话框从此基类继承，不是嵌套对话框不能从该类继承                                                                              
************************************************************************/

#if !defined(AFX_BASEDLG_H__86C2ADE2_ADAE_452E_B07B_7B3DE2D8B3C6__INCLUDED_)
#define AFX_BASEDLG_H__86C2ADE2_ADAE_452E_B07B_7B3DE2D8B3C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BaseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BaseDlg dialog

class BaseDlg : public CDialog
{
// Construction
public:
	BaseDlg(UINT ID,CWnd* pParent = NULL); 
	//BaseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BaseDlg)
	//enum { IDD = IDD_DLG_UndefinedObjects };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BaseDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BaseDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDLG_H__86C2ADE2_ADAE_452E_B07B_7B3DE2D8B3C6__INCLUDED_)
