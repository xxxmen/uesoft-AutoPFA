// CalcControlFace.h: interface for the CalcControlFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCONTROLFACE_H__6438B68C_682E_46E8_9C7A_B5CCA5633935__INCLUDED_)
#define AFX_CALCCONTROLFACE_H__6438B68C_682E_46E8_9C7A_B5CCA5633935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcControlFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcControlFace();
	virtual ~CalcControlFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCCONTROLFACE_H__6438B68C_682E_46E8_9C7A_B5CCA5633935__INCLUDED_)
