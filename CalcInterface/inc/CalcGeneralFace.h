// CalcGeneralFace.h: interface for the CalcGeneralFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCGENERALFACE_H__9C122F00_0DD0_46D5_A4BD_43E486916D4D__INCLUDED_)
#define AFX_CALCGENERALFACE_H__9C122F00_0DD0_46D5_A4BD_43E486916D4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcGeneralFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcGeneralFace();
	virtual ~CalcGeneralFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCGENERALFACE_H__9C122F00_0DD0_46D5_A4BD_43E486916D4D__INCLUDED_)
