// CalcJunFactory.h: interface for the CalcJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUNFACTORY_H__33E6121C_BF36_425D_BA44_1094F3871BCD__INCLUDED_)
#define AFX_CALCJUNFACTORY_H__33E6121C_BF36_425D_BA44_1094F3871BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class CalcJun;
class CalcJunFactory:public CFactory<CalcJun,int>  
{
public:
	static CalcJunFactory* Instance();
	virtual ~CalcJunFactory();
	
protected:
	CalcJunFactory();
	
private:
	CalcJunFactory(const CalcJunFactory &ref);
	CalcJunFactory& operator=(const CalcJunFactory &ref);

};

#endif // !defined(AFX_CALCJUNFACTORY_H__33E6121C_BF36_425D_BA44_1094F3871BCD__INCLUDED_)
