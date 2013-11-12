// PCFFilter.cpp: implementation of the PCFFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFFilter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFFilter::PCFFilter()
{

}

PCFFilter::~PCFFilter()
{

}

void PCFFilter::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFFilter::Creator()
{
	PCFFilter *pObj = new PCFFilter;
	return pObj;	
}

