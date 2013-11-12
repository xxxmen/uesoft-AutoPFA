// AutoPFADoc.cpp : implementation of the CAutoPFADoc class
//
#pragma once
#include "stdafx.h"


#include "AutoPFADoc.h"
#include "AutoPFA.h"
#include "htmlhelp.h"


#include "ResourceInstance.h"
#include "DlgSysProperties.h"
#include "Scenario.h"
#include "ComponentManager.h"
#include "NetModel.h"
#include "CalcManager.h"
#include "dlgparamunit.h"
#include "dlgsteadyset.h"
#include "dlgsectionpipe.h"
#include "dlgtransientset.h"
#include "DlgCheckList.h"
#include "CaclDriverMgr.h"
#include "CalcFileFace.h"
#include "AutoPFAView.h"
#include "workspaceview.h"
#include "OutPutDataView.h"
#include "GraphView.h"
#include "ImpulseDataMgr.h"
#include "DlgUndefinedObjects.h"
#include "DlgOutPutControl.h"
#include "ADOConnection.h"
#include "DlgDataFormatDll.h"
#include "StartCADObj.h"
#include "ResourcePathManager.h"

//#include "OutPutRef.h"

#include "MainFrm.h"
#include "ChildFrm.h"
//#include "OptResult.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoPFADoc

IMPLEMENT_DYNCREATE(CAutoPFADoc, CDocument)

BEGIN_MESSAGE_MAP(CAutoPFADoc, CDocument)
	//{{AFX_MSG_MAP(CAutoPFADoc)
	ON_COMMAND(ID_PARAMUNIT, OnParamUnit)
	ON_COMMAND(ID_SYSTEMPROPER, OnSystemProper)
	ON_COMMAND(ID_STEADYANALYSIS, OnSteadyAnalysis)
	ON_UPDATE_COMMAND_UI(ID_STEADYANALYSIS, OnUpdateSteadyAnalysis)
	ON_COMMAND(ID_TRANSANALYSIS, OnTransanAlysis)
	ON_UPDATE_COMMAND_UI(ID_TRANSANALYSIS, OnUpdateTransAnalysis)
	ON_COMMAND(ID_STEADYCONTROL, OnSteadyControl)
	ON_COMMAND(ID_SECTIONPIPE, OnSectionPipe)
	ON_COMMAND(ID_TRANSCONTROL, OnTransControl)
	ON_COMMAND(ID_EXPORTCALCFILE, OnExportCalcFile)
	ON_COMMAND(ID_RUNMODEL, OnRunModel)
	ON_COMMAND(ID_CHECKMODEL, OnCheckModel)
	ON_COMMAND(ID_PFAHELP, OnPfahelp)
	ON_COMMAND(ID_VIEW_DATAMODEL, OnViewDataModel)
	ON_COMMAND(ID_VIEW_GRAPH, OnViewGraph)
	ON_COMMAND(ID_VIEW_OUTPUT, OnViewOutput)
	ON_COMMAND(ID_VIEW_WORKSPECE, OnViewWorkSpece)
	ON_COMMAND(AFX_ID_OPTIMIZATION_OPTPARA, OnIdOptimizationOptpara)
	ON_COMMAND(ID_OPTCONTRAL, OnOptcontral)
	ON_COMMAND(ID_OPTANALYSIS, OnOptanalysis)
	ON_UPDATE_COMMAND_UI(ID_OPTANALYSIS, OnUpdateOptanalysis)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_OUTPUTCONTROL, &CAutoPFADoc::OnOutPutControl)
	ON_COMMAND(ID_OUTPUTRESULT, &CAutoPFADoc::OnOutPutResult)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoPFADoc construction/destruction

CAutoPFADoc::CAutoPFADoc()
:m_OutModel(m_unitSystem,m_OutPutData)
{
	// TODO: add one-time construction code here
	m_pImpulseData = &ImpulseDataMgr::Instance();
	m_unitSystem.Init();
	m_bMutex = TRUE;
	m_bOutMutex = FALSE;
}

CAutoPFADoc::~CAutoPFADoc()
{

}
//BOOL flagread=FALSE;
//BOOL flagnew=FALSE;

