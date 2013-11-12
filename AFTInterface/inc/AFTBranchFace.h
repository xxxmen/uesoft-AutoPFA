// AFTBranchFace.h: interface for the AFTBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTBRANCHFACE_H__C478DA1E_108A_4CA2_87CB_AE7C2D42FCB0__INCLUDED_)
#define AFX_AFTBRANCHFACE_H__C478DA1E_108A_4CA2_87CB_AE7C2D42FCB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTBranchFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTBranchFace();
	virtual ~AFTBranchFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTBRANCHFACE_H__C478DA1E_108A_4CA2_87CB_AE7C2D42FCB0__INCLUDED_)
