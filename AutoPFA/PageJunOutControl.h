#pragma once
#include "TabSheet.h"
#include "PageNotShowOutAtt.h"

// PageJunOutControl 对话框

class PageJunOutControl : public CDialog
{
	DECLARE_DYNAMIC(PageJunOutControl)

public:
	PageJunOutControl(PFAOutModel& outModel, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageJunOutControl();

// 对话框数据
	enum { IDD = IDD_PAGE_PIPEOUTCONTROL };

    CTabSheet	m_tab;
	CListCtrl   m_lstShowAtt;

	void UpData();
	BOOL Read(CStdioFile& file);
	BOOL Save(CStdioFile& file);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	void InitData(CString InData,CString str[50]);

	DECLARE_MESSAGE_MAP()
private:
	PageNotShowOutAtt m_pPageAtt;
	PFAOutModel& m_outModel;
	CString m_strJunOrder;
	CString m_strUnitOrder;

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBtnDeleteAll();

	void LoadAllAtt(OutMgr& outMgr);
	void LoadShowAtt(OutMgr& outMgr);
	BOOL Find( CString strKey );

	afx_msg void OnCbnSelchangeComboUnit();
	afx_msg void OnLvnItemchangedListShowout(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox m_comboUnit;
};
