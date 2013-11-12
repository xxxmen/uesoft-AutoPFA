// CalcDeadEndFace.h: interface for the CalcDeadEndFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCDEADENDFACE_H__BA5A6838_3961_4EA6_9DEE_98AAD72A9187__INCLUDED_)
#define AFX_CALCDEADENDFACE_H__BA5A6838_3961_4EA6_9DEE_98AAD72A9187__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcDeadEndFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcDeadEndFace();
	virtual ~CalcDeadEndFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCDEADENDFACE_H__BA5A6838_3961_4EA6_9DEE_98AAD72A9187__INCLUDED_)
