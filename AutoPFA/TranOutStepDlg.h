#pragma once
#include "afxwin.h"


// TranOutStepDlg 对话框
class PageTranOutTable;

class TranOutStepDlg : public CDialog
{
	DECLARE_DYNAMIC(TranOutStepDlg)

public:
	TranOutStepDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TranOutStepDlg();

// 对话框数据
	enum { IDD = IDD_TRAN_STEP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_iTranStep;
	CEdit m_MaxStepControl;
	int m_iMaxStepValue;
public:
	afx_msg void OnBnClickedOk();
public:
	void SetTranStep( int iStep );
	int  GetTranStep();
	void SetMaxTranStep( int iMaxStep );
	int  GetMaxTranStep();

	void SetCurTranOutTbl( PageTranOutTable* pCurTranOutTbl );
	PageTranOutTable* GetCurTranOutTbl();
	void Check();
public:
	PageTranOutTable* m_pCurTranOutTbl;
public:
	afx_msg void OnBnClickedAdd();
public:
	afx_msg void OnBnClickedMinus();
public:
	CButton m_AddButton;
	CButton m_MinusButton;
};
