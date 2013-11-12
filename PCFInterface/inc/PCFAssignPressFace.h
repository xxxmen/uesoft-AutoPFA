// PCFAssignPressFace.h: interface for the AFTAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_)
#define AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class AFX_EXT_CLASS PCFAssignPressFace : public PCFJunFace  
{
public:
	static PCFJunFace* Creator();
	PCFAssignPressFace();
	virtual ~PCFAssignPressFace();
	virtual ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	
};

#endif // !defined(AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_)
