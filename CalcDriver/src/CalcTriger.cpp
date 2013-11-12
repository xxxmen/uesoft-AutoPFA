// CalcTriger.cpp: implementation of the CalcTriger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTriger.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTriger::CalcTriger()
{
	m_nEventType = 0;               
	m_nConditionType = 0;			
	m_dValue = 0;				
	m_nPort1 = 0;					
	m_nComponentID1 = 0;			 
	m_nPort2 = 0;					 
	m_nComponentID2 = 0;
}

CalcTriger::~CalcTriger()
{

}
ostream& operator<< (ostream &CalcOut,const CalcTriger &ref)
{
	CalcOut<<ref.m_nEventType<<s_Separator
		   <<ref.m_nConditionType<<s_Separator
		   <<ref.m_dValue<<s_Separator
		   <<ref.m_nPort1<<s_Separator
		   <<ref.m_nComponentID1<<s_Separator
		   <<ref.m_nPort2<<s_Separator
	       <<ref.m_nComponentID2<<s_Separator;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcTriger::EventType(int nValue)
{
	m_nEventType = nValue;
}
/*------------------------------------------------*/
void CalcTriger::ConditionType(int nValue)
{
	m_nConditionType = nValue;
}
/*------------------------------------------------*/
void CalcTriger::Value(double dValue)
{
	m_dValue = dValue;
}
/*------------------------------------------------*/
void CalcTriger::Port1(int nValue)
{
	m_nPort1 = nValue;
}
/*------------------------------------------------*/
void CalcTriger::ComponentID1(int nValue)
{
	m_nComponentID1 = nValue;
}
/*------------------------------------------------*/
void CalcTriger::Port2(int nValue)
{
	m_nPort2 = nValue;
}
/*------------------------------------------------*/
void CalcTriger::ComponentID2(int nValue)
{
	m_nComponentID2 = nValue;
}

/////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcTriger::EventType()
{
	return m_nEventType;
}
/*------------------------------------------------*/
int CalcTriger::ConditionType()
{
	return m_nConditionType;
}
/*------------------------------------------------*/
double CalcTriger::Value()
{
	return m_dValue;
}
/*------------------------------------------------*/
int CalcTriger::Port1()
{
	return m_nPort1;
}
/*------------------------------------------------*/
int CalcTriger::ComponentID1()
{
	return m_nComponentID1;
}
/*------------------------------------------------*/
int CalcTriger::Port2()
{
	return m_nPort2;
}
/*------------------------------------------------*/
int CalcTriger::ComponentID2()
{
	return m_nComponentID2;
}