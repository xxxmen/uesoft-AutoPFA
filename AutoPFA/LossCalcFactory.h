// LossCalcFactory.h: interface for the LossCalcFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOSSCALCFACTORY_H__4E0D7EED_7E2B_45EF_BDBC_C173D699E472__INCLUDED_)
#define AFX_LOSSCALCFACTORY_H__4E0D7EED_7E2B_45EF_BDBC_C173D699E472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class ILossCalcStrategy;

class LossCalcFactory :public CFactory<ILossCalcStrategy,int> 
{
public:
	static LossCalcFactory* Instance();
	virtual ~LossCalcFactory();
	
protected:
	LossCalcFactory();
	
private:
	LossCalcFactory(const LossCalcFactory &ref);
	LossCalcFactory& operator=(const LossCalcFactory &ref);

};

#endif // !defined(AFX_LOSSCALCFACTORY_H__4E0D7EED_7E2B_45EF_BDBC_C173D699E472__INCLUDED_)
