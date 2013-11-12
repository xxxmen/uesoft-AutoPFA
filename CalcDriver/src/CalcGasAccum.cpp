// CalcGasAccum.cpp: implementation of the CalcGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcGasAccum.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcGasAccum::CalcGasAccum()
{
	m_dPolytropic = 0;				
	m_nType = 0;				
	m_dInitVolume = 0;				
	m_dRefPress = 0;				   
	m_dMaxVolume = 0;					 
	m_dMinVolume = 0;					  											
	m_bSelInitPress = 0;					 
	m_nInitPressType = 0;					  
	m_dInitPress = 0;	
}

CalcGasAccum::~CalcGasAccum()
{

}

CalcJun* CalcGasAccum::Creator()
{
	CalcGasAccum *pData = new CalcGasAccum;
	return pData;
}

ostream& CalcGasAccum::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dPolytropic<<s_Separator
		   <<m_nType<<s_Separator
		   <<m_dInitVolume<<s_Separator
		   <<m_dInitVolume<<s_Separator
		   <<m_dRefPress<<s_Separator
		   <<m_dMaxVolume<<s_Separator
		   <<m_dMinVolume<<s_Separator
		   <<m_Orifice<<s_Separator
		   <<m_ShortPipe<<s_Separator
		   <<abs(m_bSelInitPress)<<s_Separator
		   <<m_nInitPressType<<s_Separator
		   <<m_dInitPress<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcGasAccum::Polytropic(double dValue)
{
	m_dPolytropic = dValue;
}
/*------------------------------------------------*/
void CalcGasAccum::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcGasAccum::InitVolume(double dValue)
{
	m_dInitVolume = dValue;
}
/*------------------------------------------------*/
void CalcGasAccum::RefPress(double dValue)
{
	m_dRefPress = dValue;
}
/*------------------------------------------------*/
void CalcGasAccum::MaxVolume(double dValue)
{
	m_dMaxVolume = dValue;
}
/*------------------------------------------------*/
void CalcGasAccum::MinVolume(double dValue)
{
	m_dMinVolume = dValue;
}
/*------------------------------------------------*/
void CalcGasAccum::SelInitPress(int nValue)
{
	m_bSelInitPress = nValue;
}
/*------------------------------------------------*/
void CalcGasAccum::InitPressType(int nValue)
{
	m_nInitPressType = nValue;
}
/*------------------------------------------------*/
void CalcGasAccum::InitPress(double dValue)
{
	m_dInitPress = dValue;
}


////////////////////////////////////////////////////////////
/*------------------------------------------------*/
double CalcGasAccum::Polytropic()
{
	return m_dPolytropic;
}
/*------------------------------------------------*/
int CalcGasAccum::Type()
{
	return m_nType;
}
/*------------------------------------------------*/
double CalcGasAccum::InitVolume()
{
	return m_dInitVolume;
}
/*------------------------------------------------*/
double CalcGasAccum::RefPress()
{
	return m_dRefPress;
}
/*------------------------------------------------*/
double CalcGasAccum::MaxVolume()
{
	return m_dMaxVolume;
}
/*------------------------------------------------*/
double CalcGasAccum::MinVolume()
{
	return m_dMinVolume;
}
/*------------------------------------------------*/
int CalcGasAccum::SelInitPress()
{
	return abs(m_bSelInitPress);
}
/*------------------------------------------------*/
int CalcGasAccum::InitPressType()
{
	return m_nInitPressType;
}
/*------------------------------------------------*/
double CalcGasAccum::InitPress()
{
	return m_dInitPress;
}