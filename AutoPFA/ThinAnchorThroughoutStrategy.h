// ThinAnchorThroughoutStrategy.h: interface for the ThinAnchorThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THINANCHORTHROUGHOUTSTRATEGY_H__D45A1863_85DE_4CB8_B332_A5D6E702F109__INCLUDED_)
#define AFX_THINANCHORTHROUGHOUTSTRATEGY_H__D45A1863_85DE_4CB8_B332_A5D6E702F109__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThinAnchorThroughoutStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThinAnchorThroughoutStrategy();
private:
	ThinAnchorThroughoutStrategy();
};

#endif // !defined(AFX_THINANCHORTHROUGHOUTSTRATEGY_H__D45A1863_85DE_4CB8_B332_A5D6E702F109__INCLUDED_)
