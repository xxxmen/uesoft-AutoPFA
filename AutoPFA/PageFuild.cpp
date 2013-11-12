// PageFuild.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageFuild.h"
#include "Fuild.h"
#include "UeChartHeader.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageFuild dialog


PageFuild::PageFuild(ImpulseDataMgr &ImpulseData,UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageFuild::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_ImpulseData(ImpulseData)
	,m_cmbTemp(&m_EditTemp)
	,m_cmbViscos(&m_EditViscos)
	,m_cmbDen(&m_EditDen)
	,m_cmbBulk(&m_EditBulk)
	,m_cmbVapor(&m_EditVapor)
{
	//{{AFX_DATA_INIT(PageFuild)
	m_strName = _T("");
	m_strTemperature = _T("");
	m_strVapor = _T("");
	m_strViscos = _T("");
	m_strDensity = _T("");
	m_strBulkMudus = _T("");
	m_strTempUnit = _T("");
	m_strVaporUnit = _T("");
	m_strViscosUnit = _T("");
	m_strDensityUnit = _T("");
	m_strBulkMudusUnit = _T("");
	m_strRange = _T("");
	m_bStandard = 0;
	//}}AFX_DATA_INIT
	m_pFuild = NULL;
	m_pFuildDB = NULL;
	m_nOldKey = 0;
}


void PageFuild::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageFuild)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_EVAPOR, m_EditVapor);
	DDX_Control(pDX, IDC_EVISCOS, m_EditViscos);
	DDX_Control(pDX, IDC_ETEMP, m_EditTemp);
	DDX_Control(pDX, IDC_EDEN, m_EditDen);
	DDX_Control(pDX, IDC_EBULK, m_EditBulk);
	DDX_Control(pDX, IDC_CMBVISCOS, m_cmbViscos);
	DDX_Control(pDX, IDC_CMBVAPOR, m_cmbVapor);
	DDX_Control(pDX, IDC_CMBTEMP, m_cmbTemp);
	DDX_Control(pDX, IDC_CMBDEN, m_cmbDen);
	DDX_Control(pDX, IDC_CMBBULK, m_cmbBulk);
	DDX_Text(pDX, IDC_ENAME, m_strName);
	DDX_Text(pDX, IDC_ETEMP, m_strTemperature);
	DDX_Text(pDX, IDC_EVAPOR, m_strVapor);
	DDX_Text(pDX, IDC_EVISCOS, m_strViscos);
	DDX_Text(pDX, IDC_EDEN, m_strDensity);
	DDX_Text(pDX, IDC_EBULK, m_strBulkMudus);
	DDX_CBString(pDX, IDC_CMBTEMP, m_strTempUnit);
	DDX_CBString(pDX, IDC_CMBVAPOR, m_strVaporUnit);
	DDX_CBString(pDX, IDC_CMBVISCOS, m_strViscosUnit);
	DDX_CBString(pDX, IDC_CMBDEN, m_strDensityUnit);
	DDX_CBString(pDX, IDC_CMBBULK, m_strBulkMudusUnit);
	DDX_Text(pDX, IDC_STATICRANGE, m_strRange);
	DDX_Radio(pDX, IDC_RADIOPFA, m_bStandard);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageFuild, BaseDlg)
	//{{AFX_MSG_MAP(PageFuild)
	ON_BN_CLICKED(IDC_BCALC, OnCalc)
	ON_BN_CLICKED(IDC_BADD, OnAdd)
	ON_BN_CLICKED(IDC_RADIOPFA, OnRadiopfa)
	ON_BN_CLICKED(IDC_RADIOUSER, OnRadioUser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageFuild message handlers

void PageFuild::Init(Fuild *pFuild)
{
	m_pFuild = pFuild;
	m_pFuild->InitData();
	m_strName = Fuild::ms_Name.GetValue();
	InitNum(m_strTemperature,m_strTempUnit,Fuild::ms_Temperature);
	InitNum(m_strDensity,m_strDensityUnit,Fuild::ms_Density);
	InitNum(m_strViscos,m_strViscosUnit,Fuild::ms_Viscos);
	InitNum(m_strBulkMudus,m_strBulkMudusUnit,Fuild::ms_BulkModulus);
	InitNum(m_strVapor,m_strVaporUnit,Fuild::ms_VaporPressure);

	SetStandardStatus();
	
	BOOL bStandardFuild = FALSE;
	for(int i = 0; i < m_list.GetItemCount(); i++)
	{
		if(m_list.GetItemText(i, NULL) == m_strName)
		{
			bStandardFuild = TRUE;
		}
	}
	if(!bStandardFuild)
	{
		m_bStandard = 1;
        GetDlgItem(IDC_BCALC)->ShowWindow(FALSE);
	    SetStandardStatus();
	}
	UpdateData(FALSE);
}

BOOL PageFuild::Updata()
{
	UpdateData(TRUE);

	Fuild::ms_Name.SetValue(m_strName);
	SetNum(m_strTemperature,m_strTempUnit,Fuild::ms_Temperature);
	SetNum(m_strDensity,m_strDensityUnit,Fuild::ms_Density);
	SetNum(m_strViscos,m_strViscosUnit,Fuild::ms_Viscos);
	SetNum(m_strBulkMudus,m_strBulkMudusUnit,Fuild::ms_BulkModulus);
	SetNum(m_strVapor,m_strVaporUnit,Fuild::ms_VaporPressure);

	m_pFuild->SaveData();
	return TRUE;
}


BOOL PageFuild::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Temperature,m_cmbTemp,m_strTempUnit);
	InitUnitCbo(m_UnitSys,Density,m_cmbDen,m_strDensityUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbBulk,m_strBulkMudusUnit);
	InitUnitCbo(m_UnitSys,Viscosity,m_cmbViscos,m_strViscosUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbVapor,m_strVaporUnit);

	CRect rc;
	m_list.GetWindowRect(rc);
	m_list.InsertColumn(0,_T("流体名称"),LVCFMT_LEFT,rc.Width());
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);

	InitList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL PageFuild::PreTranslateMessage(MSG* pMsg) 
{
	if( pMsg->wParam == VK_RETURN )
	{	
		OnCalc();
		return TRUE;
	}
	return CDialog::PreTranslateMessage( pMsg );
}