BOOL CAutoPFADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	CreatModelDataWnd();
	CreatOutDataWnd();
	CreatGraphWnd();
//	flagread=FALSE;
//	flagnew=TRUE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFADoc serialization

void CAutoPFADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFADoc diagnostics

#ifdef _DEBUG
void CAutoPFADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAutoPFADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoPFADoc commands

BOOL CAutoPFADoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	CreatModelDataWnd();
	CreatOutDataWnd();
	CreatGraphWnd();
	return Read(lpszPathName); 
}

BOOL CAutoPFADoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	//CResourceInstance res;
	return Save(lpszPathName);
}

BOOL CAutoPFADoc::Read(LPCTSTR lpszPathName)
{
	//设置语言为中文,否则在Unicode编码下读出中文字符为乱码
	char* old_locale=_strdup( setlocale(LC_CTYPE,NULL) ); 
	setlocale( LC_CTYPE,"chs");


	BOOL bRet = TRUE;
//	PersistentModel model;
	
	ErrorStatus::FileError error= m_PersistentMgr.Read(lpszPathName,GlobalModel);
	if(error == ErrorStatus::eFileOK)
	{
		bRet = m_scenarioManager.Read(GlobalModel.GetScenarioPersist());
	}
	m_workSpaceRef.Trans( !m_scenarioManager.GetCurScenario()->GetCalcManager()->AnalysisType() );
//	AfxMessageBox(model.GetScenarioPersist().GetBase()->GetOutputRef().PipeUnitOrder());
	m_OutPutData = (GlobalModel.GetScenarioPersist().GetBase()->GetOutputRef());
//	AfxMessageBox(m_OutPutData.PipeDataOrder());
//	m_OutModel.GetOutPutData().PipeDataOrder();
//	flagnew = FALSE ;
//	flagread = TRUE ;
	setlocale( LC_CTYPE, old_locale ); //还原语言区域的设置
	return TRUE ;
}

BOOL CAutoPFADoc::Save(LPCTSTR lpszPathName)
{
	BOOL bRet = TRUE;
	PersistentModel model;

	//设置语言为中文,否则在Unicode编码下中文字符写不到文件里面去。
	char* old_locale=_strdup( setlocale(LC_CTYPE,NULL) ); 
	setlocale( LC_CTYPE,"chs");
	
// 	if ( flagread )
// 	{
		bRet = m_scenarioManager.Save(model.GetScenarioPersist());
		model.GetScenarioPersist().GetBase()->GetOutputRef().PipeDataOrder( m_OutPutData.PipeDataOrder() );
		model.GetScenarioPersist().GetBase()->GetOutputRef().JunDataOrder( m_OutPutData.JunDataOrder() );

		model.GetScenarioPersist().GetBase()->GetOutputRef().PipeUnitOrder( m_OutPutData.PipeUnitOrder() );
		model.GetScenarioPersist().GetBase()->GetOutputRef().JunUnitOrder( m_OutPutData.JunUnitOrder() );
		if( bRet )
		{
			m_PersistentMgr.Save( lpszPathName,model );
		}


		setlocale( LC_CTYPE, old_locale ); //还原语言区域的设置
//		flagnew = FALSE;
// 	}
// 	if ( flagnew )
// 	{
// 		bRet = m_scenarioManager.Save( model.GetScenarioPersist() );
// 		model.GetScenarioPersist().GetBase()->GetOutputRef().PipeDataOrder( m_OutPutData.PipeDataOrder() );
// 		model.GetScenarioPersist().GetBase()->GetOutputRef().JunDataOrder( m_OutPutData.JunDataOrder() );
// 		
// 		model.GetScenarioPersist().GetBase()->GetOutputRef().PipeUnitOrder( m_OutPutData.PipeUnitOrder() );
// 		model.GetScenarioPersist().GetBase()->GetOutputRef().JunUnitOrder( m_OutPutData.JunUnitOrder() );
// 		flagread = FALSE;
// 		if(bRet)
// 		{
// 			m_PersistentMgr.Save( lpszPathName,model );
// 		}
// //		GlobalModel.GetScenarioPersist().GetBase()->GetOutputRef().PipeUnitOrder("None,m3/sec,meters/sec,Pascals,Pascals,meters,meters,Pascals,Pascals,Pascals,meters,Pascals,Pascals,Pascals,Pascals");
// 	}

	return bRet ;
}

