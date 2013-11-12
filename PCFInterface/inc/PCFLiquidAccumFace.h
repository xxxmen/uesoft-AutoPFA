// PCFLiquidAccumFace.h: interface for the PCFLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_)
#define AFX_PCFLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFLiquidAccumFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFLiquidAccumFace();
	virtual ~PCFLiquidAccumFace();
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	
};

#endif // !defined(AFX_PCFLIQUIDACCUMFACE_H__20090FDE_F862_4D90_B4A8_89215D737D00__INCLUDED_)
