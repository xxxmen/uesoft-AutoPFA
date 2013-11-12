// FluidData.h: interface for the FluidData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLUIDDATA_H__4626011D_6066_4786_95E0_309099C6BACA__INCLUDED_)
#define AFX_FLUIDDATA_H__4626011D_6066_4786_95E0_309099C6BACA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class AFX_EXT_CLASS FluidData : public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	FluidData();
	virtual ~FluidData();
public:
	CString Name();
	void Name(CString strValue);
	StrArray<2> Density();
	void Density(const StrArray<2>& strValue);
	StrArray<2> Viscos();
	void Viscos(const StrArray<2>& strValue);
	StrArray<2> Modulus();
	void Modulus(const StrArray<2>& strValue);
	StrArray<2> VaporPress();
	void VaporPress(const StrArray<2>& strValue);
	StrArray<2> Temperature();
	void Temperature(const StrArray<2>& strValue);
	CString Gravity();
	void Gravity(CString strValue);
	void ReTransLam(CString strValue);
	CString ReTransLam();
	void ReTransTurb(CString strValue);
	CString ReTransTurb();
	StrArray<2> AtmosphericPress();
	void AtmosphericPress(const StrArray<2>& strValue);
private:
	
	void InitArray();
	void InitRowHead();
	RowObject  m_NumofFluids;
	RowObject  m_FluidInfo;
	RowObject  m_FractionUnitsType;
	RowObject  m_InterpolationType;
	RowObject  m_Temperature;
	RowObject  m_Density;
	RowObject  m_Viscosity;
	RowObject  m_BulkModulus;
	RowObject  m_VaporPress;
	RowObject  m_AtmoPress;
	RowObject  m_Gravity;
	RowObject  m_VarGExists;
	RowObject  m_Properties;
	RowObject  m_ConstDensity;
	RowObject  m_ViscosityModel;
	RowObject  m_ReTransLam;
	RowObject  m_ReTransTurb;
	RowObject  m_NonnewtonianCorrect;
	RowObject  m_ChempakPhase;
	RowObject  m_FluidGroupsApplied;
};

#endif // !defined(AFX_FLUIDDATA_H__4626011D_6066_4786_95E0_309099C6BACA__INCLUDED_)
