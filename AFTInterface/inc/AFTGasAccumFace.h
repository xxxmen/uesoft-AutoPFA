// AFTGasAccumFace.h: interface for the AFTGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_)
#define AFX_AFTGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTGasAccumFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTGasAccumFace();
	virtual ~AFTGasAccumFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTGASACCUMFACE_H__92937330_0555_4B7B_A458_AE1C9C0580F9__INCLUDED_)
