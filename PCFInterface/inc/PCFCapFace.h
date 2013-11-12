// PCFCapFace.h: interface for the PCFCapFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFCAPFACE_H__99341742_4DA2_46CC_8E1F_ED0E26A93B12__INCLUDED_)
#define AFX_PCFCAPFACE_H__99341742_4DA2_46CC_8E1F_ED0E26A93B12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class PCFCapFace : public PCFJunFace  
{
public:
	ErrorStatus::FileError Read(PCFJun *pData, Junperisist *pModel);
	static PCFJunFace* Creator();
	PCFCapFace();
	virtual ~PCFCapFace();

};

#endif // !defined(AFX_PCFCAPFACE_H__99341742_4DA2_46CC_8E1F_ED0E26A93B12__INCLUDED_)
