// AutoPFA.cpp : Defines the class behaviors for the application.
//
#pragma once
#include "stdafx.h"
#include "AutoPFA.h"
#include "htmlhelp.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "AutoPFADoc.h"
#include "AutoPFAView.h"
#include "workspaceview.h"
#include "OutPutDataView.h"
#include "GraphView.h"
#include "graphframe.h"
#include "WorkSpaceDataFrame.h"
#include "OutPutDataFrame.h"

#include "ScenariManage.h"
#include "Scenario.h"
#include "ComponentManager.h"
#include "PFAOptimize.h"
#include "FilePreviewDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDS_PFAOPENFILETYPE _T("AutoPFA8.0,AFT Impulse3.0 (*.imp)|*.imp|AutoPDMS8.0,ISOGEN (*.pcf)|*.pcf|AFT Fathom6.0 (*.fth)|*.fth|all files (*.*)|*.*||")

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAApp
HINSTANCE _hdllInstance = NULL;

BEGIN_MESSAGE_MAP(CAutoPFAApp, CWinApp)
	//{{AFX_MSG_MAP(CAutoPFAApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_PFAHELP, OnPfahelp)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CAutoPFAApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAApp construction

CAutoPFAApp::CAutoPFAApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	ChartActiveXRegister( true );
}
CAutoPFAApp::~CAutoPFAApp()
{
	ChartActiveXRegister( false );
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CAutoPFAApp object

CAutoPFAApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAApp initialization

BOOL CAutoPFAApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_AUTOPFTYPE,
		RUNTIME_CLASS(CAutoPFADoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CAutoPFAView));
	AddDocTemplate(pDocTemplate);

	m_pModelDataTemplate = new CMultiDocTemplate(
		IDR_AUTOPFTYPE,
		RUNTIME_CLASS(CAutoPFADoc),
		RUNTIME_CLASS(CWorkSpaceDataFrame), // custom MDI child frame
		RUNTIME_CLASS(WorkSpaceDataView));

	m_pOutDataTemplate = new CMultiDocTemplate(
		IDR_AUTOPFTYPE,
		RUNTIME_CLASS(CAutoPFADoc),
		RUNTIME_CLASS(COutPutDataFrame), // custom MDI child frame
		RUNTIME_CLASS(OutPutDataView));

	m_pGraphTemplate = new CMultiDocTemplate(
		IDR_GRAPH,
		RUNTIME_CLASS(CAutoPFADoc),
		RUNTIME_CLASS(CGraphFrame), // custom MDI child frame
		RUNTIME_CLASS(GraphView));

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	

	
	//如果传入计算文件路径，将打开文件计算并显示结果
	//
	CString CommandStr;
//	CString strPathName;
	CommandStr=this->m_lpCmdLine;
	
	if(!CommandStr.IsEmpty())
	{
		if(!FileExists(CommandStr))
		{
			CString temp;
			temp.Format(_T("%s文件不存在！"),CommandStr);
			AfxMessageBox(temp);
		}
		else
		{
			
			OpenDocumentFile(CommandStr);
 		}
		//	FileOpenByName(CommandStr);
 		SendMessage(::AfxGetMainWnd()->GetSafeHwnd(),
 			WM_COMMAND,ID_RUNMODEL,NULL);
		//	SendMessage(::AfxGetMainWnd()->GetSafeHwnd(),
		//				WM_COMMAND,IDM_STATICRESULT,NULL);
		
	}




	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CAutoPFAApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAApp message handlers


int CAutoPFAApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete m_pModelDataTemplate;
	delete m_pOutDataTemplate;
	delete m_pGraphTemplate;
	return CWinApp::ExitInstance();
}



