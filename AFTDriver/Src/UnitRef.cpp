// UnitRef.cpp: implementation of the UnitRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UnitRef.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnitRef::UnitRef()
{
	InitArray();
}

UnitRef::~UnitRef()
{

}

BOOL UnitRef::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL UnitRef::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void UnitRef::Init()
{
	if(isImpFile)
	{
		CString strArray[37];
		strArray[0] = _T("0");
		strArray[1] = _T("0");
		strArray[2] = _T("meters,meters2,meters3,meters/sec,m3/sec,kg/sec,Pascals,deg. K,kg/m3,kW,cm,Pascals,Pascals,kPa/m,Btu/s-ft2,Btu/hr-ft-R,Btu/lbm-R,Btu/hr-ft2-R,sec2/m5,kg/sec-m,U.S. Dollars,Btu/lbm,Percent,hr-R/Btu,seconds,Btu/s,deg. F,kg/m,kg,kW-hr,m/100 m,gpm/psid^0.5,kg-m2,N-m");
		strArray[3] = _T("cm,feet,inches,km,meters,miles,mm");
		strArray[4] = _T("cm2,feet2,inches2,meters2,mm2");
		strArray[5] = _T("acre-ft,barrels,cm3,feet3,gal,gal-UK,inches3,liter,meters3,ml,mm3");
		strArray[6] = _T("cm/hr,cm/min,cm/sec,feet/day,feet/hr,feet/min,feet/sec,inches/min,inches/sec,km/day,km/hr,km/min,km/sec,meters/day,meters/hr,meters/min,meters/sec,miles/day,miles/hr");
		strArray[7] = _T("acre-ft/day,acre-ft/hr,acre-ft/min,acre-ft/sec,barrels/day,barrels/hr,barrels/min,barrels/sec,cm3/hr,cm3/min,cm3/sec,ft3/day,ft3/hr,ft3/min,ft3/sec,gal-UK/day,gal-UK/hr,gal-UK/min,gal-UK/sec,gal/day,gal/hr,gal/min,gal/sec,in3/hr,in3/min,in3/sec,liter/hr,liter/min,liter/sec,m3/day,m3/hr,m3/min,m3/sec,*MGD,mm3/hr,mm3/min,mm3/sec");
		strArray[8] = _T("gram/min,gram/sec,kg/day,kg/hr,kg/min,kg/sec,lbm/day,lbm/hr,lbm/min,lbm/sec,m-ton/day,m-ton/hr,m-ton/min,m-ton/sec,slug/day,slug/hr,slug/min,slug/sec,ton/day,ton/hr,ton/min,ton/sec");
		strArray[9] = _T("atm,bar,barG,cm H2O std.,cm H2O std. (g),dyn/cm2,dyn/cm2 (g),ft. H2O std.,ft. H2O std. (g),in. H2O std.,in. H2O std. (g),in. Hg,in. Hg (g),kg/cm2,kg/cm2 (g),kPa,kPa (g),m H2O std.,m H2O std. (g),mm H2O std.,mm H2O std. (g),mm Hg,mm Hg (g),MPa,MPa (g),Pascals,Pascals (g),psfa,psfg,psia,psig");
		strArray[10] = _T("deg. C,deg. F,deg. K,deg. R");
		strArray[11] = _T("gram/cm3,gram/liter,kg/cm3,kg/liter,kg/m3,lbm/ft3,lbm/gal,lbm/in3,S.G. water,slug/ft3");
		strArray[12] = _T("Btu/day,Btu/hr,Btu/min,Btu/s,cal/day,cal/hr,cal/min,cal/s,ft-lbf/day,ft-lbf/hr,ft-lbf/min,ft-lbf/s,hp,kcal/day,kcal/hr,kcal/min,kcal/s,kJ/day,kJ/hr,kW,MW,W");
		strArray[13] = _T("cm,feet,inches,meters,microinches,mm ");
		strArray[14] = _T("atm,bar,cm H2O std.,dyn/cm2,ft. H2O std.,in. H2O std.,in. Hg,kg/cm2,kPa,m H2O std.,mm H2O std.,mm Hg,MPa,Pascals,psfd,psid");
		strArray[15] = _T("atm,bar,cm H2O std.,dyn/cm2,ft. H2O std.,in. H2O std.,in. Hg,kg/cm2,kPa,m H2O std.,mm H2O std.,mm Hg,MPa,Pascals,psfa,psia");
		strArray[16] = _T("kPa/100 m,kPa/m,MPa/100 m,MPa/m,Pascals/100 m,Pascals/m,psf/100 ft,psf/ft,psf/in,psi/100 ft,psi/ft,psi/in");
		strArray[17] = _T("Btu/hr-ft2,Btu/hr-in2,Btu/s-ft2,Btu/s-in2,kJ/hr-cm2,kJ/hr-m2,kW/cm2,kW/m2,lbf/s-ft,lbf/s-in,MW/cm2,MW/m2,W/cm2,W/m2");
		strArray[18] = _T("Btu-in/s-ft2-R,Btu/hr-ft-R,Btu/s-ft-R,cal/s-cm-K,kW/m-K,lbf/hr-R,lbf/s-R,W/m-K");
		strArray[19] = _T("Btu/lbm-R,cal/g-K,ft-lbf/lbm-R,kJ/kg-K");
		strArray[20] = _T("Btu/hr-ft2-R,Btu/s-ft2-R,kW/m2-K,W/m2-K");
		strArray[21] = _T("ft/gpm2,hr2/cm5,hr2/ft5,hr2/in5,hr2/m5,min2/cm5,min2/ft5,min2/in5,min2/m5,sec2/cm5,sec2/ft5,sec2/in5,sec2/m5");
		strArray[22] = _T("centipoise,kg/sec-cm,kg/sec-m,kg/sec-mm,lbf-hr/ft2,lbf-hr/in2,lbf-s/ft2,lbf-s/in2,lbm/hr-ft,lbm/hr-in,lbm/s-ft,lbm/s-in,Pa-sec,poise");
		strArray[23] = _T("U.S. Dollars");
		strArray[24] = _T("Btu/lbm,ft-lbf/lbm,kJ/kg");
		strArray[25] = _T("Decimal,Percent");
		strArray[26] = _T("hr-R/Btu,K/kW,K/W,s-R/Btu");
		strArray[27] = _T("*days,hours,milliseconds,minutes,seconds,*years");
		strArray[28] = _T("Btu/day,Btu/hr,Btu/min,Btu/s,cal/day,cal/hr,cal/min,cal/s,ft-lbf/day,ft-lbf/hr,ft-lbf/min,ft-lbf/s,hp,kcal/day,kcal/hr,kcal/min,kcal/s,kJ/day,kJ/hr,kW,MW,W");
		strArray[29] = _T("deg. C,deg. F,deg. K,deg. R");
		strArray[30] = _T("kg/cm,kg/m,lbm/ft,lbm/in");
		strArray[31] = _T("g,kg,lbm,m-ton,ton");
		strArray[32] = _T("Btu,cal,hp-hr,kcal,kJ,kW-hr,MJ,MW-hr,W-hr");
		strArray[33] = _T("=ft/100 ft,ft/ft,m/100 m,m/km,m/m");
		strArray[34] = _T("kg-m2,lbm-ft2,lbm-in2");
		strArray[35] = _T("kg-m,lbf-ft,lbf-in,N-m");
		strArray[36] = _T("-1");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==37);  
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
	else
	{
		CString strArray[39];
		strArray[0] = _T("0");
		strArray[1] = _T("0");
		strArray[2] = _T("meters,meters2,meters3,meters/sec,m3/sec,kg/sec,MPa,deg. C,kg/m3,kW,cm,MPa,MPa,kPa/m,kW/m2,W/m-K,kJ/kg-K,W/m2-K,sec2/m5,kg/sec-m,U.S. Dollars,kJ/kg,Percent,K/W,seconds,kW,deg. C,kg/m,kg,kW-hr,m/100 m,gpm/psid^0.5,kg-m2,N-m,m3/kg,years");
		strArray[3] = _T("cm,*feet,*inches,km,meters,microinches,*miles,mm");
		strArray[4] = _T("cm2,feet2,inches2,meters2,mm2");
		strArray[5] = _T("acre-ft,barrels,cm3,feet3,gal,gal-UK,inches3,liter,meters3,ml,mm3");
		strArray[6] = _T("cm/hr,cm/min,cm/sec,feet/day,feet/hr,feet/min,feet/sec,inches/min,inches/sec,km/day,km/hr,km/min,km/sec,meters/day,meters/hr,meters/min,meters/sec,miles/day,miles/hr");
		strArray[7] = _T("*acre-ft/day,*acre-ft/hr,*acre-ft/min,*acre-ft/sec,*barrels/day,*barrels/hr,*barrels/min,*barrels/sec,cm3/hr,cm3/min,cm3/sec,*ft3/day,*ft3/hr,*ft3/min,*ft3/sec,*gal-UK/day,*gal-UK/hr,*gal-UK/min,*gal-UK/sec,*gal/day,*gal/hr,*gal/min,*gal/sec,*in3/hr,*in3/min,*in3/sec,liter/hr,liter/min,liter/sec,m3/day,m3/hr,m3/min,m3/sec,*MGD,mm3/hr,mm3/min,mm3/sec");
		strArray[8] = _T("gram/min,gram/sec,kg/day,kg/hr,kg/min,kg/sec,lbm/day,lbm/hr,lbm/min,lbm/sec,m-ton/day,m-ton/hr,m-ton/min,m-ton/sec,slug/day,slug/hr,slug/min,slug/sec,ton/day,ton/hr,ton/min,ton/sec");
		strArray[9] = _T("atm,bar,barG,cm H2O std.,cm H2O std. (g),dyn/cm2,dyn/cm2 (g),ft. H2O std.,ft. H2O std. (g),in. H2O std.,in. H2O std. (g),in. Hg,in. Hg (g),kg/cm2,kg/cm2 (g),kPa,kPa (g),m H2O std.,m H2O std. (g),mm H2O std.,mm H2O std. (g),mm Hg,mm Hg (g),MPa,MPa (g),Pascals,Pascals (g),psfa,psfg,psia,psig");
		strArray[10] = _T("deg. C,deg. F,deg. K,deg. R");
		strArray[11] = _T("gram/cm3,gram/liter,kg/cm3,kg/liter,kg/m3,lbm/ft3,lbm/gal,lbm/in3,S.G. water,slug/ft3");
		strArray[12] = _T("Btu/day,Btu/hr,Btu/min,Btu/s,cal/day,cal/hr,cal/min,cal/s,ft-lbf/day,ft-lbf/hr,ft-lbf/min,ft-lbf/s,hp,kcal/day,kcal/hr,kcal/min,kcal/s,kJ/day,kJ/hr,kW,MW,W");
		strArray[13] = _T("cm,feet,inches,meters,microinches,mm ");
		strArray[14] = _T("atm,bar,cm H2O std.,dyn/cm2,ft. H2O std.,in. H2O std.,in. Hg,kg/cm2,kPa,m H2O std.,mm H2O std.,mm Hg,MPa,Pascals,psfd,psid");
		strArray[15] = _T("atm,bar,cm H2O std.,dyn/cm2,ft. H2O std.,in. H2O std.,in. Hg,kg/cm2,kPa,m H2O std.,mm H2O std.,mm Hg,MPa,Pascals,psfa,psia");
		strArray[16] = _T("kPa/100 m,kPa/m,MPa/100 m,MPa/m,Pascals/100 m,Pascals/m,psf/100 ft,psf/ft,psf/in,psi/100 ft,psi/ft,psi/in");
		strArray[17] = _T("Btu/hr-ft2,Btu/hr-in2,Btu/s-ft2,Btu/s-in2,kJ/hr-cm2,kJ/hr-m2,kW/cm2,kW/m2,lbf/s-ft,lbf/s-in,MW/cm2,MW/m2,W/cm2,W/m2");
		strArray[18] = _T("Btu-in/s-ft2-R,Btu/hr-ft-R,Btu/s-ft-R,cal/s-cm-K,kW/m-K,lbf/hr-R,lbf/s-R,W/m-K");
		strArray[19] = _T("Btu/lbm-R,cal/g-K,ft-lbf/lbm-R,kJ/kg-K");
		strArray[20] = _T("Btu/hr-ft2-R,Btu/s-ft2-R,kW/m2-K,W/m2-K");
		strArray[21] = _T("ft/gpm2,hr2/cm5,hr2/ft5,hr2/in5,hr2/m5,min2/cm5,min2/ft5,min2/in5,min2/m5,sec2/cm5,sec2/ft5,sec2/in5,sec2/m5");
		strArray[22] = _T("centipoise,kg/sec-cm,kg/sec-m,kg/sec-mm,lbf-hr/ft2,lbf-hr/in2,lbf-s/ft2,lbf-s/in2,lbm/hr-ft,lbm/hr-in,lbm/s-ft,lbm/s-in,Pa-sec,poise");
		strArray[23] = _T("U.S. Dollars");
		strArray[24] = _T("Btu/lbm,ft-lbf/lbm,kJ/kg");
		strArray[25] = _T("Decimal,Percent");
		strArray[26] = _T("hr-R/Btu,K/kW,K/W,s-R/Btu");
		strArray[27] = _T("days,hours,minutes,seconds,years");
		strArray[28] = _T("Btu/day,Btu/hr,Btu/min,Btu/s,cal/day,cal/hr,cal/min,cal/s,ft-lbf/day,ft-lbf/hr,ft-lbf/min,ft-lbf/s,hp,kcal/day,kcal/hr,kcal/min,kcal/s,kJ/day,kJ/hr,kW,MW,W");
		strArray[29] = _T("deg. C,deg. F,deg. K,deg. R");
		strArray[30] = _T("kg/cm,kg/m,lbm/ft,lbm/in");
		strArray[31] = _T("g,kg,lbm,m-ton,ton");
		strArray[32] = _T("Btu,cal,hp-hr,kcal,kJ,kW-hr,MJ,MW-hr,W-hr");
		strArray[33] = _T("=ft/100 ft,ft/ft,m/100 m,m/km,m/m");
		strArray[34] = _T("kg-m2,lbm-ft2,lbm-in2");
		strArray[35] = _T("kg-m,lbf-ft,lbf-in,N-m");
		strArray[36] = _T("-1");
		strArray[37]=_T("cm3/gram,cm3/kg,ft3/lbm,ft3/slug,gal/lbm,in3/lbm,liter/gram,liter/kg,m3/kg");
		strArray[38]=_T("days,hours,minutes,seconds,years");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==39);  
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

void UnitRef::InitArray()
{
	if(isImpFile)
	{
		m_RowArray.SetSize(37);
		m_RowArray.SetAt(0,&m_NumCustomUnits);
		m_RowArray.SetAt(1,&m_UnitSystem);
		m_RowArray.SetAt(2,&m_Preferred);
		m_RowArray.SetAt(3,&m_Length);
		m_RowArray.SetAt(4,&m_Area);
		m_RowArray.SetAt(5,&m_Volume);
		m_RowArray.SetAt(6,&m_Velocity);
		m_RowArray.SetAt(7,&m_VolumetricFlow);
		m_RowArray.SetAt(8,&m_MassFlow);
		m_RowArray.SetAt(9,&m_Press);
		m_RowArray.SetAt(10,&m_Temperature);
		m_RowArray.SetAt(11,&m_Density);
		m_RowArray.SetAt(12,&m_Power);
		m_RowArray.SetAt(13,&m_Diameter);
		m_RowArray.SetAt(14,&m_PressDiff);
		m_RowArray.SetAt(15,&m_PressAbs);
		m_RowArray.SetAt(16,&m_PressGrad);
		m_RowArray.SetAt(17,&m_HeatFlux);
		m_RowArray.SetAt(18,&m_Conductivity);
		m_RowArray.SetAt(19,&m_SpecificHeat);
		m_RowArray.SetAt(20,&m_CvCoefficient);
		m_RowArray.SetAt(21,&m_Resistance);
		m_RowArray.SetAt(22,&m_Viscosity);
		m_RowArray.SetAt(23,&m_Monetary);
		m_RowArray.SetAt(24,&m_Enthalpy);
		m_RowArray.SetAt(25,&m_PercentFractional);
		m_RowArray.SetAt(26,&m_ThermalResistance);
		m_RowArray.SetAt(27,&m_Time);
		m_RowArray.SetAt(28,&m_HeatRate);
		m_RowArray.SetAt(29,&m_TemperatureDiff);
		m_RowArray.SetAt(30,&m_WeightperLen);
		m_RowArray.SetAt(31,&m_Mass);
		m_RowArray.SetAt(32,&m_Energy);
		m_RowArray.SetAt(33,&m_HeadGradient);
		m_RowArray.SetAt(34,&m_ValveCv);
		m_RowArray.SetAt(35,&m_Inertia);
		m_RowArray.SetAt(36,&m_Torque);
		InitRowHead();
	}
	else
	{
		m_RowArray.SetSize(39);
		m_RowArray.SetAt(0,&m_NumCustomUnits);
		m_RowArray.SetAt(1,&m_UnitSystem);
		m_RowArray.SetAt(2,&m_Preferred);
		m_RowArray.SetAt(3,&m_Length);
		m_RowArray.SetAt(4,&m_Area);
		m_RowArray.SetAt(5,&m_Volume);
		m_RowArray.SetAt(6,&m_Velocity);
		m_RowArray.SetAt(7,&m_VolumetricFlow);
		m_RowArray.SetAt(8,&m_MassFlow);
		m_RowArray.SetAt(9,&m_Press);
		m_RowArray.SetAt(10,&m_Temperature);
		m_RowArray.SetAt(11,&m_Density);
		m_RowArray.SetAt(12,&m_Power);
		m_RowArray.SetAt(13,&m_Diameter);
		m_RowArray.SetAt(14,&m_PressDiff);
		m_RowArray.SetAt(15,&m_PressAbs);
		m_RowArray.SetAt(16,&m_PressGrad);
		m_RowArray.SetAt(17,&m_HeatFlux);
		m_RowArray.SetAt(18,&m_Conductivity);
		m_RowArray.SetAt(19,&m_SpecificHeat);
		m_RowArray.SetAt(20,&m_CvCoefficient);
		m_RowArray.SetAt(21,&m_Resistance);
		m_RowArray.SetAt(22,&m_Viscosity);
		m_RowArray.SetAt(23,&m_Monetary);
		m_RowArray.SetAt(24,&m_Enthalpy);
		m_RowArray.SetAt(25,&m_PercentFractional);
		m_RowArray.SetAt(26,&m_ThermalResistance);
		m_RowArray.SetAt(27,&m_Time);
		m_RowArray.SetAt(28,&m_HeatRate);
		m_RowArray.SetAt(29,&m_TemperatureDiff);
		m_RowArray.SetAt(30,&m_WeightperLen);
		m_RowArray.SetAt(31,&m_Mass);
		m_RowArray.SetAt(32,&m_Energy);
		m_RowArray.SetAt(33,&m_HeadGradient);
		m_RowArray.SetAt(34,&m_ValveCv);
		m_RowArray.SetAt(35,&m_Inertia);
		m_RowArray.SetAt(36,&m_Torque);
		m_RowArray.SetAt(37,&m_Specific);
		m_RowArray.SetAt(38,&m_Timelong);
		InitRowHead();
	}
}

void UnitRef::InitRowHead()
{
	SetID("\n[UNIT PREFERENCES]");
	if(isImpFile)
	{
		CString strArray[37];
		strArray[0] = _T("NumberCustomUnits=");
		strArray[1] = _T("Unit System=");
		strArray[2] = _T("Preferred Units=");
		strArray[3] = _T("Length Units=");
		strArray[4] = _T("Torque Units=");
		strArray[5] = _T("Volume Units=");
		strArray[6] = _T("Velocity Units=");
		strArray[7] = _T("Volumetric Flow Rate Units=");
		strArray[8] = _T("Mass Flow Rate Units=");
		strArray[9] = _T("Pressure Units=");
		strArray[10] = _T("Temperature Units=");
		strArray[11] = _T("Density Units=");
		strArray[12] = _T("Power Units=");
		strArray[13] = _T("Diameter Units=");
		strArray[14] = _T("Pressure Differential Units=");
		strArray[15] = _T("Pressure Absolute Units=");
		strArray[16] = _T("Pressure Gradient Units=");
		strArray[17] = _T("Heat Flux Units=");
		strArray[18] = _T("Conductivity Units= ");
		strArray[19] = _T("Specific Heat Units=");
		strArray[20] = _T("Convection Coefficient Units=");
		strArray[21] = _T("Resistance Units=");
		strArray[22] = _T("Viscosity Units=");
		strArray[23] = _T("Monetary Units=");
		strArray[24] = _T("Enthalpy Units=");
		strArray[25] = _T("Percent/Fractional Units=");
		strArray[26] = _T("Thermal Resistance Units=");
		strArray[27] = _T("Time Units=");
		strArray[28] = _T("Heat Rate=");
		strArray[29] = _T("Temperature Differential Units=");
		strArray[30] = _T("Weight per Length Units=");
		strArray[31] = _T("Mass Units=");
		strArray[32] = _T("Energy Units=");
		strArray[33] = _T("Head Gradient Units=");
		strArray[34] = _T("Valve Cv Units=");
		strArray[35] = _T("Inertia Units=");
		strArray[36] = _T("Use Closed Symbols=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==37);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
	else
	{
		CString strArray[39];
		strArray[0] = _T("NumberCustomUnits=");
		strArray[1] = _T("Unit System=");
		strArray[2] = _T("Preferred Units=");
		strArray[3] = _T("Length Units=");
		strArray[4] = _T("Torque Units=");
		strArray[5] = _T("Volume Units=");
		strArray[6] = _T("Velocity Units=");
		strArray[7] = _T("Volumetric Flow Rate Units=");
		strArray[8] = _T("Mass Flow Rate Units=");
		strArray[9] = _T("Pressure Units=");
		strArray[10] = _T("Temperature Units=");
		strArray[11] = _T("Density Units=");
		strArray[12] = _T("Power Units=");
		strArray[13] = _T("Diameter Units=");
		strArray[14] = _T("Pressure Differential Units=");
		strArray[15] = _T("Pressure Absolute Units=");
		strArray[16] = _T("Pressure Gradient Units=");
		strArray[17] = _T("Heat Flux Units=");
		strArray[18] = _T("Conductivity Units= ");
		strArray[19] = _T("Specific Heat Units=");
		strArray[20] = _T("Convection Coefficient Units=");
		strArray[21] = _T("Resistance Units=");
		strArray[22] = _T("Viscosity Units=");
		strArray[23] = _T("Monetary Units=");
		strArray[24] = _T("Enthalpy Units=");
		strArray[25] = _T("Percent/Fractional Units=");
		strArray[26] = _T("Thermal Resistance Units=");
		strArray[27] = _T("Time Units=");
		strArray[28] = _T("Heat Rate=");
		strArray[29] = _T("Temperature Differential Units=");
		strArray[30] = _T("Weight per Length Units=");
		strArray[31] = _T("Mass Units=");
		strArray[32] = _T("Energy Units=");
		strArray[33] = _T("Head Gradient Units=");
		strArray[34] = _T("Valve Cv Units=");
		strArray[35] = _T("Inertia Units=");
		strArray[36] = _T("Use Closed Symbols=");
		strArray[37] = _T("Specific Volume Units=");
		strArray[38] = _T("Time Long Units=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==39);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
}
