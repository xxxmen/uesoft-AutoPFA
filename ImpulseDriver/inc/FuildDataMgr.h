// FuildDataMgr.h: interface for the FuildDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUILDDATAMGR_H__88E2D2B9_7C09_418D_A4A6_FF699AE27382__INCLUDED_)
#define AFX_FUILDDATAMGR_H__88E2D2B9_7C09_418D_A4A6_FF699AE27382__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FuildDatabase.h"
#include "Iterator.h"

class AFX_EXT_CLASS FuildDataMgr  
{
public:
	FuildDatabase* LookUp(int nKey);
	void Init(CStdioFile &File);
	FuildDataMgr();
	virtual ~FuildDataMgr();
	Iterator<FuildDatabase>* CreateIt();

private:
	FuildDatabase* Creator();
	typedef CMap<int,int,FuildDatabase*,FuildDatabase*> FuildMap;
	FuildMap m_fuildMap;

};

#endif // !defined(AFX_FUILDDATAMGR_H__88E2D2B9_7C09_418D_A4A6_FF699AE27382__INCLUDED_)
