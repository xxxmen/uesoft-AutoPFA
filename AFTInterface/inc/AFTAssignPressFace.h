// AFTAssignPressFace.h: interface for the AFTAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_)
#define AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTAssignPressFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTAssignPressFace();
	virtual ~AFTAssignPressFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTASSIGNPRESSFACE_H__B917CE18_D3B2_4116_8330_1D0C07DABAE0__INCLUDED_)
