// dlgdesignfactor.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgdesignfactor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgDesignFactor dialog


DlgDesignFactor::DlgDesignFactor(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgDesignFactor::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgDesignFactor)
	m_strDesignFactor = _T("");
	//}}AFX_DATA_INIT
}


void DlgDesignFactor::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgDesignFactor)
	DDX_Text(pDX, IDC_ELOSSFACTOR, m_strDesignFactor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgDesignFactor, BaseDlg)
	//{{AFX_MSG_MAP(DlgDesignFactor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgDesignFactor message handlers
void DlgDesignFactor::Init(StrFlyWeight &ref)
{
	m_strDesignFactor = ref.GetValue();
	UpdateData(FALSE);
}

BOOL DlgDesignFactor::UpData(StrFlyWeight &ref)
{
	UpdateData(TRUE);
	ref.SetValue(m_strDesignFactor);
	return TRUE;
}

void DlgDesignFactor::SetDesignCaption(CString strCaption)
{
	GetDlgItem(IDC_STATICCAPTION)->SetWindowText(strCaption);
}
