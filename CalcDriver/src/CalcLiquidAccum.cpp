// CalcLiquidAccum.cpp: implementation of the CalcLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcLiquidAccum.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcLiquidAccum::CalcLiquidAccum()
{
	m_dElastic = 0;				 
	m_dInitVolume = 0;	
}

CalcLiquidAccum::~CalcLiquidAccum()
{

}

CalcJun* CalcLiquidAccum::Creator()
{
	CalcLiquidAccum *pData = new CalcLiquidAccum;
	return pData;
}

ostream& CalcLiquidAccum::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dElastic<<s_Separator
		   <<m_dInitVolume<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcLiquidAccum::Elastic(double dValue)
{
	m_dElastic = dValue;
}
/*------------------------------------------------*/
void CalcLiquidAccum::InitVolume(double dValue)
{
	m_dInitVolume = dValue;
}


///////////////////////////////////////////////////////
/*------------------------------------------------*/
double CalcLiquidAccum::Elastic()
{
	return m_dElastic;
}
/*------------------------------------------------*/
double CalcLiquidAccum::InitVolume()
{
	return m_dInitVolume;
}