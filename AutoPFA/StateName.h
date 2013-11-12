// StateName.h: interface for the StateName class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATENAME_H__48DFA378_C491_49DB_A685_95B7ECD7D917__INCLUDED_)
#define AFX_STATENAME_H__48DFA378_C491_49DB_A685_95B7ECD7D917__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StateName  
{
public:
	BOOL IsShow();
	int TypeKey();
	CString Name();
	void Name(CString strName);
	CString NameUnit();
	int Key();
	StateName();
	StateName(CString strName,int nKey,int nType,BOOL bShow);
	StateName(int nKey,int nType);
	virtual ~StateName();
	
private:
	int m_nKey;
	CString m_strName;
	int m_nFlyWeightType;
	BOOL m_bShow;
};

typedef CArray<StateName,StateName> NameArray;
inline int StateName::Key()
{
	return m_nKey;
}
inline CString StateName::Name()
{
	return m_strName;
}

inline void StateName::Name(CString strName)
{
	m_strName = strName;
}
inline int StateName::TypeKey()
{
	return m_nFlyWeightType;
}
inline BOOL StateName::IsShow()
{
	return m_bShow;
}

#endif // !defined(AFX_STATENAME_H__48DFA378_C491_49DB_A685_95B7ECD7D917__INCLUDED_)
