// AFTValveFace.h: interface for the AFTValveFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTVALVEFACE_H__DB060A97_A5F1_462A_A9FB_BD19381B3A81__INCLUDED_)
#define AFX_AFTVALVEFACE_H__DB060A97_A5F1_462A_A9FB_BD19381B3A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTValveFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTValveFace();
	virtual ~AFTValveFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTVALVEFACE_H__DB060A97_A5F1_462A_A9FB_BD19381B3A81__INCLUDED_)
