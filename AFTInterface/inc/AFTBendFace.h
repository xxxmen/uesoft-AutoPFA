// AFTBendFace.h: interface for the AFTBendFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTBENDFACE_H__DD5703A5_AD70_4B9E_BB99_5A7D64E414ED__INCLUDED_)
#define AFX_AFTBENDFACE_H__DD5703A5_AD70_4B9E_BB99_5A7D64E414ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTBendFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTBendFace();
	virtual ~AFTBendFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTBENDFACE_H__DD5703A5_AD70_4B9E_BB99_5A7D64E414ED__INCLUDED_)
