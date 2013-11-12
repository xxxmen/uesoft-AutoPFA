// PagePumpOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePumpOption.h"
#include "Pump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePumpOption dialog


PagePumpOption::PagePumpOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PagePumpOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PagePumpOption)
	m_strNumber = _T("");
	m_nSpecial = -1;
	m_nType = -1;
	//}}AFX_DATA_INIT
}


void PagePumpOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePumpOption)
	DDX_Control(pDX, IDC_CMBNUMBEL, m_cmbNumber);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_CBString(pDX, IDC_CMBNUMBEL, m_strNumber);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	DDX_Radio(pDX, IDC_RADIOONE, m_nType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PagePumpOption, BaseDlg)
	//{{AFX_MSG_MAP(PagePumpOption)
	ON_BN_CLICKED(IDC_RADIOONE, OnRadioOne)
	ON_BN_CLICKED(IDC_RADIOIPARALLEL, OnRadioiParallel)
	ON_BN_CLICKED(IDC_RADIOISERIES, OnRadioSeries)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePumpOption message handlers

BOOL PagePumpOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	m_dlgOption.SetDesignCaption(_T("泵增加压力/水头："));
	InitNumber();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PagePumpOption::Init()
{
	int nSet = Pump::ms_PumpSet.GetnValue();
	InitPumpSet(nSet);
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();

	SetPumpSetStatus();
	UpdateData(FALSE);
}

BOOL PagePumpOption::UpData()
{
	UpdateData(TRUE);
	int nModel = Pump::ms_Transient.TranModel().GetnValue();
	if(nModel==5 || nModel == 6)
	{//泵瞬变模型为事件启动则特别条件为停泵允许流体通过
		m_nSpecial = 2;
	}
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	Pump::ms_PumpSet.SetValue(GetPumpSet());
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

void PagePumpOption::OnRadioOne() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetPumpSetStatus();
}

void PagePumpOption::OnRadioiParallel() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	SetPumpSetStatus();
}

void PagePumpOption::OnRadioSeries() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	SetPumpSetStatus();
	
}

void PagePumpOption::SetPumpSetStatus()
{
	BOOL bEnable = TRUE;
	if(m_nType == 0)
	{//单泵
		bEnable = FALSE;
	}
	m_cmbNumber.EnableWindow(bEnable);
}

void PagePumpOption::InitPumpSet(int nSet)
{
	if(nSet == 0)
	{
		m_nType = 0;
	}
	else
	{
		if (nSet > 0)
		{
			m_nType = 1;
		}
		else
		{
			m_nType = 2;
		}
		m_strNumber.Format(_T("%d"),abs(nSet));
	}
}

int PagePumpOption::GetPumpSet()
{
	if(m_nType==0)
	{
		return 0;
	}
	else
	{
		if(m_nType ==1)
		{
			return _ttoi(m_strNumber);
		}
		else
		{
			return -_ttoi(m_strNumber);
		}
	}
}

void PagePumpOption::InitNumber()
{
	CString strText;
	for(int i=1;i<20;i++)
	{
		strText.Format(_T("%d"),i);
		m_cmbNumber.AddString(strText);
	}
}
