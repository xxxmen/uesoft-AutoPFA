// PCFBend.h: interface for the PCFBend class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFBEND_H__B70FB407_5AE2_43BB_A47B_58FD3436EFCD__INCLUDED_)
#define AFX_PCFBEND_H__B70FB407_5AE2_43BB_A47B_58FD3436EFCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"

class AFX_EXT_CLASS PCFBend : public PCFJun  
{
public:
	void SetAngle(double dAngle);
	double GetAngle();
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFBend();
	virtual ~PCFBend();	
private:
	double m_dAngle;	
};

inline void PCFBend::SetAngle( double dAngle )
{
	m_dAngle = dAngle;
}

inline double PCFBend::GetAngle()
{
	return m_dAngle/100;
}

#endif // !defined(AFX_PCFBEND_H__B70FB407_5AE2_43BB_A47B_58FD3436EFCD__INCLUDED_)
