// ComponentStatus.h: interface for the ComponentStatus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTSTATUS_H__21338414_FC67_4112_87FA_A71D116D7986__INCLUDED_)
#define AFX_COMPONENTSTATUS_H__21338414_FC67_4112_87FA_A71D116D7986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StateName.h"
#include "ListFlyWeightImp.h"


class ComponentStatus  
{
public:
	BOOL IsDefine();
	void Add(int nKey);
	void Add(CString strName);
	Iterator<CString>* CreatIterator();
	ComponentStatus(NameArray &array);
	virtual ~ComponentStatus();

private:
	CString Find(int nKey);
	NameArray &m_array;
	ListImp<CString> m_list;

};

#endif // !defined(AFX_COMPONENTSTATUS_H__21338414_FC67_4112_87FA_A71D116D7986__INCLUDED_)
