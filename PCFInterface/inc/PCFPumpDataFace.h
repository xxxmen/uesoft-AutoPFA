// PCFPumpDataFace.h: interface for the PCFAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPUMPDATAFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_)
#define AFX_PCFPUMPDATAFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFPumpDataFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFPumpDataFace();
	virtual ~PCFPumpDataFace();
	ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	
	
};

#endif // !defined(AFX_PCFPUMPDATAFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_)

