// alcFriction.h: interface for the CalcFriction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALCFRICTION_H__F8CAD2C4_85E3_42DF_81F1_87F68A07C54E__INCLUDED_)
#define AFX_ALCFRICTION_H__F8CAD2C4_85E3_42DF_81F1_87F68A07C54E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CalcFriction  
{
public:
	CalcFriction();
	virtual ~CalcFriction();

public:
	double CalcF();
	void FrictionModel(int nValue);
	void Re(double dValue);
	void V(double dValue);
	void Q(double dValue);
	void Dia(double dValue);
	void Area(double dValue);
	void Friction(double dValue);
private:
	double HazenWilliams();
	double MITEquation();
	double MillerTurbulent();
	double LambertW(const double dK);
	void GetColebrook(double df,double dRe,double &dFun,double &dGrad);
	double Colebrook();
	double Colebrook1();
	int m_nFrictionModel;			//0,"绝对粗糙度"
									//4,"摩擦系数"
									//7,"无摩擦阻力"
									//3,"海曾-威廉公式"
									//2,"水力光滑"
									//5,"MIT Equation"
									//6,"Miller Turbulent "
									//1,"相对粗糙度"
	double m_dRe;
	double m_dDia;
	double m_dArea;
	double m_dV;                    //管道平均流速绝对值
	double m_dQ;					//管道平均体积流量绝对值
	double m_dFriction;
};
/*------------------------------------------------*/
inline void CalcFriction::FrictionModel(int nValue)
{
	m_nFrictionModel = nValue;
}

/*------------------------------------------------*/
inline void CalcFriction::Re(double dValue)
{
	m_dRe = dValue;
}
/*------------------------------------------------*/
inline void CalcFriction::V(double dValue)
{
	m_dV = fabs(dValue);
}
inline void CalcFriction::Q(double dValue)
{
	m_dQ = fabs(dValue);
}
/*------------------------------------------------*/
inline void CalcFriction::Dia(double dValue)
{
	m_dDia = dValue;
}
/*------------------------------------------------*/
inline void CalcFriction::Area(double dValue)
{
	m_dArea = dValue;
}
/*------------------------------------------------*/
inline void CalcFriction::Friction(double dValue)
{
	m_dFriction = dValue;
}
#endif // !defined(AFX_ALCFRICTION_H__F8CAD2C4_85E3_42DF_81F1_87F68A07C54E__INCLUDED_)
