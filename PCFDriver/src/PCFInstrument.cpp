// PCFInstrument.cpp: implementation of the PCFInstrument class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFInstrument.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFInstrument::PCFInstrument()
{

}

PCFInstrument::~PCFInstrument()
{

}

void PCFInstrument::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetSEBPoint(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFInstrument::Creator()
{
	PCFInstrument *pObj = new PCFInstrument;
	return pObj;	
}

