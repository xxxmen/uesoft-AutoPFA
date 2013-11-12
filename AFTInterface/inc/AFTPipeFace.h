// AFTPipeFace.h: interface for the AFTPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTPIPEFACE_H__02F2828D_099B_4816_ADD1_4C7393099D5A__INCLUDED_)
#define AFX_AFTPIPEFACE_H__02F2828D_099B_4816_ADD1_4C7393099D5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipePerisist.h"
#include "PipeData.h"

class AFX_EXT_CLASS AFTPipeFace  
{
public:
	AFTPipeFace();
	virtual ~AFTPipeFace();
	ErrorStatus::FileError Read(PipeData *pData,PipePerisist *pModel);
	ErrorStatus::FileError Save(PipeData *pData,PipePerisist *pModel);
};

#endif // !defined(AFX_AFTPIPEFACE_H__02F2828D_099B_4816_ADD1_4C7393099D5A__INCLUDED_)
