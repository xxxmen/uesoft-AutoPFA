// TreeScenario.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "TreeScenario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TreeScenario

TreeScenario::TreeScenario()
{
}

TreeScenario::~TreeScenario()
{
}

BEGIN_MESSAGE_MAP(TreeScenario, CTreeCtrl)
	//{{AFX_MSG_MAP(TreeScenario)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TreeScenario message handlers

void TreeScenario::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CTreeCtrl::OnRButtonDown(nFlags, point);
	CMenu popUpMenu;
	popUpMenu.CreatePopupMenu();
	popUpMenu.AppendMenu(MF_STRING,ID_CREATCHILD,_T("创建子工况"));
    popUpMenu.AppendMenu(MF_STRING,ID_CLONEWITHCHILD,_T("克隆兄弟和子工况"));
	popUpMenu.AppendMenu(MF_STRING,ID_CLONEWITHOUT,_T("克隆兄弟工况"));
	popUpMenu.AppendMenu(MF_STRING,ID_PROMOTE,_T("提升工况"));
	popUpMenu.AppendMenu(MF_STRING,ID_DELSCENARIO,_T("删除工况"));
	popUpMenu.AppendMenu(MF_STRING,ID_RENAME,_T("重命名工况"));
	popUpMenu.AppendMenu(MF_STRING,ID_SAVESCENARIO,_T("导出选择工况"));
	ClientToScreen(&point);
	popUpMenu.TrackPopupMenu(TPM_RIGHTBUTTON,point.x,point.y,GetParent());
}
