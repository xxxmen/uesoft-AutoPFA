// WorkSpaceRef.h: interface for the WorkSpaceRef class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：WorkSpaceRef.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKSPACEREF_H__963B6A92_D383_4D7F_9D28_0A49D4DB51B8__INCLUDED_)
#define AFX_WORKSPACEREF_H__963B6A92_D383_4D7F_9D28_0A49D4DB51B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class WorkSpaceRef  
{
public:
	WorkSpaceRef();
	virtual ~WorkSpaceRef();

public:
	COLORREF& GetJunClose();
	COLORREF& GetJunText();
	COLORREF& GetPipeText();
	COLORREF& GetUndefineText();
	COLORREF& GetPipeColor();
	COLORREF& GetSelectItemColor();
	COLORREF& GetbkColor();
	LOGFONT& GetFont();
	int GetJunSize();
	int GetPipeThick();
	BOOL Trans();
	
	void SetJunClose(const COLORREF &color);
	void SetJunText(const COLORREF &color);
	void SetPipeText(const COLORREF &color);
	void SetUndefineText(const COLORREF &color);
	void SetPipeColor(const COLORREF &color);
	void SetSelectItemColor(const COLORREF &color);
	void SetbkColor(const COLORREF &color);
	void SetFont(LOGFONT& lf);
	void SetJunSize(int nSize);
	void SetPipeThick(int nThick);
	void Trans(BOOL bTrans);
private:
	LOGFONT  m_Lf;
	COLORREF m_JunCloseColor;
	COLORREF m_JunTextColor;
	COLORREF m_PipeTextColor;
    COLORREF m_UndefineTextColor;
    COLORREF m_PipeColor;
    COLORREF m_SelectItemColor;
    COLORREF m_bkColor;

	int      m_nJunSize;
	int      m_nPipeThick;
	BOOL     m_bTrans;
	
};
inline void WorkSpaceRef::Trans(BOOL bTrans)
{
	m_bTrans = bTrans;
}
inline BOOL WorkSpaceRef::Trans()
{
	return m_bTrans;
}
inline void WorkSpaceRef::SetJunSize(int nSize)
{
	m_nJunSize = nSize;
}

inline void WorkSpaceRef::SetPipeThick(int nThick)
{
	m_nPipeThick = nThick;
}

inline void WorkSpaceRef::SetFont(LOGFONT &lf)
{
	m_Lf = lf;
}

inline void WorkSpaceRef::SetJunClose(const COLORREF &color)
{
	m_JunCloseColor = color;
}

inline void WorkSpaceRef::SetJunText(const COLORREF &color)
{
	m_JunTextColor = color;
}
inline void WorkSpaceRef::SetPipeText(const COLORREF &color)
{
	m_PipeTextColor = color;
}
inline void WorkSpaceRef::SetUndefineText(const COLORREF &color)
{
	m_UndefineTextColor = color;
}
inline void WorkSpaceRef::SetPipeColor(const COLORREF &color)
{
	m_PipeColor = color;
}
inline void WorkSpaceRef::SetSelectItemColor(const COLORREF &color)
{
	m_SelectItemColor = color;
}
inline void WorkSpaceRef::SetbkColor(const COLORREF &color)
{
	m_bkColor = color;
}
inline LOGFONT& WorkSpaceRef::GetFont()
{
	return m_Lf;
}

inline COLORREF& WorkSpaceRef::GetJunClose()
{
	return m_JunCloseColor;
}

inline COLORREF& WorkSpaceRef::GetJunText()
{
	return m_JunTextColor;
}

inline COLORREF& WorkSpaceRef::GetPipeText()
{
	return m_PipeTextColor;
}

inline COLORREF& WorkSpaceRef::GetUndefineText()
{
	return m_UndefineTextColor;
}

inline COLORREF& WorkSpaceRef::GetPipeColor()
{
	return m_PipeColor;
}

inline COLORREF& WorkSpaceRef::GetSelectItemColor()
{
	return m_SelectItemColor;
}

inline COLORREF& WorkSpaceRef::GetbkColor()
{
	return m_bkColor;
}

inline int WorkSpaceRef::GetJunSize()
{
	return m_nJunSize;
}
inline int WorkSpaceRef::GetPipeThick()
{
	return m_nPipeThick;
}
#endif // !defined(AFX_WORKSPACEREF_H__963B6A92_D383_4D7F_9D28_0A49D4DB51B8__INCLUDED_)
