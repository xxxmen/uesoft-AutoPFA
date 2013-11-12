// CalcBrach.cpp: implementation of the CalcBrach class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBrach.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBrach::CalcBrach()
{
	m_nImposeFlowType = 0;	
	m_dImposeFlow = 0;		
}

CalcBrach::~CalcBrach()
{

}

CalcJun* CalcBrach::Creator()
{
	CalcBrach *pData = new CalcBrach;
	return pData;
}

ostream& CalcBrach::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeInfo<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nImposeFlowType<<s_Separator
		   <<m_dImposeFlow<<s_Separator
		   //<<m_TranData
		   <<endl;
	return CalcOut;
}

void CalcBrach::PipeInfo(const ListImp<StrArray<4> >& ref)
{
	m_PipeInfo.SetData(ref);
}

/*------------------------------------------------*/
void CalcBrach::ImposeFlowType(int nValue)
{
	m_nImposeFlowType = nValue;
}
/*------------------------------------------------*/
void CalcBrach::ImposeFlow(double dValue)
{
	m_dImposeFlow = dValue;
}

ListImp<StrArray<4> >& CalcBrach::PipeInfo()
{
	return m_PipeInfo.GetData();
}

/*------------------------------------------------*/
int CalcBrach::ImposeFlowType()
{
	return m_nImposeFlowType;
}
/*------------------------------------------------*/
double CalcBrach::ImposeFlow()
{
	return m_dImposeFlow;
}