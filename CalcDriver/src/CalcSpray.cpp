// CalcSpray.cpp: implementation of the CalcSpray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcSpray.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSpray::CalcSpray()
{
	m_nHoleNum = 0;
	m_nLossType = 0;
	m_dExitArea = 0;					
	m_dKOrCv = 0;					    
    m_nExitPressType = 0;				
	m_dExitPress = 0;
}

CalcSpray::~CalcSpray()
{

}

CalcJun* CalcSpray::Creator()
{
	CalcSpray *pData = new CalcSpray;
	return pData;
}

ostream& CalcSpray::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator 
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nLossType<<s_Separator
		   <<m_dKOrCv<<s_Separator
		   <<m_dExitArea<<s_Separator
		   <<m_dKOrCv<<s_Separator
		   <<m_nHoleNum<<s_Separator
		   <<m_nExitPressType<<s_Separator
		   <<m_dExitPress<<s_Separator
		  //  <<m_TranData
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcSpray::HoleNum(int nValue)
{
	m_nHoleNum = nValue;
}
/*------------------------------------------------*/
void CalcSpray::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcSpray::ExitArea(double dValue)
{
	m_dExitArea = dValue;
}
/*------------------------------------------------*/
void CalcSpray::KOrCv(double dValue)
{
	m_dKOrCv = dValue;
}
/*------------------------------------------------*/
void CalcSpray::ExitPressType(int nValue)
{
	m_nExitPressType = nValue;
}
/*------------------------------------------------*/
void CalcSpray::ExitPress(double dValue)
{
	m_dExitPress = dValue;
}


//////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcSpray::HoleNum()
{
	return m_nHoleNum;
}
/*------------------------------------------------*/
int CalcSpray::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
double CalcSpray::ExitArea()
{
	return m_dExitArea;
}
/*------------------------------------------------*/
double CalcSpray::KOrCv()
{
	return m_dKOrCv;
}
/*------------------------------------------------*/
int CalcSpray::ExitPressType()
{
	return m_nExitPressType;
}
/*------------------------------------------------*/
double CalcSpray::ExitPress()
{
	return m_dExitPress;
}