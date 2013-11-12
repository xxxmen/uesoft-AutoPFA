// PageUnit.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageUnit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageUnit dialog


PageUnit::PageUnit(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageUnit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageUnit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pUnitSystem = NULL;
	m_pCurUnit = NULL;
	m_CurSel = 0;
}


void PageUnit::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageUnit)
	DDX_Control(pDX, IDC_LIST1, m_symbolList);
	DDX_Control(pDX, IDC_UNITTYPELIST, m_UnitTypeList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageUnit, BaseDlg)
	//{{AFX_MSG_MAP(CPageUnit)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_UNITTYPELIST, OnChangedType)
	ON_BN_CLICKED(IDC_BUTCURUNIT, OnCurUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageUnit message handlers

BOOL PageUnit::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitListHeader();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageUnit::InitListHeader()
{
	CRect rc;
	m_UnitTypeList.GetWindowRect(rc);
	m_UnitTypeList.InsertColumn(0,_T("物理量"),LVCFMT_LEFT,rc.Width()/2);
	m_UnitTypeList.InsertColumn(1,_T("引用单位"),LVCFMT_LEFT,rc.Width()/2.2);
	DWORD styles = m_UnitTypeList.GetExtendedStyle();
	m_UnitTypeList.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
}


void PageUnit::Init(UnitSubSystem *pUnitSystem)
{
	ASSERT(pUnitSystem != NULL);
	m_pUnitSystem = pUnitSystem;
	UnitType *pUnitType = NULL;
	UnitTypeArrayRef &arrayRef = pUnitSystem->GetUnitArray();
	for(int i=0; i<arrayRef.GetSize();i++)
	{
		pUnitType = arrayRef.GetAt(i);
		m_UnitTypeList.InsertItem(i,pUnitType->GetName());
		m_UnitTypeList.SetItemText(i,1,pUnitType->GetCurSymbol());
		m_UnitTypeList.SetItemData(i,pUnitType->GetTypeID());
	}
}

void PageUnit::OnChangedType(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	int index = pNMListView->iItem;
	if(index == -1)
	{
		return;
	}
	int nID = m_UnitTypeList.GetItemData(index);
	UnitTypeID Id = static_cast<UnitTypeID>(nID);
	UnitType *pUnitType = NULL;
	UnitString *pSymbol = NULL;
	if(m_pUnitSystem->FindUnit(Id,pUnitType))
	{
		if(!UpdataSymbol())
			return;
		m_UnitTypeList.SetHotItem(index);
		m_CurSel = index;
		m_pCurUnit = pUnitType;
		m_symbolList.ResetContent();
		IteratorPtr<UnitString> iteratorPtr(pUnitType->CreatIterator());
		for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
		{
			pSymbol = &iteratorPtr->CurrentItem();
			InitSymbol(pSymbol);
		}
	}
	else
	{
		ASSERT(FALSE);
	}
	*pResult = 0;
}

void PageUnit::InitSymbol(UnitString *pSymbol)
{
	ASSERT(pSymbol != NULL);
	int nIndex = m_symbolList.AddString(pSymbol->GetSymbol());
	if(LB_ERR == nIndex)
		return;

	m_symbolList.SetCheck(nIndex,pSymbol->IsUsed());
}


BOOL PageUnit::UpdataSymbol()
{
	if(m_pCurUnit == NULL)
		return TRUE;
 	UnitString *pSymbol = NULL;
	int i = 0;
	BOOL bUsed = FALSE;
	CString strText1,strText2;
	strText1 = m_UnitTypeList.GetItemText(m_CurSel,1);
	IteratorPtr<UnitString> iteratorPtr(m_pCurUnit->CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pSymbol = &iteratorPtr->CurrentItem();
		bUsed = m_symbolList.GetCheck(i);
		m_symbolList.GetText(i,strText2);
		if(!bUsed && !strText1.CompareNoCase(strText2))
		{
			CString strMsg = m_pCurUnit->GetName() + strText1 + _T("为当前引用单位自动选中");
			bUsed = TRUE;
			AfxMessageBox(strMsg);
			return TRUE;
		}
		pSymbol->SetUsed(bUsed);
		i++;
	}
	return TRUE;
}

void PageUnit::OnCurUnit() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_symbolList.GetCurSel();
	if(LB_ERR == nIndex)
		return;
	ASSERT(m_pCurUnit != NULL);
	CString strText;
	m_symbolList.GetText(nIndex,strText);
	//将字符设置选种状态
    m_symbolList.SetCheck(nIndex,1);
	m_pCurUnit->SetCurSymbol(strText);
	m_UnitTypeList.SetItemText(m_CurSel,1,strText);
}
