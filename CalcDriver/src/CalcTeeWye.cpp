// CalcTeeWye.cpp: implementation of the CalcTeeWye class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTeeWye.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTeeWye::CalcTeeWye()
{
	m_dAngle = 0;		
	m_nModel = 0;			
	m_nType  = 0;	
}

CalcTeeWye::~CalcTeeWye()
{

}

CalcJun* CalcTeeWye::Creator()
{
	CalcTeeWye *pData = new CalcTeeWye;
	return pData;
}

ostream& CalcTeeWye::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
		   <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nModel<<s_Separator
		   <<m_dAngle<<s_Separator
		   <<m_nType<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcTeeWye::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcTeeWye::Angle(double dValue)
{
	m_dAngle = dValue;
}
/*------------------------------------------------*/
void CalcTeeWye::Model(int nValue)
{
	m_nModel = nValue;
}


//////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcTeeWye::Type()
{
	return m_nType;
}
/*------------------------------------------------*/
double CalcTeeWye::Angle()
{
	return m_dAngle;
}
/*------------------------------------------------*/
int CalcTeeWye::Model()
{
	return m_nModel;
}