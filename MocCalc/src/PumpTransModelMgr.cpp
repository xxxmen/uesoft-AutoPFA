// PumpTransModelMgr.cpp: implementation of the PumpTransModelMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PumpTransModelMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpTransModelMgr::PumpTransModelMgr(EndListRef &jun,
					  MOCPumpModel &Model,
					  MOCPumpInertia &Inertia,
					  MOCFourQuadrantData &FourQuadrantData,
					  MOCPumpConfig &config,
					  MOCTranData &tranData)
					  :m_jun(jun)
					  ,m_Model(Model)
					  ,m_Inertia(Inertia)
					  ,m_FourQuadrantData(FourQuadrantData)
					  ,m_config(config)
					  ,m_tranData(tranData)
					  ,m_TripWhitInertia()
{
	m_dCurSpeedRatio = 0;
}

PumpTransModelMgr::~PumpTransModelMgr()
{

}

// 	7,"正常运行-四象限特性曲线"
// 	1,"非惯性"
// 	2,"惯性停泵不存在倒流或反转"
// 	3,"惯性停泵-四象限特性曲线"
// 	5,"惯性启动不存在倒流或反转"
// 	6,"惯性启动-四象限特性曲线"
// 	4,"已知转速启动-四象限特性曲线"
void PumpTransModelMgr::CalcImpulse(MOCTrans &trans, double dTime,int nTranModel,double dSpeedRatio,int nSet)
{
	if(m_tranData.IsIgnoreTrans())//忽略瞬变数据
		m_Model.CalcStm(m_jun,m_config,dSpeedRatio,nSet);
	int nStatus = m_tranData.TrigerStatus(dTime,trans.StartTime());
	switch(nTranModel)
	{
	case 1:
		m_WhitoutInertia.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
		break;
	case 2:
		CalcTrip(*this,trans,dTime,dSpeedRatio,nSet,nStatus);
		break;
	case 3:
		CalcTripFourQundrant(*this,trans,dTime,dSpeedRatio,nSet,nStatus);
	    break;
	case 4:
		m_WhitoutInertiaFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	case 5:
		CalcStart(*this,trans,dTime,dSpeedRatio,nSet,nStatus);
		break;
	case 6:
		CalcStartFourQundrant(*this,trans,dTime,dSpeedRatio,nSet,nStatus);
	    break;
	case 7:
		m_NoTranFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
}



void PumpTransModelMgr::SetStmSpeed(int nTranModel,double dSpeedRatio)
{
	switch(nTranModel)
	{
	case 1:
	case 2:
	case 3:
	case 7:
		m_dCurSpeedRatio = dSpeedRatio;
	    break;
	case 4:
	case 5:
	case 6:
		m_dCurSpeedRatio = 0;
	    break;
	default:
		m_dCurSpeedRatio = dSpeedRatio;
	    break;
	}
}

void PumpTransModelMgr::CalcTrip(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet, int nStatus)
{
	m_Model.ExitCheck(TRUE);
	switch(nStatus)
	{
	case 0:
		m_Model.CalcStm(m_jun,m_config,dSpeedRatio,nSet);
		break;
	case 1:
		m_TripWhitInertia.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
		break;
	case 2:
		m_StartWhitInertia.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
}

void PumpTransModelMgr::CalcStart(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet, int nStatus)
{
	m_Model.ExitCheck(TRUE);
	switch(nStatus)
	{
	case 0:
		m_Model.CalcStm(m_jun,m_config,dSpeedRatio,nSet);
		break;
	case 1:
		m_StartWhitInertia.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
		break;
	case 2:
		m_TripWhitInertia.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
}

void PumpTransModelMgr::CalcTripFourQundrant(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet, int nStatus)
{
	switch(nStatus)
	{
	case 0:
		m_Model.CalcStm(m_jun,m_config,dSpeedRatio,nSet);
		break;
	case 1:
		m_TripFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
		break;
	case 2:
		m_StartFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
}

void PumpTransModelMgr::CalcStartFourQundrant(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet, int nStatus)
{
	switch(nStatus)
	{
	case 0:
		m_Model.CalcStm(m_jun,m_config,dSpeedRatio,nSet);
		break;
	case 1:
		m_StartFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
		break;
	case 2:
		m_TripFourQundrant.CalcImpulse(*this,trans,dTime,dSpeedRatio,nSet);
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
}
BOOL PumpTransModelMgr::IsFourQundrant()
{
	double dMaxMass = m_config.MaxMassFlow();
	double dMass = m_Model.MassFlow();
	double d1 = dMass - dMaxMass;
	if(d1>0 || dMass<1)
		return TRUE;
	if(m_dCurSpeedRatio<0)
		return TRUE;
	return FALSE;
}


void PumpTransModelMgr::CalcImpulse(int nSet)
{
	m_Model.CalcImpulse(m_jun,m_config,m_dCurSpeedRatio,nSet);
}

void PumpTransModelMgr::CalcFourQundrant(double dMass, int nSet)
{
	m_Model.MassFlow(dMass);
	if(nSet>0)
	{//并联泵
		dMass = dMass * nSet;
	}
	m_jun.FlowStrategy(dMass);
}


