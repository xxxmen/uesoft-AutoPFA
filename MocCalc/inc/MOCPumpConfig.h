// MOCPumpConfig.h: interface for the MOCPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPUMPCONFIG_H__67C79226_4D6A_49EC_A54F_F2E0799E4360__INCLUDED_)
#define AFX_MOCPUMPCONFIG_H__67C79226_4D6A_49EC_A54F_F2E0799E4360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ListFlyWeightImp.h"
#include "MOCPolynomial.h"
#include "MOCTable.h"
class CalcPumpConfig;


class MOCPumpConfig  
{
public:
	void Read(CalcPumpConfig &config);
	MOCPumpConfig();
	virtual ~MOCPumpConfig();
public:
	double MaxMassFlow();
	double GetTr(double dSpeed);
	double GetPr();//得到最佳效率点的压力上升
	double GetMr();//得到最佳效率点的流量
	double GetPower(double dX);
	double GetNPSHR(double dX);
	double GetPress(double dX);
private:
	double CalcPe(double dMass,double dPress);
	int PressType();
	int FlowType();
	int PowerType();
	double MaxFlow();
	double CalcBEP();
	void InitData(ListImp<StrArray<4> > &ref);
	
	MOCPolynomial m_CurveHQ;
	MOCPolynomial m_CurveNPSHR;
	MOCPolynomial m_CurvePower;
	MOCCurveData m_HQData;
	MOCCurveData m_NPSHRData;
	MOCCurveData m_PowerData;
	
	double m_dBEP;
	double m_dEndFlow;
	double m_dAffiniity;
};

#endif // !defined(AFX_MOCPUMPCONFIG_H__67C79226_4D6A_49EC_A54F_F2E0799E4360__INCLUDED_)
