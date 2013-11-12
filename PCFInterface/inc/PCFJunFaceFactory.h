// PCFJunFaceFactory.h: interface for the PCFJunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUNFACEFACTORY_H__ED97BD1E_C841_4627_BF18_21CE123CB5A3__INCLUDED_)
#define AFX_PCFJUNFACEFACTORY_H__ED97BD1E_C841_4627_BF18_21CE123CB5A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class PCFJunFace;

class PCFJunFaceFactory:public CFactory<PCFJunFace,int>  
{
public:
	static PCFJunFaceFactory* Instance();
	virtual ~PCFJunFaceFactory();
	
protected:
	PCFJunFaceFactory();
	
private:
	PCFJunFaceFactory(const PCFJunFaceFactory &ref);
	PCFJunFaceFactory& operator=(const PCFJunFaceFactory &ref);
};

#endif // !defined(AFX_PCFJUNFACEFACTORY_H__ED97BD1E_C841_4627_BF18_21CE123CB5A3__INCLUDED_)
