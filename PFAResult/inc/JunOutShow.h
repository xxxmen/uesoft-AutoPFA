// JunOutShow.h : control the output of the result
//
//////////////////////////////////////////////////////////////////////


#if !defined(AFX_JUNOUTSHOW_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_)
#define AFX_JUNOUTSHOW_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JunOutShow.h"


class AFX_EXT_CLASS JunOutShow
{
public:
	CString GetKey();
	void SetKey(CString nkey);
	UnitTypeID GetTypeId();
	void SetTypeId(UnitTypeID nTypeId);
	CString GetStrName();
	void SetStrName(CString nStrName);
	CString GetStrUnit();
	void SetStrUnit(CString nStrUnit);
	BOOL GetShow();
	void SetShow(BOOL nShow);
	
public:
	JunOutShow();
	virtual ~JunOutShow();
	
	
	
	
protected:
	
private:
	CString m_Key;//这就是单位的KEY号，即是Data
	UnitTypeID m_TypeId;
	CString m_StrName;
	CString m_StrUnit;
	BOOL m_Show;
};

typedef CArray<JunOutShow,JunOutShow> JunOutShowArray;

#endif // !defined(AFX_OUTDATAATTR_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_)