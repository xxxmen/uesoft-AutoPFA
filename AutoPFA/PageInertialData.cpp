// PageInertialData.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageInertialData.h"

#include "FourQuadrantDBInterface.h"
//using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageInertialData dialog


PageInertialData::PageInertialData(UnitSubSystem &UnitSys,PageFourQuadTable &table,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageInertialData::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_table(table)
	,m_cmbInerial(&m_EditInerial)
{
	//{{AFX_DATA_INIT(PageInertialData)
	m_strInerialUnit = _T("");
	m_strInerial = _T("");
	m_strNum = _T("");
	m_strSpeed = _T("");
	m_nAngel = -1;
	//}}AFX_DATA_INIT
	m_nSource = 0;
}


void PageInertialData::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageInertialData)
    DDX_Control(pDX, IDC_RADIOANGEL2, m_AngelExpression2);
	DDX_Control(pDX, IDC_RADIOANGEL1, m_AngelExpression1);
	DDX_Control(pDX, IDC_EDITSPEED, m_EditSpeed);
	DDX_Control(pDX, IDC_EDITNUM, m_EditNum);
	DDX_Control(pDX, IDC_EDITINERIAL, m_EditInerial);
	DDX_Control(pDX, IDC_CMBSOURCE, m_cmbSource);
	DDX_Control(pDX, IDC_CMBINERIALUNIT, m_cmbInerial);
	DDX_CBString(pDX, IDC_CMBINERIALUNIT, m_strInerialUnit);
	DDX_Text(pDX, IDC_EDITINERIAL, m_strInerial);
	DDX_Text(pDX, IDC_EDITNUM, m_strNum);
	DDX_Text(pDX, IDC_EDITSPEED, m_strSpeed);
	DDX_Radio(pDX, IDC_RADIOANGEL1, m_nAngel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageInertialData, BaseDlg)
	//{{AFX_MSG_MAP(PageInertialData)
	ON_EN_KILLFOCUS(IDC_EDITNUM, OnKillFocusNum)
	ON_CBN_SELCHANGE(IDC_CMBSOURCE, OnSelchangeSource)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageInertialData message handlers

BOOL PageInertialData::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Inertia,m_cmbInerial,m_strInerialUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void PageInertialData::Init(PumpTransient &ref)
{
	InitStatus(ref);
	GetSpeedTable();
	m_strSpeed = ref.Speed().GetValue();
	InitNum(m_strInerial,m_strInerialUnit,ref.m_RotateInertia);
	m_nSource = ref.FourQuadrantData().GetnValue();
	m_nAngel = ref.FourQuadrantData().GetnValue(2);
	m_strNum = ref.FourQuadrantData().GetValue(1);

	int iIDindex;
	iIDindex = GetIndexOfSqecID( );
	m_cmbSource.SetCurSel(iIDindex);
	OnSelchangeSource();
	UpdateData(FALSE);
}

BOOL PageInertialData::UpData(PumpTransient &ref)
{
	UpdateData(TRUE);
	ref.m_Speed.SetValue(m_strSpeed);
	SetNum(m_strInerial,m_strInerialUnit,ref.m_RotateInertia);
	ref.m_FourQuadrantData.SetValue(m_nSource);
	ref.m_FourQuadrantData.SetValue(m_strNum,1);
	ref.m_FourQuadrantData.SetValue(m_nAngel,2);
	return TRUE;
}


void PageInertialData::OnKillFocusNum() 
{
	// TODO: Add your control notification handler code here
	CString strNum;
	m_EditNum.GetWindowText(strNum);
	m_table.InitRow(_ttoi(strNum));
}

void PageInertialData::InitStatus(PumpTransient &ref)
{
	int nModel = ref.TranModel().GetnValue();
	GetDlgItem(IDC_STATIC1)->EnableWindow();
	m_EditSpeed.EnableWindow();
	GetDlgItem(IDC_STATIC2)->EnableWindow();
	m_EditInerial.EnableWindow();
	m_cmbInerial.EnableWindow();
	GetDlgItem(IDC_STATIC3)->EnableWindow();
	m_cmbSource.EnableWindow();
	GetDlgItem(IDC_STATIC4)->EnableWindow();
	m_EditNum.EnableWindow();
	GetDlgItem(IDC_RADIOANGEL1)->EnableWindow();
	GetDlgItem(IDC_RADIOANGEL2)->EnableWindow();
	switch(nModel) {
	case 2:
	case 5:
		GetDlgItem(IDC_STATIC3)->EnableWindow(FALSE);
		m_cmbSource.EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC4)->EnableWindow(FALSE);
		m_EditNum.EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOANGEL1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOANGEL2)->EnableWindow(FALSE);
		ref.m_FourQuadrantData.SetValue(0,1);
		break;
	case 4:
		GetDlgItem(IDC_STATIC1)->EnableWindow(FALSE);
		m_EditSpeed.EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC2)->EnableWindow(FALSE);
		m_EditInerial.EnableWindow(FALSE);
		m_cmbInerial.EnableWindow(FALSE);
		break;
	case 7:
		GetDlgItem(IDC_STATIC2)->EnableWindow(FALSE);
		m_EditInerial.EnableWindow(FALSE);
		m_cmbInerial.EnableWindow(FALSE);
		break;
	default:
		break;
	}
}

