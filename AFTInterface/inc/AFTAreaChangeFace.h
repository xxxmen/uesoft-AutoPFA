// AFTAreaChangeFace.h: interface for the AFTAreaChangeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTAREACHANGEFACE_H__7684D62F_A040_4AE7_80C5_588EE42B215A__INCLUDED_)
#define AFX_AFTAREACHANGEFACE_H__7684D62F_A040_4AE7_80C5_588EE42B215A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AFTJunFace.h"

class AFX_EXT_CLASS AFTAreaChangeFace : public AFTJunFace  
{
public:
	static AFTJunFace* Creator();
	AFTAreaChangeFace();
	virtual ~AFTAreaChangeFace();
	virtual ErrorStatus::FileError Read(JunctionData *pData,Junperisist* pModel);
	virtual ErrorStatus::FileError Save(JunctionData *pData,Junperisist* pModel);

};

#endif // !defined(AFX_AFTAREACHANGEFACE_H__7684D62F_A040_4AE7_80C5_588EE42B215A__INCLUDED_)
