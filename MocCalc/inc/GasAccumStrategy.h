// GasAccumStrategy.h: interface for the GasAccumStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASACCUMSTRATEGY_H__E934E3BE_9807_4B9E_9F93_8AC6FB1C033B__INCLUDED_)
#define AFX_GASACCUMSTRATEGY_H__E934E3BE_9807_4B9E_9F93_8AC6FB1C033B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;
class MOCLumpedInertia;

class GasAccumStrategy  
{
public:
	static GasAccumStrategy* Instance();
	virtual ~GasAccumStrategy();
protected:
	void Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double &dMass,double &dPress,double &dVolume);
	GasAccumStrategy();
private:
	double CalcC3(EndListRef &jun,MOCLumpedInertia &Inertia,double dPress,double dMass);
	double CalcC4(EndListRef &jun,MOCLumpedInertia &Inertia,double dMass,BOOL bInSys);
	double CalcC5(double dMass,double dVolume);
	double CalcC6();
	double CalcC7(double dPolytropic,double dCA);
	void Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double dOldMass,double dPress,double dVolume,double dNewMass,double &dFun,double &dGrad);
	GasAccumStrategy(const GasAccumStrategy &ref);
	GasAccumStrategy& operator=(const GasAccumStrategy &ref);
	friend class EndListRef;

};

#endif // !defined(AFX_GASACCUMSTRATEGY_H__E934E3BE_9807_4B9E_9F93_8AC6FB1C033B__INCLUDED_)
