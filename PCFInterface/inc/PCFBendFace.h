// PCFBendFace.h: interface for the PCFBendFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFBENDFACE_H__969BB937_070F_4753_BD56_00087715F424__INCLUDED_)
#define AFX_PCFBENDFACE_H__969BB937_070F_4753_BD56_00087715F424__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFBendFace : public PCFJunFace  
{
public:
    ErrorStatus::FileError Read(PCFJun *pData, Junperisist *pModel);
	static PCFJunFace* Creator();
	PCFBendFace();
	virtual ~PCFBendFace();

};

#endif // !defined(AFX_PCFBENDFACE_H__969BB937_070F_4753_BD56_00087715F424__INCLUDED_)
