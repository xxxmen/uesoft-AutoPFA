// WorkSpace.h: interface for the WorkSpace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKSPACE_H__DFAD24BB_903D_4A75_947C_27C0BF0021A5__INCLUDED_)
#define AFX_WORKSPACE_H__DFAD24BB_903D_4A75_947C_27C0BF0021A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PersistentObj.h"
#include "RowObject.h"

class WorkSpace: public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	WorkSpace();
	virtual ~WorkSpace();

private:
	void InitRowHead();
	void InitArray();
	RowObject  m_JunLabColor;
	RowObject  m_PipeLabColor;
	RowObject  m_PipeColor;
	RowObject  m_SelectColor;
	RowObject  m_SpaceColor;
	RowObject  m_SpaceChildColor;
	RowObject  m_SpaceGrandColor;
	RowObject  m_SpaceGrid;
	RowObject  m_UndefinedColor;
	RowObject  m_ClosedJunColor;
	RowObject  m_GridSize;
	RowObject  m_GridLineStyle;
	RowObject  m_GridOn;
	RowObject  m_PipeThick;
	RowObject  m_VaryThick;
	RowObject  m_ThickParame;
	RowObject  m_ThickUnits;
	RowObject  m_ClosedPipeStyle;
	RowObject  m_JunSize;
	RowObject  m_FontName;
	RowObject  m_FontSize;
	RowObject  m_FontBold;
	RowObject  m_FontItalic;
	RowObject  m_ReverseCTRL;
	RowObject  m_ShiftLab;
	RowObject  m_ShowName;
	RowObject  m_JunLabLocation;
	RowObject  m_IconSource;
    RowObject  m_AutoIncPipe;
	RowObject  m_AutoIncJun;
	RowObject  m_PipeArrow;
	RowObject  m_ReverseSelect;
	RowObject  m_UseFlowSymbol;
	RowObject  m_Inflow;
	RowObject  m_Outflow;
	RowObject  m_ClosedSymbol;
	RowObject  m_ShowClosedJun;
	RowObject  m_Pipes;
	RowObject  m_Juns;
	RowObject  m_TranData;
	RowObject  m_TranSpecial;
	RowObject  m_InfinitePipe;
	
	RowObject  m_WorkspaceOptimizedColor;
	RowObject  m_Popup;
	RowObject  m_AutoAdjust;
	RowObject  m_BackgroundPictureScaling;
	RowObject  m_GSCVariable;
	RowObject  m_GSCGoal;
};

#endif // !defined(AFX_WORKSPACE_H__DFAD24BB_903D_4A75_947C_27C0BF0021A5__INCLUDED_)
