// CalcPumpFace.h: interface for the CalcPumpFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPUMPFACE_H__C6F744AA_9DC1_4D80_842F_751028F9A943__INCLUDED_)
#define AFX_CALCPUMPFACE_H__C6F744AA_9DC1_4D80_842F_751028F9A943__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcPumpFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcPumpFace();
	virtual ~CalcPumpFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCPUMPFACE_H__C6F744AA_9DC1_4D80_842F_751028F9A943__INCLUDED_)
