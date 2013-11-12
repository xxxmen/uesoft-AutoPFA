// CalcGeneral.cpp: implementation of the CalcGeneral class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcGeneral.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcGeneral::CalcGeneral()
{
	m_nLossType = 0;                       
	m_dK = 0;							
	m_nBasisAreaType = 0;			
	m_dBasisArea = 0;	
}

CalcGeneral::~CalcGeneral()
{

}

CalcJun* CalcGeneral::Creator()
{
	CalcGeneral *pData = new CalcGeneral;
	return pData;
}

ostream& CalcGeneral::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_PipeID<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nLossType<<s_Separator
		   <<m_dK<<s_Separator
		   <<m_Curve.XAxisType()<<s_Separator
		   <<m_Curve.YAxisType()<<s_Separator
		   <<m_Curve<<s_Separator;
		   if(m_Curve.CurveType()==2)
		   {
			   CalcOut<<m_CurveData;
		   }
	CalcOut<<m_nBasisAreaType<<s_Separator
		   <<m_dBasisArea<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcGeneral::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcGeneral::K(double dValue)
{
	m_dK = dValue;
}
/*------------------------------------------------*/
void CalcGeneral::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcGeneral::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}

///////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcGeneral::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
double CalcGeneral::K()
{
	return m_dK;
}
/*------------------------------------------------*/
int CalcGeneral::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcGeneral::BasisArea()
{
	return m_dBasisArea;
}