#if !defined(AFX_PAGEINERTIALDATA_H__43BAF580_8310_4A92_BA72_58833790396B__INCLUDED_)
#define AFX_PAGEINERTIALDATA_H__43BAF580_8310_4A92_BA72_58833790396B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageInertialData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageInertialData dialog
#include "PumpTransient.h"
#include "pagefourquadtable.h"
#include "BaseDlg.h"
#include <iostream>
using namespace std;
class PageInertialData : public BaseDlg
{
// Construction
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	PageInertialData(UnitSubSystem &UnitSys,PageFourQuadTable &table,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageInertialData)
	enum { IDD = IDD_INERTIALDATA };
	CButton m_AngelExpression2;
	CButton	m_AngelExpression1;
	CNumEdit	m_EditSpeed;
	CNumEdit	m_EditNum;
	CNumEdit	m_EditInerial;
	CComboBox	m_cmbSource;
	CUnitComboBox	m_cmbInerial;
	CString	m_strInerialUnit;
	CString	m_strInerial;
	CString	m_strNum;
	CString	m_strSpeed;
	int		m_nAngel;
	//}}AFX_DATA
	int m_nSource;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageInertialData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	PageFourQuadTable &m_table;
	// Generated message map functions
	//{{AFX_MSG(PageInertialData)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillFocusNum();
	afx_msg void OnSelchangeSource();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetOtherParameter(CString strID, int iAngelCount = 0);
	int GetIndexOfSqecID( );
	void GetDBTable(ListImp<StrArray<3> > &CurDBTable);
	void GetSpeedTable();
	void InitStatus(PumpTransient &ref);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEINERTIALDATA_H__43BAF580_8310_4A92_BA72_58833790396B__INCLUDED_)
