// CalcBreakerFace.h: interface for the CalcBreakerFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBREAKERFACE_H__44065668_ED36_47FE_AEF7_0515BA0E7FAB__INCLUDED_)
#define AFX_CALCBREAKERFACE_H__44065668_ED36_47FE_AEF7_0515BA0E7FAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcBreakerFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcBreakerFace();
	virtual ~CalcBreakerFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCBREAKERFACE_H__44065668_ED36_47FE_AEF7_0515BA0E7FAB__INCLUDED_)
