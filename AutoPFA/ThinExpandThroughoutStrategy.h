// ThinExpandThroughoutStrategy.h: interface for the ThinExpandThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THINEXPANDTHROUGHOUTSTRATEGY_H__5A0C13BA_649B_4DAA_9D1D_56E40962AE9C__INCLUDED_)
#define AFX_THINEXPANDTHROUGHOUTSTRATEGY_H__5A0C13BA_649B_4DAA_9D1D_56E40962AE9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class ThinExpandThroughoutStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~ThinExpandThroughoutStrategy();
private:
	ThinExpandThroughoutStrategy();

};

#endif // !defined(AFX_THINEXPANDTHROUGHOUTSTRATEGY_H__5A0C13BA_649B_4DAA_9D1D_56E40962AE9C__INCLUDED_)
