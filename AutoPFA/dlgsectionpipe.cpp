// dlgsectionpipe.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgsectionpipe.h"
#include "NetModel.h"
#include "Pipe.h"
#include "SectionSet.h"
#include "UnitSubSystem.h"
#include "TransDataTable.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSectionPipe dialog


DlgSectionPipe::DlgSectionPipe(UnitSubSystem &UnitSys,NetModel* pNetModel,CWnd* pParent /*=NULL*/)
	: CDialog(DlgSectionPipe::IDD, pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(DlgSectionPipe)
	m_bSearch = FALSE;
	m_bSort = FALSE;
	m_strMaxSection = _T("");
	m_strMinSection = _T("");
	m_nKey = 0;
	m_fTimeStep = 0.0f;
	m_fPctIncrement = 0.0f;
	m_fMaxError = 0.0f;
	m_fIdealSection = 0.0f;
	//}}AFX_DATA_INIT
	m_pNetModel = pNetModel;
}


void DlgSectionPipe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSectionPipe)
	DDX_Check(pDX, IDC_CHECKSEARCH, m_bSearch);
	DDX_Check(pDX, IDC_CHECKSORT, m_bSort);
	DDX_CBString(pDX, IDC_CMBMAXSECTION, m_strMaxSection);
	DDX_CBString(pDX, IDC_CMBMINSECTION, m_strMinSection);
	DDX_Text(pDX, IDC_ENUM, m_nKey);
	DDX_Text(pDX, IDC_ETIMESTEP, m_fTimeStep);
	DDX_Text(pDX, IDC_EPCTINCREMENT, m_fPctIncrement);
	DDX_Text(pDX, IDC_EMAXERROR, m_fMaxError);
	DDX_Text(pDX, IDC_EIDEALSECTION, m_fIdealSection);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LISTRESULT, m_Search);
	DDX_Control(pDX, IDC_LISTSECTION, m_Section);
}


BEGIN_MESSAGE_MAP(DlgSectionPipe, CDialog)
	//{{AFX_MSG_MAP(DlgSectionPipe)
	ON_BN_CLICKED(IDC_BSEARCH, OnSearch)
	ON_BN_CLICKED(IDC_BUPDATATABLE, OnUpdataTable)
	ON_CBN_SELCHANGE(IDC_CMBMAXSECTION, OnSelchangeMaxSection)
	ON_CBN_SELCHANGE(IDC_CMBMINSECTION, OnSelchangeMinSection)
	ON_EN_CHANGE(IDC_EMAXERROR, OnChangeMaxError)
	ON_EN_CHANGE(IDC_EPCTINCREMENT, OnChangeIncrement)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSectionPipe message handlers

BOOL DlgSectionPipe::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ASSERT(m_pNetModel != NULL);
	SectionSet *pSectionSet = m_pNetModel->m_calcManager.GetSectionSet();
	pSectionSet->InitData();

	m_bSearch = abs(SectionSet::ms_Search.GetnValue());
	m_bSort   = abs(SectionSet::ms_Sort.GetnValue());
	m_strMaxSection = SectionSet::ms_MaxSections.GetValue();
	m_strMinSection = SectionSet::ms_MinSections.GetValue();
	m_fTimeStep = SectionSet::ms_TimeStep.GetfValue();
	m_fPctIncrement = SectionSet::ms_PctIncrement.GetfValue();
	m_fMaxError = SectionSet::ms_MaxError.GetfValue();
	m_fIdealSection = SectionSet::ms_IdealSections.GetfValue();

	InitSectionHeader();
	InitSearchHeader();
	InitResult();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSectionPipe::OnSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nMax = _ttoi(m_strMaxSection);
	int nMin = _ttoi(m_strMinSection);
	if(nMin > nMax || nMax <=0 || nMax <=0)
	{
		AfxMessageBox(IDS_MSGNUMERROR);
		return;
	}
	if(0 >= m_fPctIncrement)
	{
		AfxMessageBox(IDS_MSGINCREMENTERROR);
		return;
	}
	if(0 >= m_fMaxError)
	{
		AfxMessageBox(IDS_MSGMAXERROR);
		return;
	}
	ListImp<StrArray<5> > table;
	SectionSet *pSectionSet = m_pNetModel->m_calcManager.GetSectionSet();
	pSectionSet->SearchSection(table,m_pNetModel->m_compManager,nMin,nMax,m_fPctIncrement,m_fMaxError);
	InitSearchData(table);
}

