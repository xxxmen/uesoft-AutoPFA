// onfigPerisist.cpp: implementation of the ConfigPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "onfigPerisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConfigPerisist::ConfigPerisist()
{

}

ConfigPerisist::~ConfigPerisist()
{

}

int ConfigPerisist::GetCount()
{
	return m_list.GetCount();
}

Iterator<ConfigItemPerisist>* ConfigPerisist::CreatIterator()const
{
	return m_list.CreatIterator();
}

ConfigItemPerisist* ConfigPerisist::CreatConfigItem()
{
	ConfigItemPerisist *pItem = new ConfigItemPerisist;
    m_list.AddItem(pItem);
	return pItem;
}

ConfigItemPerisist* ConfigPerisist::GetHead()
{
	if(m_list.GetCount() == 0)
	{
		return NULL;
	}
	else
	{
		return m_list.GetHead();
	}
}
