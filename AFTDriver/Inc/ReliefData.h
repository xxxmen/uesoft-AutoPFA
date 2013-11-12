// ReliefData.h: interface for the ReliefData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RELIEFDATA_H__1D9B9CC2_81D1_4716_BFCE_E4ADF95D5CB5__INCLUDED_)
#define AFX_RELIEFDATA_H__1D9B9CC2_81D1_4716_BFCE_E4ADF95D5CB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
#include "JunTransData.h"
//安全阀
class AFX_EXT_CLASS ReliefData : public JunctionData  
{
public:
	static JunctionData* Creator();
	ReliefData();
	virtual ~ReliefData();
public:
	CString Type();
	void Type(CString strValue);
	StrArray<13> Curve();
	void Curve(const StrArray<13>& strValue);
	StrArray<5> CrackExitPress();
	void CrackExitPress(const StrArray<5>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3> BasisArea();
	void BasisArea(const StrArray<3>& strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
public:
	JunTransData m_TranData;
private:
	RowObjectFace<1> m_Type;			//类型(1:内部安全阀（internal relief）2:出口安全阀（exit relief）3:内嵌安全阀（inline relief）)
	VariableFace<13,7> m_Curve;			//损失模型(0：流量系数模型，1：K系数模型3：变流量系数)
										//Y轴参数类型数字标记[]
										//Y轴参数单位[]
										//X轴参数类型数字标记[]
										//X轴参数单位[]
										//x的最大取值[]
										//曲线类型[曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）]
										//公式中参数和常量的个数[]
										//公式中的参数和常量a，b，c，d，e的值[]
	RowObjectFace<1> m_UnKown;			//1（未知）
	RowObjectFace<5> m_CrackExitPress;	//压力/水头类型0：绝对水头1：绝对压力2：水头差3：压力差
										//破裂压力\单位
										//出口压力\单位
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
	RowObjectFace<2> m_FthRestrictedFlowArea ;    //,22,feet2,两位
	
};

#endif // !defined(AFX_RELIEFDATA_H__1D9B9CC2_81D1_4716_BFCE_E4ADF95D5CB5__INCLUDED_)
