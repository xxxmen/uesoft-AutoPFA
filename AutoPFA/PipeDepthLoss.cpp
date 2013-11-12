// PipeDepthLoss.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PipeDepthLoss.h"
#include "Jun.h"
#include "GlobalUse.h"
#include "Reservoir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PipeDepthLoss dialog


PipeDepthLoss::PipeDepthLoss(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PipeDepthLoss::IDD, pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PipeDepthLoss)
	m_nDepthOrEle = 0;
	m_nType = 3;
	m_strDepthEleUnit = _T("");
	//}}AFX_DATA_INIT
}


void PipeDepthLoss::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PipeDepthLoss)
	DDX_Control(pDX, IDC_CMBDEPTNELEUNIT, m_cmbDepthEleUnit);
	DDX_Radio(pDX, IDC_RADIODEPTH, m_nDepthOrEle);
	DDX_Radio(pDX, IDC_RADIOSHARP, m_nType);
	DDX_CBString(pDX, IDC_CMBDEPTNELEUNIT, m_strDepthEleUnit);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_PIPELIST, m_list);
}


BEGIN_MESSAGE_MAP(PipeDepthLoss, BaseDlg)
	//{{AFX_MSG_MAP(PipeDepthLoss)
	ON_BN_CLICKED(IDC_RADIODEPTH, OnRadioDepth)
	ON_BN_CLICKED(IDC_RADIOELE, OnRadioEle)
	ON_BN_CLICKED(IDC_RADIOSHARP, OnRadioSharp)
	ON_BN_CLICKED(IDC_RADIOROUND, OnRadioRound)
	ON_BN_CLICKED(IDC_RADIOREENTRART, OnRadioReentrart)
	ON_BN_CLICKED(IDC_RADIOCUSTOM, OnRadioCustom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PipeDepthLoss message handlers

BOOL PipeDepthLoss::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbDepthEleUnit,m_strDepthEleUnit);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PipeDepthLoss::InitListHeader()
{
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T("管道"));
    m_list.InsertColumn(_T("流向"));
	m_list.InsertColumn(_T("类型"));
	m_list.InsertColumn(_T("r/D"));
	m_list.InsertColumn(_T("K-流入管道"));
	m_list.InsertColumn(_T("K-流出管道"));
	m_list.InsertColumn(_T("深度"));
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount(4);
	m_list.SetColumnCount(7);
	// m_list.SetEditable(FALSE);
	
}

void PipeDepthLoss::Init()
{
	InitListHeader();
	InitListData();
	CString strTemp = Reservoir::ms_EleOrDepthUnit.GetUnit();
	if(!strTemp.IsEmpty()&& strTemp.CompareNoCase(_T("None"))!=0)
		m_strDepthEleUnit = strTemp;
	m_nDepthOrEle = abs(Reservoir::ms_EleOrDepthType.GetnValue());
	
	SetDepthStatus();
	UpdateData(FALSE);
}

BOOL PipeDepthLoss::UpData()
{
	UpdateData(TRUE);
	UpDataListData();
	SetNum(_T("0"),m_strDepthEleUnit,Reservoir::ms_EleOrDepthUnit);
	CString strTemp;
	strTemp.Format(_T("%d"),-m_nDepthOrEle);
	Reservoir::ms_EleOrDepthType.SetValue(strTemp);
	return TRUE;
}


void PipeDepthLoss::InitListData()
{
	InitPipeDir(Jun::ms_PipeID,m_list);

	TableFlyWeight<6>&ref = Reservoir::ms_PipeInfo;
	StrArray<6> *pArray = NULL;
	CString strKey;
	int n = m_list.GetRowCount();
	for(int i=1;i<n;i++)
	{
//		assert(ref.GetCount()== n-1);
		strKey = m_list.GetCell(i,0)->GetText();
		if(ref.LookUp(pArray,_ttoi(strKey)))
		{
			m_list.SetItemText(i,2,pArray->Data(3));
			m_list.SetItemText(i,3,pArray->Data(4));
			m_list.SetItemText(i,4,pArray->Data(1));
			m_list.SetItemText(i,5,pArray->Data(2));
			m_list.SetItemText(i,6,pArray->Data(5));
		}
		else
		{
//			assert(FALSE);
		}
	}
}

BOOL PipeDepthLoss::UpDataListData()
{
	TableFlyWeight<6>&ref = Reservoir::ms_PipeInfo;
	StrArray<6> *pArray = NULL;
	CString strKey; 
	CString strData;
	int n = m_list.GetRowCount();
	for(int i=1;i<n;i++)
	{
		strKey = m_list.GetCell(i,0)->GetText();
		if(ref.LookUp(pArray,_ttoi(strKey)))
		{
			strData = m_list.GetItemText(i,2);
			pArray->Data(strData,3);
			strData = m_list.GetItemText(i,3);
			pArray->Data(strData,4);
			strData = m_list.GetItemText(i,4);
			pArray->Data(strData,1);
			strData = m_list.GetItemText(i,5);
			pArray->Data(strData,2);
			strData = m_list.GetItemText(i,6);
			pArray->Data(strData,5);
		}
		else
		{
//			assert(FALSE);
		}
	}
	return TRUE;
}

void PipeDepthLoss::OnRadioDepth() 
{
	// TODO: Add your control notification handler code here
	m_nDepthOrEle = 0;
	SetDepthStatus();
}

void PipeDepthLoss::OnRadioEle() 
{
	// TODO: Add your control notification handler code here
	m_nDepthOrEle = 1;
	SetDepthStatus();
}

void PipeDepthLoss::OnRadioSharp() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	CCellID cell = m_list.GetFocusCell();
    if(!m_list.IsValid(cell))
    {
        return;
    }
}

void PipeDepthLoss::OnRadioRound() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	CCellID cell = m_list.GetFocusCell();
    if(!m_list.IsValid(cell))
    {
        return;
    }
}

void PipeDepthLoss::OnRadioReentrart() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	CCellID cell = m_list.GetFocusCell();
    if(!m_list.IsValid(cell))
    {
        return;
    }
}

void PipeDepthLoss::OnRadioCustom() 
{
	// TODO: Add your control notification handler code here
	m_nType = 3;
	CCellID cell = m_list.GetFocusCell();
    if(!m_list.IsValid(cell))
    {
        return;
    }
}

BOOL PipeDepthLoss::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	NM_GRIDVIEW * m_GridView=(NM_GRIDVIEW *) lParam;
	if(IDC_PIPELIST==wParam&&m_GridView->hdr.code ==NM_CLICK)
	{
		
	}
	return BaseDlg::OnNotify(wParam, lParam, pResult);
}

void PipeDepthLoss::SetDepthStatus()
{
	if(m_nDepthOrEle == 0)
	{
		m_list.SetItemText(0, 6, _T("深度"));
	}
	else
	{
		m_list.SetItemText(0, 6, _T("标高"));
	}
	m_list.RedrawCell(0,6);
}
