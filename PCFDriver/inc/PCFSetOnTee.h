// PCFSetOnTee.h: interface for the PCFSetOnTee class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSETONTEE_H__1F4D9F72_F014_4D92_AE0F_FFEBB40BBBA6__INCLUDED_)
#define AFX_PCFSETONTEE_H__1F4D9F72_F014_4D92_AE0F_FFEBB40BBBA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//¼ÙÈýÍ¨
class PCFSetOnTee : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFSetOnTee();
	virtual ~PCFSetOnTee();
private:
	
};

#endif // !defined(AFX_PCFSETONTEE_H__1F4D9F72_F014_4D92_AE0F_FFEBB40BBBA6__INCLUDED_)
