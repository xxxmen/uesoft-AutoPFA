// PCFFilter.h: interface for the PCFFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFFILTER_H__FBDB86D4_36EA_4047_B1A8_8BACC4B3AA18__INCLUDED_)
#define AFX_PCFFILTER_H__FBDB86D4_36EA_4047_B1A8_8BACC4B3AA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//¹ýÂËÆ÷
class PCFFilter : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFFilter();
	virtual ~PCFFilter();

private:
};

#endif // !defined(AFX_PCFFILTER_H__FBDB86D4_36EA_4047_B1A8_8BACC4B3AA18__INCLUDED_)
