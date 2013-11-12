// PCFCap.h: interface for the PCFCap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFCAP_H__7157AB8F_63DB_419A_8235_5922752918BB__INCLUDED_)
#define AFX_PCFCAP_H__7157AB8F_63DB_419A_8235_5922752918BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//π‹√±
class PCFCap : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFCap();
	virtual ~PCFCap();

};

#endif // !defined(AFX_PCFCAP_H__7157AB8F_63DB_419A_8235_5922752918BB__INCLUDED_)
