// CaclSteady.cpp: implementation of the CaclSteady class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CaclSteady.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSteady::CalcSteady()
{
	m_AnalysisType = 0;			
	m_PresTolType = 0;
	m_PresAbsTolType = 1;
	m_PresAbsTol = 0;		
	m_PresRelTol = 0;	  
	m_FlowTolType = 0;
	m_FlowAbsTolType = 1;
	m_FlowAbsTol = 0;	
	m_FlowRelTol = 0;
	m_FlowRelaxation=0;	
	m_PresRelaxation=0;
    m_MaxIterations = 0;		
	m_KeepHistory = 0;	
	m_bUserGiveSteadyInitValue = 0;
}

CalcSteady::~CalcSteady()
{

}

ostream& operator<<(ostream &CalcOut,const CalcSteady &ref)
{
	CalcOut<<ref.m_PresTolType<<s_Separator
		   <<ref.m_PresAbsTolType<<s_Separator
		   <<ref.m_PresAbsTol<<s_Separator
		   <<ref.m_PresRelTol<<s_Separator
		   <<ref.m_FlowTolType<<s_Separator
		   <<ref.m_FlowAbsTolType<<s_Separator
		   <<ref.m_FlowAbsTol<<s_Separator
		   <<ref.m_FlowRelTol<<s_Separator
		   <<ref.m_MaxIterations<<s_Separator
		   <<ref.m_bUserGiveSteadyInitValue<<s_Separator
		   <<endl;
	return CalcOut;
}

int CalcSteady::AnalysisType()
{
	return m_AnalysisType;
}

/*------------------------------------------------*/
void CalcSteady::AnalysisType(int nValue)
{
	m_AnalysisType = nValue;
}
/*------------------------------------------------*/
void CalcSteady::PresTolType(int nValue)
{
	m_PresTolType = nValue;
}
/*------------------------------------------------*/
void CalcSteady::PresAbsTolType(int nValue)
{
	m_PresAbsTolType = nValue;
}
/*------------------------------------------------*/
void CalcSteady::PresAbsTol(double dValue)
{
	m_PresAbsTol = dValue;
}
/*------------------------------------------------*/
void CalcSteady::PresRelTol(double dValue)
{
	m_PresRelTol = dValue;
}
/*------------------------------------------------*/
void CalcSteady::FlowTolType(int nValue)
{
	m_FlowTolType = nValue;
}
/*------------------------------------------------*/
void CalcSteady::FlowAbsTolType(int nValue)
{
	m_FlowAbsTolType = nValue;
}
/*------------------------------------------------*/
void CalcSteady::FlowAbsTol(double dValue)
{
	m_FlowAbsTol = dValue;
}
/*------------------------------------------------*/
void CalcSteady::FlowRelTol(double dValue)
{
	m_FlowRelTol = dValue;
}
/*------------------------------------------------*/
void CalcSteady::MaxIterations(int nValue)
{
	m_MaxIterations = nValue;
}
/*------------------------------------------------*/
void CalcSteady::KeepHistory(int nValue)
{
	m_KeepHistory = nValue;
}
/*------------------------------------------------*/
/*------------------------------------------------*/
void CalcSteady::FlowRelaxation(double dValue)
{
	m_FlowRelaxation = dValue;
}
/*------------------------------------------------*/
void CalcSteady::PresRelaxation(double dValue)
{
	m_PresRelaxation = dValue;
}
///////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcSteady::PresTolType()
{
	return m_PresTolType;
}
/*------------------------------------------------*/
int CalcSteady::PresAbsTolType()
{
	return m_PresAbsTolType;
}
/*------------------------------------------------*/
double CalcSteady::PresAbsTol()
{
	return m_PresAbsTol;
}
/*------------------------------------------------*/
double CalcSteady::PresRelTol()
{
	return m_PresRelTol;
}
/*------------------------------------------------*/
int CalcSteady::FlowTolType()
{
	return m_FlowTolType;
}
/*------------------------------------------------*/
int CalcSteady::FlowAbsTolType()
{
	return m_FlowAbsTolType;
}
/*------------------------------------------------*/
double CalcSteady::FlowAbsTol()
{
	return m_FlowAbsTol;
}
/*------------------------------------------------*/
double CalcSteady::FlowRelTol()
{
	return m_FlowRelTol;
}
/*------------------------------------------------*/
int CalcSteady::MaxIterations()
{
	return m_MaxIterations;
}
/*------------------------------------------------*/
int CalcSteady::KeepHistory()
{
	return m_KeepHistory;
}
/*------------------------------------------------*/
/*------------------------------------------------*/
double CalcSteady::FlowRelaxation()
{
	return m_FlowRelaxation;
}
/*------------------------------------------------*/
double CalcSteady::PresRelaxation()
{
	return m_PresRelaxation;
}