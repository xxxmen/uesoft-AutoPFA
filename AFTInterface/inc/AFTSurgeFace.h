// AFTSurgeFace.h: interface for the AFTSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_)
#define AFX_AFTSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTSurgeFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTSurgeFace();
	virtual ~AFTSurgeFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_)
