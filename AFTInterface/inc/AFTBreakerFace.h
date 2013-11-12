// AFTBreakerFace.h: interface for the AFTBreakerFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTBREAKERFACE_H__E07FF3E5_C16E_4C7D_A20D_3D9992802C70__INCLUDED_)
#define AFX_AFTBREAKERFACE_H__E07FF3E5_C16E_4C7D_A20D_3D9992802C70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTBreakerFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTBreakerFace();
	virtual ~AFTBreakerFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTBREAKERFACE_H__E07FF3E5_C16E_4C7D_A20D_3D9992802C70__INCLUDED_)
