// TripWhitInertia.h: interface for the TripWhitInertia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIPWHITINERTIA_H__2E8CD5BF_58E5_4384_A1A0_99D4B9A6AF6D__INCLUDED_)
#define AFX_TRIPWHITINERTIA_H__2E8CD5BF_58E5_4384_A1A0_99D4B9A6AF6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class TripWhitInertia  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	TripWhitInertia();
	virtual ~TripWhitInertia();


private:
	void IneriaTripSpeed(PumpTransModelMgr &mgr,int nSet);
	double CalcSpeed(PumpTransModelMgr &mgr,double dSpeedOld,double dTorqueOld,double dTorqueNew);
};

#endif // !defined(AFX_TRIPWHITINERTIA_H__2E8CD5BF_58E5_4384_A1A0_99D4B9A6AF6D__INCLUDED_)
