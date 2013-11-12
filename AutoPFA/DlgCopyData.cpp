// DlgCopyData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgCopyData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCopyData dialog


DlgCopyData::DlgCopyData( Component* pSrcComponent , Component* pAimComponent , CWnd* pParent /*=NULL*/)
	: CDialog(DlgCopyData::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgCopyData)
		// NOTE: the ClassWizard will add member initialization here
	m_pSrcComponent = pSrcComponent;
	m_pAimComponent = pAimComponent;
	m_bOther = FALSE;
	//}}AFX_DATA_INIT
}


void DlgCopyData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgCopyData)
	DDX_Control(pDX, IDC_AttrList, m_attrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgCopyData, CDialog)
	//{{AFX_MSG_MAP(DlgCopyData)
	ON_BN_CLICKED(IDC_BUT_SelectAll, OnSelectAll)
	ON_BN_CLICKED(IDC_BUT_SelectNone, OnSelectNone)
	ON_BN_CLICKED(IDC_BUT_Invert, OnInvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgCopyData message handlers

BOOL DlgCopyData::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_attrList.SetExtendedStyle( LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_attrList.InsertColumn( 0 , _T("属性名") , LVCFMT_LEFT , 200 );
	m_attrList.InsertColumn( 1 , _T("值") , LVCFMT_LEFT , 200 );
	
	int nIndex = 0;
	NameArray& nameArray =  m_pSrcComponent->GetArray() ;
	for ( int i = 0 ; i < nameArray.GetSize() ; i++ )
	{
		StateName stateName = nameArray.GetAt( i );
		CString strName = stateName.Name();
		int nKey = stateName.Key();	
		//如果是管道,排除入口点，出口点，入口节点和出口节点
		if( m_pSrcComponent->GetType() == 1 )
		{
			if ( 2 == nKey || 3 == nKey || 4 == nKey || 5 == nKey )
			{
				continue;
			}
		}
		//如果是元件,则排除“中心连接点”和“管道连接”
		else
		{
			if ( 2 == nKey || 5 == nKey )
			{
				continue;
			}
		}

		//名字为空的不显示出来
		if ( strName.IsEmpty() )
		{
			continue;
		}
		m_attrList.InsertItem( nIndex ,  strName );
		m_attrList.SetItemData( nIndex , (DWORD)nKey );
		
		FlyWeight* flyWeight = m_pSrcComponent->GetValue( nKey );
		CString flyValue;
		CString flyUnit;
		flyWeight->GetValue( flyValue , flyUnit );
		//如果有单位则把单位显示出来
		if ( !flyUnit.IsEmpty() )
		{
			flyValue += _T(" ");
            flyValue += flyUnit;
		}
		m_attrList.SetItemText( nIndex++ , 1 ,  flyValue );
	}
	
	//其他项(是包含一些名字为空为未知的属性)
	int nCount = 0;
	if ( m_pSrcComponent->GetType() == 1 )
	{
		nCount = 4;
	}
	else
	{
		nCount = 2;
	}
	if ( nameArray.GetSize() > nIndex + nCount )
	{
		m_bOther = TRUE;
        m_attrList.InsertItem( nIndex ,  _T("其它项") );
	}
	return TRUE; 
}

void DlgCopyData::OnOK() 
{
    //数据拷贝
	int nCount = m_attrList.GetItemCount();
	for ( int i = 0; i < nCount ; i++ )
	{
        if( m_attrList.GetCheck( i ) )
		{
			int nKey = (int)m_attrList.GetItemData( i );
			FlyWeight* pFlyWeight = m_pSrcComponent->GetValue( nKey );
			if ( pFlyWeight != NULL )
			{	
				m_pAimComponent->SetValue( *pFlyWeight , nKey );
			}
		}
	}

	//其它项拷贝
	if ( m_bOther && m_attrList.GetCheck( m_attrList.GetItemCount() - 1 ) )
	{
		NameArray& nameArray =  m_pSrcComponent->GetArray() ;
		for ( int i = 0 ; i < nameArray.GetSize() ; i++ )
		{
			StateName stateName = nameArray.GetAt( i );
			CString strName = stateName.Name();
			int nKey = stateName.Key();
			if ( strName.IsEmpty() )
			{
				FlyWeight* pFlyWeight = m_pSrcComponent->GetValue( nKey );
				if ( pFlyWeight != NULL )
				{	
					m_pAimComponent->SetValue( *pFlyWeight , nKey );
				}
			}    
		}
	}

	CDialog::OnOK();
}

//全部选择
void DlgCopyData::OnSelectAll() 
{
	int nCount = m_attrList.GetItemCount();
	for ( int i = 0; i < nCount ; i++ )
	{
        m_attrList.SetCheck( i );
	}
}

//全部不选择
void DlgCopyData::OnSelectNone() 
{
	int nCount = m_attrList.GetItemCount();
	for ( int i = 0; i < nCount ; i++ )
	{
        m_attrList.SetCheck( i , FALSE );
	}
}

//反选
void DlgCopyData::OnInvert() 
{
	int nCount = m_attrList.GetItemCount();
	for ( int i = 0; i < nCount ; i++ )
	{
		if ( m_attrList.GetCheck( i ) )
		{
			m_attrList.SetCheck( i , FALSE );
		}
		else
		{
			m_attrList.SetCheck( i , TRUE );
		}
	}
}

