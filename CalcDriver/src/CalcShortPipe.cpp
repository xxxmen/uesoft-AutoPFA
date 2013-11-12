// CalcShortPipe.cpp: implementation of the CalcShortPipe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcShortPipe.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcShortPipe::CalcShortPipe()
{
	m_bModel = 0;				
	m_dFriction = 0;		
	m_dArea = 0;			
	m_dInDia = 0;			
	m_dLen = 0;				
	m_dEle = 0;		
}

CalcShortPipe::~CalcShortPipe()
{

}

ostream& operator<< (ostream &CalcOut,const CalcShortPipe &ref)
{
	CalcOut<<abs(ref.m_bModel)<<s_Separator
		   <<ref.m_dInDia<<s_Separator
		   <<ref.m_dArea<<s_Separator
		   <<ref.m_dLen<<s_Separator
		   <<ref.m_dEle<<s_Separator
		   <<ref.m_dFriction<<s_Separator;
		   
	return CalcOut;
}

/*------------------------------------------------*/
void CalcShortPipe::Model(int nValue)
{
	m_bModel = nValue;
}
/*------------------------------------------------*/
void CalcShortPipe::Friction(double dValue)
{
	m_dFriction = dValue;
}
/*------------------------------------------------*/
void CalcShortPipe::Area(double dValue)
{
	m_dArea = dValue;
}
/*------------------------------------------------*/
void CalcShortPipe::InDia(double dValue)
{
	m_dInDia = dValue;
}
/*------------------------------------------------*/
void CalcShortPipe::Len(double dValue)
{
	m_dLen = dValue;
}
/*------------------------------------------------*/
void CalcShortPipe::Ele(double dValue)
{
	m_dEle = dValue;
}

/////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcShortPipe::Model()
{
	return abs(m_bModel);
}
/*------------------------------------------------*/
double CalcShortPipe::Friction()
{
	return m_dFriction;
}
/*------------------------------------------------*/
double CalcShortPipe::Area()
{
	return m_dArea;
}
/*------------------------------------------------*/
double CalcShortPipe::InDia()
{
	return m_dInDia;
}
/*------------------------------------------------*/
double CalcShortPipe::Len()
{
	return m_dLen;
}
/*------------------------------------------------*/
double CalcShortPipe::Ele()
{
	return m_dEle;
}