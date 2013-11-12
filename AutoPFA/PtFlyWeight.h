// PtFlyWeight.h: interface for the PtFlyWeight class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PtFlyWeight.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PTFLYWEIGHT_H__B7B473B7_BC41_476D_AB24_43A063D7D54E__INCLUDED_)
#define AFX_PTFLYWEIGHT_H__B7B473B7_BC41_476D_AB24_43A063D7D54E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlyWeight.h"

class PtFlyWeight : public FlyWeight  
{
public:
	virtual BOOL GetValue(CString &strValue)const;
    virtual BOOL GetValue(CString &strValue,CString &strUnit)const;
	static FlyWeight* CreatPtFlyWeight();
	PtFlyWeight();
	PtFlyWeight(const PtFlyWeight &ref);
	PtFlyWeight& operator=(const PtFlyWeight &ref);
	virtual ~PtFlyWeight();
public:
	void SetNull();
	BOOL IsEmpty()const;
	void SetValue1(CString strValue);
	void SetValue2(CString strValue);
	void SetValue3(CString strValue);
	void SetValue1(int nValue);
	void SetValue2(int nValue);
	void SetValue3(int nValue);
	void SetValue1(double dValue);
	void SetValue2(double dValue);
	void SetValue3(double dValue);
	CString GetValue1()const;
	CString GetValue2()const;
	CString GetValue3()const;
	void Assign(FlyWeight *pFly);
	BOOL IsEqual(FlyWeight &ref)const;
	CString m_strValue1;
	CString m_strValue2;
	CString m_strValue3;
private:
	FlyWeight* DoClone();

};

inline BOOL PtFlyWeight::GetValue(CString &strValue)const
{
	return FALSE;
}

inline BOOL PtFlyWeight::GetValue(CString &strValue,CString &strUnit)const
{
	strValue = m_strValue1+_T(",")+m_strValue2+_T(",")+m_strValue3;
	return TRUE;
}

inline void PtFlyWeight::SetValue1(CString strValue)
{
	m_strValue1 = strValue;
}
inline void PtFlyWeight::SetValue1(int nValue)
{
	m_strValue1.Format(_T("%d"),nValue);
}
inline void PtFlyWeight::SetValue1(double dValue)
{
	m_strValue1.Format(_T("%.4f"),dValue);
}

inline CString PtFlyWeight::GetValue1()const
{
	return m_strValue1;
}

inline void PtFlyWeight::SetValue2(CString strValue)
{
	m_strValue2 = strValue;
}
inline void PtFlyWeight::SetValue2(int nValue)
{
	m_strValue2.Format(_T("%d"),nValue);
}
inline void PtFlyWeight::SetValue2(double dValue)
{
	m_strValue2.Format(_T("%.4f"),dValue);
}
inline CString PtFlyWeight::GetValue2()const
{
	return m_strValue2;
}
inline void PtFlyWeight::SetValue3(CString strValue)
{
	m_strValue3 = strValue;
}
inline void PtFlyWeight::SetValue3(int nValue)
{
	m_strValue3.Format(_T("%d"),nValue);
}
inline void PtFlyWeight::SetValue3(double dValue)
{
	m_strValue3.Format(_T("%.4f"),dValue);
}
inline CString PtFlyWeight::GetValue3()const
{
	return m_strValue3;
}
#endif // !defined(AFX_PTFLYWEIGHT_H__B7B473B7_BC41_476D_AB24_43A063D7D54E__INCLUDED_)
