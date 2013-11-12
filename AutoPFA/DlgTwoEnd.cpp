// DlgTwoEnd.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgTwoEnd.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTwoEnd dialog


DlgTwoEnd::DlgTwoEnd(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgTwoEnd::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbUnit(&m_EditInEle,&m_EditOutEle)
{
	//{{AFX_DATA_INIT(DlgTwoEnd)
	m_strInPipeID = _T("");
	m_strOutPipeID = _T("");
	m_strOutEle = _T("");
	m_strInEle = _T("");
	m_strUnit = _T("");
	m_bSameEle = TRUE;
	//}}AFX_DATA_INIT
}


void DlgTwoEnd::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTwoEnd)
	DDX_Control(pDX, IDC_EOUTPIPEID, m_EditOutPipe);
	DDX_Control(pDX, IDC_EINPIPEID, m_EditInPipe);
	DDX_Control(pDX, IDC_EOUTELE, m_EditOutEle);
	DDX_Control(pDX, IDC_EINELE, m_EditInEle);
	DDX_Control(pDX, IDC_CHECKSAME, m_CheckSameEle);
	DDX_Control(pDX, IDC_CMBUNIT, m_cmbUnit);
	DDX_Text(pDX, IDC_EINPIPEID, m_strInPipeID);
	DDX_Text(pDX, IDC_EOUTPIPEID, m_strOutPipeID);
	DDX_Text(pDX, IDC_EOUTELE, m_strOutEle);
	DDX_Text(pDX, IDC_EINELE, m_strInEle);
	DDX_CBString(pDX, IDC_CMBUNIT, m_strUnit);
	DDX_Check(pDX, IDC_CHECKSAME, m_bSameEle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTwoEnd, BaseDlg)
	//{{AFX_MSG_MAP(DlgTwoEnd)
	ON_BN_CLICKED(IDC_CHECKSAME, OnCheckSame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTwoEnd message handlers

BOOL DlgTwoEnd::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	InitUnitCbo(m_UnitSys,Length,m_cmbUnit,m_strUnit);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgTwoEnd::OnCheckSame() 
{
	// TODO: Add your control notification handler code here
	m_bSameEle = !m_bSameEle;
	CheckSame();
}

void DlgTwoEnd::Init()
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
	m_strOutEle = Jun::ms_OutletEle.GetValue();
	
	InitNum(m_strInEle,m_strUnit,Jun::ms_InletEle);
	if(0==m_strInEle.CompareNoCase(m_strOutEle))
	{
		m_bSameEle = TRUE;
	}
	else
	{
		m_bSameEle = FALSE;
	}
	CheckSame();
	UpdateData(FALSE);
}

BOOL DlgTwoEnd::UpData()
{
	UpdateData(TRUE);
    SetNum(m_strInEle,m_strUnit,Jun::ms_InletEle);
	if(m_bSameEle)
	{
		Jun::ms_OutletEle.SetValue(m_strInEle);
	}
	else
	{
		Jun::ms_OutletEle.SetValue(m_strOutEle);
	}
	Jun::ms_OutletEle.SetUnit(m_strUnit);
	return TRUE;
}

void DlgTwoEnd::CheckSame()
{
	m_EditOutEle.EnableWindow(!m_bSameEle);
}

int DlgTwoEnd::InPipeID()
{
	return _ttoi(m_strInPipeID);
}

int DlgTwoEnd::OutPipeID()
{
	return _ttoi(m_strOutPipeID);
}
