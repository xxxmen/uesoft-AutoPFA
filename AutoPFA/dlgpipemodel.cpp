// dlgpipemodel.cpp : implementation file
//
#pragma once
#include "stdafx.h"
#include "autopfa.h"
#include "dlgpipemodel.h"
#include "ComponentManager.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "ADOConnection.h"
#include "GetPropertyofMaterial2.h"
#include "Fuild.h"
#include "ResourcePathManager.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPipeModel dialog


DlgPipeModel::DlgPipeModel(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgPipeModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_manager(manager)
	,m_cmbLenUnit(&m_EditLen)
	,m_cmbWaveUnit(&m_EditWave)
	,m_cmbElaticity(&m_EditElastic)
	,m_cmbInDiaUnit(&m_EditInDia)
	,m_cmbThick(&m_EditThick)
	,m_cmbFriction(&m_EditFriction)
{
	//{{AFX_DATA_INIT(DlgPipeModel)
	m_strInDiaUnit = _T("");
	m_strLenUnit = _T("");
	m_strWaveUnit = _T("");
	m_strInDia = _T("");
	m_strLen = _T("");
	m_strWave = _T("");
	m_strElasticityUnit = _T("");
	m_strThickUnit = _T("");
	m_strType = _T("");
	m_strC1 = _T("");
	m_strElasticity = _T("");
	m_strFrictionUnit = _T("");
	m_strFriction = _T("");
	m_strInDiaReduce = _T("");
	m_strPossionRatio = _T("");
	m_strThick = _T("");
	m_bCalcWave = 0;
	m_strMaterial = _T("");
	m_strSize = _T("");
	//}}AFX_DATA_INIT
	m_support = 1;
	m_frictionModel = 0;
}


void DlgPipeModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPipeModel)
	DDX_Control(pDX, IDC_EFRICTION, m_EditFriction);
	DDX_Control(pDX, IDC_EELASTICITY, m_EditElastic);
	DDX_Control(pDX, IDC_EINDIA, m_EditInDia);
	DDX_Control(pDX, IDC_ELEN, m_EditLen);
	DDX_Control(pDX, IDC_EPOISSONRATIO, m_EditPossion);
	DDX_Control(pDX, IDC_ETHICK, m_EditThick);
	DDX_Control(pDX, IDC_EWAVE, m_EditWave);
	DDX_Control(pDX, IDC_EC1, m_EditC1);
	DDX_Control(pDX, IDC_CMBLOSSTYPE, m_cmbLossType);
	DDX_Control(pDX, IDC_CMBTYPE, m_cmbType);
	DDX_Control(pDX, IDC_CMBTHICK, m_cmbThick);
	DDX_Control(pDX, IDC_CMBSUPPORT, m_cmbSupport);
	DDX_Control(pDX, IDC_CMBSIZE, m_cmbSize);
	DDX_Control(pDX, IDC_CMBMATIRAIL, m_cmbMaterail);
	DDX_Control(pDX, IDC_CMBFRICTIONUNIT, m_cmbFriction);
	DDX_Control(pDX, IDC_CMBELASTICITY, m_cmbElaticity);
	DDX_Control(pDX, IDC_CMBWAVEUNIT, m_cmbWaveUnit);
	DDX_Control(pDX, IDC_CMBLENUNIT, m_cmbLenUnit);
	DDX_Control(pDX, IDC_CMBINDIAUNIT, m_cmbInDiaUnit);
	DDX_CBString(pDX, IDC_CMBINDIAUNIT, m_strInDiaUnit);
	DDX_CBString(pDX, IDC_CMBLENUNIT, m_strLenUnit);
	DDX_CBString(pDX, IDC_CMBWAVEUNIT, m_strWaveUnit);
	DDX_Text(pDX, IDC_EINDIA, m_strInDia);
	DDX_Text(pDX, IDC_ELEN, m_strLen);
	DDX_Text(pDX, IDC_EWAVE, m_strWave);
	DDX_CBString(pDX, IDC_CMBELASTICITY, m_strElasticityUnit);
	DDX_CBString(pDX, IDC_CMBTHICK, m_strThickUnit);
	DDX_CBString(pDX, IDC_CMBTYPE, m_strType);
	DDX_Text(pDX, IDC_EC1, m_strC1);
	DDX_Text(pDX, IDC_EELASTICITY, m_strElasticity);
	DDX_CBString(pDX, IDC_CMBFRICTIONUNIT, m_strFrictionUnit);
	DDX_Text(pDX, IDC_EFRICTION, m_strFriction);
	DDX_Text(pDX, IDC_EIDREDUCE, m_strInDiaReduce);
	DDX_Text(pDX, IDC_EPOISSONRATIO, m_strPossionRatio);
	DDX_Text(pDX, IDC_ETHICK, m_strThick);
	DDX_Radio(pDX, IDC_RADIOASSIGN, m_bCalcWave);
	DDX_CBString(pDX, IDC_CMBMATIRAIL, m_strMaterial);
	DDX_CBString(pDX, IDC_CMBSIZE, m_strSize);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_STATIC1, m_ThickControl);
	DDX_Control(pDX, IDC_STATIC2, m_ElasticityControl);
	DDX_Control(pDX, IDC_STATIC3, m_PossinControl);
}


