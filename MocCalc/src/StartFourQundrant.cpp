// StartFourQundrant.cpp: implementation of the StartFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StartFourQundrant.h"
#include "FourQundrantModel.h"
#include "PumpTransModelMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StartFourQundrant::StartFourQundrant()
{

}

StartFourQundrant::~StartFourQundrant()
{

}

void StartFourQundrant::CalcImpulse(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet)
{
	if(mgr.IsFourQundrant())
	{
		CalcImpulse(mgr,nSet);
	}
	else
	{
		mgr.m_StartWhitInertia.CalcImpulse(mgr,trans,dTime,dSpeedRatio,nSet);
	}
}

void StartFourQundrant::CalcImpulse(PumpTransModelMgr &mgr, int nSet)
{
	FourQundrantModel &FourModel = *FourQundrantModel::Instance();
	MOCPumpConfig &config = mgr.GetConfig();
	MOCPumpModel &model = mgr.GetModel();
	double dNr = mgr.GetInertia().Speed();
	double dMr = config.GetMr();
	double dPr = config.GetPr();
	double dTr = config.GetTr(dNr);
	double da0 = mgr.GetCurSpeedRatio();
	double dv0  = model.MassFlow()/dMr;
	double dBf0 = FourModel.CalcdBf(mgr.GetFourQuadrantData(),da0,dv0);
	double dBm0 = MotorTb(mgr,da0,dTr);
	double dBm = dBm0;
	double da = da0;
	double dv = dv0;
	double dBmtemp = dBm;
	double datemp = da;
	double dvtemp = dv;
	double dv1 = 0;
	double dv2 = 0;
	double da1 = 0;
	double da2 = 0;
	int i=0;
	do 
	{//斯蒂芬森法计算（AitKen加速迭代）
		dBm = dBmtemp;
		da = datemp;
		dv = dvtemp;
		dv1 = FourModel.Calcv(mgr,dMr,dPr,da,dv,nSet);
		da1 = FourModel.Calca(mgr,dTr,dNr,da0,dBf0,dBm0,dBm,da,dv1);
		dv2 = FourModel.Calcv(mgr,dMr,dPr,da1,dv1,nSet);
		da2 = FourModel.Calca(mgr,dTr,dNr,da0,dBf0,dBm0,dBm,da1,dv1);
		if(fabs(dv2-2*dv1+dv)<1E-6)
		{
			dvtemp = dv;
		}
		else
		{
			dvtemp = dv - pow(dv1-dv,2)/(dv2-2*dv1+dv);
		}
		if(fabs(da2-2*da1+da)<1E-6)
		{
			datemp = da;
		}
		else
		{
			datemp = da - pow(da1-da,2)/(da2-2*da1+da);
		}
		dBmtemp = MotorTb(mgr,datemp,dTr);
		i++;
	} while((fabs(dvtemp-dv)>1E-6||fabs(datemp-da)>1E-6)&&i<100);
	if(i>90)
	{
		ASSERT(FALSE);
		return;
	}
	mgr.SetCurSpeedRatio(datemp);
	mgr.CalcFourQundrant(dMr*dvtemp,nSet);
}

double StartFourQundrant::MotorTb(PumpTransModelMgr &mgr, double da, double dTr)
{
	MOCTranData &data = mgr.GetTranData();
	return data.GeTransY(da*100)/dTr;
}
