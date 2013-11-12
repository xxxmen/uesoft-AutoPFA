// onfigItemPerisist.h: interface for the ConfigItemPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONFIGITEMPERISIST_H__262439FB_E49F_484B_ABFB_422882510F26__INCLUDED_)
#define AFX_ONFIGITEMPERISIST_H__262439FB_E49F_484B_ABFB_422882510F26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TwoDTablePersistent.h"


class AFX_EXT_CLASS ConfigItemPerisist  
{
public:
	ConfigItemPerisist();
	virtual ~ConfigItemPerisist();
    ConfigItemPerisist(const ConfigItemPerisist &ref);
	ConfigItemPerisist& operator=(const ConfigItemPerisist &ref);
public:
	CString Name();
	void Name(CString strValue);
	CString RPM();
	void RPM(CString strValue);
	StrArray<2>& ImpellerDia();
	void ImpellerDia(const StrArray<2>& strValue);
	CString MaxFlow();
	void MaxFlow(CString strValue);
	StrArray<7>& Curve1();
	void Curve1(const StrArray<7>& strValue);
	CString ID();
	void ID(CString strValue);
	StrArray<7>& Curve2();
	void Curve2(const StrArray<7>& strValue);
	CString Affiniity();
	void Affiniity(CString strValue);
	StrArray<7>& Curve3();
	void Curve3(const StrArray<7>& strValue);
	StrArray<3>& CurveEndFlow();
	void CurveEndFlow(const StrArray<3>& strValue);
	StrArray<2>& BEP();
	void BEP(const StrArray<2>& strValue);
public:
	RawDataPersistent m_RawData;
private:
	CString		 m_Name;				//泵结构定义描述
	CString		 m_RPM;					//泵的RPM值
	StrArray<2>  m_ImpellerDia;			//泵的叶轮直径\单位
	CString		 m_MaxFlow;				//泵结构泵图形的X轴最大值
	StrArray<7>  m_Curve1;				//H-Q曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	CString		 m_ID;					//标记（RDS+Num）在[RAW DATA SETS]和[RAW DATA REFERENCES]中的标记ID
	StrArray<7>  m_Curve2;				//HNPSHR曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	CString		 m_Affiniity ;			//NPSHR Affiniity Exponent At Operating Speed 的K值
	StrArray<7>  m_Curve3;				//BEP曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	StrArray<3>  m_CurveEndFlow;		//流量类型（0：体积流量，1：质量流量）\流量值\单位
	StrArray<2>  m_BEP;					//最佳功效点BEP的值\单位

};

/*------------------------------------------*/
inline CString ConfigItemPerisist::Name()
{
	return m_Name;
}
inline void ConfigItemPerisist::Name(CString strValue)
{
	m_Name = strValue;
}
/*------------------------------------------*/
inline CString ConfigItemPerisist::RPM()
{
	return m_RPM;
}
inline void ConfigItemPerisist::RPM(CString strValue)
{
	m_RPM = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& ConfigItemPerisist::ImpellerDia()
{
	return m_ImpellerDia;
}
inline void ConfigItemPerisist::ImpellerDia(const StrArray<2>& strValue)
{
	m_ImpellerDia = strValue;
}
/*------------------------------------------*/
inline CString ConfigItemPerisist::MaxFlow()
{
	return m_MaxFlow;
}
inline void ConfigItemPerisist::MaxFlow(CString strValue)
{
	m_MaxFlow = strValue;
}
/*------------------------------------------*/
inline StrArray<7>& ConfigItemPerisist::Curve1()
{
	return m_Curve1;
}
inline void ConfigItemPerisist::Curve1(const StrArray<7>& strValue)
{
	m_Curve1 = strValue;
}
/*------------------------------------------*/
inline CString ConfigItemPerisist::ID()
{
	return m_ID;
}
inline void ConfigItemPerisist::ID(CString strValue)
{
	m_ID = strValue;
}
/*------------------------------------------*/
inline StrArray<7>& ConfigItemPerisist::Curve2()
{
	return m_Curve2;
}
inline void ConfigItemPerisist::Curve2(const StrArray<7>& strValue)
{
	m_Curve2 = strValue;
}
/*------------------------------------------*/
inline CString ConfigItemPerisist::Affiniity()
{
	return m_Affiniity;
}
inline void ConfigItemPerisist::Affiniity(CString strValue)
{
	m_Affiniity = strValue;
}
/*------------------------------------------*/
inline StrArray<7>& ConfigItemPerisist::Curve3()
{
	return m_Curve3;
}
inline void ConfigItemPerisist::Curve3(const StrArray<7>& strValue)
{
	m_Curve3 = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& ConfigItemPerisist::CurveEndFlow()
{
	return m_CurveEndFlow;
}
inline void ConfigItemPerisist::CurveEndFlow(const StrArray<3>& strValue)
{
	m_CurveEndFlow = strValue;
}

/*------------------------------------------*/
inline StrArray<2>& ConfigItemPerisist::BEP()
{
	return m_BEP;
}
inline void ConfigItemPerisist::BEP(const StrArray<2>& strValue)
{
	m_BEP = strValue;
}

#endif // !defined(AFX_ONFIGITEMPERISIST_H__262439FB_E49F_484B_ABFB_422882510F26__INCLUDED_)
