// CheckPerisist.h: interface for the CheckPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKPERISIST_H__9B18840A_FDB9_4018_9E01_D4B63B577B93__INCLUDED_)
#define AFX_CHECKPERISIST_H__9B18840A_FDB9_4018_9E01_D4B63B577B93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS CheckPerisist : public Junperisist  
{
public:
	static Junperisist* CreatCheckValve();
	CheckPerisist();
	virtual ~CheckPerisist();
public:
	StrArray<13>& Curve();
	void Curve(const StrArray<13>& strValue);
	StrArray<3>& ReOpenPress();
	void ReOpenPress(const StrArray<3>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3>& BasisArea();
	void BasisArea(const StrArray<3>& strValue);
	StrArray<2>& CloseVel();
	void CloseVel(const StrArray<2>& strValue);
	
private:
	StrArray<13> m_Curve;						//损失模型曲线。
	StrArray<3>  m_ReOpenPress;					//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值\单位;					//出口压力类型0：水头1：压力
												//压力\单位
	CString		 m_KOrCv;						//K或Cv系数值
	StrArray<3>	 m_BasisArea;					//损失模型面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
												//值/单位
	StrArray<2>  m_CloseVel;					//关闭阀门的最小正向速度\速度单位
public:
	TransDataPersistent m_TransPersistent;

};
/*------------------------------------------*/
inline StrArray<13>& CheckPerisist::Curve()
{
	return m_Curve;
}
inline void CheckPerisist::Curve(const StrArray<13>& strValue)
{
	m_Curve = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& CheckPerisist::ReOpenPress()
{
	return m_ReOpenPress;
}
inline void CheckPerisist::ReOpenPress(const StrArray<3>& strValue)
{
	m_ReOpenPress = strValue;
}
/*------------------------------------------*/
inline CString CheckPerisist::KOrCv()
{
	return m_KOrCv;
}
inline void CheckPerisist::KOrCv(CString strValue)
{
	m_KOrCv = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& CheckPerisist::BasisArea()
{
	return m_BasisArea;
}
inline void CheckPerisist::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& CheckPerisist::CloseVel()
{
	return m_CloseVel;
}
inline void CheckPerisist::CloseVel(const StrArray<2>& strValue)
{
	m_CloseVel = strValue;
}
#endif // !defined(AFX_CHECKPERISIST_H__9B18840A_FDB9_4018_9E01_D4B63B577B93__INCLUDED_)
