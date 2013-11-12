// ValvePerisist.h: interface for the ValvePerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALVEPERISIST_H__EF0383F6_54E6_4192_BFC8_E0830A299C27__INCLUDED_)
#define AFX_VALVEPERISIST_H__EF0383F6_54E6_4192_BFC8_E0830A299C27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

 class AFX_EXT_CLASS ValvePerisist : public Junperisist  
{
public:
	static Junperisist* CreatValve();
	ValvePerisist();
	virtual ~ValvePerisist();
public:
	CString Type();
	void Type(CString strValue);
	StrArray<13>& Curve();
	void Curve(const StrArray<13>& strValue);
	StrArray<3>& ExitPress();
	void ExitPress(const StrArray<3>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3>& BasisArea();
	void BasisArea(const StrArray<3>& strValue);
private:
	CString		 m_Type;						//类型(0：普通阀门，-1：选中阀门为出口阀门)
    StrArray<13> m_Curve;						//损失模型曲线。
	StrArray<3>  m_ExitPress;					//出口压力类型0：水头1：压力
												//出口压力\单位
	CString		 m_KOrCv;						//K或Cv系数值
	StrArray<3>  m_BasisArea;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
												//值/单位
public:
	TransDataPersistent m_TransPersistent;
};
/*------------------------------------------*/
inline CString ValvePerisist::Type()
{
	return m_Type;
}
inline void ValvePerisist::Type(CString strValue)
{
	m_Type = strValue;
}
/*------------------------------------------*/
inline StrArray<13>& ValvePerisist::Curve()
{
	return m_Curve;
}
inline void ValvePerisist::Curve(const StrArray<13>& strValue)
{
	m_Curve = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& ValvePerisist::ExitPress()
{
	return m_ExitPress;
}
inline void ValvePerisist::ExitPress(const StrArray<3>& strValue)
{
	m_ExitPress = strValue;
}

/*------------------------------------------*/
inline CString ValvePerisist::KOrCv()
{
	return m_KOrCv;
}
inline void ValvePerisist::KOrCv(CString strValue)
{
	m_KOrCv = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& ValvePerisist::BasisArea()
{
	return m_BasisArea;
}
inline void ValvePerisist::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea = strValue;
}
#endif // !defined(AFX_VALVEPERISIST_H__EF0383F6_54E6_4192_BFC8_E0830A299C27__INCLUDED_)
