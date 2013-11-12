// CalcPipe.cpp: implementation of the CalcPipe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPipe.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPipe::CalcPipe()
{
	m_nKey = 0;					
	m_nInJunID = 0;				  
	m_nOutJunID = 0;			
	m_dInDia = 0;			
	m_dLen = 0;			    
	m_nInEleNum = 0;				
	m_nPartFull = 0;			
	m_dFullRate = 1;			
	m_nInitFlowType = 0;		
	m_dInitFlow = 0;			
	m_dPipeFactor = 0;		
	m_dFitFactor = 0;			
	m_dLocalK = 0;				
	m_nFrictionModel = 0;		
	m_dFriction = 0;				
	m_dWaveSpeed = 0;	
	m_nSectionNum = 0;			
	m_dInDiaReduce = 0;	
	m_dB = 0;
}

CalcPipe::~CalcPipe()
{

}

ostream& operator<<(ostream &CalcOut,const CalcPipe &ref)
{
	CalcOut<<ref.m_nKey<<s_Separator
		   <<ref.m_nInJunID<<s_Separator
		   <<ref.m_nOutJunID<<s_Separator
		   <<ref.m_dInDia<<s_Separator
		   <<ref.m_dLen<<s_Separator
		   <<ref.m_nInEleNum<<s_Separator
		   <<ref.m_nPartFull<<s_Separator
		   <<ref.m_dFullRate<<s_Separator
		   <<ref.m_nInitFlowType<<s_Separator
		   <<ref.m_dInitFlow<<s_Separator
		   <<ref.m_dPipeFactor<<s_Separator
		   <<ref.m_dFitFactor<<s_Separator
		   <<ref.m_dLocalK<<s_Separator
		   <<ref.m_nFrictionModel<<s_Separator
		   <<ref.m_dFriction<<s_Separator
		   <<ref.m_dWaveSpeed<<s_Separator
		   <<ref.m_nSectionNum<<s_Separator
		   <<ref.m_dInDiaReduce<<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcPipe::Key(int nValue)
{
	m_nKey = nValue;
}
/*------------------------------------------------*/
void CalcPipe::InJunID(int nValue)
{
	m_nInJunID = nValue;
}
/*------------------------------------------------*/
void CalcPipe::OutJunID(int nValue)
{
	m_nOutJunID = nValue;
}
/*------------------------------------------------*/
void CalcPipe::InDia(double dValue)
{
	m_dInDia = dValue;
}
/*------------------------------------------------*/
void CalcPipe::Len(double dValue)
{
	m_dLen = dValue;
}
/*------------------------------------------------*/
void CalcPipe::InitFlowType(int nValue)
{
	m_nInitFlowType = nValue;
}
/*------------------------------------------------*/
void CalcPipe::InitFlow(double dValue)
{
	m_dInitFlow = dValue;
}
/*------------------------------------------------*/
void CalcPipe::PipeFactor(double dValue)
{
	m_dPipeFactor = dValue;
}
/*------------------------------------------------*/
void CalcPipe::FitFactor(double dValue)
{
	m_dFitFactor = dValue;
}
/*------------------------------------------------*/
void CalcPipe::LocalK(double dValue)
{
	m_dLocalK = dValue;
}
/*------------------------------------------------*/
void CalcPipe::FrictionModel(int nValue)
{
	m_nFrictionModel = nValue;
}
/*------------------------------------------------*/
void CalcPipe::Friction(double dValue)
{
	m_dFriction = dValue;
}
/*------------------------------------------------*/
void CalcPipe::B(double dValue)
{
	m_dB = dValue;
}
/*------------------------------------------------*/
void CalcPipe::WaveSpeed(double dValue)
{
	m_dWaveSpeed = dValue;
}
/*------------------------------------------------*/
void CalcPipe::SectionNum(int nValue)
{
	m_nSectionNum = nValue;
}
/*------------------------------------------------*/
void CalcPipe::InDiaReduce(double dValue)
{
	m_dInDiaReduce = dValue;
}


//////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcPipe::Key()
{
	return m_nKey;
}
/*------------------------------------------------*/
int CalcPipe::InJunID()
{
	return m_nInJunID;
}
/*------------------------------------------------*/
int CalcPipe::OutJunID()
{
	return m_nOutJunID;
}
/*------------------------------------------------*/
double CalcPipe::InDia()
{
	return m_dInDia;
}
/*------------------------------------------------*/
double CalcPipe::Len()
{
	return m_dLen;
}
/*------------------------------------------------*/
int CalcPipe::InitFlowType()
{
	return m_nInitFlowType;
}
/*------------------------------------------------*/
double CalcPipe::InitFlow()
{
	return m_dInitFlow;
}
/*------------------------------------------------*/
double CalcPipe::PipeFactor()
{
	return m_dPipeFactor;
}
/*------------------------------------------------*/
double CalcPipe::FitFactor()
{
	return m_dFitFactor;
}
/*------------------------------------------------*/
double CalcPipe::LocalK()
{
	return m_dLocalK;
}
/*------------------------------------------------*/
int CalcPipe::FrictionModel()
{
	return m_nFrictionModel;
}
/*------------------------------------------------*/
double CalcPipe::Friction()
{
	return m_dFriction;
}
/*------------------------------------------------*/
double CalcPipe::B()
{
	return m_dB;
}
/*------------------------------------------------*/
double CalcPipe::WaveSpeed()
{
	return m_dWaveSpeed;
}
/*------------------------------------------------*/
int CalcPipe::SectionNum()
{
	return m_nSectionNum;
}
/*------------------------------------------------*/
double CalcPipe::InDiaReduce()
{
	return m_dInDiaReduce;
}