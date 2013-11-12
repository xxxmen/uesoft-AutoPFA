// WhitoutInertia.h: interface for the WhitoutInertia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WHITOUTINERTIA_H__B744AF7C_8F18_4AF0_80E3_BC9011B04391__INCLUDED_)
#define AFX_WHITOUTINERTIA_H__B744AF7C_8F18_4AF0_80E3_BC9011B04391__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class WhitoutInertia  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	WhitoutInertia();
	virtual ~WhitoutInertia();

};

#endif // !defined(AFX_WHITOUTINERTIA_H__B744AF7C_8F18_4AF0_80E3_BC9011B04391__INCLUDED_)
