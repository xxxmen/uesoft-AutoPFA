// PCFFlange.cpp: implementation of the PCFFlange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFFlange.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFFlange::PCFFlange()
{
	m_nTypeID = 100;
}

PCFFlange::~PCFFlange()
{

}

void PCFFlange::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFFlange::Creator()
{
	PCFFlange *pObj = new PCFFlange;
	return pObj;	
}


