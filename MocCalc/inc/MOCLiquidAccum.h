// MOCLiquidAccum.h: interface for the MOCLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCLIQUIDACCUM_H__502248ED_380E_4F9B_95C8_2475885AB674__INCLUDED_)
#define AFX_MOCLIQUIDACCUM_H__502248ED_380E_4F9B_95C8_2475885AB674__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"

class MOCLiquidAccum : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCLiquidAccum();
	virtual ~MOCLiquidAccum();

private:
	void CalcStm();
	BOOL InitEndInfo();
private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	double m_dElastic;				    //弹性值
	double m_dInitVolume;				//初始体积值
	double m_dMass;                     //流出流体罐的流量
};

#endif // !defined(AFX_MOCLIQUIDACCUM_H__502248ED_380E_4F9B_95C8_2475885AB674__INCLUDED_)
