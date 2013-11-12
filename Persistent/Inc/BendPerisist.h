// BendPerisist.h: interface for the BendPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENDPERISIST_H__364BC445_D448_4601_BCD0_DF25DA5EF156__INCLUDED_)
#define AFX_BENDPERISIST_H__364BC445_D448_4601_BCD0_DF25DA5EF156__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS BendPerisist : public Junperisist  
{
public:
	static Junperisist* CreatBend();
	BendPerisist();
	virtual ~BendPerisist();
public:
	CString Type();
	void Type(CString strValue);
	CString Angle();
	void Angle(CString strValue);
	CString RD();
	void RD(CString strValue);
	CString K();
	void K(CString strValue);
	StrArray<2>& RestriFlowArea();
	void RestriFlowArea(const StrArray<2>& strValue);
	StrArray<3>& BasisArea();
	void BasisArea(const StrArray<3>& strValue);
private:
	CString m_bendType;				//弯头类型（0，为光滑弯头，1为标准弯头，2为Mitre Bend,3,为用户指定）
    CString m_angle;				//角度（为多少度）
	CString m_rD;					//r/D
	CString m_K;					//阻力损失（K）
    StrArray<2> m_RestriFlowArea;	//精确流体面积（Restricted Flow Area)的数字和单位
	StrArray<3> m_BasisArea;		//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径

};
/*------------------------------------------*/
inline CString BendPerisist::Type()
{
	return m_bendType;
}
inline void BendPerisist::Type(CString strValue)
{
	m_bendType = strValue;
}
/*------------------------------------------*/
inline CString BendPerisist::Angle()
{
	return m_angle;
}
inline void BendPerisist::Angle(CString strValue)
{
	m_angle = strValue;
}
/*------------------------------------------*/
inline CString BendPerisist::RD()
{
	return m_rD;
}
inline void BendPerisist::RD(CString strValue)
{
	m_rD = strValue;
}
/*------------------------------------------*/
inline CString BendPerisist::K()
{
	return m_K;
}
inline void BendPerisist::K(CString strValue)
{
	m_K = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& BendPerisist::RestriFlowArea()
{
	return m_RestriFlowArea;
}
inline void BendPerisist::RestriFlowArea(const StrArray<2>& strValue)
{
	m_RestriFlowArea = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& BendPerisist::BasisArea()
{
	return m_BasisArea;
}
inline void BendPerisist::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea = strValue;
}

#endif // !defined(AFX_BENDPERISIST_H__364BC445_D448_4601_BCD0_DF25DA5EF156__INCLUDED_)
