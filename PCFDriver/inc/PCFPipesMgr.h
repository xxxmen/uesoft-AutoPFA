// PCFPipesMgr.h: interface for the PCFPipesMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPIPESMGR_H__D0F20949_0C3A_4A2B_8147_C287FD1AE003__INCLUDED_)
#define AFX_PCFPIPESMGR_H__D0F20949_0C3A_4A2B_8147_C287FD1AE003__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "PCFJun.h"
class PCFPipe;

class AFX_EXT_CLASS PCFPipesMgr  
{
public:
	void ChangeOrigin(AcGePoint3d& OriginPt);
	void GetMaxXY(double &dMaxX, double &dMaxY);
	void CombinationPipe(AcGePoint3d &Pt1,AcGePoint3d &Pt2);
	void Del(int nKey);
	PCFPipe* LookUp(int nKey);
	void InitNetLink(AcGePoint3d &Pt,EndList &end,int nID);
	BOOL ChangePort(const AcGePoint3d &OldPt,const AcGePoint3d &NewPt);
	void OffSet(AcGePoint3d& OriginPt);
	void Tran3dTo2d();
	void GetMinXY(double &dMinX, double &dMinY);
	PCFPipe* Creator();
	Iterator<PCFPipe>* CreateIt();
	typedef CMap<int,int,PCFPipe*,PCFPipe*> PipeMap;
	PCFPipesMgr();
	virtual ~PCFPipesMgr();
private:
	void DelList();
	PipeMap m_pipeMap;
};

#endif // !defined(AFX_PCFPIPESMGR_H__D0F20949_0C3A_4A2B_8147_C287FD1AE003__INCLUDED_)
