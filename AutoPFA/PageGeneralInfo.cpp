// PageGeneralInfo.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGeneralInfo.h"
#include "NetModel.h"
#include "Fuild.h"
#include "Condition.h"
#include "SteadySet.h"
#include "PFAOutModel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGeneralInfo dialog
class NetModel;

PageGeneralInfo::PageGeneralInfo(CWnd* pParent /*=NULL*/)
	: PageDataList(pParent)
{
	//{{AFX_DATA_INIT(PageGeneralInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageGeneralInfo::DoDataExchange(CDataExchange* pDX)
{
	PageDataList::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGeneralInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGeneralInfo, PageDataList)
	//{{AFX_MSG_MAP(PageGeneralInfo)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGeneralInfo message handlers

void PageGeneralInfo::LoadData(NetModel *pNetModel)
{
	ASSERT(pNetModel != NULL);
	m_list.DeleteAllItems();
	ComponentManager &Manager = pNetModel->m_compManager;
	CalcManager &Calc = pNetModel->m_calcManager;
	Fuild* pFuild = Manager.SysProperty().GetFuild();
	Condition *pCondition = Manager.SysProperty().GetCondition();
	SteadySet *pSteadySet = Calc.GetSteadySet();
	
	Load(Manager);
	Load(pSteadySet);
	Load(pFuild);
	Load(pCondition);
}

BOOL PageGeneralInfo::OnInitDialog() 
{
	PageDataList::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	m_list.InsertColumn(0,_T(""));
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageGeneralInfo::OnSize(UINT nType, int cx, int cy) 
{
	PageDataList::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	if(m_list.GetSafeHwnd())
	{
		m_list.SetColumnWidth(0,rc.Width()-10);
	}
}

void PageGeneralInfo::Load(ComponentManager &Manager)
{
	CString strText;
	m_list.InsertItem(m_list.GetItemCount(),_T(""));
	strText.Format(_T("管道数量=%d"),Manager.GetPipeNum());
	m_list.InsertItem(m_list.GetItemCount(),strText);
	strText.Format(_T("连接元件数量=%d"),Manager.GetJunNum());
	m_list.InsertItem(m_list.GetItemCount(),strText);
}

void PageGeneralInfo::Load(ScenarioObject* pObject)
{
	CString strText;
	CString strData;
	m_list.InsertItem(m_list.GetItemCount(),_T(""));
	NameArray &array = pObject->GetArray();
	int n = array.GetSize();
	for(int i=0;i<n;i++)
	{
		if(array[i].IsShow())
		{
			strText = array[i].Name() + _T("=");
			const FlyWeight *pFly = pObject->GetValue(array[i].Key());
			ASSERT(pFly != NULL);
			pFly->GetValue(strData);
			strText += strData;
			m_list.InsertItem(m_list.GetItemCount(),strText);
		}
	}
}


void PageGeneralInfo::LoadData(PFAOutModel &outModel)
{
	CString strText;
	SteadyOutModel &out = outModel.SteadyOut();
	m_list.InsertItem(m_list.GetItemCount(),_T(""));
	strText = _T("分析运行模型时间：")+out.CurTime();
	m_list.InsertItem(m_list.GetItemCount(),strText);
	strText.Format(_T("稳态计算迭代次数=%d"),out.Iterations());
	m_list.InsertItem(m_list.GetItemCount(),strText);
	if(out.OK())
	{
		strText = _T("稳态计算成功!");
	}
	else
	{
		strText = _T("稳态计算迭代次数超过最大迭代次数未满足误差要求，可能存在0流量管道请尝试使用绝对误差");
	}
	m_list.InsertItem(m_list.GetItemCount(),strText);
}
