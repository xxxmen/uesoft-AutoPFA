// AFTSprayFace.h: interface for the AFTSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_)
#define AFX_AFTSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTSprayFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTSprayFace();
	virtual ~AFTSprayFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTSPRAYFACE_H__038F9ABE_732E_4420_B9D9_371A454079DD__INCLUDED_)
