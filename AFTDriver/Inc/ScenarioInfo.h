// ScenarioInfo.h: interface for the ScenarioInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENARIOINFO_H__121A99D5_2569_4890_BB7A_5EA8DA9C8DD7__INCLUDED_)
#define AFX_SCENARIOINFO_H__121A99D5_2569_4890_BB7A_5EA8DA9C8DD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NetModelData.h"
#include "persistentObj.h"

class AFX_EXT_CLASS ScenarioInfo : public PersistentObj  
{
public:
	NetModelData* GetModelData();
	BOOL Read(CStdioFile &file,CString strMark);
	CString GetID();
	int GetKey();
	CString GetAncestPath();
	CString GetAncestName();
	CString GetName();
	void Init();
	void OutPut(CString strData);
	void Info(CString strData);
	CString OutPut();
	CString Info();
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	ScenarioInfo(CString strInfo,CString strOut);
	ScenarioInfo();
	virtual ~ScenarioInfo();

private:
	NetModelData m_NetData;
	RowObject m_ScenarioInfo;
	RowObject m_OutputFile;

};

inline NetModelData* ScenarioInfo::GetModelData()
{
	return &m_NetData;
}


#endif // !defined(AFX_SCENARIOINFO_H__121A99D5_2569_4890_BB7A_5EA8DA9C8DD7__INCLUDED_)
