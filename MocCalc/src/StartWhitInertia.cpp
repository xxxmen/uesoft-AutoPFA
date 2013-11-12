// StartWhitInertia.cpp: implementation of the StartWhitInertia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCFluid.h"
#include "StartWhitInertia.h"
#include "PumpTransModelMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StartWhitInertia::StartWhitInertia()
{
}

StartWhitInertia::~StartWhitInertia()
{

}

void StartWhitInertia::CalcImpulse(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet)
{
	IneriaStartSpeed(mgr,nSet);
	mgr.CalcImpulse(nSet);
}


double StartWhitInertia::CalcSpeed(PumpTransModelMgr &mgr,double dSpeedOld,double dMotorOld,double dMotorNew,double dFluidOld,double dFluidNew)
{
	double dT = MOCFluid::SetpTime();
	double dRotateInertia = mgr.GetInertia().RotateInertia();
	double dSpeedNew = dSpeedOld+((dMotorOld+dMotorNew)-(dFluidOld+dFluidNew))*15*dT/PI/dRotateInertia;
	return dSpeedNew;
}

double StartWhitInertia::MotorTorque(PumpTransModelMgr &mgr,double dSpeedRatio)
{//根据转速比得到电机转矩
	MOCTranData &data = mgr.GetTranData();
	return data.GeTransY(dSpeedRatio*100);
}

void StartWhitInertia::IneriaStartSpeed(PumpTransModelMgr &mgr, int nSet)
{
	EndListRef &jun = mgr.GetEndList();
	MOCPumpInertia &Inertia = mgr.GetInertia();
	MOCPumpModel &Model = mgr.GetModel();
	MOCPumpConfig &config = mgr.GetConfig();
	double dSpeedR = Inertia.Speed();
	double dSpeedOld = mgr.GetCurSpeedRatio()*dSpeedR;
	double dMass = Model.MassFlow();
	double dRisePress = Model.RisePress();
	double dFluidOld = Model.GetTorque(config,dSpeedR,dSpeedOld,dMass,dRisePress);
	double dFluidNew = dFluidOld;
	double dFluidTorque = 0;
	double dMotorOld = MotorTorque(mgr,dSpeedOld/dSpeedR);
	double dMotorNew = dMotorOld;
	double dMotorTorque = 0;
	double dSpeed1 = 0;
	double dSpeed2 = 0;
	double dSpeedNew = 0;
	double dSpeedNew1 = 0;
	int i=0;
	do 
	{//斯蒂芬森法计算（AitKen加速迭代）
		dSpeedNew1 = dSpeedNew;
		dSpeed1 = CalcSpeed(mgr,dSpeedOld,dMotorOld,dMotorNew,dFluidOld,dFluidNew);
		Model.CalcQH(jun,config,dSpeed1/dSpeedR,nSet,dMass,dMass,dRisePress);
		dFluidTorque = Model.GetTorque(config,dSpeedR,dSpeed1,dMass,dRisePress);
		dMotorTorque = MotorTorque(mgr,dSpeed1/dSpeedR);
		dSpeed2 = CalcSpeed(mgr,dSpeedOld,dMotorOld,dMotorTorque,dFluidOld,dFluidTorque);
		if(fabs(dSpeed2-2*dSpeed1+dSpeedOld)<1E-6)
		{
			dSpeedNew = dSpeedOld;
		}
		else
		{
			dSpeedNew = dSpeedOld - pow(dSpeed1-dSpeedOld,2)/(dSpeed2-2*dSpeed1+dSpeedOld);
		}
		Model.CalcQH(jun,config,dSpeedNew/dSpeedR,nSet,dMass,dMass,dRisePress);
		dFluidNew = Model.GetTorque(config,dSpeedR,dSpeedNew,dMass,dRisePress);
		dMotorNew = MotorTorque(mgr,dSpeedOld/dSpeedR);
		i++;
	} while(fabs(dSpeedNew-dSpeedNew1)>1E-6&&i<100);
	if(i>90)
	{
		ASSERT(FALSE);
		return;
	}
	mgr.SetCurSpeedRatio(dSpeedNew/dSpeedR);
}
