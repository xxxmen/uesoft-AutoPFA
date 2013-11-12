// FuildDatabase.h: interface for the FuildDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUILDDATABASE_H__2185FB49_D6E0_4640_B628_29411E8B29E1__INCLUDED_)
#define AFX_FUILDDATABASE_H__2185FB49_D6E0_4640_B628_29411E8B29E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FuildAttrCurve.h"

class AFX_EXT_CLASS FuildDatabase  
{
public:
	CString DensityUnit();
	CString ViscosityUnit();
	CString BulkModulusUnit();
	CString VaporPressureUnit();
	CString DensityValue(int dt);
	CString ViscosityValue(int dt);
	CString BulkModulusValue(int dt);
	CString VaporPressureValue(int dt);
	CString TempertureUnit();
	BOOL IsInRange(double dT);
	CString Range();
	int Key();
	void Key(int nKey);
	CString Name();
	void Init(CString strData );
	static FuildDatabase* Creator();
	FuildDatabase();
	virtual ~FuildDatabase();

private:
	int m_nKey;
	CString m_strName;
	CString m_TemperatureUnit;
	double m_dMaxTemperature;
	double m_dMinTemperature;
	FuildAttrCurve m_Density;
	FuildAttrCurve m_Viscosity;
	FuildAttrCurve m_BulkModulus;
	FuildAttrCurve m_VaporPressure;

};

#endif // !defined(AFX_FUILDDATABASE_H__2185FB49_D6E0_4640_B628_29411E8B29E1__INCLUDED_)
