#if !defined(AFX_DLGSOLVECONTROL_H__41B70A31_1A6F_4FCD_BA79_6DB0B23A15CF__INCLUDED_)
#define AFX_DLGSOLVECONTROL_H__41B70A31_1A6F_4FCD_BA79_6DB0B23A15CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgsolvecontrol.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dlgSolveControl dialog

class dlgSolveControl : public CDialog
{
// Construction
public:
	dlgSolveControl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(dlgSolveControl)
	enum { IDD = IDD_DIALOG_TEST };
	CProgressCtrl	m_Progress;
	int		m_Total;
	int		m_NowStep;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dlgSolveControl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dlgSolveControl)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	bool m_Stop;

public:
	void SetTotal(int total)
	{
		m_Total = total;
		m_Progress.SetRange32(0,total);
		m_Progress.SetStep(1);
	}

	void SetNowStep(int step)
	{
		m_NowStep = step;
		m_Progress.SetPos(step);
//	m_Progress.StepIt();
		UpdateData(FALSE);
		UpdateWindow() ;
	}

	bool GetStop()
	{
		return m_Stop;
	}


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSOLVECONTROL_H__41B70A31_1A6F_4FCD_BA79_6DB0B23A15CF__INCLUDED_)
