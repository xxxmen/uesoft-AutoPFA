// PressDropStrategy.h: interface for the PressDropStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRESSDROPSTRATEGY_H__653B1BE4_0429_4DE1_A68A_63351847F520__INCLUDED_)
#define AFX_PRESSDROPSTRATEGY_H__653B1BE4_0429_4DE1_A68A_63351847F520__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;

class PressDropStrategy  
{
public:
	static PressDropStrategy* Instance();
	virtual ~PressDropStrategy();
protected:
	double Calc(EndListRef &jun,double dPressDelta);
	double Calc(EndListRef &jun,double dPressUp,double dPressDelta);
	double CalcMass(EndListRef &jun,double dPressDelta);
	double CalcMass(EndListRef &jun,double dPressUp,double dPressDelta);
	PressDropStrategy();
private:
	PressDropStrategy(const PressDropStrategy &ref);
	PressDropStrategy& operator=(const PressDropStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_PRESSDROPSTRATEGY_H__653B1BE4_0429_4DE1_A68A_63351847F520__INCLUDED_)
