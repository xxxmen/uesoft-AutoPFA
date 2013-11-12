// StartFourQundrant.h: interface for the StartFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTFOURQUNDRANT_H__56AFA946_229D_4972_808A_83E97523F504__INCLUDED_)
#define AFX_STARTFOURQUNDRANT_H__56AFA946_229D_4972_808A_83E97523F504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class StartFourQundrant  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	StartFourQundrant();
	virtual ~StartFourQundrant();

private:
	double MotorTb(PumpTransModelMgr &mgr,double da,double dTr);
	void CalcImpulse(PumpTransModelMgr &mgr,int nSet);
};

#endif // !defined(AFX_STARTFOURQUNDRANT_H__56AFA946_229D_4972_808A_83E97523F504__INCLUDED_)
