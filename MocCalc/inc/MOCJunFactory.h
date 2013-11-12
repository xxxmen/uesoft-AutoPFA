// MOCJunFactory.h: interface for the MOCJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCJUNFACTORY_H__BF6DDCEC_B4B8_4F1D_B797_05F924FEEB58__INCLUDED_)
#define AFX_MOCJUNFACTORY_H__BF6DDCEC_B4B8_4F1D_B797_05F924FEEB58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"

class MOCJun;

class MOCJunFactory:public CFactory<MOCJun,int>  
{
public:
	static MOCJunFactory* Instance();
	virtual ~MOCJunFactory();
	
protected:
	MOCJunFactory();
	
private:
	MOCJunFactory(const MOCJunFactory &ref);
	MOCJunFactory& operator=(const MOCJunFactory &ref);

};

#endif // !defined(AFX_MOCJUNFACTORY_H__BF6DDCEC_B4B8_4F1D_B797_05F924FEEB58__INCLUDED_)
