// pageconfigdata.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pageconfigdata.h"
#include "Pump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageConfigData dialog


PageConfigData::PageConfigData(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageConfigData::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageConfigData)
	m_strOrder = _T("2");
	//}}AFX_DATA_INIT
	m_nType = 1;
	pConfig = NULL;
}


void PageConfigData::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageConfigData)
	DDX_Control(pDX, IDC_CMBORDER, m_cmbOrder);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BFITCURVE, m_BitMap);
	DDX_Control(pDX, IDC_CMBTYPE, m_cmbCurveype);
	DDX_Control(pDX, IDC_BOXRAWDATA, m_Box1);
	DDX_Control(pDX, IDC_BOXPRAME, m_Box2);
	DDX_CBString(pDX, IDC_CMBORDER, m_strOrder);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageConfigData, BaseDlg)
	//{{AFX_MSG_MAP(PageConfigData)
	ON_BN_CLICKED(IDC_BFITCURVE, OnFitcurve)
	ON_CBN_SELCHANGE(IDC_CMBTYPE, OnSelchangeType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageConfigData message handlers

void PageConfigData::OnFitcurve() 
{
	// TODO: Add your control notification handler code here
	m_RawData.UpData(Pump::ms_Configuration.m_RawData);
	double dX[100] = {0};
	double dY[100] = {0};
	ListImp<StrArray<4> > &ref = Pump::ms_Configuration.m_RawData.m_Data.GetData();
	int nNum = ref.GetCount();
	if(nNum == 0)
	{
		pConfig->m_Num.SetValue(0);
		return;
	}

	if(!ref.ToDuoble(dX,0))
	{
		return;
	}

	pConfig->m_Num.SetValue(1);
	for(int i=0;i<m_list.GetCount();i++)
	{
		if(m_list.GetCheck(i))
		{
			if(ref.ToDuoble(dY,i+1))
			{
				Fitcurve(dX,dY,nNum,i+1);
			}
		}
	}
}

BOOL PageConfigData::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_RawData.Create(IDD_RAWDATATABLE,this);
	Combine(this,m_Box1,m_RawData);

	m_Param.Create(IDD_RAWDATATABLE,this);
	Combine(this,m_Box2,m_Param);

	CString strText;
	strText.LoadString(IDS_STRCURVERCONFIG);
	int nIndex = m_list.AddString(strText);
	if(LB_ERR != nIndex)
		m_list.SetCheck(nIndex,TRUE);
	strText.LoadString(IDS_STRCURVERNPRS);
	nIndex = m_list.AddString(strText);
	if(LB_ERR != nIndex)
		m_list.SetCheck(nIndex,TRUE);
	strText.LoadString(IDS_STRCURVERPOWER);
	nIndex = m_list.AddString(strText);
	if(LB_ERR != nIndex)
		m_list.SetCheck(nIndex,TRUE);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageConfigData::Init(Configuration &ref)
{
	pConfig = &ref;
	m_RawData.Init(ref.m_RawData);
	InitCurver();
	UpdateData(FALSE);
}

BOOL PageConfigData::UpData()
{
	UpdateData(TRUE);
	ASSERT(pConfig != NULL);
	m_RawData.UpData(pConfig->m_RawData);
	if(pConfig->m_RawData.IsEmpty())
	{//构造数据为空
		pConfig->m_Num.SetValue(0);
	}
	else
	{
		if(m_nType == 1)
		{
			OnFitcurve();
		}
		else
		{
			double dParam[5] = {0,0,0,0,0};
			UpDataCurve(pConfig->m_Curve1,dParam,0);
			UpDataCurve(pConfig->m_Curve2,dParam,0);
			UpDataCurve(pConfig->m_Curve3,dParam,0);
		}
		if(-1==pConfig->m_ID.GetValue().Find(_T("RDS")))
		{
			pConfig->CreatID();
		}
	}
	return TRUE;
}

void PageConfigData::Fitcurve(double dx[],double dy[],int nNum,int nCol)
{
	double dParam[5] = {0,0,0,0,0};
	int ma = GetOrder();
	Polyfit(dx,dy,nNum, dParam,ma);
	m_Param.SetParam(dParam,ma,nCol);
	UpDataCurve(GetCurve(nCol),dParam,ma);
	UpDataMaxFLow(dx,nNum);
}

int PageConfigData::GetOrder()
{
	m_strOrder =  GetCmbText(m_cmbOrder);
	return _ttoi(m_strOrder)+1;
}

ArrayFlyWeight<7> &PageConfigData::GetCurve(int nCol)
{
	ASSERT(pConfig != NULL);
	if(nCol ==1)
	{
		return pConfig->m_Curve1;
	}
	else if(nCol == 2)
	{
		return pConfig->m_Curve2;
	}
	else
	{
		return pConfig->m_Curve3;
	}
}

void PageConfigData::UpDataCurve(ArrayFlyWeight<7>& ref,double dParam[],int nNum)
{
	GetCurKey(m_cmbCurveype,m_nType);
	ref.SetValue(m_nType,0);
	ref.SetValue(nNum,1);
	ref.SetValue(float(dParam[0]),2);
	ref.SetValue(float(dParam[1]),3);
	ref.SetValue(float(dParam[2]),4);
	ref.SetValue(float(dParam[3]),5);
	ref.SetValue(float(dParam[4]),6);
}

void PageConfigData::UpDataMaxFLow(double dx[],int nNum)
{
	ASSERT(pConfig != NULL);
	double dMaxFlow = pConfig->m_MaxFlow.GetfValue();
	double dMax,dMin;
	MaxMin(dx,nNum,dMax,dMin);
	if(dMax>dMaxFlow)
		pConfig->m_MaxFlow.SetValue(float(dMax));
}

void PageConfigData::InitCurver()
{
	CString strText;
	strText.LoadString(IDS_STRCURVERCONFIG);
	m_Param.InsertColumn(strText,pConfig->m_Curve1.GetData(),2);
	strText.LoadString(IDS_STRCURVERNPRS);
	m_Param.InsertColumn(strText,pConfig->m_Curve2.GetData(),2);
	strText.LoadString(IDS_STRCURVERPOWER);
	m_Param.InsertColumn(strText,pConfig->m_Curve3.GetData(),2);
	m_nType = pConfig->m_Curve1.GetnValue();
	if(m_nType != 2)
	{
		m_nType = 1;
	}
	InitDataCmb(Jun::ms_CurveType,2,m_cmbCurveype,m_nType);
	CurverStatus();
}

void PageConfigData::OnSelchangeType() 
{
	// TODO: Add your control notification handler code here
	GetCurKey(m_cmbCurveype,m_nType);
	CurverStatus();
}

void PageConfigData::CurverStatus()
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


