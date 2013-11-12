// CalcPumpConfig.h: interface for the CalcPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPUMPCONFIG_H__9976238D_725C_4A8D_B955_A08E8E8919E3__INCLUDED_)
#define AFX_CALCPUMPCONFIG_H__9976238D_725C_4A8D_B955_A08E8E8919E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcCurve.h"
#include "ListFlyWeightImp.h"
#include "CalcTable.h"

class AFX_EXT_CLASS CalcPumpConfig  
{
public:
	CalcPumpConfig();
	virtual ~CalcPumpConfig();
public:
	friend ostream& operator<< (ostream &CalcOut,CalcPumpConfig &ref);
	void CurveData(const ListImp<StrArray<4> >& ref);
	void PressType(int nValue);
	void FlowType(int nValue);
	void PowerType(int nValue);
	void MaxFlow(double dValue);
	void CalcBEP(BOOL nValue);
	void BEP(double dValue);
	void EndFlow(double dValue);
	void Affiniity(double dValue);
	
	ListImp<StrArray<4> >& CurveData();
	BOOL CalcBEP();
	double BEP();
	double EndFlow();
	double Affiniity();
public:
	CalcCurve m_CurveHQ;
	CalcCurve m_CurveNPSHR;
	CalcCurve m_CurvePower;
	CalcTable<4> m_CurveData;
	BOOL m_bCalcBEP;
	double m_dBEP;
	double m_dEndFlow;
	double m_dAffiniity;

	BOOL m_bHavePreRiseData;
	BOOL m_bHaveNPSHRData;
	BOOL m_bHavePowerData;

	
};

#endif // !defined(AFX_CALCPUMPCONFIG_H__9976238D_725C_4A8D_B955_A08E8E8919E3__INCLUDED_)
