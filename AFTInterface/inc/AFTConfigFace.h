// AFTConfigFace.h: interface for the AFTConfigFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTCONFIGFACE_H__01E4FA9B_0258_46D8_9B69_A7DC669A9EBD__INCLUDED_)
#define AFX_AFTCONFIGFACE_H__01E4FA9B_0258_46D8_9B69_A7DC669A9EBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "onfigPerisist.h"
#include "PumpConfig.h"
class AFX_EXT_CLASS AFTConfigFace  
{
public:
	ErrorStatus::FileError Read(PumpConfig &pData,ConfigPerisist &Model);
	ErrorStatus::FileError Save(PumpConfig &Data,ConfigPerisist &Model);
	AFTConfigFace();
	virtual ~AFTConfigFace();

};

#endif // !defined(AFX_AFTCONFIGFACE_H__01E4FA9B_0258_46D8_9B69_A7DC669A9EBD__INCLUDED_)
