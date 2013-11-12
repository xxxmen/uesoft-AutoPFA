// PageCurveData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageCurveData.h"
#include "Jun.h"
#include "CurveWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCurveData dialog


PageCurveData::PageCurveData(CWnd* pParent /*=NULL*/)
	: CDialog(PageCurveData::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageCurveData)
		// NOTE: the ClassWizard will add member initialization here
	m_strOrder = _T("2");
	//}}AFX_DATA_INIT
	m_nType = 1;
	pRef = NULL;
}


void PageCurveData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCurveData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_CMBORDER, m_cmbOrder);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BFITCURVE, m_BitMap);
	DDX_Control(pDX, IDC_CMBTYPE, m_cmbCurveype);
	DDX_Control(pDX, IDC_BOXRAWDATA, m_Box1);
	DDX_Control(pDX, IDC_BOXPRAME, m_Box2);
	DDX_CBString(pDX, IDC_CMBORDER, m_strOrder);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCurveData, CDialog)
	//{{AFX_MSG_MAP(PageCurveData)
	ON_BN_CLICKED(IDC_BFITCURVE, OnFitcurve)
	ON_CBN_SELCHANGE(IDC_CMBTYPE, OnSelchangeType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCurveData message handlers


void PageCurveData::OnFitcurve() 
{
	// TODO: Add your control notification handler code here
	m_RawData.UpData(Jun::ms_RawData);
	double dX[100] = {0};
	double dY[100] = {0};
	ListImp<StrArray<2> > &ref = Jun::ms_RawData.m_Data.GetData();
	int nNum = ref.GetCount();
	if(!ref.ToDuoble(dX,0))
	{
		return;
	}
	if(ref.ToDuoble(dY,1))
	{
		Fitcurve(dX,dY,nNum);
	}
}

BOOL PageCurveData::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_RawData.Create(IDD_RAWDATATABLE,this);
	Combine(this,m_Box1,m_RawData);

	m_Param.Create(IDD_RAWDATATABLE,this);
	Combine(this,m_Box2,m_Param);

	CString strText;
	strText.LoadString(IDS_STRPRESSLOSS);
	int nIndex = m_list.AddString(strText);
	if(LB_ERR != nIndex)
		m_list.SetCheck(nIndex,TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageCurveData::Init(ArrayFlyWeight<13>& ref)
{
	pRef = &ref;
	m_RawData.Init(Jun::ms_RawData);
	InitCurver();
	UpdateData(FALSE);
}

BOOL PageCurveData::UpData()
{
	UpdateData(TRUE);
	m_RawData.UpData(Jun::ms_RawData);
	if(m_nType == 1)
	{
		OnFitcurve();
	}
	else
	{
		double dParam[5] = {0,0,0,0,0};
		UpDataCurve(dParam,0);
	}
	if(-1==Jun::ms_RawKey.GetValue().Find(_T("RDS")))
	{
		Jun::CreatRawKey();
	}
	return TRUE;
}

void PageCurveData::Fitcurve(double dx[],double dy[],int nNum)
{
	double dParam[5] = {0,0,0,0,0};
	int ma = GetOrder();
	Polyfit(dx,dy,nNum, dParam,ma);
	m_Param.SetParam(dParam,ma,1);
	UpDataCurve(dParam,ma);
	UpDataMaxFLow(dx,nNum);
}

int PageCurveData::GetOrder()
{
	m_strOrder =  GetCmbText(m_cmbOrder);
	return _ttoi(m_strOrder)+1;
}


void PageCurveData::UpDataCurve(double dParam[],int nNum)
{
	GetCurKey(m_cmbCurveype,m_nType);
	CurveWrapper wrapper(*pRef);
	wrapper.CurveType(m_nType);
	wrapper.PrameNum(nNum);
	wrapper.SetPrame(dParam);
}

void PageCurveData::UpDataMaxFLow(double dx[],int nNum)
{
	CurveWrapper wrapper(*pRef);
	double dMaxFlow = wrapper.MaxValue();
	double dMax,dMin;
	MaxMin(dx,nNum,dMax,dMin);
	if(dMax>dMaxFlow)
		wrapper.MaxValue(float(dMax));
}

void PageCurveData::InitCurver()
{
	CString strText;
	strText.LoadString(IDS_STRPRESSLOSS);
	m_Param.InsertColumn(strText,pRef->GetData(),8);
	CurveWrapper wrapper(*pRef);
	m_nType = wrapper.CurveType();
	if(m_nType != 2)
	{
		m_nType = 1;
	}
	InitDataCmb(Jun::ms_CurveType,2,m_cmbCurveype,m_nType);
	CurverStatus();
}

void PageCurveData::OnSelchangeType() 
{
	// TODO: Add your control notification handler code here
	GetCurKey(m_cmbCurveype,m_nType);
	CurverStatus();
}

void PageCurveData::CurverStatus()
{
	if(m_nType == 2)
	{
		GetDlgItem(IDC_BFITCURVE)->EnableWindow(FALSE);
		m_cmbOrder.EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_BFITCURVE)->EnableWindow(TRUE);
		m_cmbOrder.EnableWindow(TRUE);
	}
}


