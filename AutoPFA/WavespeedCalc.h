// WavespeedCalc.h: interface for the WavespeedCalc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WAVESPEEDCALC_H__EAA28FD5_CAEC_4FD5_9FEF_F1049569CCD5__INCLUDED_)
#define AFX_WAVESPEEDCALC_H__EAA28FD5_CAEC_4FD5_9FEF_F1049569CCD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SupportStrategyFactory.h"

class WavespeedCalc  
{
public:
	double CalcC1();
	double GetWave(double dC1,CString strUnit);
	double GetWave(double dC1);
	double K()const;
	double Den()const;
	double Dia()const;
	double E()const;
	double e()const;
	double D()const;
	double u()const;
	double C1()const;
	void SupportType(int nValue);
	void K(double dValue);
	void Den(double dValue);
	void E(double dValue);
	void Dia(double dValue);
	void e(double dValue);
	void u(double dValue);
	WavespeedCalc();
	virtual ~WavespeedCalc();

private:
	SupportStrategyFactory *m_factory;
	int m_nSupportType;			//Pipe Support
	double m_dK;				//fluid bulk modulus of elasticity
	double m_dDen;				//fluid density
	double m_dE;				//pipe modulus of elasticity
	double m_dDia;				//pipe inner diameter
	double m_de;				//pipe wall thickness
	double m_dC1;				//correction factor
	double m_du;				//≤¥À…±»¬ 
};
inline double WavespeedCalc::K()const
{
	return m_dK;
}

inline double WavespeedCalc::Den()const
{
	return m_dDen;
}

inline double WavespeedCalc::E()const
{
	return m_dE;
}

inline double WavespeedCalc::Dia()const
{
	return m_dDia;
}

inline double WavespeedCalc::e()const
{
	return m_de;
}

inline double WavespeedCalc::u()const
{
	return m_du;
}
inline double WavespeedCalc::C1()const
{
	return m_dC1;
}
inline void WavespeedCalc::SupportType(int nValue)
{
	m_nSupportType = nValue;
}
inline void WavespeedCalc::K(double dValue)
{
	m_dK = dValue;
}
inline void WavespeedCalc::Den(double dValue)
{
	m_dDen = dValue;
}
inline void WavespeedCalc::E(double dValue)
{
	m_dE = dValue;
}
inline void WavespeedCalc::Dia(double dValue)
{
	m_dDia = dValue;
}
inline void WavespeedCalc::e(double dValue)
{
	m_de = dValue;
}
inline void WavespeedCalc::u(double dValue)
{
	m_du = dValue;
}
#endif // !defined(AFX_WAVESPEEDCALC_H__EAA28FD5_CAEC_4FD5_9FEF_F1049569CCD5__INCLUDED_)
