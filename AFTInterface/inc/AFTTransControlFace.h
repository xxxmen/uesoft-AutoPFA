// AFTTransControlFace.h: interface for the AFTTransControlFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTTRANSCONTROLFACE_H__6CDCE616_B55D_4885_B109_73A3636A5F71__INCLUDED_)
#define AFX_AFTTRANSCONTROLFACE_H__6CDCE616_B55D_4885_B109_73A3636A5F71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TranContorlData.h"
#include "TransControlPerisistent.h"
class AFX_EXT_CLASS AFTTransControlFace  
{
public:
	AFTTransControlFace();
	virtual ~AFTTransControlFace();
	ErrorStatus::FileError Read(TranContorlData &Data,TransControlPerisistent& model);
	ErrorStatus::FileError Save(TranContorlData &Data,TransControlPerisistent& model);

};

#endif // !defined(AFX_AFTTRANSCONTROLFACE_H__6CDCE616_B55D_4885_B109_73A3636A5F71__INCLUDED_)
