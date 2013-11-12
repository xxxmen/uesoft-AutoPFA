// PCFJunFace.h: interface for the PCFJunFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUNFACE_H__AA75EA79_88F5_4EE8_A455_6B5D0D590F78__INCLUDED_)
#define AFX_PCFJUNFACE_H__AA75EA79_88F5_4EE8_A455_6B5D0D590F78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
#include "Junperisist.h"

class AFX_EXT_CLASS PCFJunFace  
{
public:
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	PCFJunFace();
	virtual ~PCFJunFace();

};

#endif // !defined(AFX_PCFJUNFACE_H__AA75EA79_88F5_4EE8_A455_6B5D0D590F78__INCLUDED_)
