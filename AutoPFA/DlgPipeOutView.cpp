// DlgPipeOutView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgPipeOutView.h"
#include "PFAOutModel.h"
#include "PipeTranOutMgr.h"
#include "Component.h"
#include "ComponentTranOut.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPipeOutView dialog
CArray<OutDataAttr,OutDataAttr> DlgPipeOutView::m_staticArray;
CArray<OutDataAttr,OutDataAttr> DlgPipeOutView::m_staticArrayPage2;
CArray<OutDataAttr,OutDataAttr> DlgPipeOutView::m_staticArrayPage3;
CArray<OutDataAttr,OutDataAttr> DlgPipeOutView::m_staticPipeArray;
OutAttrArray DlgPipeOutView::m_staticTranArray;
OutAttrArray DlgPipeOutView::m_staticMaxMinArray;
//OutAttrArray DlgPipeOutView::m_staticPipeArray;


DlgPipeOutView::DlgPipeOutView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgPipeOutView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pComMgr   = NULL;
	m_pUnitSys  = NULL;
}

DlgPipeOutView::~DlgPipeOutView()
{
	m_staticArray.RemoveAll();
	m_staticArrayPage2.RemoveAll();
	m_staticArrayPage3.RemoveAll();
}

void DlgPipeOutView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPipeOutView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPipeOutView, DlgTabView)
	//{{AFX_MSG_MAP(DlgPipeOutView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPipeOutView message handlers

BOOL DlgPipeOutView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRPIPE,&m_page1,IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRTRANOUTPUT,&m_page2,IDD_DATATABLE,FALSE);
	m_tab.AddPage(IDS_STRTRANMAXMIN,&m_page3,IDD_DATATABLE,FALSE);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgPipeOutView::LoadData(Scenario* pScenario, PFAOutModel &outModel, UnitSubSystem* pUnitSys)
{
	NetModel* pNetModel = pScenario->GetNetModel();
	ComponentManager* pComMgr = pScenario->GetCompManager();

	m_pComMgr  = pComMgr;
	m_pUnitSys = pUnitSys;

	OutMgr &outMgr1 = outModel.SteadyOut().ComponentOutMgr().PipeOutMgr();
	PipeTranOutMgr &outMgr2 = outModel.TransOut().ComponentOutMgr().PipeOutMgr();

	SetOutPutArray(outMgr1,pScenario->GetPipeSteadyArray());
	//SetOutPutArray(outMgr2,pScenario->GetPipeStationArray());
	SetTranPutArray(outMgr2,pScenario->GetPipeTranArray());	
	
	CString str1[50];//保存Key;
	CString strUnit[50];//Units
	CString strTemp1;
	CString strUnitTemp;
	int k=0;
	strTemp1 = outMgr1.m_OutPutData.PipeDataOrder();
	InitData(strTemp1,str1);
	strUnitTemp =  outMgr1.m_OutPutData.PipeUnitOrder();
	InitData( strUnitTemp,strUnit );

	int j=0;   
	m_staticPipeArray.RemoveAll();
    m_staticArray.RemoveAll();
	m_staticPipeArray.Add(outMgr1.GetArray().GetAt(0)); //输出窗口的第一个字段
	for (k = 0; k < 30;k++)
	{
		for(j = 0; j < 50; j++)
		{				
			if (str1[k] != "0" && str1[k] == outMgr1.m_OutPutSys.GetPipeOutArray()[j].GetKey()) //对输出数组赋值
			{
				outMgr1.GetArray().GetAt(j+1).Unit( strUnit[k] );
				m_staticPipeArray.Add(outMgr1.GetArray().GetAt(j+1));
				break;
			}
		}
	}
	
	//瞬变,Added by Zhufy
	strTemp1 = outMgr1.m_OutPutData.TranDataOrder();
	InitData(strTemp1,str1);
	strUnitTemp = outMgr1.m_OutPutData.TranUnitOrder();
	InitData( strUnitTemp , strUnit );
	m_staticTranArray.RemoveAll();
	m_staticArrayPage2.RemoveAll();
	m_staticTranArray.Add( outMgr2.GetStationArray().GetAt( 0 ) );
	for ( k = 0 ; k < 11 ; k++ )
	{
		for ( j = 0 ; j < 11 ; j++ )
		{
			if ( str1[k] != _T("0") && _ttoi( str1[k] ) == outMgr2.GetStationArray()[j].Key() )
			{
				outMgr2.GetStationArray().GetAt( j ).Unit( strUnit[k] );
				m_staticTranArray.Add( outMgr2.GetStationArray().GetAt( j ) );
				break;
			}
		}
	}

	//最大最小瞬变
	strTemp1 = outMgr1.m_OutPutData.MaxMinDataOrder();
	InitData(strTemp1,str1);
	strUnitTemp = outMgr1.m_OutPutData.MaxMinUnitOrder();
	InitData( strUnitTemp , strUnit );
	m_staticMaxMinArray.RemoveAll();
	m_staticArrayPage3.RemoveAll();
	m_staticMaxMinArray.Add( outMgr2.GetMaxMinArray().GetAt( 0 ) );
	for ( k = 0 ; k < 30 ; k++ )
	{
		for ( j = 0 ; j < 30 ; j++ )
		{
			if ( str1[k] != _T("0") && _ttoi( str1[k] ) == outMgr2.GetMaxMinArray()[j].Key() )
			{
				outMgr2.GetMaxMinArray().GetAt( j ).Unit( strUnit[k] );
				m_staticMaxMinArray.Add( outMgr2.GetMaxMinArray().GetAt( j ) );
				break;
			}
		}
	}

//	LoadStmData(outMgr1,outMgr1.GetArray(),m_page1,0);  //改用下面的一个
	LoadStmData(outMgr1,m_staticPipeArray,m_page1,0);
//  LoadStmData(outMgr2,outMgr2.GetStationArray(),m_page2,1);
	LoadStmData(outMgr2,m_staticTranArray,m_page2,1);
    
//	LoadStmData(outMgr2,outMgr2.GetArray(),m_page2,1);
//	LoadStmData(outMgr2,outMgr2.GetMaxMinArray(),m_page3,2);

	LoadStmData(outMgr2,m_staticMaxMinArray,m_page3,2);
//	outMgr2.GetArray()
	m_tab.SetCurSel(0);
}

