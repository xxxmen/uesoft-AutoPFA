// PCFFBlind.cpp: implementation of the PCFFBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFFBlind.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFFBlind::PCFFBlind()
{

}

PCFFBlind::~PCFFBlind()
{

}

void PCFFBlind::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}	
}

PCFJun* PCFFBlind::Creator()
{
	PCFFBlind *pObj = new PCFFBlind;
	return pObj;	
}


