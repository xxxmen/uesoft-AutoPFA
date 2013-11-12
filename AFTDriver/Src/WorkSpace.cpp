// WorkSpace.cpp: implementation of the WorkSpace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorkSpace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WorkSpace::WorkSpace()
{
	InitArray();
}

WorkSpace::~WorkSpace()
{

}

void WorkSpace::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(42);
		m_RowArray.SetAt(0,&m_JunLabColor);
		m_RowArray.SetAt(1,&m_PipeLabColor);
		m_RowArray.SetAt(2,&m_PipeColor);
		m_RowArray.SetAt(3,&m_SelectColor);
		m_RowArray.SetAt(4,&m_SpaceColor);
		m_RowArray.SetAt(5,&m_SpaceChildColor);
		m_RowArray.SetAt(6,&m_SpaceGrandColor);
		m_RowArray.SetAt(7,&m_SpaceGrid);
		m_RowArray.SetAt(8,&m_UndefinedColor);
		m_RowArray.SetAt(9,&m_ClosedJunColor);
		m_RowArray.SetAt(10,&m_GridSize);
		m_RowArray.SetAt(11,&m_GridLineStyle);
		m_RowArray.SetAt(12,&m_GridOn);
		m_RowArray.SetAt(13,&m_PipeThick);
		m_RowArray.SetAt(14,&m_VaryThick);
		m_RowArray.SetAt(15,&m_ThickParame);
		m_RowArray.SetAt(16,&m_ThickUnits);
		m_RowArray.SetAt(17,&m_ClosedPipeStyle);
		m_RowArray.SetAt(18,&m_JunSize);
		m_RowArray.SetAt(19,&m_FontName);
		m_RowArray.SetAt(20,&m_FontSize);
		m_RowArray.SetAt(21,&m_FontBold);
		m_RowArray.SetAt(22,&m_FontItalic);
		m_RowArray.SetAt(23,&m_ReverseCTRL);
		m_RowArray.SetAt(24,&m_ShiftLab);
		m_RowArray.SetAt(25,&m_ShowName);
		m_RowArray.SetAt(26,&m_JunLabLocation);
		m_RowArray.SetAt(27,&m_IconSource);
		m_RowArray.SetAt(28,&m_AutoIncPipe);
		m_RowArray.SetAt(29,&m_AutoIncJun);
		m_RowArray.SetAt(30,&m_PipeArrow);
		m_RowArray.SetAt(31,&m_ReverseSelect);
		m_RowArray.SetAt(32,&m_UseFlowSymbol);
		m_RowArray.SetAt(33,&m_Inflow);
		m_RowArray.SetAt(34,&m_Outflow);
		m_RowArray.SetAt(35,&m_ClosedSymbol);
		m_RowArray.SetAt(36,&m_ShowClosedJun);
		m_RowArray.SetAt(37,&m_Pipes);
		m_RowArray.SetAt(38,&m_Juns);
		m_RowArray.SetAt(39,&m_TranData);
		m_RowArray.SetAt(40,&m_TranSpecial);
		m_RowArray.SetAt(41,&m_InfinitePipe);
	} 
	else
	{
		m_RowArray.SetSize(47);
		m_RowArray.SetAt(0,&m_JunLabColor);
		m_RowArray.SetAt(1,&m_PipeLabColor);
		m_RowArray.SetAt(2,&m_PipeColor);
		m_RowArray.SetAt(3,&m_SelectColor);
		m_RowArray.SetAt(4,&m_SpaceColor);
		m_RowArray.SetAt(5,&m_SpaceChildColor);
		m_RowArray.SetAt(6,&m_WorkspaceOptimizedColor);
		m_RowArray.SetAt(7,&m_SpaceGrandColor);
		m_RowArray.SetAt(8,&m_SpaceGrid);
		m_RowArray.SetAt(9,&m_UndefinedColor);
		m_RowArray.SetAt(10,&m_ClosedJunColor);
		m_RowArray.SetAt(11,&m_GridSize);
		m_RowArray.SetAt(12,&m_GridLineStyle);
		m_RowArray.SetAt(13,&m_GridOn);
		m_RowArray.SetAt(14,&m_PipeThick);
		m_RowArray.SetAt(15,&m_VaryThick);
		m_RowArray.SetAt(16,&m_ThickParame);
		m_RowArray.SetAt(17,&m_ThickUnits);
		m_RowArray.SetAt(18,&m_ClosedPipeStyle);
		m_RowArray.SetAt(19,&m_JunSize);
		m_RowArray.SetAt(20,&m_FontName);
		m_RowArray.SetAt(21,&m_FontSize);
		m_RowArray.SetAt(22,&m_FontBold);
		m_RowArray.SetAt(23,&m_FontItalic);
		m_RowArray.SetAt(24,&m_ReverseCTRL);
		m_RowArray.SetAt(25,&m_ShiftLab);
		m_RowArray.SetAt(26,&m_ShowName);
		m_RowArray.SetAt(27,&m_JunLabLocation);
		m_RowArray.SetAt(28,&m_IconSource);
		m_RowArray.SetAt(29,&m_AutoIncPipe);
		m_RowArray.SetAt(30,&m_AutoIncJun);
		m_RowArray.SetAt(31,&m_PipeArrow);
		m_RowArray.SetAt(32,&m_ReverseSelect);
		m_RowArray.SetAt(33,&m_Popup);
		m_RowArray.SetAt(34,&m_AutoAdjust);
		m_RowArray.SetAt(35,&m_BackgroundPictureScaling);
		m_RowArray.SetAt(36,&m_UseFlowSymbol);
		m_RowArray.SetAt(37,&m_Inflow);
		m_RowArray.SetAt(38,&m_Outflow);
		m_RowArray.SetAt(39,&m_ClosedSymbol);
		m_RowArray.SetAt(40,&m_ShowClosedJun);
		m_RowArray.SetAt(41,&m_Pipes);
		m_RowArray.SetAt(42,&m_Juns);
		m_RowArray.SetAt(43,&m_TranData);
		m_RowArray.SetAt(44,&m_TranSpecial);
		m_RowArray.SetAt(45,&m_GSCVariable);
		m_RowArray.SetAt(46,&m_GSCGoal);
	}
	
	InitRowHead();
}

