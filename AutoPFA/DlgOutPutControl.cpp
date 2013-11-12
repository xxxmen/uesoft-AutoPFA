// DlgOutPutControl.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgOutPutControl.h"


// CDlgOutPutControl 对话框

IMPLEMENT_DYNAMIC(CDlgOutPutControl, CDialog)

CDlgOutPutControl::CDlgOutPutControl(PFAOutModel& outModel, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOutPutControl::IDD, pParent)
	,m_PagePipe(outModel)
	,m_PageJun(outModel)
{
    m_pAutoPFADoc = NULL;
}

CDlgOutPutControl::~CDlgOutPutControl()
{
}

void CDlgOutPutControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(CDlgOutPutControl, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgOutPutControl::OnBnClickedOk)
	ON_BN_CLICKED(ID_BTN_IMPORT, &CDlgOutPutControl::OnBnImport)
	ON_BN_CLICKED(ID_BTN_SAVE, &CDlgOutPutControl::OnBnSave)
END_MESSAGE_MAP()


// CDlgOutPutControl 消息处理程序

BOOL CDlgOutPutControl::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_tab.AddPage( _T("管道"), &m_PagePipe, IDD_PAGE_PIPEOUTCONTROL, TRUE );
	m_tab.AddPage( _T("节点"), &m_PageJun, IDD_PAGE_PIPEOUTCONTROL, TRUE );
	m_tab.Show();
	return TRUE;
}

void CDlgOutPutControl::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_PagePipe.UpData();
	m_PageJun.UpData();
/*	m_pAutoPFADoc->OnViewOutput();*/
	OnOK();
}

void CDlgOutPutControl::SetCurDoc( CAutoPFADoc* pDoc )
{
    m_pAutoPFADoc = pDoc;
}

void CDlgOutPutControl::OnBnImport()
{
	// TODO: 在此添加控件通知处理程序代码
	static TCHAR BASED_CODE szFilter[] = _T("BAT文件(*.bat)|*.bat| 所有文件(*.*)|*.*||");

	CFileDialog dlg( TRUE,_T("bat"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter,this);
	if(IDOK == dlg.DoModal())
	{
		CString strFileName = dlg.GetPathName();
		CStdioFile File;
		if( File.Open( strFileName, CFile::modeRead ) )
		{
			CString strTemp;
			File.ReadString(strTemp);
			if ( strTemp == _T("AutoPFA Output Preferences") )
			{
				File.ReadString(strTemp);
				if ( strTemp == _T("[OUTPUT PREFERENCES]") )
				{
					m_PagePipe.Read(File);
					m_PageJun.Read(File);
				}
			}
			File.Close();
		}
	}
}

void CDlgOutPutControl::OnBnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	static TCHAR BASED_CODE szFilter[] = _T("BAT文件(*.bat)|*.bat| 所有文件(*.*)|*.*||");

	CFileDialog dlg( FALSE,_T("bat"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter,this);
	if(IDOK == dlg.DoModal())
	{
		CString strFileName = dlg.GetPathName();
		CStdioFile File;
		if( File.Open( strFileName, CFile::modeCreate | CFile::modeWrite ) )
		{
			CString str = _T("AutoPFA Output Preferences\n");
			File.WriteString(str);
			str = _T("[OUTPUT PREFERENCES]\n");
			File.WriteString(str);

			m_PagePipe.Save(File);
			File.Close();
		}
	}
}
