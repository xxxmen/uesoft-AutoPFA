// ontrolWrapper.cpp: implementation of the ControlWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ControlWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlWrapper::ControlWrapper(ArrayFlyWeight<5> &ControlSet)
:m_ControlSet(ControlSet)
{

}

ControlWrapper::~ControlWrapper()
{

}

int ControlWrapper::GetType()
{
	return m_ControlSet.GetnValue();
}

void ControlWrapper::SetType(int nType)
{
	m_ControlSet.SetValue(nType);
}

int ControlWrapper::GetSetType()
{
	return m_ControlSet.GetnValue(1);
}

void ControlWrapper::SetSetType(int nType)
{
	m_ControlSet.SetValue(nType,1);
}

int ControlWrapper::GetPressType()
{
	return m_ControlSet.GetnValue(2);
}

void ControlWrapper::SetPressType(int nType)
{
	m_ControlSet.SetValue(nType,2);
}

void ControlWrapper::GetSetNum(CString &strValue, CString &strUnit)
{
	strValue = m_ControlSet.GetValue(3);
	if(!strValue.IsEmpty())
		strUnit  = m_ControlSet.GetValue(4);
}

void ControlWrapper::SetSetNum(CString strValue, CString strUnit)
{
	m_ControlSet.SetValue(strValue,3);
	m_ControlSet.SetValue(strUnit,4);
}