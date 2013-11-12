// AFTCheckFace.h: interface for the AFTCheckFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTCHECKFACE_H__93D340E6_3F0E_4A9C_93D4_327D24AAC542__INCLUDED_)
#define AFX_AFTCHECKFACE_H__93D340E6_3F0E_4A9C_93D4_327D24AAC542__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTCheckFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTCheckFace();
	virtual ~AFTCheckFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTCHECKFACE_H__93D340E6_3F0E_4A9C_93D4_327D24AAC542__INCLUDED_)
