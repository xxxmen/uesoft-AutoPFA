// CalcSprayFace.h: interface for the CalcSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSPRAYFACE_H__F5DB7960_786D_4DAB_BFDD_F127A7C524B5__INCLUDED_)
#define AFX_CALCSPRAYFACE_H__F5DB7960_786D_4DAB_BFDD_F127A7C524B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcSprayFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcSprayFace();
	virtual ~CalcSprayFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCSPRAYFACE_H__F5DB7960_786D_4DAB_BFDD_F127A7C524B5__INCLUDED_)
