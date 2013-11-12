// ScenarioInfo.cpp: implementation of the ScenarioInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScenarioInfo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
ScenarioInfo::ScenarioInfo()
{
}
ScenarioInfo::ScenarioInfo(CString strInfo,CString strOut)
{
	Info(strInfo);
	OutPut(strOut);
}

ScenarioInfo::~ScenarioInfo()
{

}

BOOL ScenarioInfo::Read(CStdioFile &file)
{
	return TRUE;
}

BOOL ScenarioInfo::Save(CStdioFile &file)
{
	return m_NetData.Save(file);
}

CString ScenarioInfo::Info()
{
	return m_ScenarioInfo.Save();
}

CString ScenarioInfo::OutPut()
{
	return m_OutputFile.Save();
}

void ScenarioInfo::Info(CString strData)
{
	m_ScenarioInfo.InitRow(strData);
	CString strMark = GetID();
	CString strName = GetName();
	CString strAncest = GetAncestPath();
	m_NetData.SetIDSub(strMark,strName,strAncest);
}

void ScenarioInfo::OutPut(CString strData)
{
	m_OutputFile.InitRow(strData);
}

void ScenarioInfo::Init()
{
	m_NetData.Init();
}

CString ScenarioInfo::GetID()
{
	return m_ScenarioInfo.GetData();
}

int ScenarioInfo::GetKey()
{
	int iKey = 0;
	CString strID = GetID();
	int nIndex = strID.ReverseFind('#');
	if(-1 != nIndex)
	{
		int nCount = strID.GetLength()-nIndex-1;
		iKey = _ttoi(strID.Right(nCount));
	}
	return iKey;
}

CString ScenarioInfo::GetName()
{
	CString strData;
	m_ScenarioInfo.GetData(strData,1);
	return strData;
}

CString ScenarioInfo::GetAncestPath()
{
	CString strData;
	m_ScenarioInfo.GetData(strData,2);
	return strData;
}
CString ScenarioInfo::GetAncestName()
{
	CString strRet;
	strRet = GetAncestPath();
	if(strRet.IsEmpty())
	{
		strRet = GetName();
	}
	else
	{
		strRet +='/'+ GetName();
	}
	return strRet;
}

BOOL ScenarioInfo::Read(CStdioFile &file, CString strMark)
{
	strMark.TrimLeft();
	strMark.TrimRight();
	return m_NetData.Read(file,strMark);
}

