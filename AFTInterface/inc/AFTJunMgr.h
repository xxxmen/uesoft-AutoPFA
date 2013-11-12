// AFTJunMgr.h: interface for the AFTJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTJUNMGR_H__F574694B_C75A_4C34_A0F8_09C19B6AAB6C__INCLUDED_)
#define AFX_AFTJUNMGR_H__F574694B_C75A_4C34_A0F8_09C19B6AAB6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JunManager.h"
#include "JunctionsMgr.h"
#include "AFTJunFace.h"
#include "JunFaceFactory.h"

class AFX_EXT_CLASS AFTJunMgr  
{
public:
	AFTJunFace* CreatJunFace(int nID);
	AFTJunMgr();
	virtual ~AFTJunMgr();
	ErrorStatus::FileError Read(JunctionsMgr &Data,JunManager& model);
	ErrorStatus::FileError Save(JunctionsMgr &Data,JunManager& model);
private:
	JunFaceFactory *m_factory;
	AFTJunMgr(const AFTJunMgr &ref);
	AFTJunMgr& operator=(const AFTJunMgr &ref);
};

#endif // !defined(AFX_AFTJUNMGR_H__F574694B_C75A_4C34_A0F8_09C19B6AAB6C__INCLUDED_)
