// PCFFlange.h: interface for the PCFFlange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFFLANGE_H__2D02B8FB_563F_44E6_A9C7_C055C114E2EB__INCLUDED_)
#define AFX_PCFFLANGE_H__2D02B8FB_563F_44E6_A9C7_C055C114E2EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"

class PCFFlange : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFFlange();
	virtual ~PCFFlange();

private:

};

#endif // !defined(AFX_PCFFLANGE_H__2D02B8FB_563F_44E6_A9C7_C055C114E2EB__INCLUDED_)
