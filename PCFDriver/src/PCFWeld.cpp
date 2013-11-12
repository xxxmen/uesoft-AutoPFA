// PCFWeld.cpp: implementation of the PCFWeld class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFWeld.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFWeld::PCFWeld()
{
	m_nTypeID = 104;
}

PCFWeld::~PCFWeld()
{

}

void PCFWeld::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFWeld::Creator()
{
	PCFWeld *pObj = new PCFWeld;
	return pObj;
}


