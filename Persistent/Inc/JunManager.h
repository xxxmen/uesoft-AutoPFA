// JunManager.h: interface for the JunManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNMANAGER_H__1B77743C_B31A_4DD8_97A1_2032A5DBA0C7__INCLUDED_)
#define AFX_JUNMANAGER_H__1B77743C_B31A_4DD8_97A1_2032A5DBA0C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Junperisist.h"
#include "Iterator.h"
#include "JunPerisistFactory.h"

class AFX_EXT_CLASS JunManager  
{
public:
	JunManager();
	virtual ~JunManager();

public:
	int GetJunNum();
	Junperisist* CreatJunperisist(int nID);
	Iterator<Junperisist>* CreateIt();

private:
	void DelList();
	JunManager(const JunManager &ref);
	JunManager& operator=(const JunManager &ref);
	typedef CList<Junperisist*,Junperisist*> JunList;
	JunList m_junList;
	JunPerisistFactory *m_factory;
};

#endif // !defined(AFX_JUNMANAGER_H__1B77743C_B31A_4DD8_97A1_2032A5DBA0C7__INCLUDED_)
