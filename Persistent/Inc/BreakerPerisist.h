// BreakerPerisist.h: interface for the BreakerPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BREAKERPERISIST_H__81D90514_DCCB_4461_B123_F660C753AF7F__INCLUDED_)
#define AFX_BREAKERPERISIST_H__81D90514_DCCB_4461_B123_F660C753AF7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS BreakerPerisist : public Junperisist  
{
public:
	static Junperisist* CreatBreaker();
	BreakerPerisist();
	virtual ~BreakerPerisist();
public:
	StrArray<3>& CrackPress();
	void CrackPress(const StrArray<3>& strValue);
	StrArray<2>& OrificeInCdA();
	void OrificeInCdA(const StrArray<2>& strValue);
	StrArray<2>& OrificeOutCdA();
	void OrificeOutCdA(const StrArray<2>& strValue);
	StrArray<3>& LiquidTemp();
	void LiquidTemp(const StrArray<3>& strValue);
	StrArray<9>& GasProperty();
	void GasProperty(const StrArray<9>& strValue);
	CString ConnectPipe();
	void ConnectPipe(CString strValue);
	CString ValveType();
	void ValveType(CString strValue);
	StrArray<2>& InterMediateCdA();
	void InterMediateCdA(const StrArray<2>& strValue);
	StrArray<3>& MediateActivation();
	void MediateActivation(const StrArray<3>& strValue);

private:
	StrArray<3>		m_CrackPress;				 //破裂的压力类型0：水头，1：压力/压力值/压力单位
	StrArray<2>     m_OrificeInCdA;				 //孔口全部打开流入面积值/单位
	StrArray<2>     m_OrificeOutCdA;			 //流出面积值/单位
	StrArray<3>		m_LiquidTemp;				 //流体温度选择0：系统属性1：用户指定温度/温度值/单位
	StrArray<9>		m_GasProperty;				 //气体属性0：空气1、其它气体/分子量/Cp/Cv/气体温度/气体压力/内部初始化气体气体质量/单位
	CString			m_ConnectPipe;				 //连接管道数0：两根管道1：一根管道
	CString			m_ValveType;			     //阀门类型
	StrArray<2>     m_InterMediateCdA;			 //孔口全部打开媒介流出面积值/单位
	StrArray<3>		m_MediateActivation;		 //媒介孔口激活标准0：压力不同1：流速不同/标准值/准值的单位

};

/*------------------------------------------*/
inline StrArray<3>& BreakerPerisist::CrackPress()
{
	return m_CrackPress;
}
inline void BreakerPerisist::CrackPress(const StrArray<3>& strValue)
{
	m_CrackPress = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& BreakerPerisist::OrificeInCdA()
{
	return m_OrificeInCdA;
}
inline void BreakerPerisist::OrificeInCdA(const StrArray<2>& strValue)
{
	m_OrificeInCdA = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& BreakerPerisist::OrificeOutCdA()
{
	return m_OrificeOutCdA;
}
inline void BreakerPerisist::OrificeOutCdA(const StrArray<2>& strValue)
{
	m_OrificeOutCdA = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& BreakerPerisist::LiquidTemp()
{
	return m_LiquidTemp;
}
inline void BreakerPerisist::LiquidTemp(const StrArray<3>& strValue)
{
	m_LiquidTemp = strValue;
}
/*------------------------------------------*/
inline StrArray<9>& BreakerPerisist::GasProperty()
{
	return m_GasProperty;
}
inline void BreakerPerisist::GasProperty(const StrArray<9>& strValue)
{
	m_GasProperty = strValue;
}
/*------------------------------------------*/
inline CString BreakerPerisist::ConnectPipe()
{
	return m_ConnectPipe;
}
inline void BreakerPerisist::ConnectPipe(CString strValue)
{
	m_ConnectPipe = strValue;
}
/*------------------------------------------*/
inline CString BreakerPerisist::ValveType()
{
	return m_ValveType;
}
inline void BreakerPerisist::ValveType(CString strValue)
{
	m_ValveType = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& BreakerPerisist::InterMediateCdA()
{
	return m_InterMediateCdA;
}
inline void BreakerPerisist::InterMediateCdA(const StrArray<2>& strValue)
{
	m_InterMediateCdA = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& BreakerPerisist::MediateActivation()
{
	return m_MediateActivation;
}
inline void BreakerPerisist::MediateActivation(const StrArray<3>& strValue)
{
	m_MediateActivation = strValue;
}
#endif // !defined(AFX_BREAKERPERISIST_H__81D90514_DCCB_4461_B123_F660C753AF7F__INCLUDED_)
