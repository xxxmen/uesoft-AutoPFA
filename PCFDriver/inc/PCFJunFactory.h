// PCFJunFactory.h: interface for the PCFJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUNFACTORY_H__AAE080A1_AC3D_4554_A833_1D1AFE25A428__INCLUDED_)
#define AFX_PCFJUNFACTORY_H__AAE080A1_AC3D_4554_A833_1D1AFE25A428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"

class PCFJun;
class PCFJunFactory:public CFactory<PCFJun,CString>  
{
public:
	static PCFJunFactory* Instance();
	virtual ~PCFJunFactory();

private:
	PCFJunFactory();
	PCFJunFactory(const PCFJunFactory &ref);
	PCFJunFactory& operator=(const PCFJunFactory &ref);

};

#endif // !defined(AFX_PCFJUNFACTORY_H__AAE080A1_AC3D_4554_A833_1D1AFE25A428__INCLUDED_)
