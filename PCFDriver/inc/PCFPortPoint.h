// PCFPortPoint.h: interface for the PCFPortPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPORTPOINT_H__132EBCB2_84FE_4B4C_9D7D_0DC11F29CA6A__INCLUDED_)
#define AFX_PCFPORTPOINT_H__132EBCB2_84FE_4B4C_9D7D_0DC11F29CA6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>

class AFX_EXT_CLASS PCFPortPoint  
{
public: 
	AcGePoint3d* GetTail();
	AcGePoint3d* GetHead();
 	POSITION GetHeadPosition() ;
	AcGePoint3d* GetAt(POSITION position);
	AcGePoint3d* GetNext(POSITION& position);
	int GetCount();
	void AddTail(const AcGePoint3d &Pt);
	PCFPortPoint();
	virtual ~PCFPortPoint();
	Iterator<AcGePoint3d>* CreatIterator();

private:
	typedef CList<AcGePoint3d*, AcGePoint3d*> PointList;
	PointList m_PointList;

};

#endif // !defined(AFX_PCFPORTPOINT_H__132EBCB2_84FE_4B4C_9D7D_0DC11F29CA6A__INCLUDED_)