BEGIN_MESSAGE_MAP(DlgPipeModel, BaseDlg)
	//{{AFX_MSG_MAP(DlgPipeModel)
	ON_BN_CLICKED(IDC_RADIOASSIGN, OnRadioAssign)
	ON_BN_CLICKED(IDC_RADIOCALC, OnRadioCalc)
	ON_CBN_SELCHANGE(IDC_CMBSUPPORT, OnSelchangeSupport)
	ON_CBN_SELCHANGE(IDC_CMBLOSSTYPE, OnSelchangeLoss)
	ON_CBN_SELCHANGE(IDC_CMBMATIRAIL, OnSelchangeMatirail)
	ON_EN_CHANGE(IDC_EC1, OnChangeC1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPipeModel message handlers

GetPropertyofMaterial material;

void DlgPipeModel::Init()
{
	ADOConnection m_ado;
	ADORecordSetPtr pRs;
	_RecordsetPtr _pRs;
	CString strFile,strSql;
	strSql = "SELECT Material FROM MaterialNameText";
	strFile = ResourcePathManager::Instance().GetOldSoftShareDbPath();
	if( strFile.IsEmpty() )
		return ;
	strFile.TrimRight( _T( "\\" ) );
	strFile += _T("\\MaterialName.mdb");
	m_ado.Open(strFile);
	
	pRs = m_ado.ExecuteSelectSQL(strSql);
	for ( pRs->MoveFirst(); !pRs->IsEOF(); pRs->MoveNext() )
	{
		CString strname = pRs->GetString(_T("Material"));
		m_cmbMaterail.AddString(strname);
	}
	strFile.Empty();
	strSql.Empty();

	m_strMaterial  = Pipe::ms_Material.GetValue();
	m_strSize      = Pipe::ms_Size.GetValue();
	m_strType      = Pipe::ms_PipeType.GetValue();
	
	InitNum(m_strInDia,m_strInDiaUnit,Pipe::ms_InDia);
    InitNum(m_strThick,m_strThickUnit,Pipe::ms_Thick);
    InitNum(m_strElasticity,m_strElasticityUnit,Pipe::ms_Elasticity);

	m_strPossionRatio = Pipe::ms_PossionRatio.GetValue();
	m_strInDiaReduce  = Pipe::ms_InDiaReduce.GetValue();

	InitNum(m_strLen,m_strLenUnit,Pipe::ms_Len);
	InitNum(m_strWave,m_strWaveUnit,Pipe::ms_WaveSpeed);
	
	m_bCalcWave		   = Pipe::ms_CalcWave.GetnValue();
	m_support		   = Pipe::ms_SupportType.GetnValue();
	m_strC1            = Pipe::ms_C1.GetValue();
	m_frictionModel    = Pipe::ms_LossType.GetnValue();

	InitNum(m_strFriction,m_strFrictionUnit,Pipe::ms_Friction);
	
	InitDataCmb(Pipe::ms_supportTypeArray,8,m_cmbSupport,m_support);
	InitDataCmb(Pipe::ms_frictionModel,8,m_cmbLossType,m_frictionModel);

	SetControlStatus();
	SetLossStatus();
	UpdateData(FALSE);
}

void DlgPipeModel::UpData()
{
	UpdateData(TRUE);

	Pipe::ms_Material.SetValue(m_strMaterial);
	Pipe::ms_Size.SetValue(m_strSize);
	Pipe::ms_PipeType.SetValue(m_strType);
	SetNum(m_strInDia,m_strInDiaUnit,Pipe::ms_InDia);
	SetNum(m_strThick,m_strThickUnit,Pipe::ms_Thick);
    SetNum(m_strElasticity,m_strElasticityUnit,Pipe::ms_Elasticity);
	
	Pipe::ms_PossionRatio.SetValue(m_strPossionRatio);
	Pipe::ms_InDiaReduce.SetValue(m_strInDiaReduce);
	
	SetNum(m_strLen,m_strLenUnit,Pipe::ms_Len);
	
	
	Pipe::ms_CalcWave.SetValue(m_bCalcWave);
	Pipe::ms_SupportType.SetValue(m_support);
	Pipe::ms_C1.SetValue(m_strC1);

	SetNum(m_strWave,m_strWaveUnit,Pipe::ms_WaveSpeed);
	
	Pipe::ms_LossType.SetValue(m_frictionModel);
	if(m_frictionModel != 0)
		m_strFrictionUnit.Empty();
	SetNum(m_strFriction,m_strFrictionUnit,Pipe::ms_Friction);
	UpdateData(TRUE);
		
}

BOOL DlgPipeModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here

	InitUnitCbo(m_UnitSys,Diameter,m_cmbInDiaUnit,m_strInDiaUnit);
	InitUnitCbo(m_UnitSys,Diameter,m_cmbThick,m_strThickUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbElaticity,m_strElasticityUnit);
	InitUnitCbo(m_UnitSys,Length,m_cmbLenUnit,m_strLenUnit);
	InitUnitCbo(m_UnitSys,Velocity,m_cmbWaveUnit,m_strWaveUnit);
	InitUnitCbo(m_UnitSys,Diameter,m_cmbFriction,m_strFrictionUnit);


	//CMainFrame* pMainFrame = NULL; 
    //pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	//CMenu* pMenu = ((CWnd*)pMainFrame)->GetMenu();
	//if( (pMenu->GetMenuState(ID_STEADYANALYSIS,MF_BYCOMMAND) == MF_CHECKED) )
	//{
	//	if( (_ttoi(m_strWave) == 0) )
	//	{
	//		m_strWave = _T( "1400" );
	//		m_strWaveUnit = _T( "meters/sec" );
	//	}
    //    m_bCalcWave = 0;
	//}
	//SetControlStatus();
	//SetLossStatus();
	//UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPipeModel::OnRadioAssign() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(FALSE);
	m_bCalcWave = 0;
	SetControlStatus();
//	m_cmbMaterail.GetLBText(m_cmbMaterail.GetCurSel(),m_strMaterial);
	UpdateData(TRUE);
	UpdateData(FALSE);
}

