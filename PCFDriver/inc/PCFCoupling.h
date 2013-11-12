// PCFCoupling.h: interface for the PCFCoupling class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFCOUPLING_H__D6E9152E_6E02_481C_B451_97E09F34013F__INCLUDED_)
#define AFX_PCFCOUPLING_H__D6E9152E_6E02_481C_B451_97E09F34013F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"

class PCFCoupling  : public PCFJun 
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFCoupling();
	virtual ~PCFCoupling();

private:
};

#endif // !defined(AFX_PCFCOUPLING_H__D6E9152E_6E02_481C_B451_97E09F34013F__INCLUDED_)
