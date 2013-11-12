// NoTranFourQundrant.h: interface for the NoTranFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTRANFOURQUNDRANT_H__5A60538F_988E_405E_B63F_94C295E474C6__INCLUDED_)
#define AFX_NOTRANFOURQUNDRANT_H__5A60538F_988E_405E_B63F_94C295E474C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
#include "MOCTrans.h"

class NoTranFourQundrant  
{
public:
	void CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet);
	NoTranFourQundrant();
	virtual ~NoTranFourQundrant();

};

#endif // !defined(AFX_NOTRANFOURQUNDRANT_H__5A60538F_988E_405E_B63F_94C295E474C6__INCLUDED_)
