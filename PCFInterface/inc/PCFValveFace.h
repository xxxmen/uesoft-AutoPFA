// PCFValveFace.h: interface for the PCFValveFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFVALVEFACE_H__D356B447_1F3B_4585_B746_49FE21265CE1__INCLUDED_)
#define AFX_PCFVALVEFACE_H__D356B447_1F3B_4585_B746_49FE21265CE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class PCFValveFace : public PCFJunFace  
{
public:
	ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	static PCFJunFace* Creator();
	PCFValveFace();
	virtual ~PCFValveFace();

};

#endif // !defined(AFX_PCFVALVEFACE_H__D356B447_1F3B_4585_B746_49FE21265CE1__INCLUDED_)
