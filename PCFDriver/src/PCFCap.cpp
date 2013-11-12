// PCFCap.cpp: implementation of the PCFCap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFCap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFCap::PCFCap()
{
	m_strName = _T("Cap");
	m_nTypeID = 11;
	m_bPFAJun = TRUE;
}

PCFCap::~PCFCap()
{

}

void PCFCap::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFCap::Creator()
{
	PCFCap *pObj = new PCFCap;
	return pObj;	
}


