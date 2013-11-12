// CalcTeeWyeFace.h: interface for the CalcTeeWyeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTEEWYEFACE_H__4788EE2B_3123_4C98_B0C3_D38AAFE5D9B3__INCLUDED_)
#define AFX_CALCTEEWYEFACE_H__4788EE2B_3123_4C98_B0C3_D38AAFE5D9B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcTeeWyeFace : public CalcJunFace    
{
public:
	static CalcJunFace* Creator();
	CalcTeeWyeFace();
	virtual ~CalcTeeWyeFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCTEEWYEFACE_H__4788EE2B_3123_4C98_B0C3_D38AAFE5D9B3__INCLUDED_)
