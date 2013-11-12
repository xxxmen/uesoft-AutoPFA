// CalcAreaChange.cpp: implementation of the CalcAreaChange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAreaChange.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAreaChange::CalcAreaChange()
{
	m_Type = 0;								 
	m_Angle = 0;						
	m_K = 0;							
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;		
}

CalcAreaChange::~CalcAreaChange()
{

}

CalcJun* CalcAreaChange::Creator()
{
	CalcAreaChange *pData = new CalcAreaChange;
	return pData;
}

ostream& CalcAreaChange::Write(ostream &CalcOut)
{

	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_PipeID
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_Type<<s_Separator
		   <<m_Angle<<s_Separator
		   <<m_K<<s_Separator
		   <<m_nBasisAreaType<<s_Separator
		   <<m_dBasisArea<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcAreaChange::Type(int nValue)
{
	m_Type = nValue;
}
/*------------------------------------------------*/
void CalcAreaChange::Angle(double dValue)
{
	m_Angle = dValue;
}
/*------------------------------------------------*/
void CalcAreaChange::K(double dValue)
{
	m_K = dValue;
}
void CalcAreaChange::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcAreaChange::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}

/*------------------------------------------------*/
double CalcAreaChange::K()
{
	return m_K;
}
int CalcAreaChange::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcAreaChange::BasisArea()
{
	return m_dBasisArea;
}