// ToolBoxItem.h: interface for the ToolBoxItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBOXITEM_H__6D5923B5_91BE_4EF5_BE35_AB57477280DA__INCLUDED_)
#define AFX_TOOLBOXITEM_H__6D5923B5_91BE_4EF5_BE35_AB57477280DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObject.h"

class ToolBoxItem  
{
public:
	int GetToolNum();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	void InitToolsNum(CString InData);
	ToolBoxItem();
	virtual ~ToolBoxItem();

private:
	void InitTools(CString InData);
	void InitIcons(CString InData);
	void InitIconRotation(CString InData);


	RowObject m_ToolsNum;
	RowObject m_Tools;
	RowObject m_ToolIcons;
	RowObject m_ToolIconRotation;

};

#endif // !defined(AFX_TOOLBOXITEM_H__6D5923B5_91BE_4EF5_BE35_AB57477280DA__INCLUDED_)
