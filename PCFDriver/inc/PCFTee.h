// PCFTee.h: interface for the PCFTee class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFTEE_H__E3BEEF7E_62CB_48A6_96E1_3B3CCFF5D731__INCLUDED_)
#define AFX_PCFTEE_H__E3BEEF7E_62CB_48A6_96E1_3B3CCFF5D731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//ÈýÍ¨
class PCFTee : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFTee();
	virtual ~PCFTee();
private:
	double m_dAngel;
	double m_dInDia1;
	double m_dInDia2;
	double m_dInDia3;
	
};

#endif // !defined(AFX_PCFTEE_H__E3BEEF7E_62CB_48A6_96E1_3B3CCFF5D731__INCLUDED_)
