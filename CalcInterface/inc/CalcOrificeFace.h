// CalcOrificeFace.h: interface for the CalcOrificeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCORIFICEFACE_H__B14DB20E_F95E_40E3_B9D8_DDA759CA2C22__INCLUDED_)
#define AFX_CALCORIFICEFACE_H__B14DB20E_F95E_40E3_B9D8_DDA759CA2C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcOrifice.h"

class AFX_EXT_CLASS CalcOrificeFace  
{
public:
	CalcOrificeFace();
	virtual ~CalcOrificeFace();
	ErrorStatus::FileError Save(CalcOrifice &Data,StrArray<5> &Model);
};

#endif // !defined(AFX_CALCORIFICEFACE_H__B14DB20E_F95E_40E3_B9D8_DDA759CA2C22__INCLUDED_)
