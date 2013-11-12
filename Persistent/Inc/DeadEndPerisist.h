// DeadEndPerisist.h: interface for the DeadEndPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEADENDPERISIST_H__F9B14272_0B96_4A38_AC54_C6493CF45A54__INCLUDED_)
#define AFX_DEADENDPERISIST_H__F9B14272_0B96_4A38_AC54_C6493CF45A54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class DeadEndPerisist : public Junperisist  
{
public:
	static Junperisist* CreatDeadEnd();
	DeadEndPerisist();
	virtual ~DeadEndPerisist();

};

#endif // !defined(AFX_DEADENDPERISIST_H__F9B14272_0B96_4A38_AC54_C6493CF45A54__INCLUDED_)
