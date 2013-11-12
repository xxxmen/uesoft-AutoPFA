// CalcBend.cpp: implementation of the CalcBend class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBend.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBend::CalcBend()
{
	m_K = 0;							
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;	
}

CalcBend::~CalcBend()
{

}

ostream& CalcBend::Write(ostream &CalcOut)
{

	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_PipeID
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_K<<s_Separator
		   <<m_nBasisAreaType<<s_Separator
		   <<m_dBasisArea<<s_Separator
		   <<endl;
	return CalcOut;
}

CalcJun* CalcBend::Creator()
{
	CalcBend *pData = new CalcBend;
	return pData;
}
/*------------------------------------------------*/
void CalcBend::K(double dValue)
{
	m_K = dValue;
}
void CalcBend::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcBend::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}

/*------------------------------------------------*/
double CalcBend::K()
{
	return m_K;
}
int CalcBend::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcBend::BasisArea()
{
	return m_dBasisArea;
}