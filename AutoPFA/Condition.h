// Condition.h: interface for the Condition class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Condition.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONDITION_H__32DB5B21_5774_4599_80FD_AAFDB786E318__INCLUDED_)
#define AFX_ONDITION_H__32DB5B21_5774_4599_80FD_AAFDB786E318__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScenarioObject.h"
class PropertyPersistent;

class Condition : public ScenarioObject  
{
public:
	void SaveData();
	void InitData();
	static void Instance();
	int GetType();
	NameArray& GetArray();
	static ScenarioObject* CreatCondition();
	Condition();
	virtual ~Condition();
	BOOL Read(PropertyPersistent &persistent);
	BOOL Save(PropertyPersistent &persistent);

public:
	double Gravity();
    static StrFlyWeight ms_Gravity;
	static StrFlyWeight ms_ReTransLam;
	static StrFlyWeight ms_ReTransTurb;
	static NumFlyWeight ms_AtmosphericPress;
	static NumFlyWeight ms_AtmosphericTemp;
private:
	static NameArray s_StateName;
	ScenarioObject* DoClone();

};

inline NameArray& Condition::GetArray()
{
	return s_StateName;
}


inline int Condition::GetType()
{
	return 11;
}

#endif // !defined(AFX_ONDITION_H__32DB5B21_5774_4599_80FD_AAFDB786E318__INCLUDED_)
