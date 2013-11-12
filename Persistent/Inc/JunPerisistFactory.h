// JunPerisistFactory.h: interface for the JunPerisistFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNPERISISTFACTORY_H__A029D6AA_8532_4D21_AC95_CA70B69872B5__INCLUDED_)
#define AFX_JUNPERISISTFACTORY_H__A029D6AA_8532_4D21_AC95_CA70B69872B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class Junperisist;

class JunPerisistFactory:public CFactory<Junperisist,int>  
{
public:
	static JunPerisistFactory* Instance();
	virtual ~JunPerisistFactory();
	
protected:
	JunPerisistFactory();
	
private:
	JunPerisistFactory(const JunPerisistFactory &ref);
	JunPerisistFactory& operator=(const JunPerisistFactory &ref);

};

#endif // !defined(AFX_JUNPERISISTFACTORY_H__A029D6AA_8532_4D21_AC95_CA70B69872B5__INCLUDED_)
