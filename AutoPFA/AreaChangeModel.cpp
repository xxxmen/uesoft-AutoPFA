// AreaChangeModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "AreaChangeModel.h"
#include "GlobalUse.h"
#include "AreaChange.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AreaChangeModel dialog


AreaChangeModel::AreaChangeModel(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(AreaChangeModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_manager(manager)
{
	//{{AFX_DATA_INIT(AreaChangeModel)
	m_strAngle = _T("");
	m_strK = _T("");
	m_nType = 2;
	//}}AFX_DATA_INIT
	m_InPipeID  = 0;
	m_OutPipeID = 0;
	BitMapID[0] = IDB_BITCONICALE;
	BitMapID[1] = IDB_BITCONICALE;
	BitMapID[2] = IDB_BITCONICALC;
	BitMapID[3] = IDB_BITCONICALC;
	BitMapID[4] = IDB_BITABRUPTE;
	BitMapID[5] = IDB_BITABRUPTC;
}


void AreaChangeModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AreaChangeModel)
	DDX_Control(pDX, IDC_BITMAP, m_BitMap);
	DDX_Control(pDX, IDC_EK, m_EditK);
	DDX_Control(pDX, IDC_EANGEL, m_EditAngle);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_Text(pDX, IDC_EANGEL, m_strAngle);
	DDX_Text(pDX, IDC_EK, m_strK);
	DDX_Radio(pDX, IDC_RADIOCONICAL, m_nType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AreaChangeModel, BaseDlg)
	//{{AFX_MSG_MAP(AreaChangeModel)
	ON_BN_CLICKED(IDC_RADIOCONICAL, OnRadioConical)
	ON_BN_CLICKED(IDC_RADIOABRUPT, OnRadioAbrupt)
	ON_BN_CLICKED(IDC_RADIOCUSTOM, OnRadioCustom)
	ON_EN_CHANGE(IDC_EANGEL, OnChangeAngel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AreaChangeModel message handlers

BOOL AreaChangeModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
    m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void AreaChangeModel::Init(int nId1,int nId2)
{
	m_InPipeID = nId1;
	m_OutPipeID = nId2;
	m_dlgBasisArea.Init(AreaChange::ms_BasisArea);
	m_nType = AreaChange::ms_Type.GetnValue();
	m_strAngle = AreaChange::ms_Angle.GetValue();
	m_strK     = AreaChange::ms_K.GetValue();
	SetControlStatus();
	UpdateData(FALSE);
	SetTypeModel();
	CalcK();
}

BOOL AreaChangeModel::UpData()
{
	UpdateData(TRUE);
	m_dlgBasisArea.UpData(AreaChange::ms_BasisArea);
	AreaChange::ms_Type.SetValue(m_nType);
	AreaChange::ms_Angle.SetValue(m_strAngle);
	AreaChange::ms_K.SetValue(m_strK);
	return TRUE;
}

void AreaChangeModel::OnRadioConical() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	CalcK();
	SetControlStatus();
	SetTypeModel();
}

void AreaChangeModel::OnRadioAbrupt() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	CalcK();
	SetControlStatus();
	SetTypeModel();
}

void AreaChangeModel::OnRadioCustom() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	SetControlStatus();
	SetTypeModel();
}

void AreaChangeModel::SetControlStatus()
{
	switch(m_nType) {
	case 0: 
		m_EditAngle.EnableWindow(TRUE);
		m_EditK.SetReadOnly(TRUE);
		break;
	case 1: 
		m_EditAngle.EnableWindow(FALSE);
		m_EditK.SetReadOnly(TRUE);
		break;
	case 2: 
		m_EditAngle.EnableWindow(FALSE);
		m_EditK.SetReadOnly(FALSE);
		break;
	default:
		break;
	}
}

BOOL AreaChangeModel::PreTranslateMessage(MSG* pMsg) 
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

void AreaChangeModel::CalcK()
{
	double dAreaUp = 0;
	double dAreaDown = 0;
	double temp = 0;
	GetArea(dAreaUp,dAreaDown);
	UpData();
// 	if (m_dlgBasisArea.m_nRefType == 1)
// 	{
// 		temp = dAreaUp;
// 		dAreaUp = dAreaDown;
// 		dAreaDown = temp;
// 	}
	AreaChange::CalcK(dAreaUp,dAreaDown,m_dlgBasisArea.m_nRefType,_tcstod(m_dlgBasisArea.GetArea(), NULL ));
	m_strK = AreaChange::ms_K.GetValue();
	UpdateData(FALSE);
}

void AreaChangeModel::OnChangeAngel() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcK();
}

void AreaChangeModel::GetArea(double &dUp, double &dDown)
{
	dUp = m_manager.GetPipeArea(m_InPipeID);
	dDown = m_manager.GetPipeArea(m_OutPipeID);
}

void AreaChangeModel::SetTypeModel()
{
	UpData();
	double dAreaUp = 0;
	double dAreaDown = 0;
	GetArea(dAreaUp,dAreaDown);
	int Index = AreaChange::AreaType(dAreaUp,dAreaDown);
	if(Index>0&&Index<7)
	{
		m_bitmap.DeleteObject();
		m_bitmap.LoadBitmap(BitMapID[Index-1]);
		m_BitMap.SetBitmap(m_bitmap);
	}
	else
	{
		m_BitMap.SetBitmap(NULL);
	}
}