void PageInertialData::OnSelchangeSource() 
{
	int iID;
	GetCurKey(m_cmbSource, iID);
	
	if (0 == iID)
	{
		SetOtherParameter(_T("0"));
		return;
	}

	ListImp<StrArray<3> > CurDBTable;
	GetDBTable(CurDBTable);
	
	TransDataTable<3> table;
	TableFlyWeight<3> FlyWeiTable;
	FlyWeiTable.SetData(CurDBTable);	
	table.Data(FlyWeiTable);
	m_table.Init(table,CurDBTable.GetCount()-1);
}

void PageInertialData::GetSpeedTable()
{
	m_cmbSource.ResetContent();
	CFourQuadrantDBInterface FourSpeedDB;
	CalcTable<2> speedTable;
	FourSpeedDB.GetSqecSpeedTable(speedTable);
	
    CString strSpeed;
	if (! strSpeed.LoadString( IDS_STRUSERDEF ))
	{
		AfxMessageBox(_T("Error Loading String: IDS_STRUSERDEF"));
		return;
	}
	m_cmbSource.AddString(strSpeed);
	m_cmbSource.SetItemData(0, 0);
	
	int index = 1;
	IteratorPtr<StrArray<2> > DBPtr(speedTable.CreatIterator());
	for(DBPtr->Fist();!DBPtr->IsDone();DBPtr->Next())
	{		
		strSpeed = DBPtr->CurrentItem().Data(1); 
		index = m_cmbSource.AddString(strSpeed);
		
		CString strID;
		strID = DBPtr->CurrentItem().Data(0);
		int iID;
		iID = _ttoi(strID);
		m_cmbSource.SetItemData(index, iID);
	}
}

void PageInertialData::GetDBTable(ListImp<StrArray<3> > &CurDBTable)
{
	CString strID;
	int iindexData=0;
	GetCurKey(m_cmbSource, iindexData);
	strID.Format(_T("%d"),iindexData);
	
	CFourQuadrantDBInterface FourDB;
	CalcTable<2> DBTable;
	FourDB.GetFourQuadrantTable(DBTable, strID);
	
	int iAngelCount = DBTable.GetCount() - 1;
	double Angel = 0;
	int i = 0;
	CurDBTable.DelList();
	IteratorPtr<StrArray<2> > DBPtr(DBTable.CreatIterator());
	for( DBPtr->Fist();!DBPtr->IsDone();DBPtr->Next())
	{
		StrArray<3> strArray;
		CString strMember;
		StrArray<2> temp;

		strMember.Format(_T("%0.2f"), Angel);
		Angel += 360.0/iAngelCount;
		strArray.Data(strMember, 0);
		temp = DBPtr->CurrentItem();
		strMember = temp.Data(0);
		strArray.Data(strMember, 1);
		strMember = temp.Data(1);
		strArray.Data(strMember, 2);
		CurDBTable.AddItem(strArray);
		i++;
	}
	SetOtherParameter(strID, iAngelCount);
}

int PageInertialData::GetIndexOfSqecID( )
{
	for (int i=0; i<m_cmbSource.GetCount(); i++)
	{
		if (m_cmbSource.GetItemData(i) == m_nSource)
		{
			return i;
		}
	}
	return 0;
}

void PageInertialData::SetOtherParameter(CString strID, int iAngelCount)
{
	CFourQuadrantDBInterface FourDBSpeed;
	int iAngelExpression;

	iAngelExpression = FourDBSpeed.GetAngelExpression(strID);
	if (iAngelExpression)
	{
		m_AngelExpression2.SetCheck(TRUE);
		m_AngelExpression1.SetCheck(FALSE);
		m_AngelExpression1.SetState(FALSE);
		m_AngelExpression2.SetState(TRUE);
		m_AngelExpression1.EnableWindow(FALSE);
		m_AngelExpression2.EnableWindow(TRUE);
	}
	else
	{
		m_AngelExpression1.SetCheck(TRUE);
		m_AngelExpression2.SetCheck(FALSE);
		m_AngelExpression1.SetState(TRUE);
		m_AngelExpression2.SetState(FALSE);
		m_AngelExpression2.EnableWindow(FALSE);
		m_AngelExpression1.EnableWindow(TRUE);
	}

	CString strAngelCount;
	strAngelCount.Format(_T("%d"),iAngelCount);
	m_EditNum.SetWindowText(strAngelCount);
	if (strID.Compare(_T("0")) == 0)
	{
		m_EditNum.SetReadOnly(FALSE);
		m_AngelExpression1.EnableWindow(TRUE);
		m_AngelExpression2.EnableWindow(TRUE);
	}
	else
	{
		m_EditNum.SetReadOnly();
	}
}