void WorkSpace::Init()
{
	if ( isImpFile )
	{
		CString strArray[42];
		strArray[0] = _T("0");
		strArray[1] = _T("0");
		strArray[2] = _T("8421504");
		strArray[3] = _T("255");
		strArray[4] = _T("16777215");
		strArray[5] = _T("16777215");
		strArray[6] = _T("16777215");
		strArray[7] = _T("16777088");
		strArray[8] = _T("255");
		strArray[9] = _T("255");
		strArray[10] = _T("0");
		strArray[11] = _T("-1");
		strArray[12] = _T(" 0");
		strArray[13] = _T("3");
		strArray[14] = _T("0");
		strArray[15] = _T("0,0,0,0");
		strArray[16] = _T("None");
		strArray[17] = _T("2");
		strArray[18] = _T("100");
		strArray[19] = _T("Arial");
		strArray[20] = _T("9");
		strArray[21] = _T("0");
		strArray[22] = _T("0 ");
		strArray[23] = _T("-1 ");
		strArray[24] = _T("0 ");
		strArray[25] = _T("1");
		strArray[26] = _T("0");
		strArray[27] = _T("0 ");
		strArray[28] = _T("1");
		strArray[29] = _T("1 ");
		strArray[30] = _T("5");
		strArray[31] = _T("-1 ");
		strArray[32] = _T("-1 ");
		strArray[33] = _T("v");
		strArray[34] = _T("^");
		strArray[35] = _T("-1 ");
		strArray[36] = _T("-1 ");
		strArray[37] = _T("X");
		strArray[38] = _T("X");
		strArray[39] = _T("T");
		strArray[40] = _T("#");
		strArray[41] = _T("*");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==42);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	} 
	else
	{
		CString strArray[47];
		strArray[0] = _T("32768");
		strArray[1] = _T("10485760");
		strArray[2] = _T("8421504");
		strArray[3] = _T("255");
		strArray[4] = _T("16777215");
		strArray[5] = _T("16777215");
		strArray[6] = _T("16777215");
		strArray[7] = _T("16777215");
		strArray[8] = _T("16777088");
		strArray[9] = _T("255");
		strArray[10] = _T("255");
		strArray[11] = _T("0");
		strArray[12] = _T("-1");
		strArray[13] = _T(" 0");
		strArray[14] = _T("3");
		strArray[15] = _T("0");
		strArray[16] = _T("0,0,0,0");
		strArray[17] = _T("None");
		strArray[18] = _T("2");
		strArray[19] = _T("100");
		strArray[20] = _T("Arial");
		strArray[21] = _T("9");
		strArray[22] = _T("0");
		strArray[23] = _T("0 ");
		strArray[24] = _T("-1 ");
		strArray[25] = _T("0 ");
		strArray[26] = _T("1");
		strArray[27] = _T("0");
		strArray[28] = _T("0 ");
		strArray[29] = _T("1");
		strArray[30] = _T("1 ");
		strArray[31] = _T("5");
		strArray[32] = _T("-1");
		strArray[33] = _T("-1");
		strArray[34] = _T("-1");
		strArray[35] = _T("1");
		strArray[36] = _T("-1 ");
		strArray[37] = _T("v");
		strArray[38] = _T("^");
		strArray[39] = _T("-1 ");
		strArray[40] = _T("-1 ");
		strArray[41] = _T("X");
		strArray[42] = _T("X");
		strArray[43] = _T("T");
		strArray[44] = _T("#");
		strArray[45] = _T("V");
		strArray[46] = _T("G");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==47);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

