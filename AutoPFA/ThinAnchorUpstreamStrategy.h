// ThinAnchorUpstreamStrategy.h: interface for the ThinAnchorUpstreamStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THINANCHORUPSTREAMSTRATEGY_H__22361FCD_0EAC_4FD4_A663_90FE1A17ADF1__INCLUDED_)
#define AFX_THINANCHORUPSTREAMSTRATEGY_H__22361FCD_0EAC_4FD4_A663_90FE1A17ADF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThinAnchorUpstreamStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThinAnchorUpstreamStrategy();
private:
	ThinAnchorUpstreamStrategy();
};

#endif // !defined(AFX_THINANCHORUPSTREAMSTRATEGY_H__22361FCD_0EAC_4FD4_A663_90FE1A17ADF1__INCLUDED_)
