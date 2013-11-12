// AFTDeadEndFace.h: interface for the AFTDeadEndFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTDEADENDFACE_H__63CFCACC_45CB_4BE0_AD5E_CCDC2BF6CA21__INCLUDED_)
#define AFX_AFTDEADENDFACE_H__63CFCACC_45CB_4BE0_AD5E_CCDC2BF6CA21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTDeadEndFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTDeadEndFace();
	virtual ~AFTDeadEndFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTDEADENDFACE_H__63CFCACC_45CB_4BE0_AD5E_CCDC2BF6CA21__INCLUDED_)
