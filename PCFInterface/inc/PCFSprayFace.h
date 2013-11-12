// PCFSprayFace.h: interface for the PCFSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_)
#define AFX_PCFSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFSprayFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFSprayFace();
	virtual ~PCFSprayFace();
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_PCFSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_)
