// CalcTrans.cpp: implementation of the CalcTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTrans.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTrans::CalcTrans()
{
	m_StartTime = 0;			
	m_StopTime = 0;	
	m_TimeStep = 0.0001;
	m_Frequency = 0;				
	m_Cavitation = 0;				
	m_VariableR = 0;				
	m_Artificial = 0;				
	m_Criteria = 0;				
	m_MinFlow = 0;				
	m_TotalSteps = 0;	
}

CalcTrans::~CalcTrans()
{

}

ostream& operator<<(ostream &CalcOut,const CalcTrans &ref)
{
	CalcOut<<ref.m_StartTime<<s_Separator
		   <<ref.m_StopTime<<s_Separator
		   <<ref.m_Frequency<<s_Separator
		   <<ref.m_Cavitation<<s_Separator
		   <<ref.m_VariableR<<s_Separator
		   <<ref.m_Artificial<<s_Separator
		   <<ref.m_Criteria<<s_Separator
		   <<ref.m_MinFlow<<s_Separator
		   <<ref.m_TotalSteps<<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcTrans::StopTime(double dValue)
{
	m_StopTime = dValue;
}

/*------------------------------------------------*/
void CalcTrans::StartTime(double dValue)
{
	m_StartTime = dValue;
}
/*------------------------------------------------*/
void CalcTrans::TimeStep(double dValue)
{
	m_TimeStep = dValue;
}
/*------------------------------------------------*/
void CalcTrans::Frequency(int nValue)
{
	m_Frequency = nValue;
}
/*------------------------------------------------*/
void CalcTrans::Cavitation(int nValue)
{
	m_Cavitation = nValue;
}
/*------------------------------------------------*/
void CalcTrans::VariableR(int nValue)
{
	m_VariableR = nValue;
}
/*------------------------------------------------*/
void CalcTrans::Artificial(int nValue)
{
	m_Artificial = nValue;
}
/*------------------------------------------------*/
void CalcTrans::Criteria(double dValue)
{
	m_Criteria = dValue;
}
/*------------------------------------------------*/
void CalcTrans::MinFlow(double dValue)
{
	m_MinFlow = dValue;
}
/*------------------------------------------------*/
void CalcTrans::TotalSteps(int nValue)
{
	m_TotalSteps = nValue;
}

////////////////////////////////////////////////////
/*------------------------------------------------*/
double CalcTrans::StopTime()
{
	return m_StopTime;
}

/*------------------------------------------------*/
double CalcTrans::StartTime()
{
	return m_StartTime;
}
/*------------------------------------------------*/
double CalcTrans::TimeStep()
{
	return m_TimeStep;
}
/*------------------------------------------------*/
int CalcTrans::Frequency()
{
	return m_Frequency;
}
/*------------------------------------------------*/
int CalcTrans::Cavitation()
{
	return m_Cavitation;
}
/*------------------------------------------------*/
int CalcTrans::VariableR()
{
	return m_VariableR;
}
/*------------------------------------------------*/
int CalcTrans::Artificial()
{
	return m_Artificial;
}
/*------------------------------------------------*/
double CalcTrans::Criteria()
{
	return m_Criteria;
}
/*------------------------------------------------*/
double CalcTrans::MinFlow()
{
	return m_MinFlow;
}
/*------------------------------------------------*/
int CalcTrans::TotalSteps()
{
	return m_TotalSteps;
}