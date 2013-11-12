// StationOut.h: interface for the StationOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATIONOUT_H__32DF3316_42D0_4752_9B53_C3AE7723550A__INCLUDED_)
#define AFX_STATIONOUT_H__32DF3316_42D0_4752_9B53_C3AE7723550A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "ListFlyWeightImp.h"
#include "StationStmOut.h"


typedef double (*PMAXMIN)(double,double);

class PipeTranOut;
class AFX_EXT_CLASS StationOut
{
public:
	int Step();
	void Step(int nStep);
	StationStmOut* Creator(int nKey);
	
	Iterator<StationStmOut>* CreatIterator();
	StationOut();
	virtual ~StationOut();

public:
	double Data(int nKey,int nSubKey);
	void InitMaxMinOut(PipeTranOut& out);
	void InitMaxMin(PipeTranOut& out,double dTime);
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys);
private:
	double GetValve(int nKey,int nSubKey);
	StationStmOut* LookUp(int nKey);
	int m_nStep;
	ListImp<StationStmOut> m_list;
};

#endif // !defined(AFX_STATIONOUT_H__32DF3316_42D0_4752_9B53_C3AE7723550A__INCLUDED_)
