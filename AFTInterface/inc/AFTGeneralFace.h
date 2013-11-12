// AFTGeneralFace.h: interface for the AFTGeneralFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTGENERALFACE_H__04AB92D7_3945_4531_A3DF_BAE450C94BE1__INCLUDED_)
#define AFX_AFTGENERALFACE_H__04AB92D7_3945_4531_A3DF_BAE450C94BE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTGeneralFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTGeneralFace();
	virtual ~AFTGeneralFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTGENERALFACE_H__04AB92D7_3945_4531_A3DF_BAE450C94BE1__INCLUDED_)
