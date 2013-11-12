// PCFTee.cpp: implementation of the PCFTee class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFTee.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFTee::PCFTee()
{
	m_strName = _T("Tee");
	m_nTypeID = 7;
	m_bPFAJun = TRUE;
	m_dAngel = 90;
	m_dInDia1 = 0;
	m_dInDia2 = 0;
	m_dInDia3 = 0;
}

PCFTee::~PCFTee()
{

}

void PCFTee::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	AcGePoint3d BranchPt;

	for(int i = 0; i < wordNum; i++)
	{
		SetSEBPoint(wordArray, i, pointNum, m_PointList, m_CenterPt);
		if( wordArray.GetAt(i) == _T("BRANCH1-POINT") )
		{
			
			BranchPt.x = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			BranchPt.y = _tcstod( UELPCSTR (wordArray.GetAt( i+2 ) ), NULL );
			BranchPt.z = _tcstod( UELPCSTR (wordArray.GetAt( i+3 ) ), NULL );
			i= i+4;
			m_PointList.AddTail(BranchPt);
		}
		
		if ( wordArray.GetAt(i) == _T("End-IN-DIA"))
		{
			m_dInDia1 = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			m_dInDia2 = _tcstod( UELPCSTR (wordArray.GetAt( i+2 ) ), NULL );
			m_dInDia3 = _tcstod( UELPCSTR (wordArray.GetAt( i+3 ) ), NULL );
			i=i+4;
			continue;
		}
		if ( wordArray.GetAt(i) == _T("ANGLE"))
		{
			m_dAngel = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
	}
}

PCFJun* PCFTee::Creator()
{
	PCFTee *pObj = new PCFTee;
	return pObj;	
}


