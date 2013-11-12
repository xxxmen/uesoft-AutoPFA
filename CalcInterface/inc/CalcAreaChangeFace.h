// CalcAreaChangeFace.h: interface for the CalcAreaChangeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCAREACHANGEFACE_H__CE653D74_8C53_4865_8344_58832CCA4155__INCLUDED_)
#define AFX_CALCAREACHANGEFACE_H__CE653D74_8C53_4865_8344_58832CCA4155__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcAreaChangeFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcAreaChangeFace();
	virtual ~CalcAreaChangeFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCAREACHANGEFACE_H__CE653D74_8C53_4865_8344_58832CCA4155__INCLUDED_)
