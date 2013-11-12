// ThickAnchorThroughoutStrategy.h: interface for the ThickAnchorThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THICKANCHORTHROUGHOUTSTRATEGY_H__A0527364_CBC9_478B_9220_925C7AFF4CB5__INCLUDED_)
#define AFX_THICKANCHORTHROUGHOUTSTRATEGY_H__A0527364_CBC9_478B_9220_925C7AFF4CB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThickAnchorThroughoutStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThickAnchorThroughoutStrategy();
private:
	ThickAnchorThroughoutStrategy();
};

#endif // !defined(AFX_THICKANCHORTHROUGHOUTSTRATEGY_H__A0527364_CBC9_478B_9220_925C7AFF4CB5__INCLUDED_)