void CAutoPFADoc::OnCloseDocument() 
{
	// TODO: Add your specialized code here and/or call the base class

	CDocument::OnCloseDocument();
} 

void CAutoPFADoc::CreatModelDataWnd()
{
	CMultiDocTemplate *pTemplate = ((CAutoPFAApp*)AfxGetApp())->m_pModelDataTemplate;
	CFrameWnd *m_pFrame = pTemplate->CreateNewFrame(this,NULL);
	ASSERT(m_pFrame != NULL);
	pTemplate->InitialUpdateFrame(m_pFrame,this);
}

void CAutoPFADoc::CreatOutDataWnd()
{
	CMultiDocTemplate *pTemplate = ((CAutoPFAApp*)AfxGetApp())->m_pOutDataTemplate;
	CFrameWnd *m_pFrame = pTemplate->CreateNewFrame(this,NULL);
	ASSERT(m_pFrame != NULL);
	pTemplate->InitialUpdateFrame(m_pFrame,this);
}
void CAutoPFADoc::CreatGraphWnd()
{
	CMultiDocTemplate *pTemplate = ((CAutoPFAApp*)AfxGetApp())->m_pGraphTemplate;
	CFrameWnd *m_pFrame = pTemplate->CreateNewFrame(this,NULL);
	ASSERT(m_pFrame != NULL);
	pTemplate->InitialUpdateFrame(m_pFrame,this);
}
void CAutoPFADoc::OnSteadyAnalysis() 
{
	// TODO: Add your command handler code here
	m_scenarioManager.GetCurScenario()->GetCalcManager()->AnalysisType(1);
	m_workSpaceRef.Trans(FALSE);
	m_iAnalysisTpye = 2;
}

void CAutoPFADoc::OnUpdateSteadyAnalysis(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if( 3 == m_iAnalysisTpye )
	{
		pCmdUI->SetCheck( false );
		return;
	}

	if(m_scenarioManager.GetCurScenario()->GetCalcManager()->AnalysisType()==0)
	{
		pCmdUI->SetCheck(FALSE);
		m_workSpaceRef.Trans(TRUE);
	}
	else
	{	
	    pCmdUI->SetCheck(TRUE);
    	m_workSpaceRef.Trans(FALSE);
	}
}

void CAutoPFADoc::OnTransanAlysis() 
{
	// TODO: Add your command handler code here
	m_scenarioManager.GetCurScenario()->GetCalcManager()->AnalysisType(0);//获得当前工况的计算管理器，设置计算类型为0，即计算瞬态
	m_workSpaceRef.Trans(TRUE);

    m_iAnalysisTpye = 1;
}

