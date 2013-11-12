#if !defined(AFX_DLGPARAMTABLE_H__DAC4A5DE_9900_4400_B3C8_9E01B4E8FA91__INCLUDED_)
#define AFX_DLGPARAMTABLE_H__DAC4A5DE_9900_4400_B3C8_9E01B4E8FA91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgParamTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgParamTable dialog
#include "GridCtrl.h"
#include "ListFlyWeightImp.h"
#include "BaseDlg.h"
class DlgParamTable : public BaseDlg
{
// Construction
public:
	void SetParam(double dParam[],int nNum,int nCol);
	DlgParamTable(CWnd* pParent = NULL);   // standard constructor
	template<UINT size> void InsertColumn(CString strName,StrArray<size> &ref,int nIndex)
	{
		ASSERT(size-nIndex == 5);
		int nCol = m_table.InsertColumn(strName);
		for(int i =1;i<6;i++)
		{
			m_table.SetItemText(i,nCol,ref.Data(nIndex+i-1));
		}
	}


// Dialog Data
	//{{AFX_DATA(DlgParamTable)
	enum { IDD = IDD_RAWDATATABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgParamTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	CGridCtrl m_table;
	// Generated message map functions
	//{{AFX_MSG(DlgParamTable)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitTable();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMTABLE_H__DAC4A5DE_9900_4400_B3C8_9E01B4E8FA91__INCLUDED_)
