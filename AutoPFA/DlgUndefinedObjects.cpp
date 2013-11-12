// DlgUndefinedObjects.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgUndefinedObjects.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgUndefinedObjects dialog


CDlgUndefinedObjects::CDlgUndefinedObjects( UnitSubSystem* pUnitSubSystem , ComponentManager* pComponentManager , CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUndefinedObjects::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgUndefinedObjects)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pComponentManager = pComponentManager;
	m_pUnitSystem = pUnitSubSystem;
}


void CDlgUndefinedObjects::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgUndefinedObjects)
	DDX_Control(pDX, IDC_STA_UndefinedProps, m_staDisplayMsg);
	DDX_Control(pDX, IDC_LIST_UndefinedProps, m_listUndefinedProps);
	DDX_Control(pDX, IDC_LIST_UndefinedPipes, m_listUndefinedPipes);
	DDX_Control(pDX, IDC_LIST_UndefinedJuns, m_listUndefinedJuns);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgUndefinedObjects, CDialog)
	//{{AFX_MSG_MAP(CDlgUndefinedObjects)
	ON_LBN_SELCHANGE(IDC_LIST_UndefinedPipes, OnSelChangeListUndefinedPipes)
	ON_LBN_SELCHANGE(IDC_LIST_UndefinedJuns, OnSelChangeListUndefinedJuns)
	ON_LBN_SELCHANGE(IDC_LIST_UndefinedProps, OnSelChangeListUndefinedProps)

	ON_LBN_DBLCLK( IDC_LIST_UndefinedPipes , OnLDBClickPipeList )
	ON_LBN_DBLCLK( IDC_LIST_UndefinedJuns , OnDBClickJunList )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgUndefinedObjects message handlers

void CDlgUndefinedObjects::OnSelChangeListUndefinedPipes() 
{
	m_listUndefinedJuns.SetCurSel( -1 );
    m_listUndefinedProps.ResetContent();
	int nIndex = m_listUndefinedPipes.GetCurSel();
	if ( nIndex == -1 )
	{
		return;
	}
	Component* pComponent = (Component*)m_listUndefinedPipes.GetItemData( nIndex );
	if ( pComponent != NULL )
	{
		ComponentStatus status( pComponent->GetArray() );
		pComponent->InitData();
	    pComponent->Status(status,TRUE );
		Iterator<CString>* pIt = status.CreatIterator();
		for ( pIt->Fist(); !pIt->IsDone(); pIt->Next() )
		{
			CString strPropName;
			strPropName = pIt->CurrentItem();
			m_listUndefinedProps.AddString( strPropName );
		}
	}
}

void CDlgUndefinedObjects::OnSelChangeListUndefinedJuns() 
{
	m_listUndefinedPipes.SetCurSel( -1 );
	m_listUndefinedProps.ResetContent();
	int nIndex = m_listUndefinedJuns.GetCurSel();
	if ( nIndex == -1 )
	{
		return;
	}
	Component* pComponent = (Component*)m_listUndefinedJuns.GetItemData( nIndex );
	if ( pComponent != NULL )
	{
		ComponentStatus status( pComponent->GetArray() );
		pComponent->InitData();
		pComponent->Status(status,TRUE );
		Iterator<CString>* pIt = status.CreatIterator();
		for ( pIt->Fist(); !pIt->IsDone(); pIt->Next() )
		{
			CString strPropName;
			strPropName = pIt->CurrentItem();
			m_listUndefinedProps.AddString( strPropName );
		}
	}
}

void CDlgUndefinedObjects::OnLDBClickPipeList()
{
	int nIndex = m_listUndefinedPipes.GetCurSel();
	if ( nIndex == -1 )
	{
		return;
	}
	Component* pComponent = (Component*)m_listUndefinedPipes.GetItemData( nIndex );
	if ( pComponent != NULL )
	{
        ShowPropDlg( pComponent );
	}
  	m_unDefinedPipesMap.RemoveAll();
 	m_pComponentManager->GetAllUndefinedPipes( &m_unDefinedPipesMap );
 	InitWindow();
	if ( nIndex > m_listUndefinedPipes.GetCount() - 1 )
	{
		nIndex = -1;
	}
	m_listUndefinedPipes.SetCurSel( nIndex );
	OnSelChangeListUndefinedPipes();
}

void CDlgUndefinedObjects::OnDBClickJunList()
{
	int nIndex = m_listUndefinedJuns.GetCurSel();
	Component* pComponent = (Component*)m_listUndefinedJuns.GetItemData( nIndex );
	if ( pComponent != NULL )
	{
        ShowPropDlg( pComponent );
	}

    m_unDefinedJunsMap.RemoveAll();
 	m_pComponentManager->GetAllUndefinedJuns( &m_unDefinedJunsMap );
 	InitWindow();
	if ( nIndex > m_listUndefinedJuns.GetCount() - 1 )
	{
		nIndex = -1;
	}
	m_listUndefinedJuns.SetCurSel( nIndex );
    OnSelChangeListUndefinedJuns();
}

void CDlgUndefinedObjects::ShowPropDlg( Component* pComponent )
{
	if ( pComponent != NULL )
	{
		pComponent->Show( *m_pUnitSystem , m_pComponentManager );
	}
}

BOOL CDlgUndefinedObjects::OnInitDialog() 
{
    CDialog::OnInitDialog();
	m_pComponentManager->GetAllUndefinedPipes( &m_unDefinedPipesMap );
	m_pComponentManager->GetAllUndefinedJuns( &m_unDefinedJunsMap );
	InitWindow();
	return TRUE; 
}

void CDlgUndefinedObjects::InitWindow()
{
	int nKey;
	Component* pComponet = NULL ;
	int nCount = 0;
	//初始化未定义管件列表
	m_listUndefinedPipes.ResetContent();
	m_listUndefinedJuns.ResetContent();
	m_listUndefinedProps.ResetContent();
	POSITION pos = m_unDefinedPipesMap.GetStartPosition();
    while ( pos )
    {
		m_unDefinedPipesMap.GetNextAssoc( pos , nKey , pComponet );
		if ( pComponet != NULL )
		{
			CString strTemp;
			strTemp.Format( _T("%d     %s"), nKey , pComponet->GetName() );
			m_listUndefinedPipes.AddString( strTemp );
			m_listUndefinedPipes.SetItemData( nCount++ , (DWORD)pComponet );
		}
    }

	//初始化未定义节点列表
	nCount = 0;
	pos = m_unDefinedJunsMap.GetStartPosition();
    while ( pos )
    {
		m_unDefinedJunsMap.GetNextAssoc( pos , nKey , pComponet );
		if ( pComponet != NULL )
		{
			CString strTemp;
			strTemp.Format( _T("%d     %s"), nKey , pComponet->GetName() );
			m_listUndefinedJuns.AddString( strTemp );
            m_listUndefinedJuns.SetItemData( nCount++ , (DWORD)pComponet );
		}
    }
}

void CDlgUndefinedObjects::OnSelChangeListUndefinedProps() 
{
	m_listUndefinedProps.SetCurSel( -1 );
}
