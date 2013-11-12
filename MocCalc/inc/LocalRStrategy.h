// LocalRStrategy.h: interface for the LocalRStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOCALRSTRATEGY_H__C6595872_C2C4_4429_A150_653FC18AB31F__INCLUDED_)
#define AFX_LOCALRSTRATEGY_H__C6595872_C2C4_4429_A150_653FC18AB31F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;
class EndInfo;

class LocalRStrategy  
{
public:
	static LocalRStrategy* Instance();
	virtual ~LocalRStrategy();
protected:
	void CalcCv(EndListRef &jun,double dCv,double dArea);
	void CalcK(EndListRef &jun,double dK,double dArea);
	void CalcR(EndListRef &jun,double dR);
	void CalcCv(EndListRef &jun,double dPress,double dCv,double dArea,double &dOutMass);
	void CalcR(EndListRef &jun,double dPress,double dR,double &dOutMass);
	void CalcK(EndListRef &jun,double dPress,double dK,double dArea,double &dOutMass);
	LocalRStrategy();
private:
	double CalcPositMass(EndInfo *pInEnd,EndInfo *pOutEnd,double dR);
	void ExitSpray(EndListRef &jun,double dPress,double dR,double &dOutMass);

	double K(double dCv,double dArea);
	double R(double dK,double dArea);
	LocalRStrategy(const LocalRStrategy &ref);
	LocalRStrategy& operator=(const LocalRStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_LOCALRSTRATEGY_H__C6595872_C2C4_4429_A150_653FC18AB31F__INCLUDED_)
