// PageTeeWyeModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pageteewyemodel.h"
#include "TeeWye.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeModel dialog


PageTeeWyeModel::PageTeeWyeModel(TeeWye *pTeeWye,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTeeWyeModel::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageTeeWyeModel)
	m_strAngle = _T("");
	m_nType = 0;
	m_nLossType = 0;
	//}}AFX_DATA_INIT
	m_pTeeWye = pTeeWye;
	ASSERT(m_pTeeWye != NULL);
	m_pTeeWye->GetPipeID(m_nPipeId);
	BitMapID[0] = IDB_BITSHARP;
	BitMapID[1] = IDB_BITROUND;
	BitMapID[2] = IDB_BITCHANGE;
	BitMapID[3] = IDB_BITWAY;
}


void PageTeeWyeModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTeeWyeModel)
	DDX_Control(pDX, IDC_CMBC, m_cbmC);
	DDX_Control(pDX, IDC_CMBB, m_cbmB);
	DDX_Control(pDX, IDC_CMBA, m_cbmA);
	DDX_Text(pDX, IDC_CMBA, m_numA);
	DDX_Text(pDX, IDC_CMBB, m_numB);
	DDX_Text(pDX, IDC_CMBC, m_numC);
	DDX_Control(pDX, IDC_STATICMAP, m_BitMap);
	DDX_Control(pDX, IDC_EANGEL, m_EditAngle);
	DDX_Text(pDX, IDC_EANGEL, m_strAngle);
	DDX_Radio(pDX, IDC_RADIOSHARP, m_nType);
	DDX_Radio(pDX, IDC_RADIODETAILE, m_nLossType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTeeWyeModel, BaseDlg)
	//{{AFX_MSG_MAP(PageTeeWyeModel)
	ON_BN_CLICKED(IDC_RADIOSHARP, OnRadioSharp)
	ON_BN_CLICKED(IDC_RADIOROUND, OnRadioRound)
	ON_BN_CLICKED(IDC_RADIOCHANGE, OnRadioChange)
	ON_BN_CLICKED(IDC_RADIOWYE, OnRadioWye)
	ON_CBN_SELCHANGE(IDC_CMBA, OnSelchangeA)
	ON_CBN_SELCHANGE(IDC_CMBB, OnSelchangeB)
	ON_CBN_SELCHANGE(IDC_CMBC, OnSelchangeC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeModel message handlers

BOOL PageTeeWyeModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitCbm(m_cbmA);
	InitCbm(m_cbmB);
	InitCbm(m_cbmC);
	SetSelKey(m_cbmA,m_nPipeId[0]);
	SetSelKey(m_cbmB,m_nPipeId[1]);
	SetSelKey(m_cbmC,m_nPipeId[2]);
	m_cbmA.GetWindowText(m_numA);
	m_cbmB.GetWindowText(m_numB);
	m_cbmC.GetWindowText(m_numC);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageTeeWyeModel::Init()
{
	m_nType = TeeWye::ms_Type.GetnValue();
	m_strAngle = TeeWye::ms_Angle.GetValue();
	m_nLossType = TeeWye::ms_Model.GetnValue();
	m_nLossType -= 1;
	UpdateData(FALSE);
	SetTypeStatus();
}

BOOL PageTeeWyeModel::UpData()
{
	UpdateData(TRUE);
	m_nLossType += 1;
	TeeWye::ms_Type.SetValue(m_nType);
    TeeWye::ms_Angle.SetValue(m_strAngle);
    TeeWye::ms_Model.SetValue(m_nLossType);
	GetCurKey(m_cbmA,m_nPipeId[0]);
	GetCurKey(m_cbmB,m_nPipeId[1]);
	GetCurKey(m_cbmC,m_nPipeId[2]);
	m_cbmA.GetWindowText(m_numA);
	m_cbmB.GetWindowText(m_numB);
	m_cbmC.GetWindowText(m_numC);
	if(m_pTeeWye !=NULL)
	{
		m_pTeeWye->SetPipeID(m_nPipeId);
	}
	else
	{
		ASSERT(FALSE);
	}
	return TRUE;
}

void PageTeeWyeModel::SetTypeStatus()
{
	if(m_nType>=0 && m_nType<=3)
	{
		m_bitmap.DeleteObject();
		m_bitmap.LoadBitmap(BitMapID[m_nType]);
		m_BitMap.SetBitmap(m_bitmap);
	}
}

void PageTeeWyeModel::OnRadioSharp() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetTypeStatus();
}

void PageTeeWyeModel::OnRadioRound() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	SetTypeStatus();
}

void PageTeeWyeModel::OnRadioChange() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	SetTypeStatus();
}

void PageTeeWyeModel::OnRadioWye() 
{
	// TODO: Add your control notification handler code here
	m_nType = 3;
	SetTypeStatus();
}

void PageTeeWyeModel::InitCbm(CComboBox &cbm)
{
	CString strText;
	cbm.ResetContent();
	for(int i=0;i<3;i++)
	{
		strText.Format(_T("P%d"),abs(m_nPipeId[i]));
		cbm.InsertString(i,strText);
		cbm.SetItemData(i,m_nPipeId[i]);
	}
}

void PageTeeWyeModel::OnSelchangeA() 
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	ChangeLink(m_cbmA,m_numA);
	UpData();
}

void PageTeeWyeModel::OnTeeDetail()
{
	m_nLossType = 0;
}

void PageTeeWyeModel::OnTeeSimple()
{
	m_nLossType = 1;
}

void PageTeeWyeModel::OnSelchangeB() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
	ChangeLink(m_cbmB,m_numB);
	UpData();
}

void PageTeeWyeModel::OnSelchangeC() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
	ChangeLink(m_cbmC,m_numC);
	UpData();
}



CComboBox& PageTeeWyeModel::Find(CString strText)
{
	CString strTemp;
//	m_cbmA.GetWindowText(strTemp);
	strTemp = m_numA;
	if(strTemp.CollateNoCase(strText)==0)
		return m_cbmA;
//	m_cbmB.GetWindowText(strTemp);
	strTemp = m_numB;
	if(strTemp.CollateNoCase(strText)==0)
		return m_cbmB;
//	m_cbmC.GetWindowText(strTemp);
	strTemp = m_numC;
	if(strTemp.CollateNoCase(strText)==0)
		return m_cbmC;
	ASSERT(FALSE);
	return m_cbmA;
}

void PageTeeWyeModel::ChangeLink(CComboBox &cmb,CString &m_num)
{
	CString strOldText;
	CString strNewText;
	strOldText = m_num;
	int nCur = cmb.GetCurSel();
	if(CB_ERR != nCur)
	{
		//cmb.GetWindowText(strOldText);
		cmb.GetLBText(nCur,strNewText);
		int chang = Find(strNewText).SelectString(-1,strOldText);
		Find(strNewText).SetCurSel(chang);
	}
}
