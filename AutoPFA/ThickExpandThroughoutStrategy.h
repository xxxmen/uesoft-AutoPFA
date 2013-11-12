// ThickExpandThroughoutStrategy.h: interface for the ThickExpandThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THICKEXPANDTHROUGHOUTSTRATEGY_H__A3CF51B5_2967_4C4F_9487_E99CF147A343__INCLUDED_)
#define AFX_THICKEXPANDTHROUGHOUTSTRATEGY_H__A3CF51B5_2967_4C4F_9487_E99CF147A343__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThickExpandThroughoutStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThickExpandThroughoutStrategy();
private:
	ThickExpandThroughoutStrategy();
};

#endif // !defined(AFX_THICKEXPANDTHROUGHOUTSTRATEGY_H__A3CF51B5_2967_4C4F_9487_E99CF147A343__INCLUDED_)