void DlgSectionPipe::OnUpdataTable() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL DlgSectionPipe::Init()
{
	ASSERT(m_pNetModel != NULL);
	Pipe *pPipe = NULL;
	if(!m_pNetModel->m_compManager.SearchControlPipe(pPipe))
	{
		AfxMessageBox(IDS_STRSECTIONPIPEERROE1);
		return FALSE;
	}
	m_nKey = pPipe->GetKey();
	return TRUE;
}

void DlgSectionPipe::InitSectionHeader()
{
	CString strText;
	m_Section.DeleteAllItems();
	strText.LoadString(IDS_STRPIPE);
	m_Section.InsertColumn(strText);

	strText.LoadString(IDS_STRLEN);
	m_Section.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(Length)),DT_CENTER|DT_VCENTER);

	strText.LoadString(IDS_STRWAVESPEED);
	m_Section.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(Velocity)),DT_CENTER|DT_VCENTER);

	strText.LoadString(IDS_STRIDEALSECTION);
	m_Section.InsertColumn(strText,DT_CENTER|DT_VCENTER);

	strText.LoadString(IDS_STRINTSECTION);
	m_Section.InsertColumn(strText,DT_CENTER|DT_VCENTER);
	
	strText.LoadString(IDS_STRTOLERANCE);
	m_Section.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(PercentFractional)),DT_CENTER|DT_VCENTER);

	strText.LoadString(IDS_STRMODIFYWAVE);
	m_Section.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(Velocity)),DT_CENTER|DT_VCENTER);

	strText = _T("B");
	m_Section.InsertColumn(strText,DT_CENTER|DT_VCENTER);

	m_Section.SetFixedRowCount();
	m_Section.SetFixedColumnCount();
	m_Section.SetRowHeight(0,25);

	m_Section.SetColumnWidth(0,40);
	m_Section.SetColumnWidth(1,60);
	m_Section.SetColumnWidth(2,85);
	m_Section.SetColumnWidth(3,65);
	m_Section.SetColumnWidth(4,65);
	m_Section.SetColumnWidth(5,70);
	m_Section.SetColumnWidth(6,85);
	m_Section.SetColumnWidth(7,70);
	m_Section.SetEditable(FALSE);
	m_Section.EnableTitleTips(FALSE);
}

void DlgSectionPipe::InitSearchHeader()
{
	CString strText;
	m_Search.DeleteAllItems();
	m_Search.InsertColumn(_T(""));
	strText = _T("控制管道\n分段数");
	m_Search.InsertColumn(strText,DT_CENTER|DT_VCENTER);
	
	strText = _T("平均误差");
	m_Search.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(PercentFractional)),DT_CENTER|DT_VCENTER);

	strText = _T("最大误差");
	m_Search.InsertColumn(GetTitle(strText,m_UnitSys.FindCurSymbol(PercentFractional)),DT_CENTER|DT_VCENTER);

	strText = _T("最大误差\n管道");
	m_Search.InsertColumn(strText,DT_CENTER|DT_VCENTER);

	m_Search.SetFixedRowCount();
	m_Search.SetFixedColumnCount();
	m_Search.SetRowHeight(0,30);

	m_Search.SetColumnWidth(0,40);
	m_Search.SetColumnWidth(1,80);
	m_Search.SetColumnWidth(2,80);
	m_Search.SetColumnWidth(3,80);
	m_Search.SetColumnWidth(4,80);
	m_Search.SetEditable(FALSE);
	m_Search.EnableTitleTips(FALSE);
}

void DlgSectionPipe::InitSectionData(ListImp<StrArray<8> > &table)
{
	m_Section.SetRowCount(1);
	m_Section.SetRowCount(table.GetCount()+1);
	TranToCur(table,1,m_UnitSys.FindCurSymbol(Length));
	TranToCur(table,2,m_UnitSys.FindCurSymbol(Velocity));
	TranToCur(table,5,m_UnitSys.FindCurSymbol(PercentFractional));
	TranToCur(table,6,m_UnitSys.FindCurSymbol(Velocity));
	LoadTable(table,m_Section);
	m_Section.AutoSizeColumns();
	m_Section.SortItems(CGridCtrl::pfnCellNumericCompare,0,TRUE);
}

