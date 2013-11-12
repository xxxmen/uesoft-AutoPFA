// Fuild.h: interface for the Fuild class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Fuild.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUILD_H__FA56E91C_548D_45A3_9AFA_7F294E5393D3__INCLUDED_)
#define AFX_FUILD_H__FA56E91C_548D_45A3_9AFA_7F294E5393D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScenarioObject.h"

class PropertyPersistent;

class Fuild : public ScenarioObject  
{
public:
	void SaveData();
	void InitData();
	static void Instance();
	NameArray& GetArray();
	int GetType();
	static ScenarioObject* CreatFuild();
	BOOL Read(PropertyPersistent &persistent);
	BOOL Save(PropertyPersistent &persistent);
	Fuild();
	virtual ~Fuild();
public:
	BOOL IsDefine();
	double BulkModulus();
	double Density();
    static StrFlyWeight ms_Name;
	static NumFlyWeight ms_Density;
	static NumFlyWeight ms_Temperature;
	static NumFlyWeight ms_Viscos;
	static NumFlyWeight ms_BulkModulus;
	static NumFlyWeight ms_VaporPressure;
private:
    static NameArray s_StateName;
	ScenarioObject* DoClone();
};

inline int Fuild::GetType()
{
	return 10;
}

inline NameArray& Fuild::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_FUILD_H__FA56E91C_548D_45A3_9AFA_7F294E5393D3__INCLUDED_)
