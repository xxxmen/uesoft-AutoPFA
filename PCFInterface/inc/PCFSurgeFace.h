// PCFSurgeFace.h: interface for the PCFSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_)
#define AFX_PCFSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFSurgeFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFSurgeFace();
	virtual ~PCFSurgeFace();
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);

	
};

#endif // !defined(AFX_PCFSURGEFACE_H__033D3675_7B65_4775_BB89_C32EBFB4650A__INCLUDED_)
