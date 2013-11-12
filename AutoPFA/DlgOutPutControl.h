#pragma once
#include "PagePipeOutControl.h"
#include "PageJunOutControl.h"
#include "TabSheet.h"
#include "PFAOutModel.h"
#include "AutoPFADoc.h"
// CDlgOutPutControl 对话框

class CDlgOutPutControl : public CDialog
{
	DECLARE_DYNAMIC(CDlgOutPutControl)

public:
	CDlgOutPutControl(PFAOutModel& outModel, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgOutPutControl();
	void SetCurDoc( CAutoPFADoc* pDoc );

// 对话框数据
	enum { IDD = IDD_DLG_OUTPUTCONTROL };
	CTabSheet	m_tab;
	PagePipeOutControl m_PagePipe;
	PageJunOutControl m_PageJun;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:

	afx_msg void OnBnClickedOk();
protected:
	CAutoPFADoc* m_pAutoPFADoc;
public:
	afx_msg void OnBnImport();
public:
	afx_msg void OnBnSave();
};
