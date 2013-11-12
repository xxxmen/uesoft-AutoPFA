#if !defined(AFX_PAGETRANS_H__9F83DDDB_C528_4FB1_92BF_71A35C0ACD71__INCLUDED_)
#define AFX_PAGETRANS_H__9F83DDDB_C528_4FB1_92BF_71A35C0ACD71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTrans dialog
#include "DlgInitiation.h"
#include "DlgTarnsData.h"
#include "Transient.h"
#include "dlgtransspecial.h"
#include "dlgperiodic.h"
#include "ComponentManager.h"
#include "BaseDlg.h"

class PageTrans : public BaseDlg
{
// Construction
public:
	void SetUnit(CString strUnit);
	void SetType(UnitTypeID id,CString strType);
	PageTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTrans)
	enum { IDD = IDD_PAGETRANS3 };
	CButton	m_Box4;
	CButton	m_Box3;
	CButton	m_Box2;
	CButton	m_Box1;
	//}}AFX_DATA

	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL UpDataTransient(Transient &ref,DlgTransSpecial *pSpecial = NULL,DlgPeriodic *pPeriodic = NULL);
	void InitTransient(Transient &ref,UnitTypeID id,CString strType,CString strUnit,DlgTransSpecial *pSpecial = NULL,DlgPeriodic *pPeriodic = NULL);
	DlgTarnsData  m_dlgTransData;
	DlgInitiation m_dlgInitTrans;
	UnitSubSystem &m_UnitSys;
	DlgPeriodic *m_pDlgPeriodic;
	// Generated message map functions
	//{{AFX_MSG(PageTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETRANS_H__9F83DDDB_C528_4FB1_92BF_71A35C0ACD71__INCLUDED_)
