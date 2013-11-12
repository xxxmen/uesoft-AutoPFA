// LiquidAccumPerisist.h: interface for the LiquidAccumPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIQUIDACCUMPERISIST_H__9074386F_A43C_437B_B155_66C03302BCF9__INCLUDED_)
#define AFX_LIQUIDACCUMPERISIST_H__9074386F_A43C_437B_B155_66C03302BCF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS LiquidAccumPerisist : public Junperisist  
{
public:
	static Junperisist* CreatLiquidAccum();
	LiquidAccumPerisist();
	virtual ~LiquidAccumPerisist();
public:
    StrArray<2>& Elastic();
	void Elastic(const StrArray<2>& strValue);
	StrArray<2>& InitVolume();
	void InitVolume(const StrArray<2>& strValue);

private:
	StrArray<2> m_Elastic;				    //弹性值\弹性单位
	StrArray<2> m_InitVolume;				//初始体积值\初始体积值单位

};
/*------------------------------------------*/
inline StrArray<2>& LiquidAccumPerisist::Elastic()
{
	return m_Elastic;
}
inline void LiquidAccumPerisist::Elastic(const StrArray<2>& strValue)
{
	m_Elastic = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& LiquidAccumPerisist::InitVolume()
{
	return m_InitVolume;
}
inline void LiquidAccumPerisist::InitVolume(const StrArray<2>& strValue)
{
	m_InitVolume = strValue;
}
#endif // !defined(AFX_LIQUIDACCUMPERISIST_H__9074386F_A43C_437B_B155_66C03302BCF9__INCLUDED_)
