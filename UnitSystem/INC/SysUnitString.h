// SysUnitString.h: interface for the UnitString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSUNITSTRING_H__1840377A_F31C_49FB_AC61_1E5F449D0B0C__INCLUDED_)
#define AFX_SYSUNITSTRING_H__1840377A_F31C_49FB_AC61_1E5F449D0B0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS UnitString  
{
public:
	UnitString * Clone();
	CString GetSymbol();
	BOOL IsStringEqual(CString strSymbol);
	static UnitString* Creat(CString strSymbol);
	void SetUsed(BOOL bUsed);
	BOOL IsUsed();
	UnitString(CString strSymbol);
	UnitString(const UnitString &ref);
	UnitString& operator=(const UnitString &ref);
	virtual ~UnitString();

private:
	CString m_strSymbol;
	BOOL    m_bUsed;

};

inline CString UnitString::GetSymbol()
{
	return m_strSymbol;
}


typedef CList<UnitString*,UnitString*>UnitStringList;

#endif // !defined(AFX_UNITSTRING_H__1840377A_F31C_49FB_AC61_1E5F449D0B0C__INCLUDED_)
