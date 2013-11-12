// FluidData.cpp: implementation of the FluidData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FluidData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FluidData::FluidData()
{
	InitArray();
}

FluidData::~FluidData()
{

}

void FluidData::InitRowHead()
{
	SetID("\n[FLUID DATA]");
	if(isImpFile)
	{	
		CString strArray[19];
		strArray[0] = _T("Number of Fluids=");
		strArray[1] = _T("Fluid 1=");
		strArray[2] = _T("Fraction Units Type=");
		strArray[3] = _T("Interpolation Type=");
		strArray[4] = _T("Temperature=");
		strArray[5] = _T("Density=");
		strArray[6] = _T("Viscosity=");
		strArray[7] = _T("Bulk Modulus=");
		strArray[8] = _T("Vapor Pressure=");
		strArray[9] = _T("Atmospheric Pressure=");
		strArray[10] = _T("Gravity=");
		strArray[11] = _T("VariableGExists=");
		strArray[12] = _T("Properties=");
		strArray[13] = _T("Constant Density=");
		strArray[14] = _T("Viscosity Model=");
		strArray[15] = _T("ReTransLam=");
		strArray[16] = _T("ReTransTurb=");
		strArray[17] = _T("NonnewtonianCorrect=");
		strArray[18] = _T("ChempakPhase=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==19);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
	else
	{
		CString strArray[18];
		strArray[0] = _T("Number of Fluids=");
		strArray[1] = _T("Fluid 1=");
		strArray[2] = _T("Fraction Units Type=");
		strArray[3] = _T("Interpolation Type=");
		strArray[4] = _T("Temperature=");
		strArray[5] = _T("Density=");
		strArray[6] = _T("Viscosity=");
		strArray[7] = _T("Vapor Pressure=");
		strArray[8] = _T("Atmospheric Pressure=");
		strArray[9] = _T("Gravity=");
		strArray[10] = _T("Properties=");
		strArray[11] = _T("Constant Density=");
		strArray[12] = _T("Viscosity Model=");
		strArray[13] = _T("ReTransLam=");
		strArray[14] = _T("ReTransTurb=");
		strArray[15] = _T("NonnewtonianCorrect=");
		strArray[16] = _T("ChempakPhase=");
		strArray[17] = _T("FluidGroupsApplied=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==18);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
}

void FluidData::InitArray()
{
	if (isImpFile)
	{
		m_RowArray.SetSize(19);
		m_RowArray.SetAt(0,&m_NumofFluids);
		m_RowArray.SetAt(1,&m_FluidInfo);
		m_RowArray.SetAt(2,&m_FractionUnitsType);
		m_RowArray.SetAt(3,&m_InterpolationType);
		m_RowArray.SetAt(4,&m_Temperature);
		m_RowArray.SetAt(5,&m_Density);
		m_RowArray.SetAt(6,&m_Viscosity);
		m_RowArray.SetAt(7,&m_BulkModulus);
		m_RowArray.SetAt(8,&m_VaporPress);
		m_RowArray.SetAt(9,&m_AtmoPress);
		m_RowArray.SetAt(10,&m_Gravity);
		m_RowArray.SetAt(11,&m_VarGExists);
		m_RowArray.SetAt(12,&m_Properties);
		m_RowArray.SetAt(13,&m_ConstDensity);
		m_RowArray.SetAt(14,&m_ViscosityModel);
		m_RowArray.SetAt(15,&m_ReTransLam);
		m_RowArray.SetAt(16,&m_ReTransTurb);
		m_RowArray.SetAt(17,&m_NonnewtonianCorrect);
		m_RowArray.SetAt(18,&m_ChempakPhase);
		InitRowHead();
	}
	else
	{
		m_RowArray.SetSize(18);
		m_RowArray.SetAt(0,&m_NumofFluids);
		m_RowArray.SetAt(1,&m_FluidInfo);
		m_RowArray.SetAt(2,&m_FractionUnitsType);
		m_RowArray.SetAt(3,&m_InterpolationType);
		m_RowArray.SetAt(4,&m_Temperature);
		m_RowArray.SetAt(5,&m_Density);
		m_RowArray.SetAt(6,&m_Viscosity);
		m_RowArray.SetAt(7,&m_VaporPress);
		m_RowArray.SetAt(8,&m_AtmoPress);
		m_RowArray.SetAt(9,&m_Gravity);
		m_RowArray.SetAt(10,&m_Properties);
		m_RowArray.SetAt(11,&m_ConstDensity);
		m_RowArray.SetAt(12,&m_ViscosityModel);
		m_RowArray.SetAt(13,&m_ReTransLam);
		m_RowArray.SetAt(14,&m_ReTransTurb);
		m_RowArray.SetAt(15,&m_NonnewtonianCorrect);
		m_RowArray.SetAt(16,&m_ChempakPhase);
		m_RowArray.SetAt(17,&m_FluidGroupsApplied);
		InitRowHead();
	}
}

void FluidData::Init()
{
	if (isImpFile)
	{
		CString strArray[19];
		strArray[0] = _T("1");
		strArray[1] = _T("Unspecified,0,None");
		strArray[2] = _T("1");
		strArray[3] = _T("2");
		strArray[4] = _T("0,None");
		strArray[5] = _T("0,None");
		strArray[6] = _T("0,None");
		strArray[7] = _T("0,None");
		strArray[8] = _T("0,None");
		strArray[9] = _T("1,atm");
		strArray[10] = _T("1");
		strArray[11] = _T("0");
		strArray[12] = _T("0");
		strArray[13] = _T("0");
		strArray[14] = _T("0");
		strArray[15] = _T("2300");
		strArray[16] = _T("4000");
		strArray[17] = _T("0");
		strArray[18] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==19);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
	else
	{
		CString strArray[18];
		strArray[0] = _T("1");
		strArray[1] = _T("Unspecified,0,None");
		strArray[2] = _T("1");
		strArray[3] = _T("2");
		strArray[4] = _T("0,None");
		strArray[5] = _T("0,None");
		strArray[6] = _T("0,None");
		strArray[7] = _T("0,None");
		strArray[8] = _T("1,atm");
		strArray[9] = _T("1");
		strArray[10] = _T("0");
		strArray[11] = _T("0");
		strArray[12] = _T("0");
		strArray[13] = _T("2300");
		strArray[14] = _T("4000");
		strArray[15] = _T("0");
		strArray[16] = _T("0");
		strArray[17] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==18);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

BOOL FluidData::Save(CStdioFile &file)
{
	return SaveData(file);
}

BOOL FluidData::Read(CStdioFile &file)
{
	return ReadData(file);
}

/*------------------------------------------*/
CString FluidData::Name()
{
	CString strValue;
	m_FluidInfo.GetData(strValue,1);
	return strValue;
}
void FluidData::Name(CString strValue)
{
	if(!m_FluidInfo.SetData(strValue,1))
	{
		m_FluidInfo.ReadChild("Unspecified,0,None");
		m_FluidInfo.SetData(strValue,1);
	}
		
}
/*------------------------------------------*/
StrArray<2> FluidData::Density()
{
	StrArray<2> strArray;
	CString strValue;
	m_Density.GetData(strValue,1);
	strArray.Data(strValue);
	m_Density.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::Density(const StrArray<2>& strValue)
{
	if(!m_Density.SetData(strValue.Data(),1))
	{
		m_Density.ReadChild("0,None");
	}
	m_Density.SetData(strValue.Data(),1);
	m_Density.SetData(strValue.Data(1),2);
}

/*------------------------------------------*/
StrArray<2> FluidData::Viscos()
{
	StrArray<2> strArray;
	CString strValue;
	m_Viscosity.GetData(strValue,1);
	strArray.Data(strValue);
	m_Viscosity.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::Viscos(const StrArray<2>& strValue)
{
	if(!m_Viscosity.SetData(strValue.Data(),1))
	{
		m_Viscosity.ReadChild("0,None");
	}
	m_Viscosity.SetData(strValue.Data(),1);
	m_Viscosity.SetData(strValue.Data(1),2);
}

/*------------------------------------------*/
StrArray<2> FluidData::Modulus()
{
	StrArray<2> strArray;
	CString strValue;
	m_BulkModulus.GetData(strValue,1);
	strArray.Data(strValue);
	m_BulkModulus.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::Modulus(const StrArray<2>& strValue)
{
	if(!m_BulkModulus.SetData(strValue.Data(),1))
	{
		m_BulkModulus.ReadChild("0,None");
	}
	m_BulkModulus.SetData(strValue.Data(),1);
	m_BulkModulus.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
StrArray<2> FluidData::VaporPress()
{
	StrArray<2> strArray;
	CString strValue;
	m_VaporPress.GetData(strValue,1);
	strArray.Data(strValue);
	m_VaporPress.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::VaporPress(const StrArray<2>& strValue)
{
	if(!m_VaporPress.SetData(strValue.Data(),1))
	{
		m_VaporPress.ReadChild("0,None");
	}
	m_VaporPress.SetData(strValue.Data(),1);
	m_VaporPress.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
StrArray<2> FluidData::Temperature()
{
	StrArray<2> strArray;
	CString strValue;
	m_Temperature.GetData(strValue,1);
	strArray.Data(strValue);
	m_Temperature.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::Temperature(const StrArray<2>& strValue)
{
	if(!m_Temperature.SetData(strValue.Data(),1))
	{
		m_Temperature.ReadChild("0,None");
	}
	m_Temperature.SetData(strValue.Data(),1);
	m_Temperature.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
CString FluidData::Gravity()
{
	CString strValue;
	m_Gravity.GetData(strValue,1);
	return strValue;
}
void FluidData::Gravity(CString strValue)
{
	if(!m_Gravity.SetData(strValue,1))
	{
		m_Gravity.ReadChild("1");
		m_Gravity.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString FluidData::ReTransLam()
{
	CString strValue;
	m_ReTransLam.GetData(strValue,1);
	return strValue;
}
void FluidData::ReTransLam(CString strValue)
{
	if(!m_ReTransLam.SetData(strValue,1))
	{
		m_ReTransLam.ReadChild("2300");
		m_ReTransLam.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString FluidData::ReTransTurb()
{
	CString strValue;
	m_ReTransTurb.GetData(strValue,1);
	return strValue;
}
void FluidData::ReTransTurb(CString strValue)
{
	if(!m_ReTransTurb.SetData(strValue,1))
	{
		m_ReTransTurb.ReadChild("4000");
		m_ReTransTurb.SetData(strValue,1);
	}
}
/*------------------------------------------*/
StrArray<2> FluidData::AtmosphericPress()
{
	StrArray<2> strArray;
	CString strValue;
	m_AtmoPress.GetData(strValue,1);
	strArray.Data(strValue);
	m_AtmoPress.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void FluidData::AtmosphericPress(const StrArray<2>& strValue)
{
	if(!m_AtmoPress.SetData(strValue.Data(),1))
	{
		m_AtmoPress.ReadChild("1,atm");
	}
	m_AtmoPress.SetData(strValue.Data(),1);
	m_AtmoPress.SetData(strValue.Data(1),2);
}