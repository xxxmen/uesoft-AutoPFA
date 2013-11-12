// AreaChangeLossCalc.h: interface for the AreaChangeLossCalc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREACHANGELOSSCALC_H__7DC067CD_D72F_484D_9270_EB6F1544EFFB__INCLUDED_)
#define AFX_AREACHANGELOSSCALC_H__7DC067CD_D72F_484D_9270_EB6F1544EFFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LossCalcFactory.h"

class AreaChangeLossCalc  
{
public:
	AreaChangeLossCalc();
	virtual ~AreaChangeLossCalc();
public:
	double CalcK();
	double Angel()const;
	double AreaUp()const;
	double AreaDown()const;
	int GetnRetype()const;
	int GetType()const;
	double BaseArea()const;
	void Angel(double dValue);
	void AreaUp(double dValue);
	void AreaDown(double dValue);
	void Type(int dValue);
	void nRetype(int dValue);
	void BaseArea(double dValue);
private:
	BOOL IsDataOK()const;
	LossCalcFactory *m_factory;
	double m_dAngel;
	double m_dAreaUp;
	double m_dAreaDown;
	int m_nType;   //0：圆锥，1：圆柱
	int m_nRetype;  //损失模型面积类型
	double m_BaseArea; //损失模型面积

};
inline double AreaChangeLossCalc::Angel()const
{
	return m_dAngel;
}
inline void AreaChangeLossCalc::Angel(double dValue)
{
	m_dAngel = dValue;
}
 
inline double AreaChangeLossCalc::BaseArea()const
{
	return m_BaseArea;
}

inline int AreaChangeLossCalc::GetnRetype()const
{
	return m_nRetype;
}

inline void AreaChangeLossCalc::nRetype(int dValue)
{
	m_nRetype = dValue;
}

inline void AreaChangeLossCalc::BaseArea(double dValue)
{
	m_BaseArea = dValue;
}

inline double AreaChangeLossCalc::AreaUp()const
{
	return m_dAreaUp;
}
inline void AreaChangeLossCalc::AreaUp(double dValue)
{
	m_dAreaUp = dValue;
}

inline double AreaChangeLossCalc::AreaDown()const
{
	return m_dAreaDown;
}
inline void AreaChangeLossCalc::AreaDown(double dValue)
{
	m_dAreaDown = dValue;
}

inline void AreaChangeLossCalc::Type(int nValue)
{
	m_nType = nValue;
}
#endif // !defined(AFX_AREACHANGELOSSCALC_H__7DC067CD_D72F_484D_9270_EB6F1544EFFB__INCLUDED_)
