// DeadEnd.h: interface for the DeadEnd class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DeadEnd.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEADEND_H__4372FBD9_C8A0_4E59_AE30_1E6CDDFF9792__INCLUDED_)
#define AFX_DEADEND_H__4372FBD9_C8A0_4E59_AE30_1E6CDDFF9792__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class DeadEnd : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatDeadEnd();
	DeadEnd();
	virtual ~DeadEnd();

private:
	ScenarioObject* DoClone();

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bDlgReadOnly = FALSE);
	BOOL Save(Junperisist *pPersistent);
	BOOL Read(Junperisist *pPersistent);
	CString GetTypeName();
	int GetID();
	static const int m_nTypeID;
private:
	BOOL CanLink(int nMaxLink,int nKey);
private:
	void EmptyPipeInfo();
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

};

inline CBitmap& DeadEnd::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& DeadEnd::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_DEADEND_H__4372FBD9_C8A0_4E59_AE30_1E6CDDFF9792__INCLUDED_)
