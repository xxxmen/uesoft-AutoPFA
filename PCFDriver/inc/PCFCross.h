// PCFCross.h: interface for the PCFCross class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFCROSS_H__F0568662_73DA_46A7_B8E2_0D6D07CA595E__INCLUDED_)
#define AFX_PCFCROSS_H__F0568662_73DA_46A7_B8E2_0D6D07CA595E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//ËÄÍ¨
class PCFCross : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFCross();
	virtual ~PCFCross();

private:
	
};

#endif // !defined(AFX_PCFCROSS_H__F0568662_73DA_46A7_B8E2_0D6D07CA595E__INCLUDED_)
