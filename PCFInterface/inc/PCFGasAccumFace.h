// PCFGasAccumFace.h: interface for the PCFGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_)
#define AFX_PCFGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFGasAccumFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFGasAccumFace();
	virtual ~PCFGasAccumFace();
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_PCFGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_)
