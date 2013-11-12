// PCFFBlind.h: interface for the PCFFBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFFBLIND_H__1B7864CB_978D_44CF_A940_6E1D72C36712__INCLUDED_)
#define AFX_PCFFBLIND_H__1B7864CB_978D_44CF_A940_6E1D72C36712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//Ã¤¹Ü
class PCFFBlind : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFFBlind();
	virtual ~PCFFBlind();

private:
};

#endif // !defined(AFX_PCFFBLIND_H__1B7864CB_978D_44CF_A940_6E1D72C36712__INCLUDED_)
