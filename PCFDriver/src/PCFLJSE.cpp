// PCFLJSE.cpp: implementation of the PCFLJSE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFLJSE.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFLJSE::PCFLJSE()
{

}

PCFLJSE::~PCFLJSE()
{

}

void PCFLJSE::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFLJSE::Creator()
{
	PCFLJSE *pObj = new PCFLJSE;
	return pObj;	
}

