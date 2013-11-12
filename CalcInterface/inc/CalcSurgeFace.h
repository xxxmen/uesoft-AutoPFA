// CalcSurgeFace.h: interface for the CalcSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSURGEFACE_H__C28AF47B_139B_4104_9EE0_3E1316067002__INCLUDED_)
#define AFX_CALCSURGEFACE_H__C28AF47B_139B_4104_9EE0_3E1316067002__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcSurgeFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcSurgeFace();
	virtual ~CalcSurgeFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCSURGEFACE_H__C28AF47B_139B_4104_9EE0_3E1316067002__INCLUDED_)
