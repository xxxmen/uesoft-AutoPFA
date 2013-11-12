// FlowJunStrategy.h: interface for the FlowJunStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOWJUNSTRATEGY_H__9F0802A7_7A45_4EC7_BC15_4EDE8A8C5E1C__INCLUDED_)
#define AFX_FLOWJUNSTRATEGY_H__9F0802A7_7A45_4EC7_BC15_4EDE8A8C5E1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class EndListRef;
class EndInfo;

class FlowJunStrategy  
{
public:
	static FlowJunStrategy* Instance();
	virtual ~FlowJunStrategy();
protected:
	void Calc(EndListRef &jun,double dMass);//设置端点的流量并计算压力
	void Calc(EndListRef &jun,EndInfo &end,double dMass);//设置端点的流量并计算压力。
	FlowJunStrategy();
private:
	FlowJunStrategy(const FlowJunStrategy &ref);
	FlowJunStrategy& operator=(const FlowJunStrategy &ref);
	friend class EndListRef;
};

#endif // !defined(AFX_FLOWJUNSTRATEGY_H__9F0802A7_7A45_4EC7_BC15_4EDE8A8C5E1C__INCLUDED_)