void PageFuild::OnCalc() 
{
	// TODO: Add your control notification handler code here
	if(m_pFuildDB==NULL)
	{
		MessageBox(_T("请选择一种流体!"));
		return;
	}
	double dt = 0;
	if(CheckTRange(dt))
	{
		m_strVapor = m_pFuildDB->VaporPressureValue(dt);
		m_strVaporUnit = m_pFuildDB->VaporPressureUnit();

		m_strViscos = m_pFuildDB->ViscosityValue(dt);
		m_strViscosUnit = m_pFuildDB->ViscosityUnit();

		m_strDensity = m_pFuildDB->DensityValue(dt);
		m_strDensityUnit = m_pFuildDB->DensityUnit();

		m_strBulkMudus = m_pFuildDB->BulkModulusValue(dt);
		m_strBulkMudusUnit = m_pFuildDB->BulkModulusUnit();
		UpdateData(FALSE);
	}
	else
	{
		MessageBox(_T("温度超过范围!"));
	}
}

void PageFuild::InitList()
{
	FuildDatabase *pFuild = NULL;
	int i=0;
	IteratorPtr<FuildDatabase> ItPtr(m_ImpulseData.FuildMgr().CreateIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pFuild = &ItPtr->CurrentItem();
		ASSERT(pFuild != NULL);
		m_list.InsertItem(i,pFuild->Name());
		m_list.SetItemData(i,pFuild->Key());
		i++;
	}
}

void PageFuild::OnAdd() 
{
	// TODO: Add your control notification handler code here
	int nKey = 0;
	int	nIndex = m_list.GetNextItem(-1,LVNI_SELECTED);
	if(-1 != nIndex)
	{
		 nKey = m_list.GetItemData(nIndex);
		 FuildDatabase *pFuild = m_ImpulseData.FuildMgr().LookUp(nKey);
		 if(pFuild != NULL&&m_nOldKey != nKey)
		 {
			 m_nOldKey = nKey;
			 m_pFuildDB = pFuild;
			 m_strName =  pFuild->Name();
			 m_strTempUnit = pFuild->TempertureUnit();
			 m_strRange = pFuild->Range();
			 m_strTemperature = _T("");
			 m_strVapor = _T("");
			 m_strViscos = _T("");
			 m_strDensity = _T("");
			 m_strBulkMudus = _T("");
			 UpdateData(FALSE);
		 }
	}
}



void PageFuild::OnRadiopfa() 
{
	// TODO: Add your control notification handler code here
	m_bStandard = 0;
	GetDlgItem(IDC_BCALC)->ShowWindow(TRUE);
	SetStandardStatus();
}

void PageFuild::OnRadioUser() 
{
	// TODO: Add your control notification handler code here
	m_bStandard = 1;
	GetDlgItem(IDC_BCALC)->ShowWindow(FALSE);
	SetStandardStatus();
}

BOOL PageFuild::CheckTRange(double &dt)
{
	UpdateData(TRUE);
	if(m_pFuildDB == NULL)
		return TRUE;
	CString strDbUnit = m_pFuildDB->TempertureUnit();
	TransformToStd(dt,m_strTempUnit,_tcstod( m_strTemperature, NULL ));
	dt = TransformFromStd(dt,strDbUnit);
	return m_pFuildDB->IsInRange(dt);
}

void PageFuild::SetStandardStatus()
{
	if(m_bStandard==0)
	{
		m_list.ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BADD)->ShowWindow(SW_SHOW);
		m_EditVapor.SetReadOnly(TRUE);
		m_EditViscos.SetReadOnly(TRUE);
		m_EditDen.SetReadOnly(TRUE);
		m_EditBulk.SetReadOnly(TRUE);
	}
	else
	{
		m_list.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BADD)->ShowWindow(SW_HIDE);
		m_EditVapor.SetReadOnly(FALSE);
		m_EditViscos.SetReadOnly(FALSE);
		m_EditDen.SetReadOnly(FALSE);
		m_EditBulk.SetReadOnly(FALSE);
	}
}
