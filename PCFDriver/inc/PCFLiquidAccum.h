// PCFLiquidAccum.h: interface for the PCFLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFLIQUIDACCUM_H__6D4FDA75_D697_40E9_9F96_FB041FFF850E__INCLUDED_)
#define AFX_PCFLIQUIDACCUM_H__6D4FDA75_D697_40E9_9F96_FB041FFF850E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObjectFace.h"
#include "Junction.h"
#include "PCFJun.h"
//流体罐
class AFX_EXT_CLASS PCFLiquidAccum : public PCFJun  
{
public:
	static PCFJun* Creator();
	PCFLiquidAccum();
	virtual ~PCFLiquidAccum();
	
	void Init( const CStringArray& wordArray );
	
public:
	void Elastic(StrArray<2>& array);
	StrArray<2> Elastic();
	void InitVolume(StrArray<2>& array);
	StrArray<2> InitVolume();
private:
	RowObjectFace<2> m_Elastic;				//弹性值\弹性单位
    RowObjectFace<2> m_Volume;				//初始体积值\初始体积值单位
};

#endif // !defined(AFX_PCFLIQUIDACCUM_H__6D4FDA75_D697_40E9_9F96_FB041FFF850E__INCLUDED_)
