// CalcAssignFlowFace.h: interface for the CalcAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCASSIGNFLOWFACE_H__6FC9348B_6F19_4CA2_91F1_2C04D37DCC78__INCLUDED_)
#define AFX_CALCASSIGNFLOWFACE_H__6FC9348B_6F19_4CA2_91F1_2C04D37DCC78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcAssignFlowFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcAssignFlowFace();
	virtual ~CalcAssignFlowFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCASSIGNFLOWFACE_H__6FC9348B_6F19_4CA2_91F1_2C04D37DCC78__INCLUDED_)
