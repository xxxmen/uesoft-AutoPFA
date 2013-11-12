// OptContralTwo.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "OptContralTwo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptContralTwo dialog


COptContralTwo::COptContralTwo(CWnd* pParent /*=NULL*/)
	: BaseDlg(COptContralTwo::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(COptContralTwo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COptContralTwo::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	BaseDlg::OnFinalRelease();
}

void COptContralTwo::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptContralTwo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptContralTwo, BaseDlg)
	//{{AFX_MSG_MAP(COptContralTwo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COptContralTwo, BaseDlg)
	//{{AFX_DISPATCH_MAP(COptContralTwo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOptContralTwo to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {16ACA61D-21F8-46FF-84A2-9EA3E1802AC8}
static const IID IID_IOptContralTwo =
{ 0x16aca61d, 0x21f8, 0x46ff, { 0x84, 0xa2, 0x9e, 0xa3, 0xe1, 0x80, 0x2a, 0xc8 } };

BEGIN_INTERFACE_MAP(COptContralTwo, BaseDlg)
	INTERFACE_PART(COptContralTwo, IID_IOptContralTwo, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptContralTwo message handlers
