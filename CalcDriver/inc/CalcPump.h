// CalcPump.h: interface for the CalcPump class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPUMP_H__92863BD5_5E5F_480C_BE18_CFCC57438D38__INCLUDED_)
#define AFX_CALCPUMP_H__92863BD5_5E5F_480C_BE18_CFCC57438D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"
#include "CalcPumpConfig.h"

class AFX_EXT_CLASS CalcPump : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcPump();
	virtual ~CalcPump();
public:
	void FourQuadrantData(const ListImp<StrArray<3> >& ref);
	void AntiReverse(int nValue);
	void ExitCheck(int nValue);
	void CloseVel(double dValue);
	void PressType(int nValue);
	void SelSubmerge(int nValue);
	void SubmergePressType(int nValue);
	void SuctionPress(double dValue);
	void PumpSet(int nValue);
	void TranModel(int nValue);
	void PumpType(int nValue);
	void PumpFlow(double dValue);
	void SpeedRatio(double dValue);
	void PumpControl(int nValue);
	void ControlType(int nValue);
	void ControlValue(double dValue);
	void ControlApply(int nValue);
	void ReOpenPressType(int nValue);
	void ReOpenPress(double dValue);
	void RotateInertia(double dValue);
	void Speed(double dValue);
	void FourQuadrantAngle(int nValue);

	ListImp<StrArray<2> > FHData();
	ListImp<StrArray<2> > FBData();
	int AntiReverse();
	int ExitCheck();
	double CloseVel();
	int PressType();
	int SelSubmerge();
	int SubmergePressType();
	double SuctionPress();
	int PumpSet();
	int TranModel();
	int PumpType();
	double PumpFlow();
	double SpeedRatio();
	int PumpControl();
	int ControlType();
	double ControlValue();
	int ControlApply();
	int ReOpenPressType();
	double ReOpenPress();
	double RotateInertia();
	double Speed();
	int FourQuadrantAngle();
private:
	double      m_dNPRS;				//气蚀余量参考高程
	int         m_bSelViscosCor;		//粘度修正（0：不使用粘度修正，-1：使用粘度修正）
    int         m_nBEFType;				//压力修正选择（0：假定计算流量在BEF；1：用户输入流量最佳效率点）
	double      m_dBEFFlow;				//用户输入的值
	int 		m_bAntiReverse;			//1：选择限制泵反转，0没有选择限制泵反转
	int 		m_bExitCheck;			//1：选择出口止回阀，0：没有选择出口止回阀
	double		m_dCloseVel;		    //关闭阀门的最小速度
	int         m_nReOpenPressType;
	double  	m_dReOpenPress;			//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值
	int        	m_bSelSubmerge;         //0：潜水泵没有选择；1：潜水泵选择
	int         m_nSubmergePressType;	//压力的类型0：水头1：压力
	double      m_dSuctionPress;		//吸入口压力值
	int         m_nPumpSet;				//泵机组，并联泵：泵的数量；串连泵：负号+泵的数量,0:单泵
	int			m_nTranModel;			//泵瞬变模型
	int 		m_nPumpType;			//泵模型的类型0：泵曲线，1：指定体积流量2：指定质量流量
	double   	m_dPumpFlow;			//流量大小
	double		m_dSpeedRatio;			//变速泵的速率相对泵曲线的速率（1：表示100%）
	int     	m_nPumpControl;			//控制泵类型（0：没有控制，（0：没有控制，1:出口水头  2:出口压力 3:  入口水头  4: 入口压力 5: 体积流量 6: 质量流量
	int     	m_nControlType;			//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
	int         m_nPressType;			//0：停滞压力1：静态压力
	double   	m_dControlValue;		//控制点参数值
	int 		m_nControlApply;         //控制对应的情况设置（0：总是控制1：压力超过控制设置2：压力低于控制设置）
	double      m_dRotateInertia;		//转动惯量（泵，电动机，流体）\转动惯量单位
	double      m_dSpeed;				//泵额定转速
	int         m_nFourQuadrantAngle;   //角度选择0：1
	CalcTable<3> m_FourQuadrantData;   //<FH,FB>
public:
	CalcTransData m_TranData;
	CalcPumpConfig m_Config;
};

#endif // !defined(AFX_CALCPUMP_H__92863BD5_5E5F_480C_BE18_CFCC57438D38__INCLUDED_)
