// OptionTypeNumWrapper.cpp: implementation of the OptionTypeNumWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "OptionTypeNumWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OptionTypeNumWrapper::OptionTypeNumWrapper(ArrayFlyWeight<4> &OptionTypeNum)
:m_OptionTypeNum(OptionTypeNum)
{

}

OptionTypeNumWrapper::~OptionTypeNumWrapper()
{

}

int OptionTypeNumWrapper::GetModel()
{
	return abs(m_OptionTypeNum.GetnValue());
}

void OptionTypeNumWrapper::SetModel(int bModel)
{
	if(bModel ==1)
		bModel = -1;
	m_OptionTypeNum.SetValue(bModel);
}

/*--------------------------------------------------*/
void OptionTypeNumWrapper::GetPress(int &nType,CString &strValue, CString &strUnit)
{
	nType = m_OptionTypeNum.GetnValue(1);
	strValue = m_OptionTypeNum.GetValue(2);
	if(!strValue.IsEmpty())
		strUnit  = m_OptionTypeNum.GetValue(3);
}

void OptionTypeNumWrapper::SetPress(int nType,CString strValue, CString strUnit)
{
	m_OptionTypeNum.SetValue(nType,1);
	m_OptionTypeNum.SetValue(strValue,2);
	m_OptionTypeNum.SetValue(strUnit,3);
}
/*--------------------------------------------------*/
