// BreckerStrategy.h: interface for the BreckerStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRECKERSTRATEGY_H__B999BE8E_7E33_4329_B224_39785957C752__INCLUDED_)
#define AFX_BRECKERSTRATEGY_H__B999BE8E_7E33_4329_B224_39785957C752__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;
class GasProperty;

class BreckerStrategy  
{
public:
    static BreckerStrategy* Instance();
	virtual ~BreckerStrategy();
protected:
	void Calc(EndListRef &jun,GasProperty &gas,double dCdAIn,double dCdAOut);
	BreckerStrategy();
private:
	void UpData(EndListRef &jun,GasProperty &gas,double dGasFlow,double dPress);
	double SonicInPress(EndListRef &jun,GasProperty &gas,double dCdA);
	double SubsonicInPress(EndListRef &jun,GasProperty &gas,double dCdA);
	double SonicOutPress(EndListRef &jun,GasProperty &gas,double dCdA);
	double SubsonicOutPress(EndListRef &jun,GasProperty &gas,double dCdA);
	void Calc(EndListRef &jun,GasProperty &gas,double dCdA,double dPr,BOOL bIn,double &dFun,double &dGrad);
	BreckerStrategy(const BreckerStrategy &ref);
	BreckerStrategy& operator=(const BreckerStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_BRECKERSTRATEGY_H__B999BE8E_7E33_4329_B224_39785957C752__INCLUDED_)
