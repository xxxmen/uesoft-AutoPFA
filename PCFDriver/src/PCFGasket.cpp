// PCFGasket.cpp: implementation of the PCFGasket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFGasket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFGasket::PCFGasket()
{
	m_nTypeID = 101;
}

PCFGasket::~PCFGasket()
{

}

void PCFGasket::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFGasket::Creator()
{
	PCFGasket *pObj = new PCFGasket;
	return pObj;	
}


