// PCFWeld.h: interface for the PCFWeld class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFWELD_H__4190A957_937D_463F_8F91_D7F4E3981A99__INCLUDED_)
#define AFX_PCFWELD_H__4190A957_937D_463F_8F91_D7F4E3981A99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//º¸½Ó
class PCFWeld : public PCFJun 
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFWeld();
	virtual ~PCFWeld();

private:
	
};

#endif // !defined(AFX_PCFWELD_H__4190A957_937D_463F_8F91_D7F4E3981A99__INCLUDED_)
