// BranchPage1.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "BranchPage1.h"
#include "Branch.h"
#include "AssignedPressure.h"
#include "Surge.h"
#include "GlobalUse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BranchPage1 dialog


BranchPage1::BranchPage1(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(BranchPage1::IDD, pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(BranchPage1)
	m_strEleUnit = _T("");
	//}}AFX_DATA_INIT
}


void BranchPage1::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BranchPage1)
	DDX_Control(pDX, IDC_CMBElEUNIT, m_cmbEleUnit);
	DDX_CBString(pDX, IDC_CMBElEUNIT, m_strEleUnit);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LISTCOEF, m_list);
}


BEGIN_MESSAGE_MAP(BranchPage1, BaseDlg)
	//{{AFX_MSG_MAP(BranchPage1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BranchPage1 message handlers


void BranchPage1::InitListHeader()
{
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T("管道"));
    m_list.InsertColumn(_T("流向"));
	m_list.InsertColumn(_T("K-流入管道"));
	m_list.InsertColumn(_T("K-流出管道"));
	m_list.InsertColumn(_T("高于标高距离"));
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount(2);
	m_list.SetColumnCount(5);
}

BOOL BranchPage1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbEleUnit,m_strEleUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void BranchPage1::Init(TableFlyWeight<4>&ref,StrFlyWeight &ref1)
{
	InitListHeader();
	InitPipeDir(Jun::ms_PipeID,m_list);
	InitEleK(ref);

	CString strTemp = ref1.GetValue();
	if(!strTemp.IsEmpty()
	   && strTemp.CompareNoCase(_T("None"))!=0)
		m_strEleUnit = strTemp;
	UpdateData(FALSE);
}


void BranchPage1::InitEleK(TableFlyWeight<4>&ref)
{
	StrArray<4> *pArray = NULL;
	CString strKey;
	int n = m_list.GetRowCount();
	for(int i=1;i<n;i++)
	{
//		assert(ref.GetCount()== n-1);
		strKey = m_list.GetCell(i,0)->GetText();
		if(ref.LookUp(pArray,_ttoi(strKey)))
		{
			for(int j=1;j<4;j++)
			{
				m_list.SetItemText(i,j+1,pArray->Data(j));
			}
		}
		else
		{
			for(int j=1;j<4;j++)
			{
				m_list.SetItemText(i,j+1,_T("0"));
			}
		}
	}
}

BOOL BranchPage1::UpData(TableFlyWeight<4>&ref,StrFlyWeight &ref1)
{
	UpdateData(TRUE);
    UpDataEleK(ref);
	ref1.SetValue(m_strEleUnit);
	return TRUE;
}


BOOL BranchPage1::UpDataEleK(TableFlyWeight<4>&ref)
{
	StrArray<4> *pArray = NULL;
	CString strKey; 
	CString strData;
	int n = m_list.GetRowCount();
	for(int i=1;i<n;i++)
	{
		strKey = m_list.GetCell(i,0)->GetText();
		if(ref.LookUp(pArray,_ttoi(strKey)))
		{
			for(int j=1;j<4;j++)
			{
				strData = m_list.GetItemText(i,j+1);
				pArray->Data(strData,j);
			}
		}
		else
		{
			
		}
	}
	return TRUE;
}

BOOL BranchPage1::PreTranslateMessage(MSG* pMsg) 
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
