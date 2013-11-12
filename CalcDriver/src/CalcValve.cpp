// CalcValve.cpp: implementation of the CalcValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcValve.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcValve::CalcValve()
{
	m_nLossType = 0;                    
	m_dKOrCv = 0;						 
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;						
	m_nType = 0;						    
	m_nExitPressType = 0;					
	m_dExitPress = 0;	
}

CalcValve::~CalcValve()
{

}

CalcJun* CalcValve::Creator()
{
	CalcValve *pData = new CalcValve;
	return pData;
}

ostream& CalcValve::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nLossType<<s_Separator
		   <<m_dKOrCv<<s_Separator
		   <<m_nBasisAreaType<<s_Separator
	       <<m_dBasisArea<<s_Separator
		   <<abs(m_nType)<<s_Separator
		   <<m_nExitPressType<<s_Separator
		   <<m_dExitPress<<s_Separator
		  //  <<m_TranData
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcValve::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcValve::KOrCv(double dValue)
{
	m_dKOrCv = dValue;
}
/*------------------------------------------------*/
void CalcValve::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcValve::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}
/*------------------------------------------------*/
void CalcValve::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcValve::ExitPressType(int nValue)
{
	m_nExitPressType = nValue;
}
/*------------------------------------------------*/
void CalcValve::ExitPress(double dValue)
{
	m_dExitPress = dValue;
}

//////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcValve::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
double CalcValve::KOrCv()
{
	return m_dKOrCv;
}
/*------------------------------------------------*/
int CalcValve::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcValve::BasisArea()
{
	return m_dBasisArea;
}
/*------------------------------------------------*/
int CalcValve::Type()
{
	return abs(m_nType);
}
/*------------------------------------------------*/
int CalcValve::ExitPressType()
{
	return m_nExitPressType;
}
/*------------------------------------------------*/
double CalcValve::ExitPress()
{
	return m_dExitPress;
}