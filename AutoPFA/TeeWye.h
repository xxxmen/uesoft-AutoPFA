// TeeWye.h: interface for the TeeWye class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TeeWye.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEEWYE_H__822B8F4F_A77C_4F5D_B4C9_CC5FA0AD57EC__INCLUDED_)
#define AFX_TEEWYE_H__822B8F4F_A77C_4F5D_B4C9_CC5FA0AD57EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class TeeWye : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatTeeWye();
    TeeWye();
	virtual ~TeeWye();

private:
	ScenarioObject* DoClone();

public:
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
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void SetPipeID(int ID[],int ndat = 3);
	void GetPipeID(int ID[]);
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static StrFlyWeight ms_Type;			    //类型（0，锐边直三通1，圆边直三通2，面积改变3，对称）
	static StrFlyWeight ms_Angle;			    //角度
	static StrFlyWeight ms_Model;				//损失模型类型（1：简单模型2：详细模型）
};

inline CBitmap& TeeWye::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& TeeWye::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_TEEWYE_H__822B8F4F_A77C_4F5D_B4C9_CC5FA0AD57EC__INCLUDED_)
