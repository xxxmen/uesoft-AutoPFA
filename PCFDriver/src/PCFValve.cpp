// PCFValve.cpp: implementation of the PCFValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFValve.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFValve::PCFValve()
{
	m_strName = _T("Valve");
	m_nTypeID = 8;
	m_bPFAJun = TRUE;
}

PCFValve::~PCFValve()
{

}

void PCFValve::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
       SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFValve::Creator()
{
	PCFValve *pObj = new PCFValve;
	return pObj;	
}


