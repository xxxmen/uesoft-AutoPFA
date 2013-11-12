// PCFSupport.cpp: implementation of the PCFSupport class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSupport.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSupport::PCFSupport()
{
	m_nTypeID = 102;
}

PCFSupport::~PCFSupport()
{

}

void PCFSupport::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	AcGePoint3d Point;
	for(int i = 0; i < wordNum; i++)
	{
       	if( wordArray.GetAt(i) == _T("CO-ORDS") )
		{		
			Point.x = _tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			Point.y = _tcstod( UELPCSTR (wordArray.GetAt( i+2 ) ), NULL );
			Point.z = _tcstod( UELPCSTR (wordArray.GetAt( i+3 ) ), NULL );
			i= i+3;
			m_PointList.AddTail(Point);
			m_PointList.AddTail(Point);
			m_CenterPt = Point;
		}
	}
}

PCFJun* PCFSupport::Creator()
{
	PCFSupport *pObj = new PCFSupport;
	return pObj;	
}

