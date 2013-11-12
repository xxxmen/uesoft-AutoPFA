// AFTSysPropety.h: interface for the AFTSysPropety class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSYSPROPETY_H__4551D647_A3AE_46F5_B29C_6EE9D7035266__INCLUDED_)
#define AFX_AFTSYSPROPETY_H__4551D647_A3AE_46F5_B29C_6EE9D7035266__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SysProperty.h"
#include "FluidData.h"

class AFX_EXT_CLASS AFTSysPropety  
{
public:
	AFTSysPropety();
	virtual ~AFTSysPropety();
	ErrorStatus::FileError Read(FluidData &Data,PropertyPersistent& model);
	ErrorStatus::FileError Save(FluidData &Data,PropertyPersistent& model);

};

#endif // !defined(AFX_AFTSYSPROPETY_H__4551D647_A3AE_46F5_B29C_6EE9D7035266__INCLUDED_)
