// PCFCross.cpp: implementation of the PCFCross class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFCross.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFCross::PCFCross()
{

}

PCFCross::~PCFCross()
{

}

void PCFCross::Init( const CStringArray& wordArray )
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
		if( wordArray.GetAt(i) == _T("BRANCH2-POINT") )
		{
			BranchPt.x = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			BranchPt.y = _tcstod( UELPCSTR (wordArray.GetAt( i+2 ) ), NULL );
			BranchPt.z = _tcstod( UELPCSTR (wordArray.GetAt( i+3 ) ), NULL );
			i= i+4;
			m_PointList.AddTail(BranchPt);
		}
	}
}

PCFJun* PCFCross::Creator()
{
	PCFCross *pObj = new PCFCross;
	return pObj;	
}

