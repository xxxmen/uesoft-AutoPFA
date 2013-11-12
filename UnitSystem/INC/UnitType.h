// UnitType.h: interface for the UnitType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNITTYPE_H__694053C9_E982_4F82_8491_D38B37F4CB7E__INCLUDED_)
#define AFX_UNITTYPE_H__694053C9_E982_4F82_8491_D38B37F4CB7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SysUnitString.h"
#include "Iterator.h"
#include <vector>
#include "UnitSystemShareHeader.h"
using namespace std;

typedef CArray<CString,CString>  SymbolArray;

class AFX_EXT_CLASS UnitType  
{
public:
	Iterator<UnitString>* CreatIterator();
	CString GetCurSymbol();
	CString GetStdSymbol();
	CString GetName();
	CString GetStrID();
	UINT GetTypeID();
	void GetUsedArray(SymbolArray &array);
	void SetCurSymbol(CString strSymbol);
	void SetStdSymbol(CString strSymbol);
	void InitSymbol(vector< UeStdString > &array);
	BOOL FilterString(CString strSymbol,BOOL bUsed);
	UnitType(CString strName,UINT nID,CString strID);
	UnitType();
	virtual ~UnitType();
	UnitType(const UnitType &ref);
	UnitType& operator=(const UnitType &ref);

private:
	BOOL FindUnitString(CString strSymbol,UnitString *pSymbol);
	void AddUnitSymbol(CString strSymbol);

private:
	void CloneList(const UnitStringList &symbolList);
	void DelList();
	UINT     m_nID;
	CString  m_strID;
	CString m_strName;
	CString m_strCurSymbol;
	CString m_strStdSymbol;
	UnitStringList m_symbolList;

};

inline UINT UnitType::GetTypeID()
{
	return m_nID;
}
inline CString UnitType::GetStrID()
{
	return m_strID;
}
inline CString UnitType::GetName()
{
	return m_strName;
}

inline CString UnitType::GetCurSymbol()
{
	return m_strCurSymbol;
}

inline void UnitType::SetCurSymbol(CString strSymbol)
{
	m_strCurSymbol = strSymbol;
}
inline CString UnitType::GetStdSymbol()
{
	return m_strStdSymbol;
}

inline void UnitType::SetStdSymbol(CString strSymbol)
{
	m_strStdSymbol = strSymbol;
}
#endif // !defined(AFX_UNITTYPE_H__694053C9_E982_4F82_8491_D38B37F4CB7E__INCLUDED_)
