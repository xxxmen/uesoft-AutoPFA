// PumpPerisist.h: interface for the PumpPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPPERISIST_H__C691AFF8_E3D7_45A0_9C42_136047A0EBAD__INCLUDED_)
#define AFX_PUMPPERISIST_H__C691AFF8_E3D7_45A0_9C42_136047A0EBAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"
#include "onfigPerisist.h"

class AFX_EXT_CLASS PumpPerisist : public Junperisist  
{
public:
	static Junperisist* CreatPump();
	PumpPerisist();
	virtual ~PumpPerisist();
public:
	CString PumpType();
	void PumpType(CString strValue);
	StrArray<3>& PumpFlow();
	void PumpFlow(const StrArray<3>& strValue);
	CString SpeedRatio();
	void SpeedRatio(CString strValue);
	StrArray<4>& PumpControl();
	void PumpControl(const StrArray<4>& strValue);
	CString ControlApply();
	void ControlApply(CString strValue);
	CString PressType();
	void PressType(CString strValue);
	StrArray<4>& SubmergePump();
	void SubmergePump(const StrArray<4>& strValue);
	CString ExitCheck();
	void ExitCheck(CString strValue);
	StrArray<2>& CloseVel();
	void CloseVel(const StrArray<2>& strValue);
	CString AntiReverse();
	void AntiReverse(CString strValue);
	StrArray<3>& ReOpenPress();
	void ReOpenPress(const StrArray<3>& strValue);
	CString PumpSet();
	void PumpSet(CString strValue);
private:
	CString		m_PumpType;				//泵模型的类型0：泵曲线，1：指定体积流量2：指定质量流量
	StrArray<3>	m_PumpFlow;				//流量类型\流量大小\单位
	CString		m_SpeedRatio;			//变速泵的速率相对泵曲线的速率（1：表示100%）
	StrArray<4>	m_PumpControl;			//控制泵类型（0：没有控制，1：输出端压力/水头控制，3：输入端压力/水头控制，2：流量控制
										//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
										//控制点参数值
										//控制点参数单位
	CString		m_ControlApply;         //控制对应的情况设置（0：总是控制1：压力超过控制设置2：压力低于控制设置）
	CString		m_PressType;			//0：停滞压力1：静态压力
	StrArray<4>	m_SubmergePump;         //0：潜水泵没有选择；-1：潜水泵选择
										//压力的类型0：水头1：压力
										//吸入口压力值
										//吸入口压力单位
	CString		m_ExitCheck;			//-1：选择出口止回阀，0：没有选择出口止回阀
	StrArray<2>	m_CloseVel;		        //关闭阀门的最小速度\速度单位
	CString		m_antiReverse;			//-1：没有选择限制泵反转，0选择限制泵反转
	StrArray<3>	m_ReOpenPress;			//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值\单位
	CString     m_PumpSet;				//泵机组，并联泵：泵的数量；串连泵：负号+泵的数量,0:单泵
public:
	ConfigPerisist m_ConfigPerisist;
	TransDataPersistent m_TransPersistent;

};

/*------------------------------------------*/
inline CString PumpPerisist::PumpType()
{
	return m_PumpType;
}
inline void PumpPerisist::PumpType(CString strValue)
{
	m_PumpType = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& PumpPerisist::PumpFlow()
{
	return m_PumpFlow;
}
inline void PumpPerisist::PumpFlow(const StrArray<3>& strValue)
{
	m_PumpFlow = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::SpeedRatio()
{
	return m_SpeedRatio;
}
inline void PumpPerisist::SpeedRatio(CString strValue)
{
	m_SpeedRatio = strValue;
}
/*------------------------------------------*/
inline StrArray<4>& PumpPerisist::PumpControl()
{
	return m_PumpControl;
}
inline void PumpPerisist::PumpControl(const StrArray<4>& strValue)
{
	m_PumpControl = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::ControlApply()
{
	return m_ControlApply;
}
inline void PumpPerisist::ControlApply(CString strValue)
{
	m_ControlApply = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::PressType()
{
	return m_PressType;
}
inline void PumpPerisist::PressType(CString strValue)
{
	m_PressType = strValue;
}
/*------------------------------------------*/
inline StrArray<4>& PumpPerisist::SubmergePump()
{
	return m_SubmergePump;
}
inline void PumpPerisist::SubmergePump(const StrArray<4>& strValue)
{
	m_SubmergePump = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::ExitCheck()
{
	return m_ExitCheck;
}
inline void PumpPerisist::ExitCheck(CString strValue)
{
	m_ExitCheck = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& PumpPerisist::CloseVel()
{
	return m_CloseVel;
}
inline void PumpPerisist::CloseVel(const StrArray<2>& strValue)
{
	m_CloseVel = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::AntiReverse()
{
	return m_antiReverse;
}
inline void PumpPerisist::AntiReverse(CString strValue)
{
	m_antiReverse = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& PumpPerisist::ReOpenPress()
{
	return m_ReOpenPress;
}
inline void PumpPerisist::ReOpenPress(const StrArray<3>& strValue)
{
	m_ReOpenPress = strValue;
}
/*------------------------------------------*/
inline CString PumpPerisist::PumpSet()
{
	return m_PumpSet;
}
inline void PumpPerisist::PumpSet(CString strValue)
{
	m_PumpSet = strValue;
}
#endif // !defined(AFX_PUMPPERISIST_H__C691AFF8_E3D7_45A0_9C42_136047A0EBAD__INCLUDED_)
