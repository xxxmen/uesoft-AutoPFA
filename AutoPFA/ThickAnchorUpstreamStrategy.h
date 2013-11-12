// ThickAnchorUpstreamStrategy.h: interface for the ThickAnchorUpstreamStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THICKANCHORUPSTREAMSTRATEGY_H__F9FC39C6_2E5D_4243_B931_77D99852E483__INCLUDED_)
#define AFX_THICKANCHORUPSTREAMSTRATEGY_H__F9FC39C6_2E5D_4243_B931_77D99852E483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThickAnchorUpstreamStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThickAnchorUpstreamStrategy();
private:
	ThickAnchorUpstreamStrategy();
};

#endif // !defined(AFX_THICKANCHORUPSTREAMSTRATEGY_H__F9FC39C6_2E5D_4243_B931_77D99852E483__INCLUDED_)
