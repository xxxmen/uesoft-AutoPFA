// PCFJunsMgr.h: interface for the PCFJunsMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUNSMGR_H__FBB152D4_0C2F_49AB_B721_1F091EB60537__INCLUDED_)
#define AFX_PCFJUNSMGR_H__FBB152D4_0C2F_49AB_B721_1F091EB60537__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "PCFJun.h"
#include "PCFJunFactory.h"

class AFX_EXT_CLASS PCFJunsMgr  
{
public:
	void ChangeOrigin(AcGePoint3d& OriginPt);
	void CombinationPipe(PCFPipesMgr &PipeMgr);
	void CombinationFit(PCFPipesMgr &PipeMgr);
	PCFJun* LookUp(int nKey);
	void InitNetLink(PCFPipesMgr &PipeMgr);
	void OffSet(AcGePoint3d& OriginPt);
	void Tran3dTo2d();
	void TripLen(PCFPipesMgr &PipeMgr);
	PCFJun* Creator(CString strKey);
//	void CombinationPipes(PCFPipesMgr &PipeMgr);
	Iterator<PCFJun>* CreateIt();
	typedef CMap<int,int,PCFJun*,PCFJun*> JunMap;
	PCFJunsMgr();
	virtual ~PCFJunsMgr();
private:
	void CombinationFit(PCFPipesMgr &PipeMgr,int nType);
	void CombinationPipe(PCFPipesMgr &PipeMgr,int nType);
	PCFJunFactory *m_pFactory;
	JunMap m_junMap;

};

#endif // !defined(AFX_PCFJUNSMGR_H__FBB152D4_0C2F_49AB_B721_1F091EB60537__INCLUDED_)
