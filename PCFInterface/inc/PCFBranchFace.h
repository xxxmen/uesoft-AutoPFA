// PCFBranchFace.h: interface for the PCFBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFBRANCHFACE_H__A7039AEC_D414_4FA3_826A_CED06F751E24__INCLUDED_)
#define AFX_PCFBRANCHFACE_H__A7039AEC_D414_4FA3_826A_CED06F751E24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class PCFBranchFace : public PCFJunFace  
{
public:
	ErrorStatus::FileError Read(PCFJun *pData, Junperisist *pModel);
	static PCFJunFace* Creator();
	PCFBranchFace();
	virtual ~PCFBranchFace();

};

#endif // !defined(AFX_PCFBRANCHFACE_H__A7039AEC_D414_4FA3_826A_CED06F751E24__INCLUDED_)