void CAutoPFADoc::OnUpdateTransAnalysis(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if( 3 == m_iAnalysisTpye )
	{
		pCmdUI->SetCheck( false );
		return;
	}
	if(m_scenarioManager.GetCurScenario()->GetCalcManager()->AnalysisType()==0)
	{
		pCmdUI->SetCheck(TRUE);
		m_workSpaceRef.Trans(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
		m_workSpaceRef.Trans(FALSE);
	}
}

void CAutoPFADoc::OnSystemProper() 
{
	// TODO: Add your command handler code here
	DlgSysProperties dlg(*m_pImpulseData,m_unitSystem,m_scenarioManager.GetCurScenario()->GetCompManager()->SysProperty());
	if(IDOK ==dlg.DoModal())
	{//重新计算管道波速
		m_scenarioManager.GetCurScenario()->GetCompManager()->CalcWave();
	}
}

void CAutoPFADoc::OnParamUnit() 
{
	// TODO: Add your command handler code here
	DlgParamUnit dlg(m_unitSystem);
	dlg.DoModal();
	
}



void CAutoPFADoc::OnSteadyControl() 
{
	// TODO: Add your command handler code here
	DlgSteadySet dlg(m_unitSystem,m_scenarioManager.GetCurScenario()->GetCalcManager()->GetSteadySet());
	dlg.DoModal();
}

void CAutoPFADoc::OnSectionPipe() 
{
	// TODO: Add your command handler code here
	DlgSectionPipe dlg(m_unitSystem,m_scenarioManager.GetCurScenario()->GetNetModel());
	if(dlg.Init())
		dlg.DoModal();
}

void CAutoPFADoc::OnTransControl() 
{
	// TODO: Add your command handler code here
	DlgTransientSet dlg(m_unitSystem,m_scenarioManager.GetCurScenario()->GetNetModel());
	if(dlg.Init())
		dlg.DoModal();
}

void CAutoPFADoc::OnExportCalcFile() 
{
	// TODO: Add your command handler code here
	PersistentModel model;
	PersistentMgr persistentMgr;
	Scenario *pScenario = m_scenarioManager.GetCurScenario();
	BOOL bRet = m_scenarioManager.SaveCurModel(model.GetScenarioPersist(),pScenario);
	if(bRet)
	{
		CString strDocName = GetPathName();
		int index = strDocName.ReverseFind('.');
		if(index != -1)
		{
			strDocName = strDocName.Left(index);
			strDocName = strDocName + _T("_") + pScenario->GetName();
			
			static TCHAR BASED_CODE szFilter[] = _T("PFA计算文件(*.calc)|*.calc|All Files (*.*)|*.*||");
			CFileDialog dlg(FALSE,_T("calc"),strDocName,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
			if(IDOK == dlg.DoModal())
			{
				persistentMgr.Save(dlg.GetPathName(),model);
			}
		}
		else
		{
			AfxMessageBox(_T("请先保存文件"));
		}
	}
}

void CAutoPFADoc::OnRunModel() 
{
	// TODO: Add your command handler code here

	if( 3 == m_iAnalysisTpye )          // 管网优化
	{
		
		
		if( !m_Optimize.Example() )
		{
			return;
		}
		PersistentModel model;
		
		double i;
		CString str;
		Scenario* pScenario = m_scenarioManager.GetCurScenario();
		
		PipesManager pipm;
	
		ComponentManager com;
		
		com.Read(pipm);
		
		
		if( GetModel( model,pScenario))
		{
			
			i=pScenario->GetCompManager()->LookUpPipe(1)->Len();
			
				
			
		}

		OutMutex(TRUE);//更新输出窗口
	    ActiveView(RUNTIME_CLASS(OutPutDataView));
		return;
	}


	if(CheckModel(FALSE))
	{
		return;
	}
	CString strPath;
	PersistentMgr persistentMgr;
	PersistentModel model;
	Scenario *pScenario = m_scenarioManager.GetCurScenario();
	if(GetModel(model,pScenario))
	{
		CString strDocName = GetPathName();
		int index = strDocName.ReverseFind(_T('.'));
		if(index == -1)
		{
			AfxMessageBox(_T("请先保存文档"));
			return;
		}
		strDocName = strDocName.Left(index);
		strPath = strDocName;
		strDocName = strDocName +_T(".imp");
//		OnSaveDocument(strDocName);//保存会有格式不一致问题出现，所以先屏蔽
		CalcMOCModel(strPath);
//		m_OutPutData.PipeDataOrder(_T("12,34,56"));
//		model.GetScenarioPersist().GetBase()->GetOutputRef().SetPipeDataOrder(m_OutPutData.PipeDataOrder());
//		CString str;
//		str=model.GetScenarioPersist().GetBase()->GetOutputRef().PipeDataOrder();
		OutMutex(TRUE);//更新输出窗口

		ActiveView(RUNTIME_CLASS(OutPutDataView));
	}
	
	
	//AfxMessageBox(UnSub.FindCurSymbol(6));
}

void CAutoPFADoc::OnCheckModel() 
{
	// TODO: Add your command handler code here
	CheckModel(TRUE);
}

BOOL CAutoPFADoc::CheckModel(BOOL bShow)
{
	BOOL bCheck[5] = {FALSE};
	BOOL bTran = m_workSpaceRef.Trans();
	m_scenarioManager.GetCurScenario()->GetNetModel()->CheckModel(bCheck,bTran);
	if(!bShow)
	{
		int n = bTran ? 5 : 3;
		for(int i=0;i<n;i++)
		{
			if(!bCheck[i])
				bShow = TRUE;
		}
	}

	if(bShow)
	{
		DlgCheckList dlg;
		dlg.Init(bCheck,bTran);
		dlg.SetCurDoc( this );
		dlg.DoModal();
	}
	return bShow;
}

void CAutoPFADoc::CalcMOCModel(const CString &strFile)
{
//	CString strOutFile = strFile +_T(".txt");
	PersistentModel model;
	CalcDriverMgr calcModel;
	CalcFileFace calcFace;
	if(GetModel(model))
	{
		calcFace.Save(calcModel,model);
		m_calcModel.Read(calcModel);
		m_calcModel.Calc(m_OutModel);
	}
}

BOOL CAutoPFADoc::GetModel(PersistentModel &model,Scenario *pScenario)
{
	if(pScenario==NULL)
		pScenario = m_scenarioManager.GetCurScenario();
	return m_scenarioManager.SaveCurModel(model.GetScenarioPersist(),pScenario);
}

void CAutoPFADoc::OnPfahelp() 
{
	((CAutoPFAApp*)AfxGetApp())->OnPfahelp();
}

void CAutoPFADoc::ActiveView(const CRuntimeClass* pClass)
{
	CFrameWnd* pFrameWnd=((CFrameWnd*)AfxGetMainWnd())->GetActiveFrame();
	CView* pView=(pFrameWnd)->GetActiveView();
	if(pView!=NULL && pView->IsKindOf(pClass))
		return;
	POSITION  pos = this->GetFirstViewPosition();
	CView *pView1 = NULL;
	while(pos)
	{
		pView1=this->GetNextView(pos);
		if(pView1->IsKindOf(pClass))
		{
			pView=pView1;
			break;
		}
	}
	
	CMDIChildWnd* pWnd=(CMDIChildWnd*)pView->GetParentFrame();
	pWnd->ActivateFrame();
}

void CAutoPFADoc::OnViewDataModel() 
{
	// TODO: Add your command handler code here
	ActiveView(RUNTIME_CLASS(WorkSpaceDataView));
}

void CAutoPFADoc::OnViewGraph() 
{
	// TODO: Add your command handler code here
	ActiveView(RUNTIME_CLASS(GraphView));
}

void CAutoPFADoc::OnViewOutput() 
{
	// TODO: Add your command handler code here
	ActiveView(RUNTIME_CLASS(OutPutDataView));
}

void CAutoPFADoc::OnViewWorkSpece() 
{
	// TODO: Add your command handler code here
	ActiveView(RUNTIME_CLASS(CAutoPFAView));
}

void CAutoPFADoc::OnIdOptimizationOptpara() 
{
	// TODO: Add your command handler code here
    COptimizationParameter DlgOptPara( &m_Optimize );
	if( IDOK == DlgOptPara.DoModal() )
	{

	}
}


void CAutoPFADoc::OnOptcontral() 
{
	// TODO: Add your command handler code here
	COptControl OptContral;
	if( IDOK == OptContral.DoModal() )
	{

	}
}

void CAutoPFADoc::OnOptanalysis() 
{
	// TODO: Add your command handler code here
	
	m_iAnalysisTpye = 3;
}

void CAutoPFADoc::OnUpdateOptanalysis(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if( 3 == m_iAnalysisTpye )
	{
		pCmdUI->SetCheck( true );
		return;
	}
	else
	{
		pCmdUI->SetCheck( false );
	}
}

/************************************************************************
版本: 8.0  注释时间: [2009/4/29]  作者: [Zhufy] 评审人: 
功能:     读取TableFormat.mdb数据库，根据表格设置里设置的显示的字段刷新界面                                                         
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/
void CAutoPFADoc::OnOutPutControl()
{
	CResourceInstance cr;
	CDlgDataFormatDll  dlg( _T("AutoPFA") );
	CString str = ResourcePathManager::Instance().GetOldSoftShareDbPath();;
    if( dlg.DoModal( str.GetBuffer( str.GetLength() ) ) == IDOK )
	{
		//读取数据库要显示刷新的字段
		CString strDBPath = str + _T("TableFormat.mdb");
 		ADOConnection pConn;
		ADORecordSetPtr pRs[4] = { NULL };
		ADORecordSetPtr pRsTemp;
		CString strDBName[4] = { _T("tpfaoutPipe") ,      //管道表
			                     _T("tpfaoutJun") ,       //节点表
								 _T("tpfaoutTransient") , //瞬变表
								 _T("tpfaoutMaxMinTran")  //最大最小瞬变表
		                       };
		CString strOrder[4] = { _T("") };
		CString strUnit[4] = { _T("") };

		try
		{
			pConn.Open( strDBPath );

			int i = 0;
			for ( i = 0 ; i < 4 ; i++ )
			{
				CString strSql = _T("");
				CString strSqlTemp = _T("");
				//所有显示的字段
				strSql.Format(_T("SELECT Key  FROM [%s]  WHERE NOT ISNULL( CADFieldSeq ) ORDER BY SEQ") , strDBName[i] );
				//单位不为空的字段
				strSqlTemp.Format(_T("SELECT Key ,UnitSymbol  FROM [%s] , [UNIT_SI_FREQUENT] WHERE  ( [%s].UNITID = [UNIT_SI_FREQUENT].UNITID AND [%s].UnitSEQ = [UNIT_SI_FREQUENT].UnitSEQ ) AND NOT IsNull( [%s].UNITID ) ") ,
					           strDBName[i] , strDBName[i] , strDBName[i] , strDBName[i] );
				pRs[i] = pConn.ExecuteSelectSQL( strSql );
				pRsTemp = pConn.ExecuteSelectSQL( strSqlTemp );
				//根据结果更新ORDER
				CString strKey = _T("");
				CString strUnitTemp = _T("None");
				while( !pRs[i]->IsEmpty() && !pRs[i]->IsEOF() )
				{
					strUnitTemp = _T("None");
					strKey = pRs[i]->GetString( _T("Key") );
					strOrder[i] += strKey;//关键字
					strOrder[i] += _T(",");

					CString strKeyTemp;
					pRsTemp->MoveFirst();
					while( !pRsTemp->IsEmpty() && !pRsTemp->IsEOF() )
					{
						strKeyTemp =pRsTemp->GetString( _T("Key") );
						if ( strKeyTemp == strKey )
						{
							strUnitTemp = pRsTemp->GetString( _T("UnitSymbol") );//当前单位
							break;
						}
						pRsTemp->MoveNext();
					}

					strUnit[i]  += strUnitTemp;
					strUnit[i]  += _T(",");
					pRs[i]->MoveNext();
				}
				strOrder[i].TrimRight( _T(",") );
				strUnit[i].TrimRight( _T(",") );
			}
			//关闭连接
	//		pConn.Close();
			_ConnectionPtr conTemp;
			pConn.GetConnectionptr( conTemp );
			if ( conTemp->State != adStateClosed )
			{
				conTemp->Close();
			}
		}
		catch (...)
		{
		}

		OutMgr &outMgr = m_OutModel.SteadyOut().ComponentOutMgr().PipeOutMgr();
		outMgr.m_OutPutData.PipeDataOrder( strOrder[0] );
		outMgr.m_OutPutData.PipeUnitOrder( strUnit[0]);
		outMgr.m_OutPutData.JunDataOrder( strOrder[1] );
		outMgr.m_OutPutData.JunUnitOrder( strUnit[1] );

		outMgr.m_OutPutData.TranDataOrder( strOrder[2] );
		outMgr.m_OutPutData.TranUnitOrder( strUnit[2] );

		outMgr.m_OutPutData.MaxMinDataOrder( strOrder[3] );
		outMgr.m_OutPutData.MaxMinUnitOrder( strUnit[3] );

		//进行刷新
		ActiveView(RUNTIME_CLASS(OutPutDataView));
		CFrameWnd* pFrameWnd=((CFrameWnd*)AfxGetMainWnd())->GetActiveFrame();
		CView* pView=(pFrameWnd)->GetActiveView();
		if(pView == NULL || !pView->IsKindOf( RUNTIME_CLASS(OutPutDataView) ))
			return;
		POSITION  pos = this->GetFirstViewPosition();
		CView *pView1 = NULL;
		while(pos)
		{
			pView1=this->GetNextView(pos);
			if( pView1->IsKindOf( RUNTIME_CLASS(OutPutDataView)) )
			{
				pView=pView1;
				break;
			}
		}

		OutPutDataView* pOutPutView = (OutPutDataView*)pView;
		if ( pOutPutView == NULL )
		{
			return;
		}
		//重现初始化显示列表
		pOutPutView->m_PipeView.LoadData( m_scenarioManager.GetCurScenario(), m_OutModel, &m_unitSystem );
		pOutPutView->m_JunView.LoadData( m_scenarioManager.GetCurScenario(), m_OutModel, &m_unitSystem );
	}
}

void CAutoPFADoc::OnOutPutResult()
{
	// TODO: 在此添加命令处理程序代码
	SetPFApipe();
	//这里先把出表格的写死，以后要从写数据库那里动态获取。
	CString TabIndex = _T( "202 203 204 205" );
	StartCADObj temp;
	temp.SetTabIndex(TabIndex);
	temp.StartUpCAD();
}


 void CAutoPFADoc::SetPFApipe()
{
	int nCount = 0;
	int i = 0;
	Scenario *pScenario = m_scenarioManager.GetCurScenario();
	CStringArray *PipeArray = pScenario->GetPipeSteadyArray();
	CStringArray *PipeTran = pScenario->GetPipeTranArray();
	CStringArray *JunArray = pScenario->GetJunArray();
	ADOConnection m_ado;
	CString strFile,strSqlSteady,strSqlTran,strSqlJun;
	strSqlSteady = "DELETE * FROM PFApipe";
	strSqlTran = "DELETE * FROM PFAmtran";
	strSqlJun = "DELETE * FROM PFAjun";
	CString strDBPath = ResourcePathManager::Instance().GetOldSoftShareDbPath();
	//strFile =  _T( "C:\\shareMDB\\AllPrjDB.mdb" );
	strFile =  strDBPath + _T( "AllPrjDB.mdb" );
	if( strFile.IsEmpty() )
		return ;
	m_ado.Open(strFile);
	m_ado.ExecuteSelectSQL(strSqlSteady);
	m_ado.ExecuteSelectSQL(strSqlTran);
	m_ado.ExecuteSelectSQL(strSqlJun);
	m_ado.Close();
	m_ado.Open(strFile);


	nCount = PipeArray->GetSize()/50;
	for(i = 0; i < nCount; i++ )
	{
		CString sqlStr; 
		int t = 50*i+i;
		sqlStr.Format( _T( "insert into PFApipe values('%s','%s','%s','%s',\
						   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
						   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
						   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
						   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
						   '%s','%s','%s','%s')"), PipeArray->GetAt(t+1),PipeArray->GetAt(t+2),\
						   PipeArray->GetAt(t+3),PipeArray->GetAt(t+4),PipeArray->GetAt(t+5),PipeArray->GetAt(t+6),\
						   PipeArray->GetAt(t+7),PipeArray->GetAt(t+8),PipeArray->GetAt(t+9),PipeArray->GetAt(t+10),\
						   PipeArray->GetAt(t+11),PipeArray->GetAt(t+12),PipeArray->GetAt(t+13),PipeArray->GetAt(t+14),\
						   PipeArray->GetAt(t+15),PipeArray->GetAt(t+16),PipeArray->GetAt(t+17),PipeArray->GetAt(t+18),\
						   PipeArray->GetAt(t+19),PipeArray->GetAt(t+20),PipeArray->GetAt(t+21),PipeArray->GetAt(t+22),\
						   PipeArray->GetAt(t+23),PipeArray->GetAt(t+24),PipeArray->GetAt(t+25),PipeArray->GetAt(t+26),\
						   PipeArray->GetAt(t+27),PipeArray->GetAt(t+28),PipeArray->GetAt(t+29),PipeArray->GetAt(t+30),\
						   PipeArray->GetAt(t+31),PipeArray->GetAt(t+32),PipeArray->GetAt(t+33),PipeArray->GetAt(t+34),\
						   PipeArray->GetAt(t+35),PipeArray->GetAt(t+36),PipeArray->GetAt(t+37),PipeArray->GetAt(t+38),\
						   PipeArray->GetAt(t+39),PipeArray->GetAt(t+40),PipeArray->GetAt(t+41),PipeArray->GetAt(t+42),\
						   PipeArray->GetAt(t+43),PipeArray->GetAt(t+44),PipeArray->GetAt(t+45),PipeArray->GetAt(t+46),\
						   PipeArray->GetAt(t+47),PipeArray->GetAt(t+48));
		try
		{
			m_ado.ExecuteSelectSQL( sqlStr);
		}
					catch(_com_error e)
					{
						AfxMessageBox( e.Description() );
		}
	}
	int mCount = PipeTran->GetSize()/30;
	{
		for(i = 0; i < mCount; i++ )
		{
			CString sqlStr; 
			int t = 30*i;
			sqlStr.Format( _T( "insert into PFAmtran values('%s','%s','%s','%s',\
							   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
							   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
							   '%s','%s','%s','%s','%s','%s')"), PipeTran->GetAt(t+1),PipeTran->GetAt(t),\
							   PipeTran->GetAt(t+2),PipeTran->GetAt(t+3),PipeTran->GetAt(t+4),PipeTran->GetAt(t+5),\
							   PipeTran->GetAt(t+6),PipeTran->GetAt(t+7),PipeTran->GetAt(t+8),PipeTran->GetAt(t+9),\
							   PipeTran->GetAt(t+10),PipeTran->GetAt(t+11),PipeTran->GetAt(t+12),PipeTran->GetAt(t+13),\
							   PipeTran->GetAt(t+14),PipeTran->GetAt(t+15),PipeTran->GetAt(t+16),PipeTran->GetAt(t+17),\
							   PipeTran->GetAt(t+18),PipeTran->GetAt(t+19),PipeTran->GetAt(t+20),PipeTran->GetAt(t+21),\
							   PipeTran->GetAt(t+22),PipeTran->GetAt(t+23),PipeTran->GetAt(t+24),PipeTran->GetAt(t+25),\
							   PipeTran->GetAt(t+26),PipeTran->GetAt(t+27),PipeTran->GetAt(t+28),PipeTran->GetAt(t+29));
			try
			{
				m_ado.ExecuteSelectSQL(sqlStr);
			}
			catch(_com_error e)
			{
				AfxMessageBox( e.Description() );
			}
		}
	}

	int jCount = JunArray->GetSize()/51;
	{
		for(i = 0; i < jCount; i++ )
		{
			CString sqlStr; 
			int t = 50*i+i;
			sqlStr.Format( _T( "insert into PFAjun values('%s','%s','%s','%s',\
							   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s',\
							   '%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')"), JunArray->GetAt(t),JunArray->GetAt(t+2),\
							   JunArray->GetAt(t+3),JunArray->GetAt(t+4),JunArray->GetAt(t+5),\
							   JunArray->GetAt(t+6),JunArray->GetAt(t+7),JunArray->GetAt(t+8),JunArray->GetAt(t+9),\
							   JunArray->GetAt(t+10),JunArray->GetAt(t+11),JunArray->GetAt(t+12),JunArray->GetAt(t+13),\
							   JunArray->GetAt(t+14),JunArray->GetAt(t+15),JunArray->GetAt(t+16),JunArray->GetAt(t+17),\
							   JunArray->GetAt(t+18),JunArray->GetAt(t+19),JunArray->GetAt(t+20),JunArray->GetAt(t+21),\
							   JunArray->GetAt(t+22),JunArray->GetAt(t+23),JunArray->GetAt(t+24),JunArray->GetAt(t+25));
			try
			{
				m_ado.ExecuteSelectSQL(sqlStr);
			}
			catch(_com_error e)
			{
				AfxMessageBox( e.Description() );
			}
		}
	}
}