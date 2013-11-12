// PumpTransModelMgr.h: interface for the PumpTransModelMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPTRANSMODELMGR_H__84B9B403_C348_4D96_89A5_1B0AA034CC2C__INCLUDED_)
#define AFX_PUMPTRANSMODELMGR_H__84B9B403_C348_4D96_89A5_1B0AA034CC2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTrans.h"
#include "MOCPumpConfig.h"
#include "MOCFourQuadrantData.h"
#include "MOCTranData.h"
#include "MOCPumpInertia.h"
#include "MOCPumpModel.h"
#include "EndListRef.h"

#include "WhitoutInertia.h"
#include "TripWhitInertia.h"
#include "TripFourQundrant.h"
#include "StartWhitInertia.h"
#include "StartFourQundrant.h"
#include "NoTranFourQundrant.h"
#include "WhitoutInertiaFourQundrant.h"


class PumpTransModelMgr  
{
public:
	EndListRef& GetEndList();
	MOCPumpModel& GetModel();
	MOCPumpInertia& GetInertia();
	MOCFourQuadrantData& GetFourQuadrantData();
	MOCPumpConfig& GetConfig();
	MOCTranData& GetTranData();
	void CalcImpulse(MOCTrans &trans,double dTime,int nTranModel,double nSpeedRatio,int nSet);
	PumpTransModelMgr(EndListRef &jun,
					  MOCPumpModel &Model,
					  MOCPumpInertia &Inertia,
					  MOCFourQuadrantData &FourQuadrantData,
					  MOCPumpConfig &config,
					  MOCTranData &tranData);
	virtual ~PumpTransModelMgr();

private:
	EndListRef &m_jun;
	MOCPumpModel &m_Model;
	MOCPumpInertia &m_Inertia;
	MOCFourQuadrantData &m_FourQuadrantData;
	MOCPumpConfig &m_config;
	MOCTranData &m_tranData;
public:
	void CalcFourQundrant(double dMass,int nSet);
	void CalcImpulse(int nSet);
	BOOL IsFourQundrant();
	void SetCurSpeedRatio(double dSpeedRatio);
	double GetCurSpeedRatio();
	void CalcTrip(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet,int nStatus);
	void CalcStart(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet,int nStatus);
	void CalcTripFourQundrant(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet,int nStatus);
	void CalcStartFourQundrant(PumpTransModelMgr &mgr,MOCTrans &trans,double dTime,double dSpeedRatio,int nSet,int nStatus);
	void SetStmSpeed(int nTranModel,double dSpeedRatio);
	WhitoutInertia m_WhitoutInertia;
	TripWhitInertia m_TripWhitInertia;
	TripFourQundrant m_TripFourQundrant;
	StartWhitInertia m_StartWhitInertia;
	StartFourQundrant m_StartFourQundrant;
	NoTranFourQundrant m_NoTranFourQundrant;
	WhitoutInertiaFourQundrant m_WhitoutInertiaFourQundrant;

private:
	double m_dCurSpeedRatio;

};

inline EndListRef& PumpTransModelMgr::GetEndList()
{
	return m_jun;
}
inline MOCPumpModel& PumpTransModelMgr::GetModel()
{
	return m_Model;
}
inline MOCPumpInertia& PumpTransModelMgr::GetInertia()
{
	return m_Inertia;
}
inline MOCFourQuadrantData& PumpTransModelMgr::GetFourQuadrantData()
{
	return m_FourQuadrantData;
}
inline MOCPumpConfig& PumpTransModelMgr::GetConfig()
{
	return m_config;
}
inline MOCTranData& PumpTransModelMgr::GetTranData()
{
	return m_tranData;
}

inline double PumpTransModelMgr::GetCurSpeedRatio()
{
	return m_dCurSpeedRatio;
}

inline void PumpTransModelMgr::SetCurSpeedRatio(double dSpeedRatio)
{
	m_dCurSpeedRatio = dSpeedRatio;
}

#endif // !defined(AFX_PUMPTRANSMODELMGR_H__84B9B403_C348_4D96_89A5_1B0AA034CC2C__INCLUDED_)
