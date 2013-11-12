// PageOther.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageOther.h"
#include "SteadySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageOther dialog


PageOther::PageOther(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageOther::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageOther)
	m_bKeep = FALSE;
	m_strFlowRelax = _T("");
	m_strMaxIter = _T("");
	m_strPressRelax = _T("");
	m_strIterSpan = _T("");
	//}}AFX_DATA_INIT
	m_nKeep = 0;
	m_nMatrixMethod = 0;
}


void PageOther::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageOther)
	DDX_Control(pDX, IDC_CMBMATRIX, m_cmbMatrix);
	DDX_Check(pDX, IDC_CHECKKEEPTRACK, m_bKeep);
	DDX_Text(pDX, IDC_EFLOWRELAX, m_strFlowRelax);
	DDX_Text(pDX, IDC_EMAXITER, m_strMaxIter);
	DDX_Text(pDX, IDC_EPRESSRELAX, m_strPressRelax);
	DDX_Text(pDX, IDC_EITERSPAN, m_strIterSpan);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageOther, BaseDlg)
	//{{AFX_MSG_MAP(PageOther)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageOther message handlers
void PageOther::Init()
{
	m_strFlowRelax = SteadySet::ms_FlowRelaxation.GetValue();
	m_strPressRelax = SteadySet::ms_PresRelaxation.GetValue();
	m_strMaxIter   = SteadySet::ms_MaxIterations.GetValue();
	m_strIterSpan  = SteadySet::ms_AutoDetect.GetValue();
	m_nKeep = SteadySet::ms_KeepHistory.GetnValue();
	m_nMatrixMethod = SteadySet::ms_MatrixMethod.GetnValue();
	if(0 == m_nKeep)
	{
		m_bKeep = FALSE;
	}
	else
	{
		m_bKeep = TRUE;
	}

	InitDataCmb(SteadySet::ms_Method,3,m_cmbMatrix,m_nMatrixMethod);
	UpdateData(FALSE);
}

BOOL PageOther::Updata()
{
	UpdateData(TRUE);
	SteadySet::ms_FlowRelaxation.SetValue(m_strFlowRelax);
	SteadySet::ms_PresRelaxation.SetValue(m_strPressRelax);
	SteadySet::ms_MaxIterations.SetValue(m_strMaxIter);
	SteadySet::ms_AutoDetect.SetValue(m_strIterSpan);
	if(m_bKeep)
	{
		m_nKeep = -1;
	}
	else
	{
		m_nKeep = 0;
	}
	GetCurKey(m_cmbMatrix,m_nMatrixMethod);
	SteadySet::ms_KeepHistory.SetValue(m_nKeep);
	SteadySet::ms_MatrixMethod.SetValue(m_nMatrixMethod);

	return TRUE;
}