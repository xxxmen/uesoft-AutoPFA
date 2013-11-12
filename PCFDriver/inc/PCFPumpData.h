// PCFPumpData.h: interface for the PCFPumpData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPUMPDATA_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_)
#define AFX_PCFPUMPDATA_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//泵
#include "Junction.h"
#include "PumpConfig.h"
#include "JunTransData.h"
#include "PCFJun.h"
#include "RowObjectFace.h"
#include "RowObject.h"
class AFX_EXT_CLASS PCFPumpData : public PCFJun
{
public:
	static PCFJun* Creator();
	PCFPumpData();
	virtual ~PCFPumpData();
public:
	CString PumpType();
	void PumpType(CString strValue);
	StrArray<3> PumpFlow();
	void PumpFlow(const StrArray<3>& strValue);
	CString SpeedRatio();
	void SpeedRatio(CString strValue);
	StrArray<4> PumpControl();
	void PumpControl(const StrArray<4>& strValue);
	CString ControlApply();
	void ControlApply(CString strValue);
	CString PressType();
	void PressType(CString strValue);
	StrArray<4> SubmergePump();
	void SubmergePump(const StrArray<4>& strValue);
	CString ExitCheck();
	void ExitCheck(CString strValue);
	StrArray<2> CloseVel();
	void CloseVel(const StrArray<2>& strValue);
	CString AntiReverse();
	void AntiReverse(CString strValue);
	StrArray<3> ReOpenPress();
	void ReOpenPress(const StrArray<3>& strValue);
	CString PumpSet();
	void PumpSet(CString strValue);

	
private:
	void AppendArray();
	void InitExtra(CString strData);
	void Init( const CStringArray& wordArray );
// 	void Init(CString strData);
	virtual CString GetDefaultData();
public:
	PumpConfig       m_Config;
	JunTransData m_TranData;
private:
	RowObjectFace<1> m_PumpType;				//泵模型的类型0：泵曲线，1：指定体积流量2：指定质量流量
	RowObjectFace<3> m_PumpFlow;				//流量类型\流量大小\单位
	
	RowObjectFace<1> m_SpeedRatio;				//变速泵的速率相对泵曲线的速率（1：表示100%）
	RowObjectFace<1> m_UnKown3;					////0（未知）参考控制阀门控制设置
	RowObjectFace<4> m_PumpControl;				//控制泵类型（0：没有控制，1：输出端压力/水头控制，3：输入端压力/水头控制，2：流量控制
	//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
	//控制点参数值
	//控制点参数单位
	RowObjectFace<1> m_ControlApply;            //控制对应的情况设置（0：总是控制1：压力超过控制设置2：压力低于控制设置）
	RowObjectFace<4> m_ViscosCorrection;		//粘度修正（0：不使用粘度修正，-1：使用粘度修正）
	//压力修正选择（0：假定计算流量在BEF；1：用户输入流量最佳效率点）
	//用户输入的值
	//用户输入的值的单位
	RowObjectFace<1> m_NPSHRefValule;			//NPSH参考
	RowObjectFace<1> m_PressType;				//0：停滞压力1：静态压力
	RowObjectFace<4> m_SubmergePump;           	//0：潜水泵没有选择；-1：潜水泵选择
	//压力的类型0：水头1：压力
	//吸入口压力值
	//吸入口压力单位
	RowObjectFace<1> m_ExitCheck;				//-1：选择出口止回阀，0：没有选择出口止回阀
	//	RowObjectFace<1> m_TranModel;				//瞬变模型
	//	RowObjectFace<2> m_RotateInertia;			//转动惯量（泵，电动机，流体）\转动惯量单位
	//	RowObjectFace<1> m_Speed;					//泵额定转速
	RowObjectFace<1> m_PumpSet;					//并联泵：泵的数量；串连泵：负号+泵的数量
	//	RowObjectFace<3> m_FourQuadrantData;        //四象限数据源标记\四象限数据的数量\角度选择0：1：
	//	RowObjectFace<6> m_UnKown4;					//None,2,0,None,,,
	RowObjectFace<2> m_CloseVel;		        //关闭阀门的最小速度\速度单位
	RowObjectFace<1> m_antiReverse;				//-1：没有选择限制泵反转，0选择限制泵反转
	RowObjectFace<3> m_ReOpenPress;				//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值\单位
	
	typedef CArray<RowObject*,RowObject*>RowArrayRef;
	RowArrayRef   m_RowArray;
};

#endif // !defined(AFX_PCFPumpData_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_)
