// AFTSteadyFace.h: interface for the AFTSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSTEADYFACE_H__B013E55A_52DA_4AC9_B5F4_59448791832A__INCLUDED_)
#define AFX_AFTSTEADYFACE_H__B013E55A_52DA_4AC9_B5F4_59448791832A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SettingData.h"
#include "SteadyPersistent.h"

class AFX_EXT_CLASS AFTSteadyFace  
{
public:
	AFTSteadyFace();
	virtual ~AFTSteadyFace();
	ErrorStatus::FileError Read(SettingData &Data,SteadyPersistent& model);
	ErrorStatus::FileError Save(SettingData &Data,SteadyPersistent& model);

};

#endif // !defined(AFX_AFTSTEADYFACE_H__B013E55A_52DA_4AC9_B5F4_59448791832A__INCLUDED_)
