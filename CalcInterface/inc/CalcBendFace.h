// CalcBendFace.h: interface for the CalcBendFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBENDFACE_H__80BAD327_12CD_4B7D_966A_401DBCA2C97D__INCLUDED_)
#define AFX_CALCBENDFACE_H__80BAD327_12CD_4B7D_966A_401DBCA2C97D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcBendFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcBendFace();
	virtual ~CalcBendFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCBENDFACE_H__80BAD327_12CD_4B7D_966A_401DBCA2C97D__INCLUDED_)
