// FourQundrantModel.cpp: implementation of the FourQundrantModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FourQundrantModel.h"
#include "PumpTransModelMgr.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FourQundrantModel::FourQundrantModel()
{

}

FourQundrantModel::~FourQundrantModel()
{

}

FourQundrantModel* FourQundrantModel::Instance()
{
	static FourQundrantModel Model;
	return &Model;
}

double FourQundrantModel::Calca(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dB0,double da,double dv)
{
	EndListRef &jun = mgr.GetEndList();
	MOCPumpModel &model = mgr.GetModel();
	double dT = MOCFluid::SetpTime();
	double dRotateInertia = mgr.GetInertia().RotateInertia();
	double dB = CalcdBf(mgr.GetFourQuadrantData(),da,dv);
	double dTemp1 = -(dB+dB0) * (dTr*15*dT) / (dRotateInertia*dNr*PI) + da0;
	return dTemp1;
}
double FourQundrantModel::Calca(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dBf0,double dBm0,double dBm,double da,double dv)
{
	MOCPumpModel &model = mgr.GetModel();
	double dT = MOCFluid::SetpTime();
	double dRotateInertia = mgr.GetInertia().RotateInertia();
	double dBf = CalcdBf(mgr.GetFourQuadrantData(),da,dv);
	double dTemp1 = -(dBf+dBf0-dBm0-dBm) * (dTr*15*dT) / (dRotateInertia*dNr*PI) + da0;
	return dTemp1;
}

//已知转速四象限模型
double FourQundrantModel::Calcv(PumpTransModelMgr &mgr,double dMr,double dPr,double da,double dv,int nSet)
{
	if(nSet>0)
	{//并联泵
		dMr = dMr * nSet;
	}
	else
	{//串联泵
		dPr = dPr * fabs( (double)nSet);
	}
	EndListRef &jun = mgr.GetEndList();
	MOCPumpModel &model = mgr.GetModel();
	double dCpm = model.SunCpm(jun);
	double dBpm = model.SunBpm(jun);
	double dh =  CalcdH(mgr.GetFourQuadrantData(),da,dv);
	double dTemp = dCpm + dPr*dh;
	return (dTemp/(dMr*dBpm));
}

double FourQundrantModel::CalcdBf(MOCFourQuadrantData &data,double da,double dv)
{
	double dFB = data.GetFB(da,dv);
	return dFB*(pow(da,2)+pow(dv,2));
}

double FourQundrantModel::CalcdH(MOCFourQuadrantData &data,double da,double dv)
{
	double dFH = data.GetFH(da,dv);
	return dFH*(pow(da,2)+pow(dv,2));
}

double FourQundrantModel::Calcfuna(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dB0,double da,double dv)
{
	EndListRef &jun = mgr.GetEndList();
	MOCPumpModel &model = mgr.GetModel();
	double dT = MOCFluid::SetpTime();
	double dRotateInertia = mgr.GetInertia().RotateInertia();
	double dB = CalcdBf(mgr.GetFourQuadrantData(),da,dv);
	return (dB+dB0) + (dRotateInertia*dNr*PI)*(da-da0)/(dTr*15*dT);
}

//已知转速四象限模型
double FourQundrantModel::Calcfunv(PumpTransModelMgr &mgr,double dMr,double dPr,double da,double dv,int nSet)
{
	if(nSet>0)
	{//并联泵
		dMr = dMr * nSet;
	}
	else
	{//串联泵
		dPr = dPr * fabs((double)nSet);
	}
	EndListRef &jun = mgr.GetEndList();
	MOCPumpModel &model = mgr.GetModel();
	double dCpm = model.SunCpm(jun);
	double dBpm = model.SunBpm(jun);
	double dh =  CalcdH(mgr.GetFourQuadrantData(),da,dv);
	return dCpm + dPr*dh -dv*dMr*dBpm;
}