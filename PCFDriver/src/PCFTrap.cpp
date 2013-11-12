// PCFTrap.cpp: implementation of the PCFTrap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFTrap.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFTrap::PCFTrap()
{
	m_nTypeID = 103;
}

PCFTrap::~PCFTrap()
{

}

void PCFTrap::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFTrap::Creator()
{
	PCFTrap *pObj = new PCFTrap;
	return pObj;		
}


