// PCFCoupling.cpp: implementation of the PCFCoupling class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFCoupling.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFCoupling::PCFCoupling()
{

}

PCFCoupling::~PCFCoupling()
{

}

void PCFCoupling::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFCoupling::Creator()
{
	PCFCoupling *pObj = new PCFCoupling;
	return pObj;		
}

