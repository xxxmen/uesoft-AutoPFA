// dlgperiodic.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgperiodic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPeriodic dialog


DlgPeriodic::DlgPeriodic(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgPeriodic::IDD, pParent)
	,m_cmbAmplitude(&m_EditAmplitude)
{
	//{{AFX_DATA_INIT(DlgPeriodic)
	m_bChop = FALSE;
	m_bPeriodic = FALSE;
	m_strAmplitudeUnit = _T("");
	m_strAmplitude = _T("");
	m_strFrequency = _T("");
	//}}AFX_DATA_INIT
}


void DlgPeriodic::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPeriodic)
	DDX_Control(pDX, IDC_EDITAMPLITUDE, m_EditAmplitude);
	DDX_Control(pDX, IDC_CMBAMPLITUDEUNIT, m_cmbAmplitude);
	DDX_Check(pDX, IDC_CHECKCHOP, m_bChop);
	DDX_Check(pDX, IDC_CHECKPERIODIC, m_bPeriodic);
	DDX_CBString(pDX, IDC_CMBAMPLITUDEUNIT, m_strAmplitudeUnit);
	DDX_Text(pDX, IDC_EDITAMPLITUDE, m_strAmplitude);
	DDX_Text(pDX, IDC_EDITFREQUENCY, m_strFrequency);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPeriodic, BaseDlg)
	//{{AFX_MSG_MAP(DlgPeriodic)
	ON_BN_CLICKED(IDC_CHECKPERIODIC, OnCheckPeriodic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPeriodic message handlers

void DlgPeriodic::OnCheckPeriodic() 
{
	// TODO: Add your control notification handler code here
	m_bPeriodic = !m_bPeriodic;
	if(!m_bPeriodic)
	{
		m_bChop = FALSE;
	}
	SetPeriodicStatus();
}

void DlgPeriodic::Init(const ArrayFlyWeight<5> &ref,UnitSubSystem &system,UnitTypeID id)
{
	m_bPeriodic = abs(ref.GetnValue());
	m_bChop     = abs(ref.GetnValue(1));
	m_strFrequency = ref.GetValue(2);
	InitNum<5>(m_strAmplitude,m_strAmplitudeUnit,ref,3);
	
	SetUnit(system,id);
	SetPeriodicStatus();
	UpdateData(FALSE);
}

BOOL DlgPeriodic::UpData(ArrayFlyWeight<5> &ref)
{
	UpdateData(TRUE);
	ref.SetValue(m_bPeriodic);
	ref.SetValue(m_bChop,1);
	ref.SetValue(m_strFrequency,2);
	ref.SetValue(m_strAmplitude,3);
	ref.SetValue(m_strAmplitudeUnit,4);
	return TRUE;
}

void DlgPeriodic::SetUnit(UnitSubSystem &system,UnitTypeID id)
{
	InitUnitCbo(system,id,m_cmbAmplitude,m_strAmplitudeUnit);
}

void DlgPeriodic::SetPeriodicStatus()
{
	GetDlgItem(IDC_CHECKCHOP)->EnableWindow(m_bPeriodic);
	GetDlgItem(IDC_EDITFREQUENCY)->EnableWindow(m_bPeriodic);
	GetDlgItem(IDC_EDITAMPLITUDE)->EnableWindow(m_bPeriodic);
	m_cmbAmplitude.EnableWindow(m_bPeriodic);
}
