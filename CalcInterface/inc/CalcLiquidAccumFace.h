// CalcLiquidAccumFace.h: interface for the CalcLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCLIQUIDACCUMFACE_H__B65F7A28_8AF9_49C9_AC5F_A2DBEEC0C38E__INCLUDED_)
#define AFX_CALCLIQUIDACCUMFACE_H__B65F7A28_8AF9_49C9_AC5F_A2DBEEC0C38E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcLiquidAccumFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcLiquidAccumFace();
	virtual ~CalcLiquidAccumFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCLIQUIDACCUMFACE_H__B65F7A28_8AF9_49C9_AC5F_A2DBEEC0C38E__INCLUDED_)
