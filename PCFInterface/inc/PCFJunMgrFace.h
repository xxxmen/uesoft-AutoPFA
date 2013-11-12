// PCFJunMgrFace.h: interface for the PCFJunMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFJUNMGRFACE_H__996C3ED5_0C52_49E7_B40E_688DB86A100E__INCLUDED_)
#define AFX_PCFJUNMGRFACE_H__996C3ED5_0C52_49E7_B40E_688DB86A100E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJunFaceFactory.h"
//#include <vector>
//using namespace std;

class PCFJunsMgr;
class JunManager;

class AFX_EXT_CLASS PCFJunMgrFace  
{
public:
	ErrorStatus::FileError Read(PCFJunsMgr &Data,JunManager& model);
	PCFJunMgrFace();
	virtual ~PCFJunMgrFace();

//	typedef vector<AcGePoint3d> UnPoint;
//	typedef vector<UnPoint> Un;
//	Un UnJun,ConJun;
	
private:
	PCFJunFace* CreatJunFace(int nID);
	PCFJunFaceFactory *m_factory;
	
};

#endif // !defined(AFX_PCFJUNMGRFACE_H__996C3ED5_0C52_49E7_B40E_688DB86A100E__INCLUDED_)
