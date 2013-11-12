// WhitoutInertiaFourQundrant.h: interface for the WhitoutInertiaFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WHITOUTINERTIAFOURQUNDRANT_H__AEA94862_DC0E_44F2_8055_958755E6A07D__INCLUDED_)
#define AFX_WHITOUTINERTIAFOURQUNDRANT_H__AEA94862_DC0E_44F2_8055_958755E6A07D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class WhitoutInertiaFourQundrant  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	void CalcFourQundrant(PumpTransModelMgr &mgr,double dTime,int nSet);
	WhitoutInertiaFourQundrant();
	virtual ~WhitoutInertiaFourQundrant();

private:
	double MotorSpeedRatio(PumpTransModelMgr &mgr,double dTime);
};

#endif // !defined(AFX_WHITOUTINERTIAFOURQUNDRANT_H__AEA94862_DC0E_44F2_8055_958755E6A07D__INCLUDED_)
