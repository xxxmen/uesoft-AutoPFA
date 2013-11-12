// ShortPipeWrapper.cpp: implementation of the ShortPipeWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ShortPipeWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ShortPipeWrapper::ShortPipeWrapper(ArrayFlyWeight<10> &ShortPipe)
:m_ShortPipe(ShortPipe)
{

}

ShortPipeWrapper::~ShortPipeWrapper()
{

}
/*--------------------------------------------------*/
BOOL ShortPipeWrapper::GetModel()
{
	return abs(m_ShortPipe.GetnValue());
}

void ShortPipeWrapper::SetModel(BOOL bModel)
{
	m_ShortPipe.SetValue(bModel);
}
/*--------------------------------------------------*/
CString ShortPipeWrapper::GetFriction()
{
	return m_ShortPipe.GetValue(1);
}

void ShortPipeWrapper::SetFriction(CString strFriction)
{
	m_ShortPipe.SetValue(strFriction,1);
}
/*--------------------------------------------------*/
void ShortPipeWrapper::GetDia(CString &strValue, CString &strUnit)
{
	strValue = m_ShortPipe.GetValue(2);
	if(!strValue.IsEmpty())
		strUnit  = m_ShortPipe.GetValue(3);
}

void ShortPipeWrapper::SetDia(CString strValue, CString strUnit)
{
	m_ShortPipe.SetValue(strValue,2);
	m_ShortPipe.SetValue(strUnit,3);
}
/*--------------------------------------------------*/
void ShortPipeWrapper::GetArea(CString &strValue, CString &strUnit)
{
	strValue = m_ShortPipe.GetValue(4);
	if(!strValue.IsEmpty())
		strUnit  = m_ShortPipe.GetValue(5);
}

void ShortPipeWrapper::SetArea(CString strValue, CString strUnit)
{
	m_ShortPipe.SetValue(strValue,4);
	m_ShortPipe.SetValue(strUnit,5);
}
/*--------------------------------------------------*/
void ShortPipeWrapper::GetLen(CString &strValue, CString &strUnit)
{
	strValue = m_ShortPipe.GetValue(6);
	if(!strValue.IsEmpty())
		strUnit  = m_ShortPipe.GetValue(7);
}

void ShortPipeWrapper::SetLen(CString strValue, CString strUnit)
{
	m_ShortPipe.SetValue(strValue,6);
	m_ShortPipe.SetValue(strUnit,7);
}
/*--------------------------------------------------*/
void ShortPipeWrapper::GetEleChange(CString &strValue, CString &strUnit)
{
	strValue = m_ShortPipe.GetValue(8);
	if(!strValue.IsEmpty())
		strUnit  = m_ShortPipe.GetValue(9);
}

void ShortPipeWrapper::SetEleChange(CString strValue, CString strUnit)
{
	m_ShortPipe.SetValue(strValue,8);
	m_ShortPipe.SetValue(strUnit,9);
}