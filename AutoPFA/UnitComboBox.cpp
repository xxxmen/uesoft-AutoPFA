// UnitComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "UnitComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUnitComboBox

CUnitComboBox::CUnitComboBox(CEdit *pWnd1,CEdit *pWnd2)
{
	m_pWnd1 = pWnd1;
	m_pWnd2 = pWnd2;
	m_dRatio = 1;
}

CUnitComboBox::~CUnitComboBox()
{
}


BEGIN_MESSAGE_MAP(CUnitComboBox, CComboBox)
	//{{AFX_MSG_MAP(CUnitComboBox)
	ON_CONTROL_REFLECT(CBN_SELENDOK, OnSelendOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUnitComboBox message handlers



void CUnitComboBox::InitUnit(UnitSubSystem &system, UnitTypeID id,CString &m_strCurSymbol)
{
	InitUnitCbo(system,id,*this,m_strCurSymbol);
}



CString CUnitComboBox::GetValue(double dOut)
{
	CString strBuf;
	strBuf.Format(_T("%.12f"),dOut);
	if(-1 != strBuf.Find(_T('.')))
	{
		strBuf.TrimRight(_T('0'));
		strBuf.TrimRight(_T('.'));
	}
	return strBuf;
}

void CUnitComboBox::Tran(CWnd *pWnd)
{
	CString strText;
	CString strUnit;
	double dOut = 0;
	double dOut1 = 0;
	pWnd->GetWindowText(strText);
	GetWindowText(strUnit);
	double dIn = _tcstod(strText, '\0');
	TransformToStd(dOut,strUnit,dIn);

	int nIndex = GetCurSel();
	if(CB_ERR != nIndex)
	{
		GetLBText(nIndex,strUnit);
	}
	TransformFromStd(dOut1,strUnit,dOut);
	pWnd->SetWindowText(GetValue(dOut1));
}

void CUnitComboBox::OnSelendOk() 
{
	// TODO: Add your control notification handler code here
	if(m_pWnd1 != NULL)
	{
		DWORD style1 = m_pWnd1->GetStyle();
		DWORD style2 = style1;
		style2 &=~ES_READONLY;
		if(style1 != style2)
			Tran(m_pWnd1);
	}
//	if(m_pWnd2 != NULL)
//	{
//		Tran(m_pWnd2);
//	}
}
