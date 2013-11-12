// TranOutStepDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "TranOutStepDlg.h"
#include "PageTranOutTable.h"


// TranOutStepDlg 对话框

IMPLEMENT_DYNAMIC(TranOutStepDlg, CDialog)

TranOutStepDlg::TranOutStepDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TranOutStepDlg::IDD, pParent)
	, m_iTranStep(0)
	, m_iMaxStepValue(0)
{
	m_MaxStepControl.EnableWindow( FALSE );
	m_MinusButton.EnableWindow( FALSE );
}

TranOutStepDlg::~TranOutStepDlg()
{
}

void TranOutStepDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STEP_VALUE, m_iTranStep);
	DDX_Control(pDX, IDC_MAX_STEP, m_MaxStepControl);
	DDX_Text(pDX, IDC_MAX_STEP, m_iMaxStepValue);
	DDX_Control(pDX, IDC_ADD, m_AddButton);
	DDX_Control(pDX, IDC_MINUS, m_MinusButton);
}


BEGIN_MESSAGE_MAP(TranOutStepDlg, CDialog)
	ON_BN_CLICKED(IDOK, &TranOutStepDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ADD, &TranOutStepDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MINUS, &TranOutStepDlg::OnBnClickedMinus)
END_MESSAGE_MAP()


// TranOutStepDlg 消息处理程序

void TranOutStepDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData( TRUE );
	if ( m_iTranStep>=0
		&&m_iTranStep<= m_iMaxStepValue )
	{
		m_pCurTranOutTbl->SetTransientOutPutData( m_iTranStep );
		m_pCurTranOutTbl->SetCurTranStep( m_iTranStep );
	}
	OnOK();
}

void TranOutStepDlg::SetTranStep( int iStep )
{
	m_iTranStep = iStep;
// 	m_MaxStepControl.EnableWindow( FALSE );
// 	m_MinusButton.EnableWindow( FALSE );
}

int  TranOutStepDlg::GetTranStep()
{
	return m_iTranStep;
}

void TranOutStepDlg::SetMaxTranStep( int iMaxStep )
{
	m_iMaxStepValue = iMaxStep;
}

int  TranOutStepDlg::GetMaxTranStep()
{
	return m_iMaxStepValue;
}

void TranOutStepDlg::SetCurTranOutTbl( PageTranOutTable* pCurTranOutTbl )
{
	m_pCurTranOutTbl = pCurTranOutTbl;
}
PageTranOutTable* TranOutStepDlg::GetCurTranOutTbl()
{
	return m_pCurTranOutTbl;
}
void TranOutStepDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	if ( m_iTranStep < m_iMaxStepValue )
	{
		m_iTranStep++;
		if ( m_iTranStep> 0
			&& m_iTranStep <=m_iMaxStepValue )
		{	
			if (m_iTranStep>= m_iMaxStepValue )
			{
				m_AddButton.EnableWindow( FALSE );
			}
			m_MinusButton.EnableWindow( TRUE );
			UpdateData( FALSE );
			m_pCurTranOutTbl->SetTransientOutPutData( m_iTranStep );
			m_pCurTranOutTbl->SetCurTranStep( m_iTranStep );
		}
	}
}

void TranOutStepDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	if ( m_iTranStep>0)
	{
		m_iTranStep--;
		if ( m_iTranStep>= 0
			&& m_iTranStep <=m_iMaxStepValue )
		{	
			if ( m_iTranStep <= 0 )
			{
				m_MinusButton.EnableWindow( FALSE );
			}
			m_AddButton.EnableWindow( TRUE );
			UpdateData( FALSE );
			m_pCurTranOutTbl->SetTransientOutPutData( m_iTranStep );
			m_pCurTranOutTbl->SetCurTranStep( m_iTranStep );
		}
	}
}

void TranOutStepDlg::Check()
{
	if (m_iTranStep>= m_iMaxStepValue )
	{
		m_AddButton.EnableWindow( FALSE );
	}

	if ( m_iTranStep <= 0 )
	{
		m_MinusButton.EnableWindow( FALSE );
	}

}