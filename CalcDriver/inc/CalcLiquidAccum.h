// CalcLiquidAccum.h: interface for the CalcLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCLIQUIDACCUM_H__C391BADE_FDFF_4CB8_A5B0_3F0F4F5C2679__INCLUDED_)
#define AFX_CALCLIQUIDACCUM_H__C391BADE_FDFF_4CB8_A5B0_3F0F4F5C2679__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcLiquidAccum : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcLiquidAccum();
	virtual ~CalcLiquidAccum();

public:
	void Elastic(double dValue);
	void InitVolume(double dValue);
	double Elastic();
	double InitVolume();
private:
	double m_dElastic;				    //弹性值
	double m_dInitVolume;				//初始体积值

};

#endif // !defined(AFX_CALCLIQUIDACCUM_H__C391BADE_FDFF_4CB8_A5B0_3F0F4F5C2679__INCLUDED_)
