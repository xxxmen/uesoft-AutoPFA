// StartWhitInertia.h: interface for the StartWhitInertia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTWHITINERTIA_H__6CBE987D_309D_4D8E_80F9_2833AE272267__INCLUDED_)
#define AFX_STARTWHITINERTIA_H__6CBE987D_309D_4D8E_80F9_2833AE272267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class StartWhitInertia  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	StartWhitInertia();
	virtual ~StartWhitInertia();
private:
	void IneriaStartSpeed(PumpTransModelMgr &mgr,int nSet);
	double MotorTorque(PumpTransModelMgr &mgr,double dSpeedRatio);
	double CalcSpeed(PumpTransModelMgr &mgr,double dSpeedOld,double dMotorOld,double dMotorNew,double dFluidOld,double dFluidNew);

};

#endif // !defined(AFX_STARTWHITINERTIA_H__6CBE987D_309D_4D8E_80F9_2833AE272267__INCLUDED_)
