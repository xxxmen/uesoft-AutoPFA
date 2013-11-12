// UnitRef.h: interface for the UnitRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNITREF_H__645E8631_27E1_442E_996A_B021DAA322DE__INCLUDED_)
#define AFX_UNITREF_H__645E8631_27E1_442E_996A_B021DAA322DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class UnitRef : public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	UnitRef();
	virtual ~UnitRef();

private:
	void InitRowHead();
	void InitArray();
    RowObject  m_NumCustomUnits;
	RowObject  m_UnitSystem;
	RowObject  m_Preferred;
	RowObject  m_Length;
	RowObject  m_Area;
	RowObject  m_Volume;
	RowObject  m_Velocity;
	RowObject  m_VolumetricFlow;  //体积流量
	RowObject  m_MassFlow ;
	RowObject  m_Press;
	RowObject  m_Temperature;
	RowObject  m_Density;
	RowObject  m_Power;
	RowObject  m_Diameter;
	RowObject  m_PressDiff;
	RowObject  m_PressAbs;
	RowObject  m_PressGrad;
	RowObject  m_HeatFlux;
	RowObject  m_Conductivity;
	RowObject  m_SpecificHeat;
	RowObject  m_CvCoefficient;
	RowObject  m_Resistance;
	RowObject  m_Viscosity;
	RowObject  m_Monetary;
	RowObject  m_Enthalpy;
	RowObject  m_PercentFractional;
	RowObject  m_ThermalResistance;
	RowObject  m_Time;
	RowObject  m_HeatRate;
    RowObject  m_TemperatureDiff;
	RowObject  m_WeightperLen;
	RowObject  m_Mass;
	RowObject  m_Energy;
	RowObject  m_HeadGradient;
	RowObject  m_ValveCv;
	RowObject  m_Inertia;
	RowObject  m_Torque;
	RowObject  m_Specific;//新添2个
	RowObject  m_Timelong;
};

#endif // !defined(AFX_UNITREF_H__645E8631_27E1_442E_996A_B021DAA322DE__INCLUDED_)
