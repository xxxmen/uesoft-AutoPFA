// PageComponentTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageComponentTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageComponentTable dialog


PageComponentTable::PageComponentTable(CWnd* pParent /*=NULL*/)
	: PageDataTable(pParent)
{
	//{{AFX_DATA_INIT(PageComponentTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pManager = NULL;
	m_pUnitSys = NULL;
}


void PageComponentTable::DoDataExchange(CDataExchange* pDX)
{
	PageDataTable::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageComponentTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(PageComponentTable, PageDataTable)
	//{{AFX_MSG_MAP(PageComponentTable)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageComponentTable message handlers

void PageComponentTable::InitTableHeader(Component *pComponent)
{
	m_table.InsertColumn(pComponent->GetTypeName());
	//
	NameArray &array = pComponent->GetArray();
	int n = array.GetSize();
	for(int i=0;i<n;i++)
	{
		if(array[i].IsShow())
		{
			m_table.InsertColumn(array[i].Name());
			if(2 == array[i].TypeKey())
			{
				m_table.InsertColumn(array[i].NameUnit());
			}
		}
	}
	m_table.SetFixedRowCount();
	m_table.SetFixedColumnCount();
}

void PageComponentTable::InitTableData(Component *pComponent)
{
	CString strData;
	int nRow = 0;

	strData.Format(_T("%d"),pComponent->GetKey());
	nRow = m_table.InsertRow(strData);

	UpDataTableData(pComponent,nRow);
}

void PageComponentTable::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	if(!HasData())
	{
		m_pManager = pManager;
		m_pUnitSys = pUnitSys;
		m_table.DeleteAllItems();
		InitTableHeader(pComponent);
	}
    HasData(TRUE);
	InitTableData(pComponent);	
}

BOOL PageComponentTable::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	NM_GRIDVIEW * m_GridView=(NM_GRIDVIEW *) lParam;
	if(IDC_TABLE==wParam)
	{
		if(m_GridView->hdr.code ==NM_DBLCLK)
			ShowDlg();	
	}
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void PageComponentTable::ShowDlg()
{
	CCellID cell = m_table.GetFocusCell();
    if(!m_table.IsValid(cell))
    {
        return;
    }
	CString strKey = m_table.GetCell(cell.row,0)->GetText();
	int nKey = _ttoi(strKey);
	Component *pComponent = GetComponent(nKey);
	if(pComponent != NULL)
	{
		pComponent->Show(*m_pUnitSys,m_pManager);
		UpDataTableData(pComponent,cell.row);
		m_table.RedrawRow(cell.row);
	}
}


void PageComponentTable::UpDataTableData(Component *pComponent,int nRow)
{
	int nCol = 1;
	CString strValve;
	CString strUnit;
	FlyWeight *pFly = NULL;
	NameArray &array = pComponent->GetArray();
	int n = array.GetSize();
	for(int i=0;i<n;i++)
	{
		if(array[i].IsShow())
		{
			pFly = pComponent->GetValue(array[i].Key());
			ASSERT(pFly != NULL);
			pFly->GetValue(strValve,strUnit);
			m_table.SetItemText(nRow,nCol++,strValve);
			if(2 == array[i].TypeKey())
			{
				m_table.SetItemText(nRow,nCol++,strUnit);
			}
		}
	}
}