void CAutoPFAApp::OnPfahelp() 
{

	// TODO: Add your command handler code here
	CString strPath ;
	DWORD dwRet	= ::GetModuleFileName(NULL,strPath.GetBuffer(_MAX_PATH) , _MAX_PATH);
	strPath.ReleaseBuffer();
	strPath.Replace( _T("AutoPFA.exe"), _T("") ) ;
	strPath += _T( "Help\\AutoPFA.chm" ) ;
	::HtmlHelp(this->m_pMainWnd->m_hWnd,strPath, HH_HELP_FINDER, NULL );
}


void CAutoPFAApp::OnFileOpen() 
{
    // TODO: Add your command handler code here
    CString Filter;
    Filter.Format(IDS_PFAOPENFILETYPE);
//    CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(LPCTSTR)Filter);
	CFilePreviewDlg dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(LPCTSTR)Filter);
    if(dlg.DoModal()==IDOK)
	{
		CString strPathName = _T("");
		strPathName = dlg.GetPathName();
		if(!strPathName)
		{
		    CString temp;
		    temp.Format(_T("%s文件不存在！"),strPathName);
		    AfxMessageBox(temp);
		    return;
		}
		else
		{
		    //m_strCurrentFileName = strPathName;
		    OpenDocumentFile(strPathName);
		}	

		CMainFrame* pMainFrame = NULL; 
	    pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		if( NULL == pMainFrame )
		{
			return;
		}
	    CChildFrame* pChildFrame = NULL;
	    pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
		if( NULL == pChildFrame )
		{
			return;
		}
	    CAutoPFAView* pAutoView = NULL;
	    pAutoView = (CAutoPFAView*)pChildFrame->GetActiveView();
		if( NULL == pAutoView )
		{
			return;
		}

	    //使图形最大化，但不知道为什么失败，所以改成下面代码
	    CRect rc = pAutoView->GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager()->GetRect();
        rc.top    -= 16;
	    rc.left   -= 16;
    	rc.bottom += 16;
	    rc.right  += 16;
    	pAutoView->ZoomScrollSizes(rc);
	}
 




}



bool CAutoPFAApp::ActiveXRegister( CString& OcxFileName, const bool& bChangeType )
{
	LPCTSTR pszDllName = OcxFileName.GetBuffer( MAX_PATH );         //ActiveX控件的路径及文件名         
	HINSTANCE hLib = LoadLibrary( pszDllName ); //装载ActiveX控件
	if ( (HINSTANCE)HINSTANCE_ERROR > hLib )	
	{	
		return false;
	}
	FARPROC lpDllEntryPoint; 
	if( false == bChangeType )
	{
		lpDllEntryPoint = GetProcAddress( hLib, "DllUnregisterServer" );        //获取注册函数DllUnregisterServer地址
	}
	else
	{
		lpDllEntryPoint = GetProcAddress( hLib, "DllRegisterServer" );
	}
	if( NULL != lpDllEntryPoint )   //调用注册函数DllUnregisterServer	
	{
		if( FAILED( ( *lpDllEntryPoint )() ) )			
		{			
			FreeLibrary( hLib );
			AfxMessageBox( _T(" ActiveX控件注册或卸载失败! ") );
			return false;			
		}		
		return true;		
	}	
	else
	{
		return false;	
	}
}

bool CAutoPFAApp::ChartActiveXRegister( const bool& bChangeType )
{
	TCHAR exeFullPath[MAX_PATH];
	::GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	CString strPath(exeFullPath);
	int index = strPath.ReverseFind(_T('\\'));
	ASSERT(index != -1);
	strPath = strPath.Left(index+1);
	strPath += _T("mschrt20.ocx");
	return ActiveXRegister( strPath, bChangeType );
}


BOOL CAutoPFAApp::FileExists(LPCTSTR lpszPathName)
{
	DWORD att=::GetFileAttributes(lpszPathName);
	if(att==0xFFFFFFFF || ((att & FILE_ATTRIBUTE_DIRECTORY)!=0) ) 
	{
		return FALSE;
	}
	return TRUE;
	
}
