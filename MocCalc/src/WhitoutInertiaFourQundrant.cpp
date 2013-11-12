// WhitoutInertiaFourQundrant.cpp: implementation of the WhitoutInertiaFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WhitoutInertiaFourQundrant.h"
#include "PumpTransModelMgr.h"
#include "FourQundrantModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WhitoutInertiaFourQundrant::WhitoutInertiaFourQundrant()
{
}

WhitoutInertiaFourQundrant::~WhitoutInertiaFourQundrant()
{

}

void WhitoutInertiaFourQundrant::CalcImpulse(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet)
{
	if(mgr.IsFourQundrant())
	{
		double dRatio = mgr.GetTranData().GeTransY(dTime,dSpeedRatio,trans.StartTime());
		mgr.SetCurSpeedRatio(dRatio/100);
		CalcFourQundrant(mgr,dTime,nSet);
	}
	else
	{
		mgr.m_WhitoutInertia.CalcImpulse(mgr,trans,dTime,dSpeedRatio,nSet);
	}
}

void WhitoutInertiaFourQundrant::CalcFourQundrant(PumpTransModelMgr &mgr,double dTime,int nSet)
{
	FourQundrantModel &FourModel = *FourQundrantModel::Instance();
	MOCPumpConfig &config = mgr.GetConfig();
	MOCPumpModel &model = mgr.GetModel();
	double dMr = config.GetMr();
	double dPr = config.GetPr();
	double da = mgr.GetCurSpeedRatio();
	double dv0  = model.MassFlow()/dMr;
	double dv1 = 0;
	double dv2 = 0;
	double dv = dv0;
	double dvNew = dv0;
	int i=0;
	do 
	{
		dv = dvNew;
		dv1 = FourModel.Calcv(mgr,dMr,dPr,da,dv,nSet);
		dv2 = FourModel.Calcv(mgr,dMr,dPr,da,dv1,nSet);
		if(fabs(dv2-2*dv1+dv)<1E-6)
		{
			dvNew = dv;
		}
		else
		{
			dvNew = dv - pow(dv1-dv,2)/(dv2-2*dv1+dv);
		}
		i++;
	} while(fabs(dv-dvNew)>1E-6&&i<100);
	if(i>90)
	{
		ASSERT(FALSE);
		return;
	}
	mgr.CalcFourQundrant(dMr*dvNew,nSet);
}

