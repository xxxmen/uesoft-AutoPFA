// CalcCheckFace.h: interface for the CalcCheckFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCHECKFACE_H__EFCB4542_8799_4692_B153_0E9CD75F217A__INCLUDED_)
#define AFX_CALCCHECKFACE_H__EFCB4542_8799_4692_B153_0E9CD75F217A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcCheckFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcCheckFace();
	virtual ~CalcCheckFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCCHECKFACE_H__EFCB4542_8799_4692_B153_0E9CD75F217A__INCLUDED_)
