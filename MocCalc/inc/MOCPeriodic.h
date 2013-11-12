// MOCPeriodic.h: interface for the MOCPeriodic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPERIODIC_H__FC02FB0C_1342_4D47_AA52_9C054F8479BE__INCLUDED_)
#define AFX_MOCPERIODIC_H__FC02FB0C_1342_4D47_AA52_9C054F8479BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcPeriodic;
#include "MOCTable.h"

class MOCPeriodic  
{
public:
	BOOL IsSelPeriodic();
	double GetTransY(double dX);
	void Tran(PFUNTRAN pTran);
	void Read(CalcPeriodic& periodic);
	MOCPeriodic();
	virtual ~MOCPeriodic();

private:
	BOOL 	m_bPeriodic;			//0：流量周期性没有选择，1：流量周期性选择
	BOOL 	m_bChop;				//没有选择使用正弦函数的绝对值，1：选择使用正弦函数的绝对值
	double	m_dFrequency;			//正弦函数频率
	double	m_dAmplitude;			//正弦函数振幅
};

#endif // !defined(AFX_MOCPERIODIC_H__FC02FB0C_1342_4D47_AA52_9C054F8479BE__INCLUDED_)
