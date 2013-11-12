// MOCJunControl.h: interface for the MOCJunControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCJUNCONTROL_H__ACD6F08A_9EF7_4338_B1C0_671C8A6999FB__INCLUDED_)
#define AFX_MOCJUNCONTROL_H__ACD6F08A_9EF7_4338_B1C0_671C8A6999FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "EndListRef.h"

class MOCJunControl  
{
public:
	void ControlApply(int nControlApply);
	void PressType(int nPressType);
	void ControlType(int nControlType);
	BOOL IsControlPump();
	MOCJunControl();
	virtual ~MOCJunControl();
public:
	void CalcStm(EndListRef &jun,double dControlValue,int nSet);
	void PressControl(EndListRef &jun,EndInfo *pEnd,double dControlValue);
	void FlowControl(EndListRef &jun,double dControlValue,int nSet);
	void InPressControl(EndListRef &jun,double dControlValue);
	void OutPressControl(EndListRef &jun,double dControlValue);
	void FlowControl(EndListRef &jun,EndInfo *pEnd,double dFlow);
private:
	int     	m_nPumpControl;			//控制泵类型（0：没有控制，1:出口水头  2:出口压力 3:  入口水头  4: 入口压力 5: 体积流量 6: 质量流量
	int         m_nPressType;			//0：停滞压力1：静态压力
	int 		m_nControlApply;        //控制对应的情况设置（0：总是控制1：压力超过控制设置2：压力低于控制设置）
};
inline void MOCJunControl::ControlApply(int nControlApply)
{
	m_nControlApply = nControlApply;
}
inline void MOCJunControl::PressType(int nPressType)
{
	m_nPressType = nPressType;
}
inline void MOCJunControl::ControlType(int nControlType)
{
	m_nPumpControl = nControlType;
}
inline BOOL MOCJunControl::IsControlPump()
{
	if(m_nPumpControl==0)
		return FALSE;
	return TRUE;
}
#endif // !defined(AFX_MOCJUNCONTROL_H__ACD6F08A_9EF7_4338_B1C0_671C8A6999FB__INCLUDED_)
