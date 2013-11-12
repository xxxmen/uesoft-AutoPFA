// CalcAssignFlow.cpp: implementation of the CalcAssignFlow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAssignFlow.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAssignFlow::CalcAssignFlow()
{
	m_dK = 0;					
	m_nFlowDir = 0;			
	m_nFlowType = 0;			
	m_dFlow = 0;			
	m_bSelInitPress = 0;         
	m_nInitPressType = 0;		
	m_dInitPress = 0;			
}

CalcAssignFlow::~CalcAssignFlow()
{

}

CalcJun* CalcAssignFlow::Creator()
{
	CalcAssignFlow *pData = new CalcAssignFlow;
	return pData;
}

ostream& CalcAssignFlow::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_dK<<s_Separator
		   <<m_nFlowDir<<s_Separator
		   <<m_nFlowType<<s_Separator
		   <<m_dFlow<<s_Separator
		   //<<m_TranData.m_Periodic
		   <<abs(m_bSelInitPress)<<s_Separator
		   <<m_nInitPressType<<s_Separator
		   <<m_dInitPress<<s_Separator
		   //<<m_TranData
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcAssignFlow::K(double dValue)
{
	m_dK = dValue;
}
void CalcAssignFlow::FlowDir(int nValue)
{
	m_nFlowDir = nValue;
}
void CalcAssignFlow::FlowType(int nValue)
{
	m_nFlowType = nValue;
}
/*------------------------------------------------*/
void CalcAssignFlow::Flow(double dValue)
{
	m_dFlow = dValue;
}
void CalcAssignFlow::SelInitPress(int nValue)
{
	m_bSelInitPress = nValue;
}
void CalcAssignFlow::InitPressType(int nValue)
{
	m_nInitPressType = nValue;
}
/*------------------------------------------------*/
void CalcAssignFlow::InitPress(double dValue)
{
	m_dInitPress = dValue;
}

//////////////////////////////////////////////////
/*------------------------------------------------*/
double CalcAssignFlow::K()
{
	return m_dK;
}

int CalcAssignFlow::FlowType()
{
	return m_nFlowType;
}
/*------------------------------------------------*/
double CalcAssignFlow::Flow()
{
	return m_dFlow;
}
int CalcAssignFlow::SelInitPress()
{
	return m_bSelInitPress;
}
int CalcAssignFlow::InitPressType()
{
	return m_nInitPressType;
}
/*------------------------------------------------*/
double CalcAssignFlow::InitPress()
{
	return m_dInitPress;
}