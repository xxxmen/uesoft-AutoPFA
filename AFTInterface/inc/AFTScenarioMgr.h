// AFTScenarioMgr.h: interface for the AFTScenarioMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSCENARIOMGR_H__4197BF01_DC3A_4D50_8C6C_97166836F5BC__INCLUDED_)
#define AFX_AFTSCENARIOMGR_H__4197BF01_DC3A_4D50_8C6C_97166836F5BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ScenarioPersistMgr.h"
#include "ScenarioDataMgr.h"


class AFX_EXT_CLASS AFTScenarioMgr  
{
public:
	void FileName(CString strName);
	AFTScenarioMgr();
	virtual ~AFTScenarioMgr();
	ErrorStatus::FileError Read(ScenarioDataMgr &Data,ScenarioPersistMgr& model);
	ErrorStatus::FileError Save(ScenarioDataMgr &Data,ScenarioPersistMgr& model);
private:
	
};

#endif // !defined(AFX_AFTSCENARIOMGR_H__4197BF01_DC3A_4D50_8C6C_97166836F5BC__INCLUDED_)
