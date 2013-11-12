// ToolBoxRef.cpp: implementation of the ToolBoxRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToolBoxRef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ToolBoxRef::ToolBoxRef()
{
	SetID("\n[TOOLBOX PREFERENCES]");
}

ToolBoxRef::~ToolBoxRef()
{

}

void ToolBoxRef::Init()
{
	m_ToolUsed.Init();
	if ( isImpFile)
	{
		CString strToolsNum = _T("NumberOfToolsUsed= 0");
		m_ToolsNotUsed.InitToolsNum(strToolsNum);
	} 
	else
	{
		CString str_NumberOfToolsNotUsed = _T( "NumberOfToolsNotUsed= 0" ) ;
		CString str_ShowShortcutButton = _T( "ShowShortcutButton=-1" ) ;
		CString	str_ShowShortcutLabel = _T( "ShowShortcutLabel=-1" ) ;
		InitShowShortcutButton( str_ShowShortcutButton ) ;
		InitShowShortcutLabel( str_ShowShortcutLabel ) ;
		InitNumberOfToolsNotUsed( str_NumberOfToolsNotUsed ) ;
	}
}

BOOL ToolBoxRef::Read(CStdioFile &file)
{
	CString strTemp;
	m_ToolUsed.Read(file);
    if ( isImpFile )
    {
		m_ToolsNotUsed.Read(file);
    } 
    else
    {
		file.ReadString( strTemp ) ;
		InitNumberOfToolsNotUsed( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitShowShortcutButton(strTemp) ;
		file.ReadString( strTemp ) ;
		InitShowShortcutLabel( strTemp ) ;
    }

	return TRUE;
}
BOOL ToolBoxRef::Save(CStdioFile &file)
{
	SaveRow(file);
	m_ToolUsed.Save(file);
    if ( isImpFile )
    {
		m_ToolsNotUsed.Save( file ) ;
    } 
    else
    {
		file.WriteString( m_NumberOfToolsNotUsed.Save() ) ;
		file.WriteString( m_ShowShortcutButton.Save() ) ;
		file.WriteString( m_ShowShortcutLabel.Save() ) ;
    }
	return TRUE;
}

void ToolBoxRef::InitShowShortcutButton(CString InData)
{
	m_ShowShortcutButton.InitRow(InData);
}

void ToolBoxRef::InitShowShortcutLabel(CString InData)
{
	m_ShowShortcutLabel.InitRow( InData ) ;
}
void ToolBoxRef::InitNumberOfToolsNotUsed(CString InData)
{
	m_NumberOfToolsNotUsed.InitRow( InData ) ;
}