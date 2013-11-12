// MOCPumpModel.h: interface for the MOCPumpModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPUMPMODEL_H__5F50A6E8_37D7_41EE_9A94_9A0FBCC7B618__INCLUDED_)
#define AFX_MOCPUMPMODEL_H__5F50A6E8_37D7_41EE_9A94_9A0FBCC7B618__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "EndListRef.h"
#include "MOCPumpConfig.h"

class CalcPump;

class MOCPumpModel  
{
public:
	void Read(CalcPump *pData);
	MOCPumpModel();
	virtual ~MOCPumpModel();
public:
	double SunCpm(EndListRef &jun);
	double SunBpm(EndListRef &jun);
	double GetTorque(MOCPumpConfig &config,double dSpeedR,double dSpeed,double dMass,double dPress);
	double RisePress();
	void RisePress(double dRisePress,int nSet =1);
	double MassFlow();
	void MassFlow(double dMass,int nSet =1);
	BOOL IsExitCheck();
	void ExitCheck(BOOL bCheck);
	BOOL IsAntiReverse();
	BOOL IsSubmerge();
	double SuctionPress();
	void CalcStm(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	void CalcImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	void CalcQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress);
private:
	double CalcParallImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	double CalcSeriseImpulse(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	double CalcParall(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	double CalcSerise(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet);
	double CalcImpulse(EndListRef &jun,double dPress,double dMass);
	double Calc(EndListRef &jun,double dPress);
	double CalcMass(EndListRef &jun,double dPress);
	void CalcParallQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress);
	void CalcSeriseQH(EndListRef &jun,MOCPumpConfig &config,double dSpeedRatio,int nSet,double dOldMass,double &dMass,double &dPress);
	
private:
	double GetPower(MOCPumpConfig &config,double dSpeedRatio,double dMass,double dPress);
	int 		m_bAntiReverse;			//1：选择限制泵反转，0没有选择限制泵反转
	int 		m_bExitCheck;			//1：选择出口止回阀，0：没有选择出口止回阀
	BOOL        m_bExitCheckOpen;
	double		m_dCloseVel;		    //关闭阀门的最小速度
	double  	m_dReOpenPress;			//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值
	int        	m_bSelSubmerge;         //0：潜水泵没有选择；1：潜水泵选择
	double      m_dSuctionPress;		//吸入口压力值
	double      m_dMassFlow;
	double      m_dTranRisePress;

};

inline BOOL MOCPumpModel::IsSubmerge()
{
	if(m_bSelSubmerge==1)
		return TRUE;
	return FALSE;
}
inline double MOCPumpModel::SuctionPress()
{
	return m_dSuctionPress;
}
inline BOOL MOCPumpModel::IsAntiReverse()
{
	if(m_bAntiReverse==1)
		return TRUE;
	return FALSE;
}
inline BOOL MOCPumpModel::IsExitCheck()
{
	if(m_bExitCheck==1)
		return TRUE;
	return FALSE;
}
inline void MOCPumpModel::ExitCheck(BOOL bCheck)
{
	if(bCheck)
	{
		m_bExitCheck = 1;
	}
	else
	{
	    m_bExitCheck = 0;
	}

}
#endif // !defined(AFX_MOCPUMPMODEL_H__5F50A6E8_37D7_41EE_9A94_9A0FBCC7B618__INCLUDED_)
