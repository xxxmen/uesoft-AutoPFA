// PCFTeeFace.h: interface for the PCFTeeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFTEEFACE_H__8EEA405D_A55E_4BB0_861E_4EAC55F3750B__INCLUDED_)
#define AFX_PCFTEEFACE_H__8EEA405D_A55E_4BB0_861E_4EAC55F3750B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class PCFTeeFace : public PCFJunFace  
{
public:
	ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	static PCFJunFace* Creator();
	PCFTeeFace();
	virtual ~PCFTeeFace();

};

#endif // !defined(AFX_PCFTEEFACE_H__8EEA405D_A55E_4BB0_861E_4EAC55F3750B__INCLUDED_)
