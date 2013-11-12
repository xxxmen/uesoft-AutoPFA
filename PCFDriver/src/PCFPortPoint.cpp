// PCFPortPoint.cpp: implementation of the PCFPortPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPortPoint.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPortPoint::PCFPortPoint()
{

}

PCFPortPoint::~PCFPortPoint()
{

}

Iterator<AcGePoint3d>* PCFPortPoint::CreatIterator()
{
	return new ListIterator<AcGePoint3d>(&m_PointList);
}
void PCFPortPoint::AddTail(const AcGePoint3d &Pt)
{
	AcGePoint3d *pPt = new AcGePoint3d(Pt);
	m_PointList.AddTail(pPt);
}

int PCFPortPoint::GetCount()
{
	return m_PointList.GetCount();
}

AcGePoint3d* PCFPortPoint::GetHead()
{
	return m_PointList.GetHead();
}
// 
POSITION PCFPortPoint::GetHeadPosition()
{
	return m_PointList.GetHeadPosition();
}

AcGePoint3d* PCFPortPoint::GetNext(POSITION& position)
{
	return m_PointList.GetNext(position);
}

AcGePoint3d* PCFPortPoint::GetAt(POSITION position)
{
	return m_PointList.GetAt(position);
}

AcGePoint3d* PCFPortPoint::GetTail()
{
	return m_PointList.GetTail();
}
