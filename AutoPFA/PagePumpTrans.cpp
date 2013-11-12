// PagePumpTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePumpTrans.h"
#include "Pump.h"
#include "DlgPump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePumpTrans dialog


PagePumpTrans::PagePumpTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(PagePumpTrans::IDD, pParent)
	,m_dlgNoInerialTrans(UnitSys,manager)
	,m_dlgInerailTrans(UnitSys,manager)
	,m_Model1(m_dlgNoInerialTrans)
	,m_Model2(m_dlgInerailTrans)
	,m_Model3(m_dlgInerailTrans)
	,m_Model4(m_dlgInerailTrans)
	,m_Model5(m_dlgInerailTrans)
	,m_Model6(m_dlgInerailTrans)
	,m_Model7(m_dlgInerailTrans)
{
	//{{AFX_DATA_INIT(PagePumpTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nTransModel = 0;
	m_nType = 0;
	m_strUnit = _T("");
	m_ModelArray[0] = &m_Model1;
	m_ModelArray[1] = &m_Model2;
	m_ModelArray[2] = &m_Model3;
	m_ModelArray[3] = &m_Model4;
	m_ModelArray[4] = &m_Model5;
	m_ModelArray[5] = &m_Model6;
	m_ModelArray[6] = &m_Model7;
}


void PagePumpTrans::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePumpTrans)
	DDX_Control(pDX, IDC_CMBTRANSMODEL, m_cmbTransModel);
	DDX_Control(pDX, IDC_BOX, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PagePumpTrans, BaseDlg)
	//{{AFX_MSG_MAP(PagePumpTrans)
	ON_CBN_SELCHANGE(IDC_CMBTRANSMODEL, OnSelchangeModel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePumpTrans message handlers

BOOL PagePumpTrans::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgInerailTrans.Create(IDD_PAGETRANS5,this);
	m_dlgNoInerialTrans.Create(IDD_PAGETRANS5,this);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PagePumpTrans::Init(PumpTransient &ref,int nType,CString strUnit)
{
	m_nTransModel = ref.TranModel().GetnValue();
	if(m_nTransModel>0&&m_nTransModel<8)
	{
		m_ModelArray[m_nTransModel-1]->Init(ref);
	}
	
	InitTransModel(nType,strUnit,m_nTransModel);
	VariableSpeed();
}

BOOL PagePumpTrans::UpData(PumpTransient &ref)
{
	ref.m_TranModel.SetValue(m_nTransModel);

	if(m_nTransModel>0&&m_nTransModel<8)
	{
		m_ModelArray[m_nTransModel-1]->UpData(ref);
	}
	return TRUE;
}

void PagePumpTrans::InitTransModel(int nType,CString strUnit,int nCurModel)
{
	m_nType = nType;
	m_strUnit = strUnit;
	m_nTransModel = nCurModel;
	if(m_nType == 0)
	{
		InitDataCmb(Pump::ms_TransModel2,8,m_cmbTransModel,m_nTransModel);
		m_dlgNoInerialTrans.SetType(None,_T("转速"));//泵曲线（离心泵）
	}
	else
	{
		InitDataCmb(Pump::ms_TransModel1,2,m_cmbTransModel,m_nTransModel);
		m_dlgNoInerialTrans.SetType(None,FlowString());//指定流量（溶剂泵）变速泵
	}
	CombineDlg(m_nTransModel);
	SetUnit(strUnit);
}

void PagePumpTrans::CombineDlg(int nCurModel)
{
	m_dlgInerailTrans.ShowWindow(SW_HIDE);
	m_dlgNoInerialTrans.ShowWindow(SW_HIDE);
	if(nCurModel == 1)
	{
		Combine(this,m_Box,m_dlgNoInerialTrans);
	}
	if(nCurModel > 1)
	{
		Combine(this,m_Box,m_dlgInerailTrans);
	}
	
}

void PagePumpTrans::OnSelchangeModel() 
{
	// TODO: Add your control notification handler code here
	GetCurKey(m_cmbTransModel,m_nTransModel);
	CombineDlg(m_nTransModel);
	if(m_nTransModel>0&&m_nTransModel<8)
	{
		PumpTransient temp;
		temp.m_TranModel.SetValue(m_nTransModel);
		temp.m_FourQuadrantData.SetValue(72,1);
		m_ModelArray[m_nTransModel-1]->Init(temp);
		InitTransModel(m_nType,m_strUnit,m_nTransModel);
	}
	VariableSpeed();
}

void PagePumpTrans::SetUnit(CString strUnit)
{
	if(m_nType == 0)
	{
		m_dlgNoInerialTrans.SetUnit(_T("Percent"));
	}
	else
	{
		m_dlgNoInerialTrans.SetUnit(strUnit);
	}
}

CString PagePumpTrans::FlowString()
{
	CString strRet;
	if(1 == m_nType)
	{
		strRet = _T("体积流量");
	}
	if(2 == m_nType)
	{
		strRet = _T("质量流量");
	}
	if(3== m_nType)
	{
		strRet = _T("控制参数");
	}
	return strRet;
}

void PagePumpTrans::VariableSpeed()
{
	//只有瞬变模型为none和没有惯性才能是变速泵
	DlgPump *pDlgPump = dynamic_cast<DlgPump*>(GetParent()->GetParent());
	ASSERT(pDlgPump != NULL);
	if(m_nTransModel<2)
	{
		pDlgPump->VariableSpeed(TRUE);
	}
	else
	{
		pDlgPump->VariableSpeed(FALSE);
	}
}
