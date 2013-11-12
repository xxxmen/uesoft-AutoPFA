// PCFLJSE.h: interface for the PCFLJSE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFLJSE_H__67E369A9_31A7_4145_A03E_4787700268CA__INCLUDED_)
#define AFX_PCFLJSE_H__67E369A9_31A7_4145_A03E_4787700268CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"

class PCFLJSE : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFLJSE();
	virtual ~PCFLJSE();

private:
	
};

#endif // !defined(AFX_PCFLJSE_H__67E369A9_31A7_4145_A03E_4787700268CA__INCLUDED_)
