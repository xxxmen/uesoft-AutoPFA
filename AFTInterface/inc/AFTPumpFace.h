// AFTPumpFace.h: interface for the AFTPumpFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTPUMPFACE_H__4DED9BAB_BEA9_4235_8BDC_8B4016833CCE__INCLUDED_)
#define AFX_AFTPUMPFACE_H__4DED9BAB_BEA9_4235_8BDC_8B4016833CCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTPumpFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTPumpFace();
	virtual ~AFTPumpFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTPUMPFACE_H__4DED9BAB_BEA9_4235_8BDC_8B4016833CCE__INCLUDED_)
