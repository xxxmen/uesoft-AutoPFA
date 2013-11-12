// CalcPeriodic.h: interface for the CalcPeriodic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPERIODIC_H__40B48C07_1EB2_4437_A7AA_946050359B43__INCLUDED_)
#define AFX_CALCPERIODIC_H__40B48C07_1EB2_4437_A7AA_946050359B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcPeriodic  
{
public:
	CalcPeriodic();
	virtual ~CalcPeriodic();
public:
	BOOL Periodic();
	BOOL Chop();
	double Frequency();
	double Amplitude();
	void Periodic(int nValue);
	void Chop(int nValue);
	void Frequency(double dValue);
	void Amplitude(double dValue);
	friend	ostream& operator<< (ostream &CalcOut,const CalcPeriodic &ref);
private:
	int 	m_bPeriodic;			//0：流量周期性没有选择，1：流量周期性选择
	int 	m_bChop;				//没有选择使用正弦函数的绝对值，1：选择使用正弦函数的绝对值
	double	m_dFrequency;			//正弦函数频率
	double	m_dAmplitude;			//正弦函数振幅

};

#endif // !defined(AFX_CALCPERIODIC_H__40B48C07_1EB2_4437_A7AA_946050359B43__INCLUDED_)
