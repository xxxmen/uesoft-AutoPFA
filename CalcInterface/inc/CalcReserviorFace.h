// CalcReserviorFace.h: interface for the CalcReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCRESERVIORFACE_H__A6D8F38A_651E_4AD6_903A_EFC1BD8731EE__INCLUDED_)
#define AFX_CALCRESERVIORFACE_H__A6D8F38A_651E_4AD6_903A_EFC1BD8731EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcReserviorFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcReserviorFace();
	virtual ~CalcReserviorFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCRESERVIORFACE_H__A6D8F38A_651E_4AD6_903A_EFC1BD8731EE__INCLUDED_)
