// CalcBranchFace.h: interface for the CalcBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBRANCHFACE_H__71109D69_EED0_4C82_9EFA_F7D76680B39D__INCLUDED_)
#define AFX_CALCBRANCHFACE_H__71109D69_EED0_4C82_9EFA_F7D76680B39D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJunFace.h"

class AFX_EXT_CLASS CalcBranchFace : public CalcJunFace  
{
public:
	static CalcJunFace* Creator();
	CalcBranchFace();
	virtual ~CalcBranchFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

};

#endif // !defined(AFX_CALCBRANCHFACE_H__71109D69_EED0_4C82_9EFA_F7D76680B39D__INCLUDED_)
