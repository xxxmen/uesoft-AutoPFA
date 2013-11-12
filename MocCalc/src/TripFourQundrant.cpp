// TripFourQundrant.cpp: implementation of the TripFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TripFourQundrant.h"
#include "MOCFluid.h"
#include "PumpTransModelMgr.h"
#include "TripWhitInertia.h"
#include "FourQundrantModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TripFourQundrant::TripFourQundrant()
{

}

TripFourQundrant::~TripFourQundrant()
{

}

void TripFourQundrant::CalcImpulse(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet)
{
	if(mgr.IsFourQundrant())
	{
		CalcImpulse1(mgr,nSet);
	}
	else
	{
		mgr.m_TripWhitInertia.CalcImpulse(mgr,trans,dTime,dSpeedRatio,nSet);
	}
}



void TripFourQundrant::CalcImpulse0(PumpTransModelMgr &mgr,int nSet)
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
	double da = da0;
	double dv = dv0;
	double datemp = da;
	double dvtemp = dv;
	double dv1 = 0;
	double dv2 = 0;
	double da1 = 0;
	double da2 = 0;
	int i=0;
	do 
	{//斯蒂芬森法计算（AitKen加速迭代）
		da = datemp;
		dv = dvtemp;
		da1 = FourModel.Calca(mgr,dTr,dNr,da0,dBf0,da,dv);
		dv1 = FourModel.Calcv(mgr,dMr,dPr,da1,dv,nSet);
		da2 = FourModel.Calca(mgr,dTr,dNr,da0,dBf0,da1,dv1);
		dv2 = FourModel.Calcv(mgr,dMr,dPr,da1,dv1,nSet);
		if(fabs(dv2-2*dv1+dv)<1E-10)
		{
			dvtemp = dv;
		}
		else
		{
			dvtemp = dv - pow(dv1-dv,2)/(dv2-2*dv1+dv);
		}
		if(fabs(da2-2*da1+da)<1E-10)
		{
			datemp = da;
		}
		else
		{
			datemp = da - pow(da1-da,2)/(da2-2*da1+da);
		}
		i++;
	} while((fabs(dvtemp-dv)>1E-6||fabs(datemp-da)>1E-6)&&i<100);
	if(i>99)
	{
		ASSERT(FALSE);
		return;
	}
	mgr.SetCurSpeedRatio(datemp);
	mgr.CalcFourQundrant(dMr*dvtemp,nSet);
}

void TripFourQundrant::CalcImpulse1(PumpTransModelMgr &mgr,int nSet)
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
	double da1 = da0;
	double dv1 = dv0;
	double da2 = da1;
	double dv2 = dv1;
	double datemp = FourModel.Calca(mgr,dTr,dNr,da0,dBf0,da0,dv0);
	double dvtemp = FourModel.Calcv(mgr,dMr,dPr,da0,dv0,nSet);
	double dfunv1 = 0;
	double dfuna1 = 0;
	double dfuna2 = FourModel.Calcfuna(mgr,dTr,dNr,da0,dBf0,da0,dv0);
	double dfunv2 = FourModel.Calcfunv(mgr,dMr,dPr,da0,dv0,nSet);
	int i=0;
	do 
	{//正割法
		da1 = da2;
		dv1 = dv2;
		da2 = datemp;
		dv2 = dvtemp;
		dfuna1 = dfuna2;
		dfunv1 = dfunv2;
		dfuna2 = FourModel.Calcfuna(mgr,dTr,dNr,da0,dBf0,da2,dv2);
		dfunv2 = FourModel.Calcfunv(mgr,dMr,dPr,da2,dv2,nSet);
		if(fabs(dfuna2-dfuna1)<1E-8||fabs(dfuna2)<1E-6)
		{
			datemp = da2;
		}
		else
		{
			datemp = da2-dfuna2*(da2-da1)/(dfuna2-dfuna1);
		}

		if(fabs(dfunv2-dfunv1)<1E-6||fabs(dfunv2)<1E-6)
		{
			dvtemp = dv2;
		}
		else
		{
			dvtemp = dv2-dfunv2*(dv2-dv1)/(dfunv2-dfunv1);
		}
		i++;
	} while((fabs(dvtemp-dv2)>1E-6||fabs(datemp-da2)>1E-6)&&i<100);
    if(i>99)
	{
		ASSERT(FALSE);
		return;
	}
	mgr.CalcFourQundrant(dMr*dvtemp,nSet);
	mgr.SetCurSpeedRatio(datemp);
}

