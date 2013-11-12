// CalcAssignPress.cpp: implementation of the CalcAssignPress class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAssignPress.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAssignPress::CalcAssignPress()
{
	m_nPressType = 0;	
	m_dPress = 0;		
}

CalcAssignPress::~CalcAssignPress()
{

}

CalcJun* CalcAssignPress::Creator()
{
	CalcAssignPress *pData = new CalcAssignPress;
	return pData;
}

ostream& CalcAssignPress::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeInfo<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nPressType<<s_Separator
		   <<m_dPress<<s_Separator
//		   <<m_TranData.m_Periodic
//		   <<m_TranData
		   <<endl;
	return CalcOut;
}

void CalcAssignPress::PipeInfo(const ListImp<StrArray<4> >& ref)
{
	m_PipeInfo.SetData(ref);
}

/*------------------------------------------------*/
void CalcAssignPress::PressType(int nValue)
{
	m_nPressType = nValue;
}
/*------------------------------------------------*/
void CalcAssignPress::Press(double dValue)
{
	m_dPress = dValue;
}

ListImp<StrArray<4> >& CalcAssignPress::PipeInfo()
{
	return m_PipeInfo.GetData();
}

/*------------------------------------------------*/
int CalcAssignPress::PressType()
{
	return m_nPressType;
}
/*------------------------------------------------*/
double CalcAssignPress::Press()
{
	return m_dPress;
}