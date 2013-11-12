// CalcAssignPressFace.h: interface for the CalcAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCASSIGNPRESSFACE_H__6E34638F_0B24_4398_AFB2_ADAEEC661DED__INCLUDED_)
#define AFX_CALCASSIGNPRESSFACE_H__6E34638F_0B24_4398_AFB2_ADAEEC661DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcAssignPressFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcAssignPressFace();
	virtual ~CalcAssignPressFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCASSIGNPRESSFACE_H__6E34638F_0B24_4398_AFB2_ADAEEC661DED__INCLUDED_)
