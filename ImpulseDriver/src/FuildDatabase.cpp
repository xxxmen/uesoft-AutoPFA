// FuildDatabase.cpp: implementation of the FuildDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FuildDatabase.h"
#include "RowObjectFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuildDatabase::FuildDatabase()
{
	m_dMaxTemperature=0;
	m_dMinTemperature=0;
	m_nKey=0;
}

FuildDatabase::~FuildDatabase()
{

}

FuildDatabase* FuildDatabase::Creator()
{
	FuildDatabase *pFuild = new FuildDatabase;
	return pFuild;
}

void FuildDatabase::Init(CString strData)
{
	RowObjectFace<4> data;
	strData = data.InitData(strData);
	data.GetData(m_strName,0);
 	data.GetData(m_TemperatureUnit,1);
 	data.GetData(m_dMaxTemperature,2);
 	data.GetData(m_dMinTemperature,3);

	strData = m_Density.Init(strData);
	strData = m_Viscosity.Init(strData);
	strData = m_BulkModulus.Init(strData);
	strData = m_VaporPressure.Init(strData);
}

CString FuildDatabase::Name()
{
	return m_strName;
}

void FuildDatabase::Key(int nKey)
{
	m_nKey = nKey;
}
int FuildDatabase::Key()
{
	return m_nKey;
}

CString FuildDatabase::Range()
{
	CString strRet;
	strRet.Format(_T("ÎÂ¶È·¶Î§£º%.1fµ½%.1f %s"),m_dMinTemperature,m_dMaxTemperature,m_TemperatureUnit);
	return strRet;
}

BOOL FuildDatabase::IsInRange(double dT)
{
	if(m_dMinTemperature<dT&&dT<m_dMaxTemperature)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

CString FuildDatabase::TempertureUnit()
{
	return m_TemperatureUnit;
}

CString FuildDatabase::DensityUnit()
{
	return m_Density.GetUnit();
}
CString FuildDatabase::ViscosityUnit()
{
	return m_Viscosity.GetUnit();
}
CString FuildDatabase::BulkModulusUnit()
{
	return m_BulkModulus.GetUnit();
}
CString FuildDatabase::VaporPressureUnit()
{
	return m_VaporPressure.GetUnit();
}

CString FuildDatabase::DensityValue(int dt)
{
	CString strRet;
	strRet.Format(_T("%f"),m_Density.GetY(dt));
	return strRet;
}

CString FuildDatabase::ViscosityValue(int dt)
{
	CString strRet;
	strRet.Format(_T("%f"),m_Viscosity.GetY(dt));
	return strRet;
}

CString FuildDatabase::BulkModulusValue(int dt)
{
	CString strRet;
	strRet.Format(_T("%f"),m_BulkModulus.GetY(dt));
	return strRet;
}

CString FuildDatabase::VaporPressureValue(int dt)
{
	CString strRet;
	strRet.Format(_T("%f"),m_VaporPressure.GetY(dt));
	return strRet;
}
