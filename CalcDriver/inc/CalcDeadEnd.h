// CalcDeadEnd.h: interface for the CalcDeadEnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCDEADEND_H__A0259F40_C157_473A_A90A_103372F80C30__INCLUDED_)
#define AFX_CALCDEADEND_H__A0259F40_C157_473A_A90A_103372F80C30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcDeadEnd : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcDeadEnd();
	virtual ~CalcDeadEnd();

};

#endif // !defined(AFX_CALCDEADEND_H__A0259F40_C157_473A_A90A_103372F80C30__INCLUDED_)
