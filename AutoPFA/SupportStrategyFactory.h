// SupportStrategyFactory.h: interface for the SupportStrategyFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUPPORTSTRATEGYFACTORY_H__CCE22436_EE9B_432D_A4F9_B367ABDCC058__INCLUDED_)
#define AFX_SUPPORTSTRATEGYFACTORY_H__CCE22436_EE9B_432D_A4F9_B367ABDCC058__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class ISupportStrategy;

class SupportStrategyFactory:public CFactory<ISupportStrategy,int>   
{
public:
	static SupportStrategyFactory* Instance();
	virtual ~SupportStrategyFactory();
	
protected:
	SupportStrategyFactory();
	
private:
	SupportStrategyFactory(const SupportStrategyFactory &ref);
	SupportStrategyFactory& operator=(const SupportStrategyFactory &ref);
};

#endif // !defined(AFX_SUPPORTSTRATEGYFACTORY_H__CCE22436_EE9B_432D_A4F9_B367ABDCC058__INCLUDED_)
