// Junperisist.h: interface for the Junperisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNPERISIST_H__1F744722_766D_4CCF_80D2_160837DE6584__INCLUDED_)
#define AFX_JUNPERISIST_H__1F744722_766D_4CCF_80D2_160837DE6584__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "PipeIDList.h"
#include "TwoDTablePersistent.h"

class AFX_EXT_CLASS Junperisist  
{
public:
	int Key();
	int ID();
	CString Name();
	CString CenterPtX();
	CString CenterPtY();
	CString InEle();
	CString OutEle();
	CString InEleUnit();
	CString OutEleUnit();
	CString RawKey();
	void RawKey(CString strValue);
	void Key(int iKey);
	void ID(int iID);
	void Name(CString strValue);
	void CenterPtX(CString strValue);
	void CenterPtY(CString strValue);
	void InEle(CString strValue);
	void OutEle(CString strValue);
	void InEleUnit(CString strValue);
	void OutEleUnit(CString strValue);

	CString DesignFactor();
	void DesignFactor(CString strValue);
	StrArray<3>& InitGuess();
	void InitGuess(const StrArray<3>& strValue);
	StrArray<3>& SpecialMark();
	void SpecialMark(const StrArray<3>& strValue);
	Junperisist();
	virtual ~Junperisist();
public:
	TablePerisist<1> m_list;
	TwoDTablePersistent m_RawData;
private:
	int m_iTypeID;
	int m_iKey;
	CString m_strName;
	CString m_strCenterPtX;
	CString m_strCenterPtY;
	CString m_strInEle;
	CString m_strInEleUnit;
	CString m_strOutEle;
	CString m_strOutEleUnit;
	CString m_DesignFactor;
	CString m_RawKey;
	StrArray<3> m_InitGuess;
	StrArray<3> m_SpecialMark;
};
/*------------------------------------------*/
inline int Junperisist::ID()
{
	return m_iTypeID;
}
inline void Junperisist::ID(int iID)
{
	m_iTypeID = iID;
}
/*------------------------------------------*/
inline int Junperisist::Key()
{
	return m_iKey;
}
inline void Junperisist::Key(int iKey)
{
	m_iKey = iKey;
}
/*------------------------------------------*/
inline CString Junperisist::Name()
{
	return m_strName;
}
inline void Junperisist::Name(CString strValue)
{
	m_strName = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::CenterPtX()
{
	return m_strCenterPtX;
}
inline void Junperisist::CenterPtX(CString strValue)
{
	m_strCenterPtX = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::CenterPtY()
{
	return m_strCenterPtY;
}
inline void Junperisist::CenterPtY(CString strValue)
{
	m_strCenterPtY = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::InEle()
{
	return m_strInEle;
}
inline void Junperisist::InEle(CString strValue)
{
	m_strInEle = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::InEleUnit()
{
	return m_strInEleUnit;
}
inline void Junperisist::InEleUnit(CString strValue)
{
	m_strInEleUnit = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::OutEle()
{
	return m_strOutEle;
}
inline void Junperisist::OutEle(CString strValue)
{
	m_strOutEle = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::OutEleUnit()
{
	return m_strOutEleUnit;
}
inline void Junperisist::OutEleUnit(CString strValue)
{
	m_strOutEleUnit = strValue;
}
/*------------------------------------------*/
/*------------------------------------------*/
inline CString Junperisist::DesignFactor()
{
	return m_DesignFactor;
}
inline void Junperisist::DesignFactor(CString strValue)
{
	m_DesignFactor = strValue;
}
/*------------------------------------------*/
inline CString Junperisist::RawKey()
{
	return m_RawKey;
}
inline void Junperisist::RawKey(CString strValue)
{
	m_RawKey = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& Junperisist::InitGuess()
{
	return m_InitGuess;
}
inline void Junperisist::InitGuess(const StrArray<3>& strValue)
{
	m_InitGuess = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& Junperisist::SpecialMark()
{
	return m_SpecialMark;
}
inline void Junperisist::SpecialMark(const StrArray<3>& strValue)
{
	m_SpecialMark = strValue;
}
#endif // !defined(AFX_JUNPERISIST_H__1F744722_766D_4CCF_80D2_160837DE6584__INCLUDED_)
