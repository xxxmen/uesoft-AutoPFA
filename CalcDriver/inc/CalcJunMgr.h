// CalcJunMgr.h: interface for the CalcJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUNMGR_H__AD1874BB_BCCB_4C72_83C0_19D301196D95__INCLUDED_)
#define AFX_CALCJUNMGR_H__AD1874BB_BCCB_4C72_83C0_19D301196D95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcJunFactory.h"
#include "Iterator.h"
class CalcJun;

class AFX_EXT_CLASS CalcJunMgr  
{
public:
	CalcJunMgr();
	virtual ~CalcJunMgr();
public:
	CalcJun* CreatJun(int nType);
	Iterator<CalcJun>* CreateIt();
	friend ostream& operator<<(ostream &CalcOut,const CalcJunMgr &ref);
private:
	typedef CList<CalcJun*,CalcJun*>JunList;
	void DelList();
	CalcJunMgr(const CalcJunMgr &ref);
	CalcJunMgr& operator=(const CalcJunMgr &ref);
	JunList m_junList;
	CalcJunFactory *m_pFactory;
};

#endif // !defined(AFX_CALCJUNMGR_H__AD1874BB_BCCB_4C72_83C0_19D301196D95__INCLUDED_)
