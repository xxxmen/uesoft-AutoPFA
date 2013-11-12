// PCFInstrument.h: interface for the PCFInstrument class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFINSTRUMENT_H__13F2CC27_FA6B_4667_AD35_492A4C5BF5B5__INCLUDED_)
#define AFX_PCFINSTRUMENT_H__13F2CC27_FA6B_4667_AD35_492A4C5BF5B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//рг╠М
class PCFInstrument : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFInstrument();
	virtual ~PCFInstrument();

private:
	
};

#endif // !defined(AFX_PCFINSTRUMENT_H__13F2CC27_FA6B_4667_AD35_492A4C5BF5B5__INCLUDED_)
