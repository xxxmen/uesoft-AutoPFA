#include "stdafx.h"
#include "SetCompKeyPt.h"
#include "PCFPortPoint.h"

#define DISTANCE 0.01
//从wordArray中得到入口，出口，基点
void SetSEBPoint(const CStringArray& wordArray, int &iPosition, int &pointNum, 
				  PCFPortPoint &listPt, AcGePoint3d &BasePt)
{
	if ( wordArray.GetAt(iPosition) == _T("END-POINT") && pointNum == 0 )
	{
		AcGePoint3d StartPt;
		StartPt.x = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+1 ) ), NULL );
		StartPt.y = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+2 ) ), NULL );
		StartPt.z = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+3 ) ), NULL );
		pointNum++;
		iPosition = iPosition+4;
		listPt.AddTail(StartPt);
	}
	
	if ( wordArray.GetAt(iPosition) == _T("END-POINT") && pointNum == 1 )
	{
		AcGePoint3d EndPt;
		EndPt.x = _tcstod( UELPCSTR(wordArray.GetAt( iPosition+1 ) ), NULL );
		EndPt.y = _tcstod( UELPCSTR(wordArray.GetAt( iPosition+2 ) ), NULL );
		EndPt.z = _tcstod( UELPCSTR(wordArray.GetAt( iPosition+3 ) ), NULL );
		pointNum++;
		iPosition = iPosition+4;
		listPt.AddTail(EndPt);
	}
	
	if( wordArray.GetAt(iPosition) == _T("CENTRE-POINT") )
	{
		BasePt.x = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+1 ) ), NULL );
		BasePt.y = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+2 ) ), NULL );
		BasePt.z = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+3 ) ), NULL );
		iPosition= iPosition+3;
	}
}

//从wordArray中得到基点，并转化为入口，出口
void SetSEFromBasePt(const CStringArray& wordArray, int &iPosition, int &pointNum, 
					  PCFPortPoint &listPt, AcGePoint3d &BasePt)
{
	if( wordArray.GetAt(iPosition) == _T("CENTRE-POINT") )
	{
		BasePt.x = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+1 ) ), NULL );
		BasePt.y = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+2 ) ), NULL );
		BasePt.z = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+3 ) ), NULL );
		iPosition = iPosition+3;
		listPt.AddTail(BasePt);
		listPt.AddTail(BasePt);
	}	
}

//从wordArray中得到入口，出口，并转化为基点
void SetBFromSEPt(const CStringArray& wordArray, int &iPosition, int &pointNum, 
				  PCFPortPoint &listPt, AcGePoint3d &BasePt)
{
	AcGePoint3d Pt;
	if ( wordArray.GetAt(iPosition) == _T("END-POINT") && pointNum == 0 )
	{	
		Pt.x = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+1 ) ), NULL );
		Pt.y = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+2 ) ), NULL );
		Pt.z = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+3 ) ), NULL );
		pointNum++;
		iPosition = iPosition+4;
		listPt.AddTail(Pt);
	}
	
	if ( wordArray.GetAt(iPosition) == _T("END-POINT") && pointNum == 1 )
	{
		AcGePoint3d *pStartPt = listPt.GetHead();
		ASSERT(pStartPt!=NULL);
		Pt.x = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+1 ) ), NULL );
		Pt.y = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+2 ) ), NULL );
		Pt.z = _tcstod( UELPCSTR (wordArray.GetAt( iPosition+3 ) ), NULL );
		pointNum++;
		iPosition = iPosition+4;
		listPt.AddTail(Pt);
		BasePt.x = (pStartPt->x + Pt.x) / 2;
		BasePt.y = (pStartPt->y + Pt.y) / 2;
		BasePt.z = (pStartPt->z + Pt.z) / 2;
	}	
}

BOOL IsEqual(const AcGePoint3d &Pt1, const AcGePoint3d &Pt2)
{
	double dDistancePt1ToPt2 = 0;
    dDistancePt1ToPt2 = Pt1.distanceTo(Pt2);

	if (dDistancePt1ToPt2 < DISTANCE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
