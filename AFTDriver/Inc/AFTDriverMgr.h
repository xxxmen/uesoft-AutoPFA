// AFTDriverMgr.h: interface for the AFTDriverMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTDRIVERMGR_H__5F84E92C_3603_4E75_B88F_F1609CE6528F__INCLUDED_)
#define AFX_AFTDRIVERMGR_H__5F84E92C_3603_4E75_B88F_F1609CE6528F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ScenarioDataMgr.h"

 
#include "VersionInfo.h"
#include "ToolBoxRef.h"
#include "WorkSpace.h"
#include "ParamRef.h"
#include "UnitRef.h"
#include "ModelDataRef.h"
#include "PrintFontRef.h"
#include "GraphSet.h"



class AFX_EXT_CLASS AFTDriverMgr
{
public:
	void Init();
	ScenarioDataMgr& GetScenarioMgr();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	AFTDriverMgr();
	virtual ~AFTDriverMgr();
	
private:
	void InitArray();
	PersistentObj* Find(CString strMark);
private:
	

	VersionInfo     m_versionInfo;
    ToolBoxRef      m_toolBox;
	WorkSpace       m_workSpace;
	ParamRef        m_paramRef;
	UnitRef         m_unitRef;
	ModelDataRef    m_modelDataRef;
	PrintFontRef    m_printFontRef;
	GraphSet        m_graphSet;
	ScenarioDataMgr m_scenarioMgr;
	 
	
	ObjectArray     m_objArray;
};

inline ScenarioDataMgr& AFTDriverMgr::GetScenarioMgr()
{
	return m_scenarioMgr;
}
#endif // !defined(AFX_AFTDRIVERMGR_H__5F84E92C_3603_4E75_B88F_F1609CE6528F__INCLUDED_)
