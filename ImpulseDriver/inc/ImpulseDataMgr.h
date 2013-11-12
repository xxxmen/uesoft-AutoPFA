// ImpulseDataMgr.h: interface for the ImpulseDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMPULSEDATAMGR_H__3C84F6CA_396A_4B48_8E4C_B4063DD2912F__INCLUDED_)
#define AFX_IMPULSEDATAMGR_H__3C84F6CA_396A_4B48_8E4C_B4063DD2912F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FuildDataMgr.h"

class AFX_EXT_CLASS ImpulseDataMgr  
{
public:
	FuildDataMgr& FuildMgr();
	static ImpulseDataMgr& Instance();
	virtual ~ImpulseDataMgr();

private:
	ImpulseDataMgr();

private:
	void Init();
	FuildDataMgr m_FuildMgr;
};

#endif // !defined(AFX_IMPULSEDATAMGR_H__3C84F6CA_396A_4B48_8E4C_B4063DD2912F__INCLUDED_)
