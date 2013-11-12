// PCFElbow.h: interface for the PCFElbow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFELBOW_H__1E1031F7_8394_486A_8C6A_7FDCE0214787__INCLUDED_)
#define AFX_PCFELBOW_H__1E1031F7_8394_486A_8C6A_7FDCE0214787__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//Õ‰Õ∑
class AFX_EXT_CLASS PCFElbow : public PCFJun  
{
public:
	double GetAngle();
	void Init(const CStringArray& wordArray );
	static PCFJun* Creator();
	PCFElbow();
	virtual ~PCFElbow();
private:
	void SetAngle(double dAngle);

private:
	double m_dAngle;
};

#endif // !defined(AFX_PCFELBOW_H__1E1031F7_8394_486A_8C6A_7FDCE0214787__INCLUDED_)
