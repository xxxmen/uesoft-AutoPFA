// PumpData.h: interface for the PumpData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPDATA_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_)
#define AFX_PUMPDATA_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
#include "PumpConfig.h"
#include "JunTransData.h"

class AFX_EXT_CLASS PumpData : public JunctionData  
{
public:
	static JunctionData* Creator();
	PumpData();
	virtual ~PumpData();
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

	RowObjectFace<1> m_Fth1;                    //config后需删除一个字符0
	RowObjectFace<8> m_Fth2;                    //fth粘度修正项位置改放了8项未知值,粘度修正则放在潜水泵选择项的位置了
//	RowObjectFace<26> m_Fth5;                   //瞬变数据前多出28项,但第27项为并/串联泵数据，28项为多出的一个泵曲线时设置的叶轮修正值1001
	RowObjectFace<5> m_Fth3;                //0,0,0,0,None, 未知
	RowObjectFace<1> m_Fth4;                //Cost面板控制 （0:Cost面板不激活 2:Cost面板激活)
	RowObjectFace<4> m_Fth5;                //未知("None,0,0,0")
	RowObjectFace<2> m_Fth6;                //正常功率值及单位
	RowObjectFace<2> m_Fth7;                //正常NPSHR值及单位
	RowObjectFace<4> m_Fth8;                //未知("NA,1,None,1")
	RowObjectFace<1> m_Fth9;                //前两列有几行填有数据 默认为0 不为0时17项后面会多出2*n项用来存前两列数据
	RowObjectFace<2> m_Fth10;               //前两列的单位
	TableData<1>     m_FthBefTwoRowArray;	//根据m_Fth10项的值会相应的多出2*n项用来存前两列数据
	RowObjectFace<2> m_Fth11;               //未知 None 1
	RowObjectFace<1> m_Fth12;               //后两列有几行填有数据 默认为0 不为0时17项后面会多出2*n项用来存前两列数据
	RowObjectFace<2> m_Fth13;               //后两列的单位
	TableData<1>     m_FthAftTwoRowArray;		    //根据m_Fth12项的值会相应的多出2*n项用来存后两列数据

	RowObjectFace<1> m_Impeller;                //28项为多出的一个泵曲线时设置的叶轮修正值1001
};

#endif // !defined(AFX_PUMPDATA_H__85B00E3B_4168_4A88_A0C0_5A58227C933E__INCLUDED_)
