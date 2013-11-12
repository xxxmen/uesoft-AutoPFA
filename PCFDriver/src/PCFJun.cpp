// PCFJun.cpp: implementation of the PCFJun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJun.h"
#include "PCFPipesMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJun::PCFJun()
{
	m_bPFAJun = FALSE;
	m_nKey = 0;
	m_nTypeID =0;
}

PCFJun::~PCFJun()
{

}

void PCFJun::SetKey(int nKey)
{
	m_nKey = nKey;
}
int PCFJun::GetKey()
{
	return m_nKey;
}
const CString& PCFJun::GetName()
{
	return m_strName;
}

const AcGePoint3d& PCFJun::Get3dPtCenter()
{
	return m_CenterPt;
}

int PCFJun::GetID()
{
	return m_nTypeID;
}

const AcGePoint3d& PCFJun::Get2dPtCenter()
{
	return m_Center2dPt;
}

void PCFJun::Tran3dTo2d()
{
	m_Center2dPt = ::Tran3dTo2d(m_CenterPt);
}

CString PCFJun::CenterPtX()
{
	CString m_strCenterPtX;
	m_strCenterPtX.Format(_T("%d"),int(m_Center2dPt.x));
	return m_strCenterPtX;
}

CString PCFJun::CenterPtY()
{
	CString m_strCenterPtY;
	m_strCenterPtY.Format(_T("%d"),int(m_Center2dPt.y));
	return m_strCenterPtY;
}

ListImp<StrArray<1> >& PCFJun::PipeID()
{
	return m_endList;
}

void PCFJun::OffSet(AcGePoint3d &OriginPt)
{
	m_Center2dPt.x -= OriginPt.x;
	m_Center2dPt.y -= OriginPt.y;
	m_Center2dPt.x += 20;
	m_Center2dPt.y += 20;
}

void PCFJun::TripLen(PCFPipesMgr &PipeMgr)
{
	AcGePoint3d *pPt = NULL;
	IteratorPtr<AcGePoint3d> PtitPtr(m_PointList.CreatIterator());
	for(PtitPtr->Fist();!PtitPtr->IsDone();PtitPtr->Next())
	{
		pPt = &PtitPtr->CurrentItem();
		ASSERT(pPt != NULL);
		PipeMgr.ChangePort(*pPt,m_CenterPt);
	}
}

void PCFJun::InitNetLink(PCFPipesMgr &PipeMgr)
{
	PipeMgr.InitNetLink(m_CenterPt,m_endList,m_nKey);
}

double PCFJun::Ele()
{
	return m_CenterPt.z;
}

PCFPortPoint& PCFJun::GetPtList()
{
	return m_PointList;
}

BOOL PCFJun::IsPFAJun()
{
	return m_bPFAJun;
}

void PCFJun::ChangeOrigin(AcGePoint3d &OriginPt)
{
	m_Center2dPt.y = OriginPt.y-m_Center2dPt.y;
}
