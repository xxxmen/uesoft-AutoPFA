// MOCPump.h: interface for the MOCPump class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPUMP_H__6827635F_F264_448A_A3B3_5E6E109A714C__INCLUDED_)
#define AFX_MOCPUMP_H__6827635F_F264_448A_A3B3_5E6E109A714C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCJunControl.h"
#include "PumpTransModelMgr.h"

class MOCPump : public MOCJun  
{
public:
	double GetSpeed();
	void UpdataEnd();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCPump();
	virtual ~MOCPump();

private:
	void CalcStm();
	BOOL InitEndInfo();
	BOOL InitTranData(MOCComponentMgr &mgr);

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	void TranControlValue(int nControl);	
	
private:
	void Result(JunTranOut &out, int nStep);
	int 		m_nPumpType;			//泵模型的类型0：泵曲线，1：指定体积流量2：指定质量流量
	double   	m_dPumpFlow;			//流量大小
	int         m_nPumpSet;				//泵机组，并联泵：泵的数量；串连泵：负号+泵的数量,1:单泵
	int			m_nTranModel;			//泵瞬变模型
	double		m_dSpeedRatio;			//变速泵的速率相对泵曲线的速率（1：表示100%）
	double   	m_dControlValue;		//控制点参数值
	MOCPumpModel m_Model;
	MOCJunControl m_Control;
	MOCPumpInertia m_Inertia;
	MOCFourQuadrantData m_FourQuadrantData;
	MOCPumpConfig m_config;
	MOCTranData m_tranData;
	PumpTransModelMgr m_mgr;
};

#endif // !defined(AFX_MOCPUMP_H__6827635F_F264_448A_A3B3_5E6E109A714C__INCLUDED_)
