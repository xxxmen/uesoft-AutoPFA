// DlgOneEnd.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgOneEnd.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgOneEnd dialog


DlgOneEnd::DlgOneEnd(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgOneEnd::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbEleUnit(&m_EditEle)
{
	//{{AFX_DATA_INIT(DlgOneEnd)
	m_strEleUnit = _T("");
	m_strEle = _T("");
	m_strInPipeID = _T("");
	m_strOutPipeID = _T("");
	//}}AFX_DATA_INIT
}


void DlgOneEnd::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgOneEnd)
	DDX_Control(pDX, IDC_EOUTPIPEID, m_EditOutPipe);
	DDX_Control(pDX, IDC_EINPIPEID, m_EditInPipe);
	DDX_Control(pDX, IDC_EJUNELE, m_EditEle);
	DDX_Control(pDX, IDC_CMBElEUNIT, m_cmbEleUnit);
	DDX_CBString(pDX, IDC_CMBElEUNIT, m_strEleUnit);
	DDX_Text(pDX, IDC_EJUNELE, m_strEle);
	DDX_Text(pDX, IDC_EINPIPEID, m_strInPipeID);
	DDX_Text(pDX, IDC_EOUTPIPEID, m_strOutPipeID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgOneEnd, BaseDlg)
	//{{AFX_MSG_MAP(DlgOneEnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgOneEnd message handlers

void DlgOneEnd::Init()
{
	int nID = 0;
	CString strID;
	IteratorPtr<int> IdItPtr(Jun::ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		strID.Format(_T("%d"),abs(nID));
		if(nID > 0)
		{
			m_strInPipeID = strID;
		}
		else
		{
			m_strOutPipeID = strID;
		}
	}
	InitNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
	
	UpdateData(FALSE);
}

BOOL DlgOneEnd::UpData()
{
	UpdateData(TRUE);
	SetNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
    SetNum(m_strEle,m_strEleUnit,Jun::ms_OutletEle);
	return TRUE;
}

BOOL DlgOneEnd::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbEleUnit,m_strEleUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
