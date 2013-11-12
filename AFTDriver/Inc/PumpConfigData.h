// PumpConfigData.h: interface for the PumpConfigData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPCONFIGDATA_H__3099EAFC_48FD_462B_9D09_75B414ACCE13__INCLUDED_)
#define AFX_PUMPCONFIGDATA_H__3099EAFC_48FD_462B_9D09_75B414ACCE13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObjectFace.h"

class AFX_EXT_CLASS PumpConfigData  
{
public:
	void InitObject();
	RowObject& GetObject();
	CString InitData(CString strData);
	PumpConfigData();
	virtual ~PumpConfigData();
public:
	CString Name();
	void Name(CString strValue);
	CString RPM();
	void RPM(CString strValue);
	StrArray<2> ImpellerDia();
	void ImpellerDia(const StrArray<2>& strValue);
	CString MaxFlow();
	void MaxFlow(CString strValue);
	StrArray<7> Curve1();
	void Curve1(const StrArray<7>& strValue);
	CString ID();
	void ID(CString strValue);
	StrArray<7> Curve2();
	void Curve2(const StrArray<7>& strValue);
	CString Affiniity();
	void Affiniity(CString strValue);
	StrArray<7> Curve3();
	void Curve3(const StrArray<7>& strValue);
	StrArray<3> CurveEndFlow();
	void CurveEndFlow(const StrArray<3>& strValue);
	StrArray<2> BEP();
	void BEP(const StrArray<2>& strValue);
private:
	RowObject m_Object;
	RowObjectFace<1>	m_Name;					//泵结构定义描述
	RowObjectFace<1>	m_RPM;					//泵的RPM值
	RowObjectFace<2>	m_ImpellerDia;			//泵的叶轮直径\单位
	RowObjectFace<1>	m_MaxFlow;				//泵结构泵图形的X轴最大值
	VariableFace<7,1>   m_Curve1;				//H-Q曲线类型（1：压力损失多项式，2：压力损失内插值）
												//公式中参数和常量的个数
												//公式中的参数和常量a，b，c，d，e的值
	RowObjectFace<1>	m_ID;					//标记（RDS+Num）在[RAW DATA SETS]和[RAW DATA REFERENCES]中的标记ID
	VariableFace<7,1>	m_Curve2;				//HNPSHR曲线类型（1：压力损失多项式，2：压力损失内插值）
												//公式中参数和常量的个数
												//公式中的参数和常量a，b，c，d，e的值
	RowObjectFace<1>	m_Affiniity ;			//NPSHR Affiniity Exponent At Operating Speed 的K值
	RowObjectFace<1>	m_UnKown;				//-9999
	VariableFace<7,1>	m_Curve3;				//BEP曲线类型（1：压力损失多项式，2：压力损失内插值）
												//公式中参数和常量的个数
												//公式中的参数和常量a，b，c，d，e的值
	RowObjectFace<3>	m_CurveEndFlow;			//流量类型（0：体积流量，1：质量流量）\流量值\单位
	RowObjectFace<2>	m_BEP;					//最佳功效点BEP的值\单位
};
inline RowObject& PumpConfigData::GetObject()
{
	return m_Object;
}


#endif // !defined(AFX_PUMPCONFIGDATA_H__3099EAFC_48FD_462B_9D09_75B414ACCE13__INCLUDED_)
