// PageSummary.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageSummary.h"
#include "Scenario.h"
#include "ComponentManager.h"
#include "SysProperties.h"
#include "Fuild.h"
#include "FlyWeight.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSummary dialog


PageSummary::PageSummary(CWnd* pParent /*=NULL*/)
: BaseDlg(PageSummary::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageSummary)
	m_strCurName = _T("");
	m_strAnName = _T("");
	m_strPipeNum = _T("");
	m_strJunNum = _T("");
	m_strFuildName = _T("");
	m_strTemp = _T("");
	m_strDen = _T("");
	m_strViscos = _T("");
	//}}AFX_DATA_INIT
	m_pCompManager = NULL;
	m_pFuild = NULL;
}


void PageSummary::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSummary)
	DDX_Text(pDX, IDC_STATIC1, m_strCurName);
	DDX_Text(pDX, IDC_STATIC2, m_strAnName);
	DDX_Text(pDX, IDC_STATIC3, m_strPipeNum);
	DDX_Text(pDX, IDC_STATIC4, m_strJunNum);
	DDX_Text(pDX, IDC_STATIC5, m_strFuildName);
	DDX_Text(pDX, IDC_STATIC6, m_strTemp);
	DDX_Text(pDX, IDC_STATIC7, m_strDen);
	DDX_Text(pDX, IDC_STATIC8, m_strViscos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSummary, BaseDlg)
	//{{AFX_MSG_MAP(PageSummary)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSummary message handlers

void PageSummary::Init(Scenario *pScenario)
{
    m_strCurName = pScenario->GetName();
	m_strAnName  = pScenario->GetAncestName();
	m_pCompManager = pScenario->GetCompManager();
	m_strPipeNum.Format(_T("%d"),m_pCompManager->GetPipeNum());
	m_strJunNum.Format(_T("%d"),m_pCompManager->GetJunNum());
	
	m_pFuild = m_pCompManager->SysProperty().GetFuild();
	const FlyWeight *pFly = m_pFuild->LookUp(1,pScenario);
	pFly->GetValue(m_strFuildName);
	pFly = m_pFuild->LookUp(2,pScenario);
    pFly->GetValue(m_strDen);
	pFly = m_pFuild->LookUp(3,pScenario);
    pFly->GetValue(m_strTemp);
	pFly = m_pFuild->LookUp(4,pScenario);
    pFly->GetValue(m_strViscos);
	UpdateData(FALSE);
}
