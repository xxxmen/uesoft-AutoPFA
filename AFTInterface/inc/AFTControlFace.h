// AFTControlFace.h: interface for the AFTControlFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTCONTROLFACE_H__F6D39113_DD12_4688_B19A_5D02BE668820__INCLUDED_)
#define AFX_AFTCONTROLFACE_H__F6D39113_DD12_4688_B19A_5D02BE668820__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTControlFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTControlFace();
	virtual ~AFTControlFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTCONTROLFACE_H__F6D39113_DD12_4688_B19A_5D02BE668820__INCLUDED_)
