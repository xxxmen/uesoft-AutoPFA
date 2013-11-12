// CalcOrifice.cpp: implementation of the CalcOrifice class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcOrifice.h"
#include "CalcOrifice.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcOrifice::CalcOrifice()
{
	m_bModel = 0;				
	m_dInFlowCD = 0;			
	m_dOutFlowCD = 0;			
	m_dArea = 0;	
}

CalcOrifice::~CalcOrifice()
{

}
ostream& operator<< (ostream &CalcOut,const CalcOrifice &ref)
{
	CalcOut<<abs(ref.m_bModel)<<s_Separator
		   <<ref.m_dInFlowCD<<s_Separator
		   <<ref.m_dOutFlowCD<<s_Separator
		   <<ref.m_dArea<<s_Separator;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcOrifice::Model(int nValue)
{
	m_bModel = nValue;
}
/*------------------------------------------------*/
void CalcOrifice::InFlowCD(double dValue)
{
	m_dInFlowCD = dValue;
}
/*------------------------------------------------*/
void CalcOrifice::OutFlowCD(double dValue)
{
	m_dOutFlowCD = dValue;
}
/*------------------------------------------------*/
void CalcOrifice::Area(double dValue)
{
	m_dArea = dValue;
}

///////////////////////////////////////////
/*------------------------------------------------*/
int CalcOrifice::Model()
{
	return abs(m_bModel);
}
/*------------------------------------------------*/
double CalcOrifice::InFlowCD()
{
	return m_dInFlowCD;
}
/*------------------------------------------------*/
double CalcOrifice::OutFlowCD()
{
	return m_dOutFlowCD;
}
/*------------------------------------------------*/
double CalcOrifice::Area()
{
	return m_dArea;
}