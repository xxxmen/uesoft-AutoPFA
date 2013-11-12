// CalcCheck.cpp: implementation of the CalcCheck class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcCheck.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcCheck::CalcCheck()
{
	m_nLossType = 0;						    	                                           
	m_dKOrCv = 0;					        
    m_nBasisAreaType = 0;		
	m_dBasisArea = 0;					
	m_nReOpenPressType = 0;			
	m_dReOpenPress = 0;				
	m_dCloseVel = 0;
}

CalcCheck::~CalcCheck()
{

}

CalcJun* CalcCheck::Creator()
{
	CalcCheck *pData = new CalcCheck;
	return pData;
}

ostream& CalcCheck::Write(ostream &CalcOut)
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
		   <<m_nReOpenPressType<<s_Separator
		   <<m_dReOpenPress<<s_Separator
		   <<m_dCloseVel<<s_Separator
//		   <<m_TranData.Special()<<s_Separator
//		   <<m_TranData.ValueType()<<s_Separator
//		   <<m_TranData.m_TranData1
//		   <<m_TranData.m_TranData2
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcCheck::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcCheck::KOrCv(double dValue)
{
	m_dKOrCv = dValue;
}
/*------------------------------------------------*/
void CalcCheck::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcCheck::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}
/*------------------------------------------------*/
void CalcCheck::ReOpenPressType(int nValue)
{
	m_nReOpenPressType = nValue;
}
/*------------------------------------------------*/
void CalcCheck::ReOpenPress(double dValue)
{
	m_dReOpenPress = dValue;
}
/*------------------------------------------------*/
void CalcCheck::CloseVel(double dValue)
{
	m_dCloseVel = dValue;
}

/////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcCheck::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
double CalcCheck::KOrCv()
{
	return m_dKOrCv;
}
/*------------------------------------------------*/
int CalcCheck::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcCheck::BasisArea()
{
	return m_dBasisArea;
}
/*------------------------------------------------*/
int CalcCheck::ReOpenPressType()
{
	return m_nReOpenPressType;
}
/*------------------------------------------------*/
double CalcCheck::ReOpenPress()
{
	return m_dReOpenPress;
}
/*------------------------------------------------*/
double CalcCheck::CloseVel()
{
	return m_dCloseVel;
}