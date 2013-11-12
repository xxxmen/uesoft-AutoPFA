// PCFSetOnTee.cpp: implementation of the PCFSetOnTee class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSetOnTee.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSetOnTee::PCFSetOnTee()
{
	m_strName = _T("SetOnTee");
	m_nTypeID = 1;
	m_bPFAJun = TRUE;
}

PCFSetOnTee::~PCFSetOnTee()
{

}

void PCFSetOnTee::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	AcGePoint3d BranchPt;

	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
		if( wordArray.GetAt(i) == _T("BRANCH1-POINT") )
		{
			
			BranchPt.x = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			BranchPt.y = _tcstod( UELPCSTR (wordArray.GetAt( i+2 ) ), NULL );
			BranchPt.z = _tcstod( UELPCSTR (wordArray.GetAt( i+3 ) ), NULL );
			i= i+4;
			m_PointList.AddTail(BranchPt);
		}
	}
}

PCFJun* PCFSetOnTee::Creator()
{
	PCFSetOnTee *pObj = new PCFSetOnTee;
	return pObj;		
}



