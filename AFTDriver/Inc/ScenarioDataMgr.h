// ScenarioDataMgr.h: interface for the ScenarioDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENARIODATAMGR_H__132A0599_91F1_4525_9287_42A5933C7464__INCLUDED_)
#define AFX_SCENARIODATAMGR_H__132A0599_91F1_4525_9287_42A5933C7464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "persistentObj.h"
#include "ScenarioInfo.h"
#include "RawDataSet.h"


class AFX_EXT_CLASS ScenarioDataMgr: public PersistentObj    
{
public:
	
	ScenarioInfo* GetBase();
	ScenarioInfo* Find(CString strKey);
	int LookUpKey(CString strAncestName);
	Iterator<ScenarioInfo>* CreatIterator();
	int ScenarioNum();
	void ScenarioNum(int nNum);
	int StartScenario();
	void StartScenario(int nKey);
	ScenarioInfo* Creat(int iKey,CString strName,CString strAncest);
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	void Init();
	ScenarioDataMgr();
	virtual ~ScenarioDataMgr();

private:
	ScenarioInfo* Creat();
	CString PickupID(CString strData);
	BOOL ReadInfo(CStdioFile &file);
	BOOL ReadRawData(CStdioFile &file,CString strKey);
	void InitArray();
	typedef CList<ScenarioInfo*,ScenarioInfo*>ScenarioInfoList;
	RowObject m_NumofScenarios;
	RowObject m_StartScenario;
    ScenarioInfoList m_InfoList;

	RowObject m_OutputScenarioOrder;
	RowObject m_OutputScenarioColor;
	RowObject m_OutputNameFormat;
	RowObject m_OutputDisplayCurrent;
public:
	static RawDataSet& GetRawData();
	static RawDataSet m_rawDataSet;
	
};
#endif // !defined(AFX_SCENARIODATAMGR_H__132A0599_91F1_4525_9287_42A5933C7464__INCLUDED_)
