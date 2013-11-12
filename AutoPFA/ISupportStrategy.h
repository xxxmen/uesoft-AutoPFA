// ISupportStrategy.h: interface for the ISupportStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISUPPORTSTRATEGY_H__BA4552F8_480E_4B15_A75E_445970590AD7__INCLUDED_)
#define AFX_ISUPPORTSTRATEGY_H__BA4552F8_480E_4B15_A75E_445970590AD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "WavespeedCalc.h"
class ISupportStrategy  
{
public:
	ISupportStrategy();
	virtual ~ISupportStrategy();
	virtual double GetC1(const WavespeedCalc &ref) = 0;
};

#endif // !defined(AFX_ISUPPORTSTRATEGY_H__BA4552F8_480E_4B15_A75E_445970590AD7__INCLUDED_)
