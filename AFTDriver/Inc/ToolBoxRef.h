// ToolBoxRef.h: interface for the ToolBoxRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBOXREF_H__5D63F63F_0ADB_4D3A_B928_8852EE7A04E5__INCLUDED_)
#define AFX_TOOLBOXREF_H__5D63F63F_0ADB_4D3A_B928_8852EE7A04E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"
#include "ToolBoxItem.h"
#include "RowObject.h"

class ToolBoxRef : public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	ToolBoxRef();
	virtual ~ToolBoxRef();

private:
	void InitShowShortcutButton(CString InData);
	void InitShowShortcutLabel(CString InData);
	void InitNumberOfToolsNotUsed(CString InData);
	ToolBoxItem m_ToolUsed;
	ToolBoxItem m_ToolsNotUsed;
	RowObject m_ShowShortcutButton;
	RowObject m_ShowShortcutLabel;
	RowObject m_NumberOfToolsNotUsed;
};

#endif // !defined(AFX_TOOLBOXREF_H__5D63F63F_0ADB_4D3A_B928_8852EE7A04E5__INCLUDED_)
