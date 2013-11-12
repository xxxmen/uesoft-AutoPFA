// PCFTrap.h: interface for the PCFTrap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFTRAP_H__312556A1_6AA8_4452_B998_88854C9DF3EB__INCLUDED_)
#define AFX_PCFTRAP_H__312556A1_6AA8_4452_B998_88854C9DF3EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//È¦Ì×
class PCFTrap : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFTrap();
	virtual ~PCFTrap();

private:
	
};

#endif // !defined(AFX_PCFTRAP_H__312556A1_6AA8_4452_B998_88854C9DF3EB__INCLUDED_)
