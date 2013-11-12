// SurgeStrategy.h: interface for the SurgeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SURGESTRATEGY_H__FC70605F_CAA2_4E2E_9A22_A367480492C6__INCLUDED_)
#define AFX_SURGESTRATEGY_H__FC70605F_CAA2_4E2E_9A22_A367480492C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;
class MOCLumpedInertia;

class SurgeStrategy  
{
public:
	static SurgeStrategy* Instance();
	virtual ~SurgeStrategy();
protected:
	void Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dSurfacePress,double dArea,double &dH,double &dMass);
	SurgeStrategy();
private:
	SurgeStrategy(const SurgeStrategy &ref);
	SurgeStrategy& operator=(const SurgeStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_SURGESTRATEGY_H__FC70605F_CAA2_4E2E_9A22_A367480492C6__INCLUDED_)
