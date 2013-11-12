// GasProperty.h: interface for the GasProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASPROPERTY_H__5C814EF6_87A6_41BD_B14D_03BE9373DA12__INCLUDED_)
#define AFX_GASPROPERTY_H__5C814EF6_87A6_41BD_B14D_03BE9373DA12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcBrecker;

class GasProperty  
{
public:
	GasProperty();
	virtual ~GasProperty();
public:
	double LiquidTemp();
	double r();
	double GasTemp();
	double GasPress();
	double GasMolMass();
	double GasFlow();
	void GasMolMass(double dMass);
	double GasInitVolume(double dPress);//根据初始质量和稳态压力得初始体积
	void GasFlow(double dGasFlow);
	void Read(CalcBrecker &Data);
	double Sonicin(double dCdAin);
	double SonicOut(double dCdAOut,double dPress);
	double SubSonicin(double dCdAin,double dPress);
	double SubSonicOut(double dCdAOut,double dPress);
	double SubSonicInC1(double dCdAin);
	double SubSonicOutC1(double dCdAOut);
	double a();
	double b();
private:
	double Sonic(double dCdA,double dT,double dPress);
	double		m_dLiquidTemp;					 //流体温度
	double		m_dGasWeight;					 //气分子量
	double      m_dCpCv;                         //Cp/Cv
	double      m_dGasTemp;						 //气体温度
	double      m_dGasPress;				     //气体压力
	double      m_dGasMass;						 //内部初始化气体气体质量
	double      m_dOldGasFlow;                   //气体质量流量
	
};

#endif // !defined(AFX_GASPROPERTY_H__5C814EF6_87A6_41BD_B14D_03BE9373DA12__INCLUDED_)
