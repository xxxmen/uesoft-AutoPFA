// PCFReserviorFace.h: interface for the PCFReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_)
#define AFX_PCFRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFReserviorFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFReserviorFace();
	virtual ~PCFReserviorFace();
	ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_PCFRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_)