// CalcPumpConfig.cpp: implementation of the CalcPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPumpConfig.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPumpConfig::CalcPumpConfig()
{
	m_bCalcBEP = 0;
	m_dBEP = 0;
	m_dEndFlow = 0;
	m_dAffiniity = 0;

	m_bHavePreRiseData = FALSE;
	m_bHaveNPSHRData = FALSE;
	m_bHavePowerData = FALSE;
}

CalcPumpConfig::~CalcPumpConfig()
{

}

void CalcPumpConfig::CurveData(const ListImp<StrArray<4> >& ref)
{
	m_CurveData.SetData(ref);

	m_bHavePreRiseData = ref.HasData(1);
	m_bHaveNPSHRData = ref.HasData(2);
	m_bHavePowerData = ref.HasData(3);
}

ListImp<StrArray<4> >& CalcPumpConfig::CurveData()
{
	return m_CurveData.GetData();
}
ostream& operator<<(ostream &CalcOut,CalcPumpConfig &ref)
{
	CalcOut<<ref.m_CurveHQ.CurveType()<<s_Separator;
	if(ref.m_CurveHQ.CurveType()==0)
		return CalcOut;

	CalcOut<<ref.m_CurveHQ.XAxisType()<<s_Separator
		   <<ref.m_CurveHQ.YAxisType()<<s_Separator
		   <<ref.m_CurvePower.YAxisType()<<s_Separator
		   <<ref.m_bHavePreRiseData<<s_Separator
		   <<ref.m_bHaveNPSHRData<<s_Separator
		   <<ref.m_bHavePowerData<<s_Separator;

	if(ref.m_CurveHQ.CurveType()==1)
	{
		CalcOut<<ref.m_CurveHQ.MaxX()<<s_Separator
		       <<ref.m_CurveHQ.Order()<<s_Separator;
		double dPrame[3][5];
		ref.m_CurveHQ.Prame(dPrame[0]);
		ref.m_CurveNPSHR.Prame(dPrame[1]);
		ref.m_CurvePower.Prame(dPrame[2]);
		for(int i=0;i<ref.m_CurveHQ.Order()+1;i++)
		{
			CalcOut<<dPrame[0][i]<<s_Separator
				   <<dPrame[1][i]<<s_Separator
				   <<dPrame[2][i]<<s_Separator;
		}
	}

	if(ref.m_CurveHQ.CurveType()==2)
	{
		CalcOut<<ref.m_CurveData;
	}
	CalcOut<<ref.m_bCalcBEP<<s_Separator
		   <<ref.m_dBEP<<s_Separator
		   <<ref.m_dEndFlow<<s_Separator
		   <<ref.m_dAffiniity<<s_Separator;	   
	return CalcOut;
}

/*------------------------------------------------*/
void CalcPumpConfig::PressType(int nValue)
{
	m_CurveHQ.YAxisType(nValue);
	m_CurveNPSHR.YAxisType(nValue);
}
/*------------------------------------------------*/
void CalcPumpConfig::FlowType(int nValue)
{
	m_CurveHQ.XAxisType(nValue);
	m_CurveNPSHR.XAxisType(nValue);
	m_CurvePower.XAxisType(nValue);
}
/*------------------------------------------------*/
void CalcPumpConfig::PowerType(int nValue)
{
	m_CurvePower.YAxisType(nValue);
}
/*------------------------------------------------*/
void CalcPumpConfig::MaxFlow(double dValue)
{
	m_CurveHQ.MaxX(dValue);
	m_CurveNPSHR.MaxX(dValue);
	m_CurvePower.MaxX(dValue);
}

/*------------------------------------------------*/
void CalcPumpConfig::CalcBEP(BOOL nValue)
{
	m_bCalcBEP = nValue;
}
/*------------------------------------------------*/
void CalcPumpConfig::BEP(double dValue)
{
	m_dBEP = dValue;
}
/*------------------------------------------------*/
void CalcPumpConfig::EndFlow(double dValue)
{
	m_dEndFlow = dValue;
}
/*------------------------------------------------*/
void CalcPumpConfig::Affiniity(double dValue)
{
	m_dAffiniity = dValue;
}

////////////////////////////////////////////////////////
/*------------------------------------------------*/

/*------------------------------------------------*/
BOOL CalcPumpConfig::CalcBEP()
{
	return m_bCalcBEP;
}
/*------------------------------------------------*/
double CalcPumpConfig::BEP()
{
	return m_dBEP;
}
/*------------------------------------------------*/
double CalcPumpConfig::EndFlow()
{
	return m_dEndFlow;
}
/*------------------------------------------------*/
double CalcPumpConfig::Affiniity()
{
	return m_dAffiniity;
}