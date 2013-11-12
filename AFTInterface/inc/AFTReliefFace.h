// AFTReliefFace.h: interface for the AFTReliefFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTRELIEFFACE_H__8CACD3CB_E565_4630_B6E1_B3E60150B784__INCLUDED_)
#define AFX_AFTRELIEFFACE_H__8CACD3CB_E565_4630_B6E1_B3E60150B784__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTReliefFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTReliefFace();
	virtual ~AFTReliefFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTRELIEFFACE_H__8CACD3CB_E565_4630_B6E1_B3E60150B784__INCLUDED_)
