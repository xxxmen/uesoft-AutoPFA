// heckValveData.h: interface for the CheckValveData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HECKVALVEDATA_H__9A86B333_4BC0_4B37_AD76_EBFB375120BF__INCLUDED_)
#define AFX_HECKVALVEDATA_H__9A86B333_4BC0_4B37_AD76_EBFB375120BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
#include "JunTransData.h"
//止回阀
class AFX_EXT_CLASS CheckValveData : public JunctionData  
{
public:
	static JunctionData* Creator();
	CheckValveData();
	virtual ~CheckValveData();
public:
	StrArray<13> Curve();
	void Curve(const StrArray<13>& strValue);
	StrArray<3> ReOpenPress();
	void ReOpenPress(const StrArray<3>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3> BasisArea();
	void BasisArea(const StrArray<3>& strValue);
	StrArray<2> CloseVel();
	void CloseVel(const StrArray<2>& strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
public:
	JunTransData m_TranData;
private:
	VariableFace<13,7> m_Curve;			//损失模型(0：流量系数模型，1：K系数模型)
										//Y轴参数类型数字标记[]
										//Y轴参数单位[]
										//X轴参数类型数字标记[]
										//X轴参数单位[]
										//x的最大取值[]
										//曲线类型[曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）]
										//公式中参数和常量的个数[]
										//公式中的参数和常量a，b，c，d，e的值[]
	RowObjectFace<1> m_UnKown;			//0（未知）//参考AssignFlowData::m_InitPress
	RowObjectFace<3> m_ReOpenPress;		//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值\单位
	RowObjectFace<1> m_KOrCv;			//K或Cv系数值
	RowObjectFace<3> m_BasisArea;		//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
										//值
										//单位
	//JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
										//没有RowObjectFace<1> m_Repeat1;
										//没有RowObjectFace<1> m_Repeat2
										//没有RowObjectFace<1> m_TranType;
										//没有RowObjectFace<8> m_TranTriger1; 
										//没有RowObjectFace<8> m_TranTriger2; 
	RowObjectFace<2> m_CloseVel;		//关闭阀门的最小速度\速度单位
	RowObjectFace<2> m_FthRestrictedArea; //值/单位；
	RowObjectFace<9> m_FthUnknown;		//None,2,0,inches,None,None,0,0,NA,
	


};

#endif // !defined(AFX_HECKVALVEDATA_H__9A86B333_4BC0_4B37_AD76_EBFB375120BF__INCLUDED_)
