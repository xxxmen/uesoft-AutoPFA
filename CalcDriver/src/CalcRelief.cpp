// CalcRelief.cpp: implementation of the CalcRelief class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcRelief.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcRelief::CalcRelief()
{
	m_nType = 0;
	m_nLossType = 0;
	m_nPressType = 0;					  
	m_dCrackPress = 0;				      
	m_dExitPress = 0;					   
	m_dKOrCv = 0;						   
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;	
}

CalcRelief::~CalcRelief()
{

}

CalcJun* CalcRelief::Creator()
{
	CalcRelief *pData = new CalcRelief;
	return pData;
}

ostream& CalcRelief::Write(ostream &CalcOut)
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
		   <<m_nType<<s_Separator
		   <<m_nLossType<<s_Separator
		   <<m_dKOrCv<<s_Separator
		   <<m_Curve<<s_Separator;
	if(m_Curve.CurveType()==2)
	{
		CalcOut<<m_CurveData<<s_Separator;
	}
    CalcOut<<m_nBasisAreaType<<s_Separator
		   <<m_dBasisArea<<s_Separator
		   <<m_nPressType<<s_Separator
		   <<m_dCrackPress<<s_Separator
		   <<m_dExitPress<<s_Separator
//		   <<m_TranData.ValueType()<<s_Separator
//		   <<m_TranData.m_TranData1
//		   <<m_TranData.m_TranData2
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcRelief::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcRelief::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcRelief::PressType(int nValue)
{
	m_nPressType = nValue;
}
/*------------------------------------------------*/
void CalcRelief::CrackPress(double dValue)
{
	m_dCrackPress = dValue;
}
/*------------------------------------------------*/
void CalcRelief::ExitPress(double dValue)
{
	m_dExitPress = dValue;
}
/*------------------------------------------------*/
void CalcRelief::KOrCv(double dValue)
{
	m_dKOrCv = dValue;
}
/*------------------------------------------------*/
void CalcRelief::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcRelief::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}


////////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcRelief::Type()
{
	return m_nType;
}
/*------------------------------------------------*/
int CalcRelief::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
int CalcRelief::PressType()
{
	return m_nPressType;
}
/*------------------------------------------------*/
double CalcRelief::CrackPress()
{
	return m_dCrackPress;
}
/*------------------------------------------------*/
double CalcRelief::ExitPress()
{
	return m_dExitPress;
}
/*------------------------------------------------*/
double CalcRelief::KOrCv()
{
	return m_dKOrCv;
}
/*------------------------------------------------*/
int CalcRelief::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcRelief::BasisArea()
{
	return m_dBasisArea;
}