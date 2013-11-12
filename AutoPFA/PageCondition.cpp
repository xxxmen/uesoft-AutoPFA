// PageCondition.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageCondition.h"
#include "Condition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCondition dialog


PageCondition::PageCondition(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageCondition::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cboTemperature(&m_AtmospherTemp)
	,m_cboPress(&m_EditAtmospherPress)
{
	//{{AFX_DATA_INIT(PageCondition)
	m_strPressUnit = _T("");
	m_strTemperatureUnit = _T("");
	m_strAtmosphericPress = _T("");
	m_strAtmosphericTemp = _T("");
	m_strGravity = _T("");
	m_strRetransTurb = _T("");
	m_strRetransLam = _T("");
	//}}AFX_DATA_INIT
}


void PageCondition::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCondition)
	DDX_Control(pDX, IDC_EATMOSPHERICTEMP, m_AtmospherTemp);
	DDX_Control(pDX, IDC_EATMOSPHERICPRESS, m_EditAtmospherPress);
	DDX_Control(pDX, IDC_CMBTEMP, m_cboTemperature);
	DDX_Control(pDX, IDC_CMBPRESS, m_cboPress);
	DDX_CBString(pDX, IDC_CMBPRESS, m_strPressUnit);
	DDX_CBString(pDX, IDC_CMBTEMP, m_strTemperatureUnit);
	DDX_Text(pDX, IDC_EATMOSPHERICPRESS, m_strAtmosphericPress);
	DDX_Text(pDX, IDC_EATMOSPHERICTEMP, m_strAtmosphericTemp);
	DDX_Text(pDX, IDC_EGRAVITY, m_strGravity);
	DDX_Text(pDX, IDC_ERETRANSTURB, m_strRetransTurb);
	DDX_Text(pDX, IDC_ERETRANSLAM, m_strRetransLam);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCondition, BaseDlg)
	//{{AFX_MSG_MAP(PageCondition)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCondition message handlers

BOOL PageCondition::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Temperature,m_cboTemperature,m_strTemperatureUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cboPress,m_strPressUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageCondition::Init(Condition *pCondition)
{
	m_pCondition = pCondition;
	m_pCondition->InitData();
	m_strGravity =     Condition::ms_Gravity.GetValue();
	m_strRetransLam =  Condition::ms_ReTransLam.GetValue();
	m_strRetransTurb = Condition::ms_ReTransTurb.GetValue();

    InitNum(m_strAtmosphericPress,m_strPressUnit,Condition::ms_AtmosphericPress);
	InitNum(m_strAtmosphericTemp,m_strTemperatureUnit,Condition::ms_AtmosphericTemp);
	
	UpdateData(FALSE);
}

BOOL PageCondition::UpData()
{
	UpdateData(TRUE);

	Condition::ms_Gravity.SetValue(m_strGravity);
	Condition::ms_ReTransLam.SetValue(m_strRetransLam);
	Condition::ms_ReTransTurb.SetValue(m_strRetransTurb);
	SetNum(m_strAtmosphericPress,m_strPressUnit,Condition::ms_AtmosphericPress);
	SetNum(m_strAtmosphericTemp,m_strTemperatureUnit,Condition::ms_AtmosphericTemp);

	ASSERT(m_pCondition != NULL);
	m_pCondition->SaveData();
	return TRUE;
}
