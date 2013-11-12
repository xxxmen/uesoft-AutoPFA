// RestrictorWrapper.cpp: implementation of the RestrictorWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "RestrictorWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RestrictorWrapper::RestrictorWrapper(ArrayFlyWeight<5> &Orifice)
:m_Orifice(Orifice)
{

}

RestrictorWrapper::~RestrictorWrapper()
{

}

/*--------------------------------------------------*/
BOOL RestrictorWrapper::GetModel()
{
	return abs(m_Orifice.GetnValue());
}

void RestrictorWrapper::SetModel(BOOL bModel)
{
	m_Orifice.SetValue(bModel);
}
/*--------------------------------------------------*/
CString RestrictorWrapper::GetInFlowCD()
{
	return m_Orifice.GetValue(1);
}

void RestrictorWrapper::SetInFlowCD(CString strInFlowCD)
{
	m_Orifice.SetValue(strInFlowCD,1);
}
/*--------------------------------------------------*/
CString RestrictorWrapper::GetOutFlowCD()
{
	return m_Orifice.GetValue(2);
}

void RestrictorWrapper::SetOutFlowCD(CString strOutFlowCD)
{
	m_Orifice.SetValue(strOutFlowCD,2);
}
/*--------------------------------------------------*/
void RestrictorWrapper::GetArea(CString &strValue, CString &strUnit)
{
	strValue = m_Orifice.GetValue(3);
	if(!strValue.IsEmpty())
		strUnit  = m_Orifice.GetValue(4);
}

void RestrictorWrapper::SetArea(CString strValue, CString strUnit)
{
	m_Orifice.SetValue(strValue,3);
	m_Orifice.SetValue(strUnit,4);
}