// dlgtransientset.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgtransientset.h"
#include "NetModel.h"
#include "TransientSet.h"
#include "SectionSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTransientSet dialog


DlgTransientSet::DlgTransientSet(UnitSubSystem &UnitSys,NetModel* pNetModel,CWnd* pParent /*=NULL*/)
	: CDialog(DlgTransientSet::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbTimeUnit(&m_EditStartTime,&m_EditStopTime)
	,m_cmbMinFlowUnit(&m_EditMinFlow)
{
	//{{AFX_DATA_INIT(DlgTransientSet)
	m_bArtificialTransient = FALSE;
	m_bCavitation = FALSE;
	m_bVariableR = FALSE;
	m_strFrequency = _T("");
	m_strMinFlowUnit = _T("");
	m_strTimeUnit = _T("");
	m_fCriteria = 0.0f;
	m_fMinFlow = 0.0f;
	m_fStartTime = 0.0f;
	m_fStopTime = 0.0f;
	m_nTotalStep = 0;
	m_fStepTime = 0.0f;
	//}}AFX_DATA_INIT
	m_pNetModel = pNetModel;
}


void DlgTransientSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTransientSet)
	DDX_Control(pDX, IDC_EMINFLOW, m_EditMinFlow);
	DDX_Control(pDX, IDC_ESTOPTIME, m_EditStopTime);
	DDX_Control(pDX, IDC_ESTARTTIME, m_EditStartTime);
	DDX_Control(pDX, IDC_CMBTIMEUNIT, m_cmbTimeUnit);
	DDX_Control(pDX, IDC_CMBMODEL, m_cmbModel);
	DDX_Control(pDX, IDC_CMBMINFLOWUNIT, m_cmbMinFlowUnit);
	DDX_Control(pDX, IDC_CMBFREQUENCY, m_cmbFrequency);
	DDX_Check(pDX, IDC_CHECKARTIFICIAL, m_bArtificialTransient);
	DDX_Check(pDX, IDC_CHECKCAVITATION, m_bCavitation);
	DDX_Check(pDX, IDC_CHECKVARIABLER, m_bVariableR);
	DDX_CBString(pDX, IDC_CMBFREQUENCY, m_strFrequency);
	DDX_CBString(pDX, IDC_CMBMINFLOWUNIT, m_strMinFlowUnit);
	DDX_CBString(pDX, IDC_CMBTIMEUNIT, m_strTimeUnit);
	DDX_Text(pDX, IDC_ESTARTTIME, m_fStartTime);
	DDX_Text(pDX, IDC_ESTOPTIME, m_fStopTime);
	DDX_Text(pDX, IDC_ETOTALlSTEP, m_nTotalStep);
	DDX_Text(pDX, IDC_ESTEPTIME, m_fStepTime);
	DDX_Text(pDX, IDC_EMINFLOW, m_fMinFlow);
	DDX_Text(pDX, IDC_ECRITERIA, m_fCriteria);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTransientSet, CDialog)
	//{{AFX_MSG_MAP(DlgTransientSet)
	ON_CBN_SELCHANGE(IDC_CMBTIMEUNIT, OnSelchangeTime)
	ON_EN_CHANGE(IDC_ESTARTTIME, OnChangeStartTime)
	ON_EN_CHANGE(IDC_ESTOPTIME, OnChangeTtopTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTransientSet message handlers

BOOL DlgTransientSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cmbModel.SetCurSel(0);
	InitUnitCbo(m_UnitSys,Time,m_cmbTimeUnit,m_strTimeUnit);
	InitUnitCbo(m_UnitSys,MassFlow,m_cmbMinFlowUnit,m_strMinFlowUnit);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL DlgTransientSet::Init()
{
	ASSERT(m_pNetModel != NULL);
	SectionSet *pSectionSet = m_pNetModel->m_calcManager.GetSectionSet();
	LoadData();
	if(pSectionSet->TimeStep(m_fStepTime,m_pNetModel->m_compManager))
	{
		if(-0.000001<m_fStepTime&&m_fStepTime<0.000001)
		{
			ASSERT(FALSE);
			return TRUE;
		}
		TotalStep();
	}
	return TRUE;
}

void DlgTransientSet::LoadData()
{
	ASSERT(m_pNetModel != NULL);
	TransientSet *pTransientSet = m_pNetModel->m_calcManager.GetTransientSet();
	pTransientSet->InitData();

	m_bArtificialTransient = abs(TransientSet::ms_StopOnArtificialTrans.GetnValue());
	m_bCavitation = abs(TransientSet::ms_ModelCavitation.GetnValue());
	m_bVariableR = abs(TransientSet::ms_VariableR.GetnValue());
	m_strFrequency = TransientSet::ms_Frequency.GetValue();
	m_fStartTime = TransientSet::ms_StartTime.GetfValue();
	m_fStopTime = TransientSet::ms_StopTime.GetfValue();
	m_strTimeUnit = TransientSet::ms_StartTime.GetUnit();
	CString strValve;
	InitNum(strValve,m_strMinFlowUnit,TransientSet::ms_CriteriaMinFlow);
	m_fMinFlow = _tcstod(strValve, NULL );
	m_fCriteria = TransientSet::ms_Criteria.GetfValue();
}

double DlgTransientSet::TotalTime()
{
	double dTime1;
	double dTime2;
	TransformToStd(dTime1,m_strTimeUnit,m_fStartTime);
	TransformToStd(dTime2,m_strTimeUnit,m_fStopTime);
	return dTime2 - dTime1;
}

void DlgTransientSet::OnOK() 
{
	// TODO: Add extra validation here
	UpData();
	CDialog::OnOK();
}

BOOL DlgTransientSet::UpData()
{
	UpdateData(TRUE);
	ASSERT(m_pNetModel != NULL);
	TransientSet *pTransientSet = m_pNetModel->m_calcManager.GetTransientSet();

	TransientSet::ms_StopOnArtificialTrans.SetValue(m_bArtificialTransient);
	TransientSet::ms_ModelCavitation.SetValue(m_bCavitation);
	TransientSet::ms_VariableR.SetValue(m_bVariableR);
	TransientSet::ms_Frequency.SetValue(m_strFrequency);
	TransientSet::ms_Criteria.SetValue(m_fCriteria);
	TransientSet::ms_StartTime.SetValue(m_fStartTime);
	TransientSet::ms_StartTime.SetUnit(m_strTimeUnit);
	TransientSet::ms_StopTime.SetValue(m_fStopTime);
	TransientSet::ms_StopTime.SetUnit(m_strTimeUnit);
	TransientSet::ms_CriteriaMinFlow.SetValue(m_fMinFlow);
	TransientSet::ms_CriteriaMinFlow.SetUnit(m_strMinFlowUnit);
	TransientSet::ms_TotalSteps.SetValue(m_nTotalStep);

	pTransientSet->SaveData();
	return TRUE;
}

void DlgTransientSet::OnSelchangeTime() 
{
	// TODO: Add your control notification handler code here
	m_strTimeUnit = GetCmbText(m_cmbTimeUnit);
	TotalStep();
	UpdateData(FALSE);

}

void DlgTransientSet::TotalStep()
{
	m_nTotalStep = (TotalTime()+m_fStepTime/2)/m_fStepTime;
}

void DlgTransientSet::OnChangeStartTime() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString strText;
	GetDlgItem(IDC_ESTARTTIME)->GetWindowText(strText);
	double dTime = _tcstod( strText, NULL );
	if(-0.0000001<dTime&&dTime<0.0000001
		||strText.Right(1).CollateNoCase(_T("."))==0)
	{
		return;
	}
	m_fStartTime = _tcstod( strText, NULL );
	TotalStep();
	UpdateData(FALSE);
}

void DlgTransientSet::OnChangeTtopTime() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString strText;
	GetDlgItem(IDC_ESTOPTIME)->GetWindowText(strText);
	double dTime = _tcstod(strText, NULL );
	if(-0.0000001<dTime&&dTime<0.0000001
		||strText.Right(1).CollateNoCase(_T("."))==0)
	{
		return;
	}
	m_fStopTime = _tcstod( strText, NULL );
	TotalStep();
	UpdateData(FALSE);

}