BOOL WorkSpace::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL WorkSpace::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void WorkSpace::InitRowHead()
{
	SetID("\n[WORKSPACE PREFERENCES]");
	if ( isImpFile )
	{
		CString strArray[42];
		strArray[0] = _T("JunctionLabelColor=");
		strArray[1] = _T("PipeLabelColor= ");
		strArray[2] = _T("PipeColor= ");
		strArray[3] = _T("SelectColor= ");
		strArray[4] = _T("WorkspaceColor=");
		strArray[5] = _T("WorkspaceChildColor= ");
		strArray[6] = _T("WorkspaceGrandChildColor=");
		strArray[7] = _T("WorkspaceGridColor= ");
		strArray[8] = _T("UndefinedColor= ");
		strArray[9] = _T("ClosedJctColor= ");
		strArray[10] = _T("GridSize= ");
		strArray[11] = _T("GridLineStyle=");
		strArray[12] = _T("GridOn= ");
		strArray[13] = _T("Pipe Thickness=");
		strArray[14] = _T("Vary Thickness= ");
		strArray[15] = _T("Thickness Parameters=");
		strArray[16] = _T("Thick Unitse=");
		strArray[17] = _T("Closed Pipe Style=");
		strArray[18] = _T("Junction Size= ");
		strArray[19] = _T("Workspace Font Name=");
		strArray[20] = _T("Workspace Font Size= ");
		strArray[21] = _T("Workspace Font Bold= ");
		strArray[22] = _T("Workspace Font Italic= ");
		strArray[23] = _T("Reverse CTRL= ");
		strArray[24] = _T("Use Shift For Labels= ");
		strArray[25] = _T("ShowNameNumber= ");
		strArray[26] = _T("JunctionLableLocation=");
		strArray[27] = _T("IconSource= ");
		strArray[28] = _T("AutoIncPipe= ");
		strArray[29] = _T("AutoIncJct=  ");
		strArray[30] = _T("PipeArrow= ");
		strArray[31] = _T("ReverseSelectBehavior= ");
		strArray[32] = _T("Use Flow Symbols= ");
		strArray[33] = _T("Inflow=");
		strArray[34] = _T("Outflow=");
		strArray[35] = _T("Use Closed Symbols=");
		strArray[36] = _T("Show Closed Jct Border=");
		strArray[37] = _T("Pipes=");
		strArray[38] = _T("Junctions=");
		strArray[39] = _T("Transient Data=");
		strArray[40] = _T("Transient Special Con=");
		strArray[41] = _T("Infinite Pipe=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==42);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	} 
	else
	{
		CString strArray[47];
		strArray[0] = _T("JunctionLabelColor= ");
		strArray[1] = _T("PipeLabelColor= ");
		strArray[2] = _T("PipeColor= ");
		strArray[3] = _T("SelectColor= ");
		strArray[4] = _T("WorkspaceColor= ");
		strArray[5] = _T("WorkspaceChildColor= ");
		strArray[6] = _T("WorkspaceGrandChildColor= ");
		strArray[7] = _T("WorkspaceOptimizedColor= "); 
		strArray[8] = _T("WorkspaceGridColor= ");
		strArray[9] = _T("UndefinedColor= ");
		strArray[10] = _T("ClosedJctColor= ");
		strArray[11] = _T("GridSize= ");
		strArray[12] = _T("GridLineStyle= ");
		strArray[13] = _T("GridOn= ");
		strArray[14] = _T("Pipe Thickness= ");
		strArray[15] = _T("Vary Thickness= ");
		strArray[16] = _T("Thickness Parameters=");
		strArray[17] = _T("Thick Units=");
		strArray[18] = _T("Closed Pipe Style= ");
		strArray[19] = _T("Junction Size= ");
		strArray[20] = _T("Workspace Font Name=");
		strArray[21] = _T("Workspace Font Size= ");
		strArray[22] = _T("Workspace Font Bold= ");
		strArray[23] = _T("Workspace Font Italic= ");
		strArray[24] = _T("Reverse CTRL= ");
		strArray[25] = _T("Use Shift For Labels= ");
		strArray[26] = _T("ShowNameNumber= ");
		strArray[27] = _T("JunctionLableLocation= ");
		strArray[28] = _T("IconSource= ");
		strArray[29] = _T("AutoIncPipe= ");
		strArray[30] = _T("AutoIncJct=  ");
		strArray[31] = _T("PipeArrow= ");
		strArray[32] = _T("ReverseSelectBehavior= ");
		strArray[33] = _T("Popup=");
		strArray[34] = _T("AutoAdjust=");
		strArray[35] = _T("BackgroundPictureScaling= ");
		strArray[36] = _T("Use Flow Symbols= ");
		strArray[37] = _T("Inflow=");
		strArray[38] = _T("Outflow=");
		strArray[39] = _T("Use Closed Symbols=");
		strArray[40] = _T("Show Closed Jct Border=");
		strArray[41] = _T("Pipes=");
		strArray[42] = _T("Junctions=");
		strArray[43] = _T("Transient Data=");
		strArray[44] = _T("Transient Special Con=");
		strArray[45] = _T("GSC Variable=");
		strArray[46] = _T("GSC Goal=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==47);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
}
