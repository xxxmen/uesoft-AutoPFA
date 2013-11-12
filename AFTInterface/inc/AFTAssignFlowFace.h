// AFTAssignFlowFace.h: interface for the AFTAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTASSIGNFLOWFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_)
#define AFX_AFTASSIGNFLOWFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTAssignFlowFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTAssignFlowFace();
	virtual ~AFTAssignFlowFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTASSIGNFLOWFACE_H__C7050E22_FE48_4CF3_B02F_B740FC970E27__INCLUDED_)
