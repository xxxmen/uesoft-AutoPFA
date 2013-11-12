// GasAccumPerisist.h: interface for the GasAccumPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASACCUMPERISIST_H__FAB5F5BD_F43A_472A_A2D0_875CB0354112__INCLUDED_)
#define AFX_GASACCUMPERISIST_H__FAB5F5BD_F43A_472A_A2D0_875CB0354112__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS GasAccumPerisist : public Junperisist  
{
public:
	static Junperisist* CreatGasAccumulator();
	GasAccumPerisist();
	virtual ~GasAccumPerisist();
public:

	CString Polytropic();
	void Polytropic(CString strValue);
	StrArray<2>& InitVolume();
	void InitVolume(const StrArray<2>& strValue);
	StrArray<5>& Orifice();
	void Orifice(const StrArray<5>& strValue);
	StrArray<10>& ShortPipe();
	void ShortPipe(const StrArray<10>& strValue);
	StrArray<4>& InitPress();
	void InitPress(const StrArray<4>& strValue);
	CString MaxVolume();
	void MaxVolume(CString strValue);
	CString MinVolume();
	void MinVolume(CString strValue);
	StrArray<3>& GasVolume();
	void GasVolume(const StrArray<3>& m_GasVolume);
private:
	CString		m_Polytropic;					//变化的常量
	StrArray<2> m_InitVolume;					//初始化气体体积\单位
	StrArray<5> m_Orifice;						//选中节流孔板模型标记\入流量系数\出流量系数\面积值\单位
	StrArray<10>m_ShortPipe;					//0：没有选择短管道模型，-1：选择短管道模型
												//短管道摩擦系数
												//短管道内直径\单位
												//短管道面积\单位
												//短管道长度\单位
												//短管道标高变化\单位
	StrArray<4> m_InitPress;					//0:没有选中设置静态流初试压力，-1:没有选中设置静态流初试压力
												//0：压力类型为水头，1：压力类型为压力
												//压力大小\单位
	CString		m_MaxVolume;					//最大体积
	CString		m_MinVolume;					//最小体积
	StrArray<3> m_GasVolume;					//类型（0：初始化指定体积，1：初始化指定压力）
												//参考气体压力\单位

};
/*------------------------------------------*/
inline CString GasAccumPerisist::Polytropic()
{
	return m_Polytropic;
}
inline void GasAccumPerisist::Polytropic(CString strValue)
{
	m_Polytropic = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& GasAccumPerisist::InitVolume()
{
	return m_InitVolume;
}
inline void GasAccumPerisist::InitVolume(const StrArray<2>& strValue)
{
	m_InitVolume = strValue;
}
/*------------------------------------------*/
inline StrArray<5>& GasAccumPerisist::Orifice()
{
	return m_Orifice;
}
inline void GasAccumPerisist::Orifice(const StrArray<5>& strValue)
{
	m_Orifice = strValue;
}
/*------------------------------------------*/
inline StrArray<10>& GasAccumPerisist::ShortPipe()
{
	return m_ShortPipe;
}
inline void GasAccumPerisist::ShortPipe(const StrArray<10>& strValue)
{
	m_ShortPipe = strValue;
}
/*------------------------------------------*/
inline StrArray<4>& GasAccumPerisist::InitPress()
{
	return m_InitPress;
}
inline void GasAccumPerisist::InitPress(const StrArray<4>& strValue)
{
	m_InitPress = strValue;
}
/*------------------------------------------*/
inline CString GasAccumPerisist::MaxVolume()
{
	return m_MaxVolume;
}
inline void GasAccumPerisist::MaxVolume(CString strValue)
{
	m_MaxVolume = strValue;
}
/*------------------------------------------*/
inline CString GasAccumPerisist::MinVolume()
{
	return m_MinVolume;
}
inline void GasAccumPerisist::MinVolume(CString strValue)
{
	m_MinVolume = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& GasAccumPerisist::GasVolume()
{
	return m_GasVolume;
}
inline void GasAccumPerisist::GasVolume(const StrArray<3>& strValue)
{
	m_GasVolume = strValue;
}

#endif // !defined(AFX_GASACCUMPERISIST_H__FAB5F5BD_F43A_472A_A2D0_875CB0354112__INCLUDED_)
