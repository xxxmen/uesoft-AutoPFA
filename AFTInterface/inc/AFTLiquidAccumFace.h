// AFTLiquidAccumFace.h: interface for the AFTLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_)
#define AFX_AFTLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTLiquidAccumFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTLiquidAccumFace();
	virtual ~AFTLiquidAccumFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_)
