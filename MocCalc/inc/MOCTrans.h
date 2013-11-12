// MOCTrans.h: interface for the MOCTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRANS_H__4C1ACEF8_F59A_48F0_9AF6_B98577B724A6__INCLUDED_)
#define AFX_MOCTRANS_H__4C1ACEF8_F59A_48F0_9AF6_B98577B724A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CalcTrans;
class MOCComponentMgr;
class TransOutModel;

#include "MOCTransOutControl.h"

class MOCTrans  
{
public:
	BOOL InitTrans(MOCComponentMgr &mgr);
	void CalcImpulse(MOCComponentMgr &mgr,TransOutModel &model);
	BOOL Read(CalcTrans& data);
	MOCTrans();
	virtual ~MOCTrans();
public:
	int Frequency();
	BOOL Cavitation();
	BOOL VariableR();
	BOOL Artificial();
	double Criteria();
	double MinFlow();
	double StartTime();
private:
	double m_StartTime;				    //瞬态模拟开始时间
	double m_StopTime;					//瞬态模拟结束时间
	int m_Frequency;					//计算结果保存的频率
	int m_Cavitation;					//0：不考虑气穴存在，1：考虑存在气穴
	int m_VariableR;					//0：管道阻力系数使用稳态阻力系数，1：根据当前瞬态流量计算管道阻力系数
	int m_Artificial;					//停止运行如果检测到人工瞬变标记0：不检测人工瞬变，1：检测人工瞬变
	double m_Criteria;					//恒定流计算结果与瞬变流初始数据标准允许误差百分数（例如：0.5%用"0.5"表示）
	double m_MinFlow;					//忽略流量值标准（当流量低于标准忽略流量存在认为流量为0）
	int m_TotalSteps;					//瞬态模拟总计算步数
	double m_TimeStep;					//控制管道时间步长
	MOCTransOutControl m_outControl;

};

#endif // !defined(AFX_MOCTRANS_H__4C1ACEF8_F59A_48F0_9AF6_B98577B724A6__INCLUDED_)
