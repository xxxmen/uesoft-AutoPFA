// MOCPumpConfig.cpp: implementation of the MOCPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPumpConfig.h"
#include "CalcPumpConfig.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPumpConfig::MOCPumpConfig()
{
	m_dBEP = 0;
	m_dEndFlow = 0;
	m_dAffiniity = 0;
}

MOCPumpConfig::~MOCPumpConfig()
{

}

void MOCPumpConfig::Read(CalcPumpConfig &config)
{
	m_CurveHQ.Read(config.m_CurveHQ);
	m_CurveNPSHR.Read(config.m_CurveNPSHR);
	m_CurvePower.Read(config.m_CurvePower);
	m_dBEP = config.BEP();
	m_dEndFlow = config.EndFlow();
	m_dAffiniity = config.Affiniity();
	InitData(config.CurveData());
	m_dBEP = CalcBEP();
}


int MOCPumpConfig::PressType()
{
	return m_CurveHQ.YAxisType();
}
int MOCPumpConfig::FlowType()
{
	return m_CurveHQ.XAxisType();
}
int MOCPumpConfig::PowerType()
{
	return m_CurvePower.YAxisType();
}
double MOCPumpConfig::MaxFlow()
{
	double dMax = 0;
	double dMin = 0;
	m_HQData.GetMaxMin(dMax,dMin,0);
	return dMax;
}

double MOCPumpConfig::GetPress(double dX)
{
	double dPress = 0;
	if(0 == FlowType())//体积流量
		dX = MOCFluid::TranMassToQ(dX);
	if(dX > MaxFlow())
		dX = MaxFlow();
	if(dX < 0)
		dX = 0;
	dPress = m_CurveHQ.GetY(m_HQData,dX);
	if(PressType()==0)//水头
		dPress = MOCFluid::TranHToPress(dPress);
	return dPress;
}

double MOCPumpConfig::GetNPSHR(double dX)
{
	double dPress = 0;
	if(0 == FlowType())//体积流量
		dX = MOCFluid::TranMassToQ(dX);
	if(dX > MaxFlow())
		return dPress;
	if(dX < 0)
		dX = 0;
	dPress = m_CurveNPSHR.GetY(m_NPSHRData,dX);
	if(PressType()==0)//水头
		dPress = MOCFluid::TranHToPress(dPress);
	return dPress;
}

double MOCPumpConfig::GetPower(double dX)
{
	double dNewPower = 0;
	double dPress = GetPress(dX);
	double dMass = dX;
	if(0 == FlowType())//体积流量
		dX = MOCFluid::TranMassToQ(dX);
	if(dX > MaxFlow())
		dX =  MaxFlow();
	if(dX < 0)
		dX = 0;
	dNewPower = m_CurvePower.GetY(m_PowerData,dX);
	if(fabs(dNewPower)<1E-6||dNewPower<0)
		return 0;
	if(0==PowerType())
	{
		double dPe = CalcPe(dMass,dPress);
		dNewPower = dPe*100/dNewPower;
	}
	return dNewPower;
}

void MOCPumpConfig::InitData(ListImp<StrArray<4> > &ref)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<1> > list2;
	ListImp<StrArray<1> > list3;
	ListImp<StrArray<1> > list4;
	ListImp<StrArray<2> > list5;
	ListImp<StrArray<2> > list6;
	Divided<2,2>(list5,list6,ref);
	Divided<1,1>(list1,list2,list5);
	Divided<1,1>(list3,list4,list6);
	m_HQData.SetData(Combi<1,1>(list1,list2));
	m_NPSHRData.SetData(Combi<1,1>(list1,list3));
	m_PowerData.SetData(Combi<1,1>(list1,list4));
}

double MOCPumpConfig::CalcBEP()
{
	double dMax = 0;
	double dMin = 0;
	m_PowerData.GetMaxMin(dMax,dMin,1);
	return dMax;
}

double MOCPumpConfig::GetMr()
{
	double dMass = m_PowerData.GetValue(m_dBEP,FALSE,0,1);
	if(0 == FlowType())//体积流量
		dMass = MOCFluid::TranQToMass(dMass);
	return dMass;
}

double MOCPumpConfig::GetPr()
{
	double dMass = m_PowerData.GetValue(m_dBEP,FALSE,0,1);
	double dPress = m_CurveHQ.GetY(m_HQData,dMass);
	if(PressType()==0)//水头
		dPress = MOCFluid::TranHToPress(dPress);
	return dPress;
}


double MOCPumpConfig::MaxMassFlow()
{
	double dMass = MaxFlow();
	if(0 == FlowType())//体积流量
		dMass = MOCFluid::TranQToMass(dMass);
	return dMass;
}

double MOCPumpConfig::CalcPe(double dMass,double dPress)
{
	return dPress*dMass/MOCFluid::Density();
}

double MOCPumpConfig::GetTr(double dSpeed)
{
	double dMass = GetMr();
	double dPower =GetPower(dMass);
	return (30*dPower/(dSpeed*PI));
}