void DlgPipeModel::OnRadioCalc() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(FALSE);
	m_bCalcWave = 1;
	OnSelchangeMatirail();
//	CalcWaveSpeed();

	SetControlStatus();
	UpdateData(TRUE);
	UpdateData(FALSE);
}

void DlgPipeModel::SetControlStatus()
{
	CEdit *pEdit = NULL;
	m_EditC1.SetReadOnly(!m_bCalcWave||m_support!=0);
	GetDlgItem(IDC_CMBSUPPORT)->EnableWindow(m_bCalcWave);
	m_EditWave.SetReadOnly(m_bCalcWave);
	m_EditThick.EnableWindow(m_bCalcWave);
	m_EditElastic.EnableWindow(m_bCalcWave);
	m_EditPossion.EnableWindow(m_bCalcWave);
	m_cmbElaticity.EnableWindow(m_bCalcWave);
	m_cmbThick.EnableWindow(m_bCalcWave);
	m_PossinControl.EnableWindow(m_bCalcWave);
	m_ElasticityControl.EnableWindow(m_bCalcWave);
	m_ThickControl.EnableWindow(m_bCalcWave);
	//m_cmbInDiaUnit.EnableWindow(m_bCalcWave);
}

void DlgPipeModel::OnSelchangeSupport() 
{
	// TODO: Add your control notification handler code here
	int Index = m_cmbSupport.GetCurSel();
	if(CB_ERR == Index)
		return;
	m_support = m_cmbSupport.GetItemData(Index);
	m_EditC1.SetReadOnly(m_support!=0);
	CalcWaveSpeed();
	m_strWave = Pipe::ms_WaveSpeed.GetValue();
}

