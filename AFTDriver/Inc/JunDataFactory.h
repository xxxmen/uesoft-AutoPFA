// JunDataFactory.h: interface for the JunDataFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNDATAFACTORY_H__775AA78A_CB02_4D32_8569_8C819A26ACC6__INCLUDED_)
#define AFX_JUNDATAFACTORY_H__775AA78A_CB02_4D32_8569_8C819A26ACC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class JunctionData;
class JunDataFactory:public CFactory<JunctionData,int>  
{
	
public:
	static JunDataFactory* Instance();
	virtual ~JunDataFactory();
	
protected:
	JunDataFactory();
	
private:
	JunDataFactory(const JunDataFactory &ref);
	JunDataFactory& operator=(const JunDataFactory &ref);


};

#endif // !defined(AFX_JUNDATAFACTORY_H__775AA78A_CB02_4D32_8569_8C819A26ACC6__INCLUDED_)
