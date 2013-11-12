// MOCFluid.h: interface for the MOCFluid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCFLUID_H__34A6D317_1B6A_4D47_AD0A_2921284AA975__INCLUDED_)
#define AFX_MOCFLUID_H__34A6D317_1B6A_4D47_AD0A_2921284AA975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcFuild;

class MOCFluid  
{
public:
	BOOL Read(CalcFuild &data);
	MOCFluid();
	virtual ~MOCFluid();
public:
	static BOOL IsVaporModel();
	static void VaporModel(BOOL bVapor);
	static BOOL IsVariableR();
	static void VariableR(BOOL bVariableR);
	static double TranHToPress(double dH);
	static double TranHGLToPress(double dH);
	static double TranPressToH(double dPress);
	static double TranPressToHGL(double dPress);
	static double TranQToMass(double dQ);
	static double TranMassToQ(double dMass);
	static double TranMassToV(double dMass);
	static double TranVToMass(double dVolume);
	static double CalcPressLoss(double dMass,double dArea);

	static void SetpTime(double dt);
	static double SetpTime();
	static double Temperature();
	static double Density();
	static double Viscos();
	static double Modulus();
	static double VaporPress();
	static double AtmosphericPress();
	static double Gravity();
	static double ReTransLam();
	static double ReTransTurb();

private:
	static double m_dTemperature;					//流体温度
	static double m_dDensity;						//流体密度
	static double m_dViscosity;						//流体运动粘度
	static double m_dBulkModulus;					//流体体积模量
	static double m_dVaporPressure;					//流体汽化压力
	static double m_dAtmosphericPressure;			//大气压力
    static double m_dGravity;						//重力加速度
	static double m_dReTransLam;					//层流雷偌数
	static double m_dReTransTurb;					//湍流雷偌数
	static BOOL m_bVapor;
	static double m_dSetpTime;
	static BOOL m_bVariableR;

};

#endif // !defined(AFX_MOCFLUID_H__34A6D317_1B6A_4D47_AD0A_2921284AA975__INCLUDED_)
