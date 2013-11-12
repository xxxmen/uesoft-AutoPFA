// LocalRStrategy.cpp: implementation of the LocalRStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LocalRStrategy.h"
#include "EndListRef.h"
#include "MOCFluid.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LocalRStrategy::LocalRStrategy()
{

}

LocalRStrategy::~LocalRStrategy()
{

}

LocalRStrategy* LocalRStrategy::Instance()
{
	static LocalRStrategy strategy;
	return &strategy;
}

void LocalRStrategy::CalcCv(EndListRef &jun,double dCv,double dArea)
{
	CalcK(jun,K(dCv,dArea),dArea);
}

void LocalRStrategy::CalcK(EndListRef &jun,double dK,double dArea)
{
	CalcR(jun,R(dK,dArea));
}

void LocalRStrategy::CalcR(EndListRef &jun,double dR)
{
	EndInfo *pInEnd = jun.GetInEnd();
	EndInfo *pOutEnd = jun.GetOutEnd();
	if(pInEnd==NULL ||pOutEnd==NULL)
	{
		ASSERT(FALSE);
		return;
	}
	if(-1E-10<(dR)&&(dR)<1E-10)
	{
		jun.BranchStrategy(0);
	}
	else
	{
		double dMass = CalcPositMass(pInEnd,pOutEnd,dR);
		jun.FlowStrategy(dMass);
	}
}

void LocalRStrategy::CalcCv(EndListRef &jun,double dPress,double dCv,double dArea,double &dOutMass)
{
	CalcK(jun,dPress,K(dCv,dArea),dArea,dOutMass);
}

void LocalRStrategy::CalcK(EndListRef &jun,double dPress,double dK,double dArea,double &dOutMass)
{
	CalcR(jun,dPress,R(dK,dArea),dOutMass);
}

void LocalRStrategy::CalcR(EndListRef &jun,double dPress,double dR,double &dOutMass)
{
	ExitSpray(jun,dPress,dR,dOutMass);
}

double LocalRStrategy::R(double dK,double dArea)
{
	double dDen = MOCFluid::Density();
	return 0.5*fabs(dK) / (dDen*pow(dArea,2));
}

double LocalRStrategy::K(double dCv,double dArea)
{
	if(-0.000000001<dCv && dCv<0.000000001)
	{
		return 1E+31;
	}
	else
	{
		return 1.0 / pow(dCv/dArea/58883.923073822689447,2);
	}
}


double LocalRStrategy::CalcPositMass(EndInfo *pInEnd,EndInfo *pOutEnd,double dR)
{
	if(-1E-28<(1/dR)&&(1/dR)<1E-28)
	{
		return 0;
	}
	double dCp = pInEnd->GetCpm();
	double dBp = pInEnd->GetBpm();
	double dCm = pOutEnd->GetCpm();
	double dBm = pOutEnd->GetBpm();
	double dMass = 0;
	if(dCp < dCm)//负流量
 		dR = -dR;
	double dTemp = 1.0/pow(dR,2)*pow(dBp+dBm,2) +4.0*(dCp-dCm)/dR;
	dMass = (-(dBp+dBm)/dR + dR/fabs(dR)*sqrt(fabs(dTemp)))/2;
	return dMass;
}

//////////////////////////////////////////////////////////////
/*
  出口，入口阀门可以统一使用喷嘴公式计算
*/
//////////////////////////////////////////////////////////////

void LocalRStrategy::ExitSpray(EndListRef &jun,double dPress,double dR,double &dOutMass)
{
	if(-1E-10<(dR)&&(dR)<1E-10)
	{
		jun.BranchStrategy(-dOutMass);
		return;
	}
	if(-1E-28<(1/dR)&&(1/dR)<1E-28)
	{
		dOutMass = 0;
	}
	else
	{
		double dSc = jun.Sc();
		double dSb = jun.Sb(); 
		if(dPress > dSc/dSb)
			dR = -dR;
		double dTemp = 1/(pow(dR,2)*pow(dSb,2)) +4.0*(dSc/dSb-dPress)/dR;
		dOutMass = (-1/(dR*dSb) + dR/fabs(dR)*sqrt(fabs(dTemp)))/2;
	}
	jun.BranchStrategy(-dOutMass);
}

