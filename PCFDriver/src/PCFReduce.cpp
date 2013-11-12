// PCFReduce.cpp: implementation of the PCFReduce class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFReduce.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFReduce::PCFReduce()
{
	m_strName = _T("Òì¾¶¹Ü");
	m_nTypeID = 5;
	m_bPFAJun = TRUE;
}

PCFReduce::~PCFReduce()
{

}

void PCFReduce::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFReduce::Creator()
{
	PCFReduce *pObj = new PCFReduce;
	return pObj;	
}


