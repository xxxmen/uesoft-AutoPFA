// CalcDeadEnd.cpp: implementation of the CalcDeadEnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcDeadEnd.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcDeadEnd::CalcDeadEnd()
{

}

CalcDeadEnd::~CalcDeadEnd()
{

}

CalcJun* CalcDeadEnd::Creator()
{
	CalcDeadEnd *pData = new CalcDeadEnd;
	return pData;
}

ostream& CalcDeadEnd::Write(ostream &CalcOut)
{

	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeID<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<endl;
	return CalcOut;
}