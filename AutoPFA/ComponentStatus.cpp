// ComponentStatus.cpp: implementation of the ComponentStatus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ComponentStatus.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentStatus::ComponentStatus(NameArray &array)
:m_array(array)
{
	
}

ComponentStatus::~ComponentStatus()
{

}

CString ComponentStatus::Find(int nKey)
{
	int n = m_array.GetSize();
	for(int i=0;i<n;i++)
	{
		if(nKey == m_array[i].Key())
			return m_array[i].Name();
	}
	return _T("");
}

void ComponentStatus::Add(int nKey)
{
	CString strName = Find(nKey);
	if(!strName.IsEmpty())
		m_list.AddItem(strName);
}

void ComponentStatus::Add(CString strName)
{
	m_list.AddItem(strName);
}

Iterator<CString>* ComponentStatus::CreatIterator()
{
	return m_list.CreatIterator();
}

BOOL ComponentStatus::IsDefine()
{
	if(m_list.IsEmpty())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
