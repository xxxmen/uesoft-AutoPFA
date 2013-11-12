// UnitSubSystem.h: interface for the UnitSubSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNITSUBSYSTEM_H__2E4301F3_5F41_4083_AEBA_DE6BB82F8053__INCLUDED_)
#define AFX_UNITSUBSYSTEM_H__2E4301F3_5F41_4083_AEBA_DE6BB82F8053__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UnitType.h"
class QuantityManager;

typedef CArray<UnitType*,UnitType*>UnitTypeArrayRef;


class AFX_EXT_CLASS UnitSubSystem  
{
public:
	UnitSubSystem();
	UnitSubSystem(const UnitSubSystem &ref);
	UnitSubSystem& operator=(const UnitSubSystem &ref);
	virtual ~UnitSubSystem();

public:
	double StdToSelUnit(double d,CString strUnit);
	double StdToCur(UnitTypeID id,double d);
	CString FindCurSymbol(UnitTypeID id);
	CString FindStdSymbol(UnitTypeID id);
	BOOL FindSymbolArray(UnitTypeID id,SymbolArray &array);
	
	UnitTypeArrayRef& GetUnitArray();
	BOOL SetDefUnitString(UnitTypeID id,CString strSymbol);
	BOOL FilterString(UnitTypeID id,CString strSymbol,BOOL bUsed);
	void Init();
	BOOL FindUnit(UnitTypeID id,UnitType *&pUnitType);

	

private:
	void Assigned(const UnitTypeArrayRef &ref);
	void InitArrayRef();
	UnitType m_Area;			//面积单位
	UnitType m_Density;			//密度单位
	UnitType m_Diameter;		//直径单位
	UnitType m_HeadGradient;	//水头坡度单位
	UnitType m_Inertia;			//惯性单位
	UnitType m_Length;			//长度单位
	UnitType m_MassFlow;		//质量流量单位
	UnitType m_Mass;			//质量单位
	UnitType m_PercentFractional;  //百分数/小数
	UnitType m_Power;			//功率单位
	UnitType m_PressGradient;	//Pressure Gradient单位
	UnitType m_Pressure;		//压力单位
	UnitType m_Resistance;		//阻力单位
	UnitType m_Temperature;		//温度单位
	UnitType m_Time;			//时间单位
	UnitType m_Torque;			//转矩单位
	UnitType m_Velocity;		//速度单位
	UnitType m_Viscosity;		//运动粘度单位
	UnitType m_Volume;			//体积单位
	UnitType m_VolumetricFlow;	//体积流量单位
	UnitType m_WeightperLength; //Weight per Length单位
	UnitType m_PressPerMeter;
  
    UnitTypeArrayRef m_arrayRef;
};

#endif // !defined(AFX_UNITSUBSYSTEM_H__2E4301F3_5F41_4083_AEBA_DE6BB82F8053__INCLUDED_)
