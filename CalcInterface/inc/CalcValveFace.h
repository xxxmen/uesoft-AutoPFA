// CalcValveFace.h: interface for the CalcValveFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCVALVEFACE_H__474E581F_C553_4624_8F18_9D15BE861777__INCLUDED_)
#define AFX_CALCVALVEFACE_H__474E581F_C553_4624_8F18_9D15BE861777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcValveFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcValveFace();
	virtual ~CalcValveFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);
};

#endif // !defined(AFX_CALCVALVEFACE_H__474E581F_C553_4624_8F18_9D15BE861777__INCLUDED_)
