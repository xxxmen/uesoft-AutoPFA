// OptimizationParameter.cpp : implementation file
//

#pragma once

#include "stdafx.h"
#include "OptimizationParameter.h"
#include "OptimitationConst.h"
#include "MainFrm.h"
#include "ChildFrm.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptimizationParameter dialog


COptimizationParameter::COptimizationParameter(CWnd* pParent /*=NULL*/)
	: CDialog(COptimizationParameter::IDD, pParent)
{
	EnableAutomation();
	//{{AFX_DATA_INIT(COptimizationParameter)
	//}}AFX_DATA_INIT
}


COptimizationParameter::COptimizationParameter( CPFAOptimize* pOptimize )
	: CDialog( COptimizationParameter::IDD )
{
	m_pOptimize = pOptimize;
	EnableAutomation();
	//{{AFX_DATA_INIT(COptimizationParameter)
	//}}AFX_DATA_INIT
}

void COptimizationParameter::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void COptimizationParameter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptimizationParameter)
	DDX_Control(pDX, IDC_TAB1, m_myTab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptimizationParameter, CDialog)
	//{{AFX_MSG_MAP(COptimizationParameter)
	ON_WM_CANCELMODE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COptimizationParameter, CDialog)
	//{{AFX_DISPATCH_MAP(COptimizationParameter)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOptimizationParameter to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D49CF9B4-7F58-4624-B8F2-2A0B0EF3E290}
static const IID IID_IOptimizationParameter =
{ 0xd49cf9b4, 0x7f58, 0x4624, { 0xb8, 0xf2, 0x2a, 0xb, 0xe, 0xf3, 0xe2, 0x90 } };

BEGIN_INTERFACE_MAP(COptimizationParameter, CDialog)
	INTERFACE_PART(COptimizationParameter, IID_IOptimizationParameter, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptimizationParameter message handlers

void COptimizationParameter::OnOK() 
{
	// TODO: Add extra validation here
	if( NULL != pOptData )
	{
		if( SaveData( *pOptData ) )
		{
			CDialog::OnOK();
		}
	}	
	CDialog::OnOK();
}

BOOL COptimizationParameter::OnInitDialog() 
{

	CDialog::OnInitDialog();

	m_myTab.InsertItem( 0,  _T("经济参数设置") );
	m_myTab.InsertItem( 1,  _T("其他参数设置") );
	m_OptConstPage.Create( IDD_DLGOPTCONST, GetDlgItem( IDC_TAB1 ) );
	CRect RectTemp;
	m_myTab.GetClientRect( &RectTemp );
	RectTemp.Width();
	RectTemp.Height();
	RectTemp.top += 21;
	RectTemp.bottom -= 2;
	RectTemp.left += 2;
	RectTemp.right -= 2;
	m_OptConstPage.MoveWindow( &RectTemp );
	if( NULL == m_pOptimize )
	{
		return false;
	}
	pOptData = m_pOptimize->GetOptDataPointer();
	OpenData( *pOptData );
	m_OptConstPage.ShowWindow( SW_SHOW );
	m_myTab.SetCurSel( 0 );
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptimizationParameter::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void COptimizationParameter::InitUnit()
{

}



bool COptimizationParameter::SaveData(PFAOptimitationData& OptData)
{
	if( NULL == &OptData )
	{
		return false;
	}	
	return m_OptConstPage.SaveData( OptData );
}

bool COptimizationParameter::OpenData(PFAOptimitationData& OptData)
{
	if( NULL == &OptData )
	{
		return false;
	}
	return m_OptConstPage.OpenData( OptData );
}

void COptimizationParameter::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int iKeyOfSelChange = m_myTab.GetCurSel();
	switch( iKeyOfSelChange )
	{
	    case 0: m_OptConstPage.ShowWindow( SW_SHOW );
			break;
		case 1: m_OptConstPage.ShowWindow( SW_HIDE );
			break;
		default: break;
	}
	*pResult = 0;
}