void DlgPipeModel::OnSelchangeLoss() 
{
	// TODO: Add your control notification handler code here
	int Index = m_cmbLossType.GetCurSel();
	if(CB_ERR == Index)
		return;
	m_frictionModel = m_cmbLossType.GetItemData(Index);
	SetLossStatus();
}

void DlgPipeModel::OnSelchangeMatirail()
{
	UpdateData(TRUE);
	if (m_bCalcWave == 1)
	{
		ADOConnection m_ado;
		CString strFile,strsql,materialname;
		Fuild *fluid;
		double Et = 0;
		double m_temp = 0;
		double fPoissons = 0;
		strFile = ResourcePathManager::Instance().GetOldSoftShareDbPath();
		if( strFile.IsEmpty() )
			return ;
		strFile.TrimRight( _T( "\\" ) );
		strFile += _T("\\Material.mdb");
		//str = "E:\\AutoPDMS2.0\\开发文档\\数据库模板\\Material.mdb";
		m_ado.Open(strFile);
		m_ado.GetConnectionptr( material.m_pMaterialCon );
		fluid = m_manager.SysProperty().GetFuild();
		m_temp = fluid->ms_Temperature.GetfValue();
		int Index = m_cmbMaterail.GetCurSel();
		if (CB_ERR == Index)
			return;
		m_cmbMaterail.GetLBText(m_cmbMaterail.GetCurSel(),materialname);
		m_strMaterial = materialname;
		Et = material.GetMaterialEt(materialname,m_temp,0);
		Et = Et * 1000;
		fPoissons = material.GetMaterialPoissons(materialname);
		m_strPossionRatio.Format(_T("%f"),fPoissons);
		m_strElasticity.Format(_T("%f"),Et);
		m_strElasticityUnit = _T("MPa");
	}
	else
		return;
	UpdateData(FALSE);
}

BOOL DlgPipeModel::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//屏蔽对话框的“按ESC和Enter键退出"
	if(WM_KEYDOWN ==	pMsg->message)
	{
		int nKey = (int) pMsg->wParam;
		if(VK_ESCAPE == nKey||VK_RETURN == nKey)
			return TRUE;
	}
	return BaseDlg::PreTranslateMessage(pMsg);
}

void DlgPipeModel::SetLossStatus()
{
	switch(m_frictionModel) {
	case 0:
		m_cmbFriction.ShowWindow(SW_SHOW);
		m_EditFriction.ShowWindow(SW_SHOW);
		break;
	case 1:
	case 3:
	case 4:
		m_cmbFriction.ShowWindow(SW_HIDE);
		m_EditFriction.ShowWindow(SW_SHOW);
		m_strFrictionUnit.Empty();
		break;
	default:
		m_cmbFriction.ShowWindow(SW_HIDE);
		m_EditFriction.ShowWindow(SW_HIDE);
		m_strFrictionUnit.Empty();
		break;
	}
	InitUnitCbo(m_UnitSys,Diameter,m_cmbFriction,m_strFrictionUnit);
}

void DlgPipeModel::CalcWaveSpeed()
{
	UpData();
	Pipe::CalcWaveSpeed(m_manager.SysProperty().Density(),m_manager.SysProperty().BulkModulus());
	Init();
}

void DlgPipeModel::OnChangeC1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcWaveSpeed();
}