void DlgSectionPipe::InitResult()
{
	
	SectionSet *pSectionSet = m_pNetModel->m_calcManager.GetSectionSet();
	if(pSectionSet->IsSection(m_pNetModel->m_compManager))
	{
		ListImp<StrArray<8> > table;
		if(m_fTimeStep > 0)
		{
			m_pNetModel->m_compManager.SectionTable(table,m_fTimeStep);
			InitSectionData(table);
		}
	}
}

void DlgSectionPipe::InitSearchData(ListImp<StrArray<5> > &table)
{
	m_Search.SetRowCount(1);
	m_Search.SetRowCount(table.GetCount()+1);
	LoadTable(table,m_Search);
	m_Search.SortItems(CGridCtrl::pfnCellFloatCompare,3,TRUE);
	CString strText;
	for(int i=1;i<m_Search.GetRowCount();i++)
	{
		strText.Format(_T("%d"),i);
		m_Search.GetCell(i,0)->SetText(strText);
	}
}

BOOL DlgSectionPipe::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	NM_GRIDVIEW * m_GridView=(NM_GRIDVIEW *) lParam;
	if(IDC_LISTRESULT==wParam)
	{
		if(m_GridView->hdr.code ==NM_CLICK)
		{
			CCellID cell = m_Search.GetFocusCell();
			if(m_Search.IsValid(cell))
			{
				CString strSection = m_Search.GetCell(cell.row,1)->GetText();
				UpdataResult(_tcstod(strSection, NULL) );
			}
		}
	}
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void DlgSectionPipe::UpdataResult(float fValue)
{
	Pipe *pPipe = NULL;
    if(!m_pNetModel->m_compManager.SearchControlPipe(pPipe))
	{
		ASSERT(FALSE);
		return;
	}
	m_fTimeStep = pPipe->StepTime() / fValue;
	m_fIdealSection = fValue;
	ListImp<StrArray<8> > table;
	m_pNetModel->m_compManager.SectionTable(table,m_fTimeStep);
	InitSectionData(table);
	UpdateData(FALSE);
}

void DlgSectionPipe::OnOK() 
{
	// TODO: Add extra validation here
	UpData();
	CDialog::OnOK();
}

void DlgSectionPipe::UpData()
{
	UpdateData(TRUE);
	SectionSet::ms_Search.SetValue(m_bSearch);
	SectionSet::ms_Sort.SetValue(m_bSort);
	SectionSet::ms_MaxSections.SetValue(m_strMaxSection);
	SectionSet::ms_MinSections.SetValue(m_strMinSection);
	SectionSet::ms_TimeStep.SetValue(m_fTimeStep);
	SectionSet::ms_PctIncrement.SetValue(m_fPctIncrement);
	SectionSet::ms_MaxError.SetValue(m_fMaxError);
	SectionSet::ms_IdealSections.SetValue(m_fIdealSection);
	ASSERT(m_pNetModel != NULL);
	SectionSet *pSectionSet = m_pNetModel->m_calcManager.GetSectionSet();
	pSectionSet->SaveData();

	ListImp<StrArray<8> > table;
	SaveTable(table,m_Section);
	m_pNetModel->m_compManager.SaveSection(table);
}

void DlgSectionPipe::OnSelchangeMaxSection() 
{
	// TODO: Add your control notification handler code here
	DelTableData();
}

void DlgSectionPipe::OnSelchangeMinSection() 
{
	// TODO: Add your control notification handler code here
	DelTableData();
}

void DlgSectionPipe::OnChangeMaxError() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	DelTableData();
}

void DlgSectionPipe::OnChangeIncrement() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	DelTableData();
}

void DlgSectionPipe::DelTableData()
{
	m_Search.SetRowCount(1);
	m_Section.SetRowCount(1);
	m_Section.Refresh();
	m_Search.Refresh();
}


