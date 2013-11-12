// AFTTeeWyeFace.h: interface for the AFTTeeWyeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTTEEWYEFACE_H__2BAD0935_C4DE_4144_809D_C72285A2F416__INCLUDED_)
#define AFX_AFTTEEWYEFACE_H__2BAD0935_C4DE_4144_809D_C72285A2F416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTTeeWyeFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTTeeWyeFace();
	virtual ~AFTTeeWyeFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTTEEWYEFACE_H__2BAD0935_C4DE_4144_809D_C72285A2F416__INCLUDED_)
