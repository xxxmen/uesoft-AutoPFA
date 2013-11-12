// PCFSupport.h: interface for the PCFSupport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSUPPORT_H__24823AB3_E4BB_4E52_AB40_63A792B3B90E__INCLUDED_)
#define AFX_PCFSUPPORT_H__24823AB3_E4BB_4E52_AB40_63A792B3B90E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//Ö§¼Ü
class PCFSupport : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFSupport();
	virtual ~PCFSupport();

private:
	
};

#endif // !defined(AFX_PCFSUPPORT_H__24823AB3_E4BB_4E52_AB40_63A792B3B90E__INCLUDED_)
