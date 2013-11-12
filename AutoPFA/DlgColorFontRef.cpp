// DlgColorFontRef.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgColorFontRef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgColorFontRef dialog


DlgColorFontRef::DlgColorFontRef(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgColorFontRef::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgColorFontRef)
	m_strFont = _T("");
	//}}AFX_DATA_INIT
	m_pWorkSpaceRef = NULL;
}


void DlgColorFontRef::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgColorFontRef)
	DDX_Text(pDX, IDC_EFONT, m_strFont);
	DDX_Control(pDX, IDC_GRIDCOLOR, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgColorFontRef, BaseDlg)
	//{{AFX_MSG_MAP(DlgColorFontRef)
	ON_BN_CLICKED(IDC_BSETCOLOR, OnSetColor)
	ON_BN_CLICKED(IDC_BSETFONT, OnSetFont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgColorFontRef message handlers

void DlgColorFontRef::OnSetColor() 
{
	// TODO: Add your control notification handler code here
	CCellID cell = m_list.GetFocusCell();
    if(!m_list.IsValid(cell))
    {
        return;
    }
	CColorDialog dlg;
	if(IDOK == dlg.DoModal())
	{
		m_list.GetCell(cell.row,1)->SetBackClr(dlg.GetColor());
		m_list.RedrawRow(cell.row);
	}
}

void DlgColorFontRef::OnSetFont() 
{
	// TODO: Add your control notification handler code here
	CClientDC dc(NULL);
	LOGFONT lf = m_lf;
	lf.lfHeight = -::MulDiv(-lf.lfHeight, dc.GetDeviceCaps(LOGPIXELSY), 72);
	CFontDialog fontDlg(&lf,CF_SCREENFONTS);
	if(IDOK ==fontDlg.DoModal())
	{
		fontDlg.GetCurrentFont(&lf);
		lf.lfHeight = ::MulDiv(-lf.lfHeight, 72, dc.GetDeviceCaps(LOGPIXELSY));
		m_lf =lf;
		SetFontText();
	}
}

BOOL DlgColorFontRef::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rect;
	m_list.GetWindowRect(rect);
    m_list.InsertColumn(_T("²ÎÊý"));
    m_list.InsertColumn(_T("ÑÕÉ«"));
	m_list.SetColumnWidth(0,(int)(rect.right-rect.left)/2);
	m_list.SetColumnWidth(1,(int)( (rect.right-rect.left)/2.2) );
	m_list.SetFixedRowCount();
	m_list.SetColumnCount(2);
	m_list.SetRowCount(8);
	m_list.SetItemTextFmtID(1,0,IDS_STRCLOSEJUN);
	m_list.SetItemTextFmtID(2,0,IDS_JUNTEXTCOROL);
	m_list.SetItemTextFmtID(3,0,IDS_PIPETEXTCOLOR);
	m_list.SetItemTextFmtID(4,0,IDS_PIPECOLOR);
	m_list.SetItemTextFmtID(5,0,IDS_SELECTITEM);
	m_list.SetItemTextFmtID(6,0,IDS_UNDEFINEITEM);
	m_list.SetItemTextFmtID(7,0,IDS_STRBKCOROL);
	m_list.SetEditable(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgColorFontRef::Init(WorkSpaceRef &ref)
{
	m_pWorkSpaceRef = &ref;
	m_lf = ref.GetFont();
	SetFontText();
	m_list.GetCell(1,1)->SetBackClr(ref.GetJunClose());
	m_list.GetCell(2,1)->SetBackClr(ref.GetJunText());
	m_list.GetCell(3,1)->SetBackClr(ref.GetPipeText());
	m_list.GetCell(4,1)->SetBackClr(ref.GetPipeColor());
	m_list.GetCell(5,1)->SetBackClr(ref.GetSelectItemColor());
	m_list.GetCell(6,1)->SetBackClr(ref.GetUndefineText());
	m_list.GetCell(7,1)->SetBackClr(ref.GetbkColor());
}

BOOL DlgColorFontRef::Updata()
{
	
	m_pWorkSpaceRef->SetFont(m_lf);
	m_pWorkSpaceRef->SetJunClose(m_list.GetCell(1,1)->GetBackClr());
	m_pWorkSpaceRef->SetJunText(m_list.GetCell(2,1)->GetBackClr());
	m_pWorkSpaceRef->SetPipeText(m_list.GetCell(3,1)->GetBackClr());
	m_pWorkSpaceRef->SetPipeColor(m_list.GetCell(4,1)->GetBackClr());
	m_pWorkSpaceRef->SetSelectItemColor(m_list.GetCell(5,1)->GetBackClr());
	m_pWorkSpaceRef->SetUndefineText(m_list.GetCell(6,1)->GetBackClr());
	m_pWorkSpaceRef->SetbkColor(m_list.GetCell(7,1)->GetBackClr());
	return TRUE;
}

void DlgColorFontRef::SetFontText()
{
	m_strFont.Format(_T("%s %d pt."),m_lf.lfFaceName,m_lf.lfHeight);
	UpdateData(FALSE);
}

BOOL DlgColorFontRef::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	NM_GRIDVIEW * m_GridView=(NM_GRIDVIEW *) lParam;
	if(IDC_GRIDCOLOR==wParam)
	{
		if(m_GridView->hdr.code ==NM_DBLCLK)
			OnSetColor();
	}
	return CDialog::OnNotify(wParam, lParam, pResult);
}