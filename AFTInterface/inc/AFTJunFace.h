// AFTJunFace.h: interface for the AFTJunFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTJUNFACE_H__F2172629_E7D8_4DF8_8CDD_44A49B0D5A34__INCLUDED_)
#define AFX_AFTJUNFACE_H__F2172629_E7D8_4DF8_8CDD_44A49B0D5A34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Junperisist.h"
#include "Junction.h"

class AFX_EXT_CLASS AFTJunFace  
{
public:
	AFTJunFace();
	virtual ~AFTJunFace();
    virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);
};

#endif // !defined(AFX_AFTJUNFACE_H__F2172629_E7D8_4DF8_8CDD_44A49B0D5A34__INCLUDED_)
