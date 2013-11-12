// AFTConfigItemFace.h: interface for the AFTConfigItemFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTCONFIGITEMFACE_H__836F4E74_AAE4_4C5D_AAB8_0F5339386861__INCLUDED_)
#define AFX_AFTCONFIGITEMFACE_H__836F4E74_AAE4_4C5D_AAB8_0F5339386861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "onfigItemPerisist.h"
#include "PumpConfigData.h"

class AFX_EXT_CLASS AFTConfigItemFace  
{
public:
	ErrorStatus::FileError Read(PumpConfigData *pData,ConfigItemPerisist *pModel);
	ErrorStatus::FileError Save(PumpConfigData *pData,ConfigItemPerisist *pModel);
	AFTConfigItemFace();
	virtual ~AFTConfigItemFace();

};

#endif // !defined(AFX_AFTCONFIGITEMFACE_H__836F4E74_AAE4_4C5D_AAB8_0F5339386861__INCLUDED_)
