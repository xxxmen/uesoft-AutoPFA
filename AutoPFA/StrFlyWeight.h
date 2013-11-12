// StrFlyWeight.h: interface for the StrFlyWeight class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：StrFlyWeight.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRFLYWEIGHT_H__63746494_349F_4DEF_A054_994A5DB37730__INCLUDED_)
#define AFX_STRFLYWEIGHT_H__63746494_349F_4DEF_A054_994A5DB37730__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlyWeight.h"

class StrFlyWeight : public FlyWeight  
{
public:

	virtual BOOL GetValue(CString &strValue)const;
    virtual BOOL GetValue(CString &strValue,CString &strUnit)const;
    void Assign(FlyWeight *pFly);
	BOOL IsEqual(FlyWeight &ref)const;

public:
	void SetNull();
	BOOL IsEmpty()const;
	void SetValue(CString strValue);
	void SetValue(int nValue);
	void SetValue(float fValue);
	CString GetValue()const;
	int GetnValue()const;
	double GetfValue()const;
	static FlyWeight* CreatStrFlyWeight();
	StrFlyWeight();
	StrFlyWeight(const StrFlyWeight &ref);
	StrFlyWeight& operator=(const StrFlyWeight &ref);
	virtual ~StrFlyWeight();
private:
	FlyWeight* DoClone();

private:
	CString m_strValue;
};


inline BOOL StrFlyWeight::GetValue(CString &strValue)const
{
	strValue = m_strValue;
	return TRUE;
}

inline BOOL StrFlyWeight::GetValue(CString &strValue,CString &strUnit)const
{
	strValue = m_strValue;
	strUnit = _T("");
	return TRUE;
}


inline void StrFlyWeight::SetValue(CString strValue)
{
	m_strValue = strValue;
}

inline void StrFlyWeight::SetValue(int nValue)
{
	m_strValue.Format(_T("%d"),nValue);
}
inline void StrFlyWeight::SetValue(float fValue)
{
	m_strValue.Format(_T("%.8f"),fValue);
	m_strValue.TrimRight(_T('0'));
	m_strValue.TrimRight(_T('.'));
}
inline CString StrFlyWeight::GetValue()const
{
	return m_strValue;
}

inline int StrFlyWeight::GetnValue()const
{
	return _ttoi(m_strValue);
}
inline double StrFlyWeight::GetfValue()const
{
	return _tcstod(m_strValue, NULL );
}

#endif // !defined(AFX_STRFLYWEIGHT_H__63746494_349F_4DEF_A054_994A5DB37730__INCLUDED_)
