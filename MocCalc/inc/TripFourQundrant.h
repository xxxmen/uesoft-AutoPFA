// TripFourQundrant.h: interface for the TripFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIPFOURQUNDRANT_H__D8502040_3B61_4DF3_8248_CD9FC9175100__INCLUDED_)
#define AFX_TRIPFOURQUNDRANT_H__D8502040_3B61_4DF3_8248_CD9FC9175100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class TripFourQundrant  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	TripFourQundrant();
	virtual ~TripFourQundrant();

private:
	void CalcImpulse0(PumpTransModelMgr &mgr,int nSet);
	void CalcImpulse1(PumpTransModelMgr &mgr,int nSet);
};

#endif // !defined(AFX_TRIPFOURQUNDRANT_H__D8502040_3B61_4DF3_8248_CD9FC9175100__INCLUDED_)