void DlgPipeOutView::SetOutPutArray(OutMgr &mgr,CStringArray* Array)
{
	ComponentStmOut *pStmOut = NULL;
	if(Array->GetSize() != 0)
		Array->RemoveAll();
	IteratorPtr<ComponentStmOut> iteratorPtr(mgr.CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pStmOut = &iteratorPtr->CurrentItem();
 		int n = mgr.GetArray().GetSize();
		int i = 0;
		for( i=0;i<n;i++)
		{
			CString strText = pStmOut->GetValue((mgr.GetArray())[i].Key());
			Array->Add(strText);
		}
	}
}

void DlgPipeOutView::SetTranPutArray(OutMgr &mgr,CStringArray* Array)
{
	ComponentTranOut *pOut = NULL;
	ComponentStmOut *pStmOut = NULL;
	int nCount = mgr.GetCount();
	int n=0;
	int i=0;
	if(Array->GetSize() != 0)
		Array->RemoveAll();
	while (n<nCount)
	{//排序
		pStmOut = mgr.LookUp(i++);
		if(pStmOut != NULL)
		{
			pOut = dynamic_cast<ComponentTranOut*>(pStmOut);
			ASSERT(pOut != NULL);
				int j =0;
			IteratorPtr<ComponentStmOut> iteratorPtr(pOut->CreatMaxMinIterator());
			for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
			{
				pStmOut = &iteratorPtr->CurrentItem();
				int n = mgr.GetArray().GetSize();
				int i = 0;	
				CString str ;
				str.Format(_T("%d"),j);
				Array->Add(str);
				for( i=0;i<n;i++)
				{
					CString strText = pStmOut->GetValue((mgr.GetArray())[i].Key());
					Array->Add(strText);
				}
				j++;
			}
			n++;
		}
	}
}

void DlgPipeOutView::InitData(CString InData,CString str[50],TCHAR chSeparator)
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
		str[strj]=_T("0");
	}
	
}

void DlgPipeOutView::LoadStmData(OutMgr &Mgr,OutAttrArray &Array,PageOutTable &page,int nIndex)
{
	if( 0 == Array.GetSize() )
	{
		return;
	}
	m_tab.ShowPage(nIndex,FALSE);

	page.HasData(FALSE);
	int i = 0;	
	CArray<OutDataAttr,OutDataAttr> *pStaticArrary = NULL;
	switch ( nIndex )
	{
	case 0:
		pStaticArrary = &m_staticArray;
		break;
	case 1:
		pStaticArrary = &m_staticArrayPage2;
		break;
	case 2:
		pStaticArrary = &m_staticArrayPage3;
		break;
	} 
	if(pStaticArrary->GetSize() == 0)
	{   
	    for( i = 0; i < Array.GetSize(); i++ )
		{
			pStaticArrary->Add(Array[i]);
//		   m_staticArray.Add(Array[i]);
		}
	}
    
	page.ComponentType( UeCoponentType::ePipe );
	page.LoadComponentMgr( m_pComMgr, m_pUnitSys );

	page.LoadData(Mgr,*pStaticArrary, nIndex );

	//	page.LoadData(Mgr,m_staticArray);
	
	
	
	
//	for( i = 0; i < m_staticArray.GetSize(); i++ )
//	{
	//	Array.SetAt(i,m_staticArray[i]);
//	}
	if(page.HasData())
	{
		m_tab.ShowPage(nIndex,TRUE);
		page.AutoSize();
	}
}
