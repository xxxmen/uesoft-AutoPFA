// CalcGasAccumFace.h: interface for the CalcGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCGASACCUMFACE_H__E695B135_F704_43D5_AFE0_5AE72E034F87__INCLUDED_)
#define AFX_CALCGASACCUMFACE_H__E695B135_F704_43D5_AFE0_5AE72E034F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcGasAccumFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcGasAccumFace();
	virtual ~CalcGasAccumFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCGASACCUMFACE_H__E695B135_F704_43D5_AFE0_5AE72E034F87__INCLUDED_)
