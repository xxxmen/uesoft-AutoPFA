// CalcBrecker.cpp: implementation of the CalcBrecker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBrecker.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBrecker::CalcBrecker()
{
	m_nType = 0;			           
	m_dOrificeInCdA = 0;		        
	m_dOrificeOutCdA = 0;			     
	m_dInterMediateCdA = 0;			    
	m_nMediateActivationType = 0;		
	m_dMediateActivation = 0;          
	m_nCrackPressType = 0;				
	m_dCrackPress = 0;				     
	m_nLiquidTempType = 0;				
	m_dLiquidTemp = 0;				
	m_dGasWeight = 0;				
	m_dCpCv = 0;                        
	m_dGasTemp = 0;						
	m_dGasPress = 0;				  
	m_dGasMass = 0;					
	m_nConnectPipe = 0;				
}

CalcBrecker::~CalcBrecker()
{

}

CalcJun* CalcBrecker::Creator()
{
	CalcBrecker *pData = new CalcBrecker;
	return pData;
}

ostream& CalcBrecker::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nType<<s_Separator
		   <<m_dOrificeInCdA<<s_Separator
		   <<m_dOrificeOutCdA<<s_Separator
		   <<m_dInterMediateCdA<<s_Separator
		   <<m_nMediateActivationType<<s_Separator
		   <<m_dMediateActivation<<s_Separator
		   <<m_dGasWeight<<s_Separator
		   <<m_dCpCv<<s_Separator
		   <<m_dGasPress<<s_Separator
		   <<m_dGasTemp<<s_Separator
		   <<m_dGasMass<<s_Separator
		   <<m_nCrackPressType<<s_Separator
		   <<m_dCrackPress<<s_Separator
		   <<m_nLiquidTempType<<s_Separator
		   <<m_dLiquidTemp<<s_Separator
		   //<<m_nConnectPipe<<s_Separator
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcBrecker::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcBrecker::OrificeInCdA(double dValue)
{
	m_dOrificeInCdA = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::OrificeOutCdA(double dValue)
{
	m_dOrificeOutCdA = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::InterMediateCdA(double dValue)
{
	m_dInterMediateCdA = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::MediateActivationType(int nValue)
{
	m_nMediateActivationType = nValue;
}
/*------------------------------------------------*/
void CalcBrecker::MediateActivation(double dValue)
{
	m_dMediateActivation = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::CrackPressType(int nValue)
{
	m_nCrackPressType = nValue;
}
/*------------------------------------------------*/
void CalcBrecker::CrackPress(double dValue)
{
	m_dCrackPress = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::LiquidTempType(int nValue)
{
	m_nLiquidTempType = nValue;
}
/*------------------------------------------------*/
void CalcBrecker::LiquidTemp(double dValue)
{
	m_dLiquidTemp = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::GasWeight(double dValue)
{
	m_dGasWeight = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::CpCv(double dValue)
{
	m_dCpCv = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::GasTemp(double dValue)
{
	m_dGasTemp = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::GasPress(double dValue)
{
	m_dGasPress = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::GasMass(double dValue)
{
	m_dGasMass = dValue;
}
/*------------------------------------------------*/
void CalcBrecker::ConnectPipe(int nValue)
{
	m_nConnectPipe = nValue;
}

/////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcBrecker::Type()
{
	return m_nType;
}
/*------------------------------------------------*/
double CalcBrecker::OrificeInCdA()
{
	return m_dOrificeInCdA;
}
/*------------------------------------------------*/
double CalcBrecker::OrificeOutCdA()
{
	return m_dOrificeOutCdA;
}
/*------------------------------------------------*/
double CalcBrecker::InterMediateCdA()
{
	return m_dInterMediateCdA;
}
/*------------------------------------------------*/
int CalcBrecker::MediateActivationType()
{
	return m_nMediateActivationType;
}
/*------------------------------------------------*/
double CalcBrecker::MediateActivation()
{
	return m_dMediateActivation;
}
/*------------------------------------------------*/
int CalcBrecker::CrackPressType()
{
	return m_nCrackPressType;
}
/*------------------------------------------------*/
double CalcBrecker::CrackPress()
{
	return m_dCrackPress;
}
/*------------------------------------------------*/
int CalcBrecker::LiquidTempType()
{
	return m_nLiquidTempType;
}
/*------------------------------------------------*/
double CalcBrecker::LiquidTemp()
{
	return m_dLiquidTemp;
}
/*------------------------------------------------*/
double CalcBrecker::GasWeight()
{
	return m_dGasWeight;
}
/*------------------------------------------------*/
double CalcBrecker::CpCv()
{
	return m_dCpCv;
}
/*------------------------------------------------*/
double CalcBrecker::GasTemp()
{
	return m_dGasTemp;
}
/*------------------------------------------------*/
double CalcBrecker::GasPress()
{
	return m_dGasPress;
}
/*------------------------------------------------*/
double CalcBrecker::GasMass()
{
	return m_dGasMass;
}
/*------------------------------------------------*/
int CalcBrecker::ConnectPipe()
{
	return m_nConnectPipe;
}