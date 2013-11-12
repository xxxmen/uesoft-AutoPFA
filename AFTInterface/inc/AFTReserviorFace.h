// AFTReserviorFace.h: interface for the AFTReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_)
#define AFX_AFTRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTReserviorFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTReserviorFace();
	virtual ~AFTReserviorFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTRESERVIORFACE_H__929FACF6_960A_4013_8D21_0F5EDC016046__INCLUDED_)
