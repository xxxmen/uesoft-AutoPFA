// GasPropertyWrapper.cpp: implementation of the GasPropertyWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "GasPropertyWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasPropertyWrapper::GasPropertyWrapper(ArrayFlyWeight<9> &GasProperty)
:m_GasProperty(GasProperty)
{

}

GasPropertyWrapper::~GasPropertyWrapper()
{

}


/*--------------------------------------------------*/
int GasPropertyWrapper::GetType()
{
	return m_GasProperty.GetnValue();
}

void GasPropertyWrapper::SetType(int nType)
{
	m_GasProperty.SetValue(nType);
}
/*--------------------------------------------------*/
CString GasPropertyWrapper::GetWeight()
{
	return m_GasProperty.GetValue(1);
}

void GasPropertyWrapper::SetWeight(CString strWeight)
{
	m_GasProperty.SetValue(strWeight,1);
}
/*--------------------------------------------------*/
CString GasPropertyWrapper::GetCpCv()
{
	return m_GasProperty.GetValue(2);
}

void GasPropertyWrapper::SetCpCv(CString strCpCv)
{
	m_GasProperty.SetValue(strCpCv,2);
}
/*--------------------------------------------------*/
void GasPropertyWrapper::GetPress(CString &strValue, CString &strUnit)
{
	strValue = m_GasProperty.GetValue(5);
	if(!strValue.IsEmpty())
		strUnit  = m_GasProperty.GetValue(6);
}

void GasPropertyWrapper::SetPress(CString strValue, CString strUnit)
{
	m_GasProperty.SetValue(strValue,5);
	m_GasProperty.SetValue(strUnit,6);
}
/*--------------------------------------------------*/

void GasPropertyWrapper::GetTemp(CString &strValue, CString &strUnit)
{
	strValue = m_GasProperty.GetValue(3);
	if(!strValue.IsEmpty())
		strUnit  = m_GasProperty.GetValue(4);
}

void GasPropertyWrapper::SetTemp(CString strValue, CString strUnit)
{
	m_GasProperty.SetValue(strValue,3);
	m_GasProperty.SetValue(strUnit,4);
}
/*--------------------------------------------------*/

void GasPropertyWrapper::GetMass(CString &strValue, CString &strUnit)
{
	strValue = m_GasProperty.GetValue(7);
	if(!strValue.IsEmpty())
		strUnit  = m_GasProperty.GetValue(8);
}

void GasPropertyWrapper::SetMass(CString strValue, CString strUnit)
{
	m_GasProperty.SetValue(strValue,7);
	m_GasProperty.SetValue(strUnit,8);
}
/*--------------------------------------------------*/