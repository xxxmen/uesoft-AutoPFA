// General.h: interface for the General class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：General.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERAL_H__F8221EB2_68CA_499B_AADD_CECECBDC9129__INCLUDED_)
#define AFX_GENERAL_H__F8221EB2_68CA_499B_AADD_CECECBDC9129__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class General : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatGeneral();
	General();
	virtual ~General();

private:
	ScenarioObject* DoClone();

public:
	void DelLinkPipeInfo(UINT nKey);
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bDlgReadOnly = FALSE);
	BOOL Save(Junperisist *pPersistent);
	BOOL Read(Junperisist *pPersistent);
	CString GetTypeName();
	int GetID();
	static const int m_nTypeID;

private:
	BOOL CanLink(int nMaxLink,int nKey);
private:
	void EmptyPipeInfo();
	void AddLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static StrFlyWeight ms_Type;							//类型(0)
	static ArrayFlyWeight<13> ms_Curve;						//损失模型曲线。
	static StrFlyWeight ms_KOrCv;							//K或Cv系数值
	static ArrayFlyWeight<3> ms_BasisArea;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
											        	//值/单位
private:
	int m_nCurve;

};

inline CBitmap& General::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& General::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_GENERAL_H__F8221EB2_68CA_499B_AADD_CECECBDC9129__INCLUDED_)
