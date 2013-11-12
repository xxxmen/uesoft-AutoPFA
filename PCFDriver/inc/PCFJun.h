// PCFJun.h: interface for the PCFJun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUN_H__BD415284_07A0_4052_A60C_373D27DBF7FD__INCLUDED_)
#define AFX_PCFJUN_H__BD415284_07A0_4052_A60C_373D27DBF7FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <gepnt3d.h>
#include "PCFPortPoint.h"

class PCFPipesMgr;
typedef ListImp<StrArray<1> > EndList;

class AFX_EXT_CLASS PCFJun  
{
public:
	CString CenterPtX();
	CString CenterPtY();
	const CString& GetName();
	int GetKey();
	int GetID();
public:
	void ChangeOrigin(AcGePoint3d &OriginPt);
	BOOL IsPFAJun();
	PCFPortPoint& GetPtList();
	double Ele();
	void InitNetLink(PCFPipesMgr &PipeMgr);
	void OffSet(AcGePoint3d& OriginPt);
	void Tran3dTo2d();
	ListImp<StrArray<1> > &PipeID();
    
	const AcGePoint3d& Get2dPtCenter();
	const AcGePoint3d& Get3dPtCenter();
	void SetKey(int nKey);
	
	PCFJun();
	virtual ~PCFJun();
	virtual void Init(const CStringArray& wordArray )=0;
	void TripLen(PCFPipesMgr &PipeMgr);
	
protected:
	PCFPortPoint m_PointList;
	CString m_strName;
	int m_nTypeID;
	int m_nKey;
	EndList m_endList;
	AcGePoint3d m_CenterPt;
	AcGePoint3d m_Center2dPt;
	BOOL m_bPFAJun;
};

#endif // !defined(AFX_PCFJUN_H__BD415284_07A0_4052_A60C_373D27DBF7FD__INCLUDED_)
