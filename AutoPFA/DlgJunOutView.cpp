// DlgJunOutView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgJunOutView.h"
#include "PFAOutModel.h"
#include "Component.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgJunOutView dialog

OutAttrArray DlgJunOutView::m_staticJunArray;

DlgJunOutView::DlgJunOutView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgJunOutView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pComponetMgr = NULL;
	m_pUnitSys     = NULL;
}

DlgJunOutView::~DlgJunOutView()
{
	m_staticJunArray.RemoveAll();
}

void DlgJunOutView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgJunOutView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgJunOutView, DlgTabView)
	//{{AFX_MSG_MAP(DlgJunOutView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgJunOutView message handlers


BOOL DlgJunOutView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRALLJUN,&m_pageList[0],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRAREACHANGE,&m_pageList[1],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRASSIGNFLOW,&m_pageList[2],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRASSIGNPRESS,&m_pageList[3],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRBRANCH,&m_pageList[4],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRCHECK,&m_pageList[5],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRCONTROL,&m_pageList[6],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRDEADEND,&m_pageList[7],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRGASACCUM,&m_pageList[8],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRGENERAL,&m_pageList[9],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRLIQUIDACCUM,&m_pageList[10],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRPUMP,&m_pageList[11],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRRELIEF,&m_pageList[12],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRRESERVIOR,&m_pageList[13],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRSPRAY,&m_pageList[14],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRSURGE,&m_pageList[15],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRTEEWYE,&m_pageList[16],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRBREAKER,&m_pageList[17],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRVALVE,&m_pageList[18],IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRBEND,&m_pageList[19],IDD_DATATABLE,FALSE);
	m_tab.Show();
	m_TypeList[0] = 0;
	m_TypeList[1] = 5;
	m_TypeList[2] = 3;
	m_TypeList[3] = 4;
	m_TypeList[4] = 1;
	m_TypeList[5] = 10;
	m_TypeList[6] = 9;
	m_TypeList[7] = 11;
	m_TypeList[8] = 22;
	m_TypeList[9] = 20;
	m_TypeList[10] = 23;
	m_TypeList[11] = 17;
	m_TypeList[12] = 21;
	m_TypeList[13] = 2;
	m_TypeList[14] = 16;
	m_TypeList[15] = 24;
	m_TypeList[16] = 7;
	m_TypeList[17] = 25;
	m_TypeList[18] = 8;
	m_TypeList[19] = 6;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgJunOutView::LoadData( Scenario* pScenario, PFAOutModel &outModel, UnitSubSystem* pUnitSys )
{
	if ( pScenario == NULL || pUnitSys == NULL )
	{
		MessageBox( _T("导入数据失败") );
		return ;
	}

	HideAllPage();//先隐藏所有页面

    m_pComponetMgr = pScenario->GetCompManager();
	m_pUnitSys     = pUnitSys;

	NetModel* pNetModel    = pScenario->GetNetModel();
	StmOutMgr &outMgr = outModel.SteadyOut().ComponentOutMgr().JunOutMgr();
	OutAttrArray &attrArray = outMgr.GetArray();
	if( 0 == attrArray.GetSize() )
	{
		return;
	}


//	CString str[50];
	CString str1[50];//保存Key;
	CString strTemp1;
//	CString strTemp;
	int k=0;
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	strTemp1 = outMgr.m_OutPutData.JunDataOrder();
//	strTemp = outMgr.m_OutPutData.JunUnitOrder();
	InitData(strTemp1,str1);
//	InitUnit(strTemp,str);

	for(int i=0; i<nCount; i++)
	{
		int j;   
		m_staticJunArray.RemoveAll();
		m_staticJunArray.Add(attrArray.GetAt(0));
		for (k = 0; k < 30;k++)
		{
			if (str1[k] == "0")
					break;
			for(j = 0; j < 30; j++)
			{	
				if (str1[k] != "0" && str1[k] == outMgr.m_OutPutSys.GetJunOutArray()[j].GetKey())
				{
					m_staticJunArray.Add(attrArray.GetAt(j+1));
					break;
				}
			}
		}

		m_pageList[i].ComponentType( UeCoponentType::eJun );
		m_pageList[i].LoadComponentMgr( m_pComponetMgr, m_pUnitSys );
		SetOutPutArray(outMgr,pScenario->GetJunArray());
		m_pageList[i].LoadData(outMgr,m_staticJunArray,m_TypeList[i]);			
	//	for (j = 0; j < m_staticJunArray.GetSize(); j++)
	//	{
	//		outMgr.GetArray().SetAt(j, m_staticJunArray.GetAt(j));
	//	}
	}
	ShowPageHasData();
}

void DlgJunOutView::SetOutPutArray(OutMgr &mgr, CStringArray *Array)
{
	ComponentStmOut *pStmOut = NULL;
	if(Array->GetSize() != 0)
		Array->RemoveAll();
	IteratorPtr<ComponentStmOut> iteratorPtr(mgr.CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pStmOut = &iteratorPtr->CurrentItem();
		int n = mgr.GetArray().GetSize();
		for(int i=0;i<n;i++)
		{
			CString strText = pStmOut->GetValue(mgr.GetArray()[i].Key());//数组不一致
			Array->Add(strText);
		}

	}	
}

void DlgJunOutView::HideAllPage()
{
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	for(int i=0; i<nCount; i++)
	{
		m_tab.ShowPage(i,FALSE);
		m_pageList[i].HasData(FALSE);
	}
}

void DlgJunOutView::InitData(CString InData,CString str[50],TCHAR chSeparator)
{
	InData.TrimLeft();
	int nIdex=0;
	int i;
	int strj=0;
	for (i=0;i<50;i++)
	{
		nIdex=InData.Find(chSeparator);
		strj++;
		if (nIdex==-1)
		{
			InData.TrimRight();
			str[strj-1]=InData;
			break;
		}
		if (nIdex==0)
		{
			InData.Delete(0,1);
			continue;
		}
		str[i]=InData.Left(nIdex);
		InData.Delete(0,nIdex+1);		
	}
	
	for (;strj<50;strj++)
	{
		str[strj]="0";
	}
	
}

void DlgJunOutView::ShowPageHasData()
{
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	int i;
	for( i=0; i<nCount; i++)
	{
		m_tab.ShowPage(i,m_pageList[i].HasData());
		m_pageList[i].AutoSize();
	}
	
	for(i=0; i<nCount; i++)
	{
		if(m_pageList[i].HasData())
		{
			m_tab.SetCurSel(i);
			break;
		}
		m_tab.SetCurSel(i+1);
	}
}