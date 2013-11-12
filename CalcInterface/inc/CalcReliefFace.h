// CalcReliefFace.h: interface for the CalcReliefFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCRELIEFFACE_H__FED07435_FEF8_4293_BF5B_F6F045D0AE07__INCLUDED_)
#define AFX_CALCRELIEFFACE_H__FED07435_FEF8_4293_BF5B_F6F045D0AE07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcReliefFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcReliefFace();
	virtual ~CalcReliefFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCRELIEFFACE_H__FED07435_FEF8_4293_BF5B_F6F045D0AE07__INCLUDED_)
