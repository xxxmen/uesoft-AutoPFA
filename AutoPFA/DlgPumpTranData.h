#if !defined(AFX_DLGPUMPTRANDATA_H__03FD888B_F194_48C8_9976_F3DFA25D78EA__INCLUDED_)
#define AFX_DLGPUMPTRANDATA_H__03FD888B_F194_48C8_9976_F3DFA25D78EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPumpTranData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgPumpTranData dialog
#include "PageTable.h"
#include "TabSheet.h"
#include "pagefourquadtable.h"
#include "PumpTransient.h"
#include "BaseDlg.h"
class DlgPumpTranData : public BaseDlg
{
// Construction
public:
	PageFourQuadTable& FourQuadTable();
	void Show(BOOL bEnable);
	void SetCurSel(int nCur);
	void ShowPage(int nIndex,BOOL bShow);
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	DlgPumpTranData(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPumpTranData)
	enum { IDD = IDD_PUMPDATASHEEP };
	CComboBox	m_cmbTorqueUnit;
	CTabSheet	m_tab;
	CString	m_strUnit;
	//}}AFX_DATA
    CString m_strUnit1;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPumpTranData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageFourQuadTable m_page1;
	PageTable m_page2;
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(DlgPumpTranData)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTorque();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
inline PageFourQuadTable& DlgPumpTranData::FourQuadTable()
{
	return m_page1;
}
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPUMPTRANDATA_H__03FD888B_F194_48C8_9976_F3DFA25D78EA__INCLUDED_)
