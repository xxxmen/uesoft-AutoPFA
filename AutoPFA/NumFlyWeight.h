// NumFlyWeight.h: interface for the NumFlyWeight class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称： NumFlyWeight.h
  摘要：    
  author  : LSP          
*/
///////////////////////////////////////////////////////////////////////

#if !defined(AFX_NUMFLYWEIGHT_H__7296042C_576B_4D95_8067_16A1110A18EE__INCLUDED_)
#define AFX_NUMFLYWEIGHT_H__7296042C_576B_4D95_8067_16A1110A18EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlyWeight.h"
#include "ListFlyWeightImp.h"

class NumFlyWeight : public FlyWeight  
{
public:
	virtual BOOL GetValue(CString &strValue)const;
    virtual BOOL GetValue(CString &strValue,CString &strUnit)const;
	void Assign(FlyWeight *pFly);
	BOOL IsEqual(FlyWeight &ref)const;
	static FlyWeight* CreatNumFlyWeight();
	NumFlyWeight();
	NumFlyWeight(const NumFlyWeight &ref);
	NumFlyWeight& operator=(const NumFlyWeight &ref);
	virtual ~NumFlyWeight();

public:
	double GetNum()const;
	void SetData(const StrArray<2> &ref);
	StrArray<2> GetData();
	void SetNull();
	BOOL IsEmpty()const;
	void SetUnit(CString strUnit);
	void SetValue(CString strValue);
	void SetValue(int nValue);
	void SetValue(double dValue);
	CString GetUnit()const;
	CString GetValue()const;
	int GetnValue()const;
	double GetfValue()const;

private:
	CString m_strValue;
	CString m_strUnit;

private:
	FlyWeight* DoClone();
};

inline CString NumFlyWeight::GetValue()const
{
	return m_strValue;
}
inline int NumFlyWeight::GetnValue()const
{
	return _ttoi(m_strValue);
}
inline double NumFlyWeight::GetfValue()const
{
	return _tcstod(m_strValue, NULL );
}
inline CString NumFlyWeight::GetUnit()const
{
	return m_strUnit;
}
inline void NumFlyWeight::SetValue(CString strValue)
{
	m_strValue = strValue;
}
inline void NumFlyWeight::SetValue(int nValue)
{
	m_strValue.Format(_T("%d"),nValue);
}
inline void NumFlyWeight::SetValue(double dValue)
{
	m_strValue.Format(_T("%f"),dValue);
	m_strValue.TrimRight(_T('0'));
	m_strValue.TrimRight(_T('.'));
}

inline void NumFlyWeight::SetUnit(CString strUnit)
{
	m_strUnit = strUnit;
}

inline BOOL NumFlyWeight::GetValue(CString &strValue)const
{
	strValue = m_strValue + m_strUnit;
	return TRUE;
}

inline BOOL NumFlyWeight::GetValue(CString &strValue,CString &strUnit)const
{
	strValue = m_strValue;
	strUnit = m_strUnit;
	return TRUE;
}


#endif // !defined(AFX_NUMFLYWEIGHT_H__7296042C_576B_4D95_8067_16A1110A18EE__INCLUDED_)
