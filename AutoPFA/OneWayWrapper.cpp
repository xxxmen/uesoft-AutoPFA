// OneWayWrapper.cpp: implementation of the OneWayWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "OneWayWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OneWayWrapper::OneWayWrapper(ArrayFlyWeight<5>& checkValve)
:m_CheckValve(checkValve)
{

}

OneWayWrapper::~OneWayWrapper()
{

}

/*--------------------------------------------------*/
BOOL OneWayWrapper::GetCvModel()
{
	if(m_CheckValve.GetValue().IsEmpty())
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


CString OneWayWrapper::GetCv()
{
	return m_CheckValve.GetValue();
}

void OneWayWrapper::SetCv(CString strCv)
{
	m_CheckValve.SetValue(strCv);
}
/*--------------------------------------------------*/
int OneWayWrapper::GetPostion()
{
	return m_CheckValve.GetnValue(1);
}

void OneWayWrapper::SetPostion(int nPostion)
{
	m_CheckValve.SetValue(nPostion,1);
}
/*--------------------------------------------------*/
void OneWayWrapper::GetPress(int &nType,CString &strValue, CString &strUnit)
{
	nType = m_CheckValve.GetnValue(2);
	strValue = m_CheckValve.GetValue(3);
	if(!strValue.IsEmpty())
		strUnit  = m_CheckValve.GetValue(4);
}

void OneWayWrapper::SetPress(int nType,CString strValue, CString strUnit)
{
	m_CheckValve.SetValue(nType,2);
	m_CheckValve.SetValue(strValue,3);
	m_CheckValve.SetValue(strUnit,4);
}
/*--------------------------------------------------*/
