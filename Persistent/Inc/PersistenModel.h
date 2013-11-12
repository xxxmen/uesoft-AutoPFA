// PersistenModel.h: interface for the PersistenModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSISTENMODEL_H__D465DF9F_FD81_4938_A167_F2299CBD2245__INCLUDED_)
#define AFX_PERSISTENMODEL_H__D465DF9F_FD81_4938_A167_F2299CBD2245__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ScenarioPersistMgr.h"
class AFX_EXT_CLASS PersistentModel  
{
public:
	ScenarioPersistMgr& GetScenarioPersist();
	const ScenarioPersistMgr& GetScenarioPersist()const;
	PersistentModel();
	virtual ~PersistentModel();

private:
	ScenarioPersistMgr m_ScenarioMgr;
	
};

inline ScenarioPersistMgr& PersistentModel::GetScenarioPersist()
{
	return m_ScenarioMgr;
}

inline const ScenarioPersistMgr& PersistentModel::GetScenarioPersist()const
{
	return m_ScenarioMgr;
}

#endif // !defined(AFX_PERSISTENMODEL_H__D465DF9F_FD81_4938_A167_F2299CBD2245__INCLUDED_)
