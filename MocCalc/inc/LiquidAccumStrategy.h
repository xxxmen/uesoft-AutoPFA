// LiquidAccumStrategy.h: interface for the LiquidAccumStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIQUIDACCUMSTRATEGY_H__8185281E_F6B9_4D96_942C_BC99BDC31608__INCLUDED_)
#define AFX_LIQUIDACCUMSTRATEGY_H__8185281E_F6B9_4D96_942C_BC99BDC31608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;

class LiquidAccumStrategy  
{
public:
    static LiquidAccumStrategy* Instance();
	virtual ~LiquidAccumStrategy();
protected:
	void Calc(EndListRef &jun,double dK,double &dVolume,double &dMass);
	LiquidAccumStrategy();
private:
	LiquidAccumStrategy(const LiquidAccumStrategy &ref);
	LiquidAccumStrategy& operator=(const LiquidAccumStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_LIQUIDACCUMSTRATEGY_H__8185281E_F6B9_4D96_942C_BC99BDC31608__INCLUDED_)
