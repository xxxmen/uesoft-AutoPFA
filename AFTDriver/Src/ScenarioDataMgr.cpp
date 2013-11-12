// ScenarioDataMgr.cpp: implementation of the ScenarioDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScenarioDataMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RawDataSet ScenarioDataMgr::m_rawDataSet;

ScenarioDataMgr::ScenarioDataMgr()
{
	InitArray();
	m_rawDataSet.RemoveAll();
}

ScenarioDataMgr::~ScenarioDataMgr()
{
	ScenarioInfo *pInfo = NULL;
	POSITION pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
		delete pInfo;
	}
}

Iterator<ScenarioInfo>* ScenarioDataMgr::CreatIterator()
{
	return new ListIterator<ScenarioInfo>(&m_InfoList);
}

void ScenarioDataMgr::Init()
{
	if ( isImpFile )
	{
		CString strArray[2];
		strArray[0] = _T("Number of Scenarios=0");
		strArray[1] = _T("Starting Scenario =0");
		m_NumofScenarios.InitRow(strArray[0]);
		m_StartScenario.InitRow(strArray[1]);
	} 
	else
	{
		CString strArray[6];
		strArray[0] = _T("Number of Scenarios=0");
		strArray[1] = _T("Starting Scenario =0");
		strArray[2] = _T("Output Scenario Order= 0");
		strArray[3] = _T("Output Scenario Color= 0");
		strArray[4] = _T("Output Name Format= 0");
		strArray[5] = _T("Output Display Current= 0");
		m_NumofScenarios.InitRow(strArray[0]);
		m_StartScenario.InitRow(strArray[1]);
		m_OutputScenarioOrder.InitRow( strArray[2] );
		m_OutputScenarioColor.InitRow( strArray[3] );
		m_OutputNameFormat.InitRow( strArray[4] );
		m_OutputDisplayCurrent.InitRow( strArray[5] );
	}
	
}

void ScenarioDataMgr::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(2);
		m_RowArray.SetAt(0,&m_NumofScenarios);
		m_RowArray.SetAt(1,&m_StartScenario);
	} 
	else
	{
		m_RowArray.SetSize(6);
		m_RowArray.SetAt(0,&m_NumofScenarios);
		m_RowArray.SetAt(1,&m_StartScenario);
		m_RowArray.SetAt(2,&m_OutputScenarioOrder);
		m_RowArray.SetAt(3,&m_OutputScenarioColor);
		m_RowArray.SetAt(4,&m_OutputNameFormat);
		m_RowArray.SetAt(5,&m_OutputDisplayCurrent);
	}
	
	SetID(_T("\n[SCENARIO MANAGER]"));
}

BOOL ScenarioDataMgr::Read(CStdioFile &file)
{
	BOOL bRet = TRUE;
	CString strTemp;
	strTemp.Empty();
	file.ReadString(strTemp);
	m_NumofScenarios.InitRow(strTemp);
	int nNum = ScenarioNum();
	ScenarioInfo *pInfo = NULL;
	for(int i=0;i<nNum;i++)
	{
		pInfo = Creat();
		file.ReadString(strTemp);
		pInfo->Info(strTemp);
	}
	file.ReadString(strTemp);
	m_StartScenario.InitRow(strTemp);
	POSITION pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
		file.ReadString(strTemp);
		pInfo->OutPut(strTemp);
	}
	ReadInfo(file);
	if ( !isImpFile )
	{
		file.ReadString( strTemp ) ;
		m_OutputScenarioOrder.InitRow( strTemp ) ;
		file.ReadString( strTemp ) ;
		m_OutputScenarioColor.InitRow( strTemp ) ;
		file.ReadString( strTemp ) ;
		m_OutputNameFormat.InitRow( strTemp ) ;
		file.ReadString( strTemp ) ;
		m_OutputDisplayCurrent.InitRow( strTemp ) ;
	}
	return TRUE;
}

BOOL ScenarioDataMgr::Save(CStdioFile &file)
{
	SaveMark(file);
	file.WriteString(m_NumofScenarios.Save());

	ScenarioInfo *pInfo = NULL;
	POSITION pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
		file.WriteString(pInfo->Info());
	}

	file.WriteString(m_StartScenario.Save());

	pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
		file.WriteString(pInfo->OutPut());
	}

	pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
		pInfo->Save(file);
	}

	m_rawDataSet.Save(file);

	if ( !isImpFile )
	{
		file.WriteString( m_OutputScenarioOrder.Save() ) ;
		file.WriteString( m_OutputScenarioColor.Save() ) ;
		file.WriteString( m_OutputNameFormat.Save() ) ;
		file.WriteString( m_OutputDisplayCurrent.Save() ) ;
	}
	
	return TRUE;
}

ScenarioInfo* ScenarioDataMgr::Creat(int iKey,CString strName,CString strAncest)
{
	CString strScenario;
	CString strFile;
	strScenario.Format(_T("Scenario #%d=%s,%s,0,"),iKey,strName,strAncest);
	strFile.Format(_T("Outfile #%d="),iKey);
	ScenarioInfo *pInfo = new ScenarioInfo(strScenario,strFile);
	m_InfoList.AddTail(pInfo);
	if(strAncest.IsEmpty())
	{
		pInfo->Init();
	}
	return pInfo;
}

ScenarioInfo* ScenarioDataMgr::Creat()
{
	ScenarioInfo *pInfo = new ScenarioInfo();
	m_InfoList.AddTail(pInfo);
	return pInfo;
}
void ScenarioDataMgr::ScenarioNum(int nNum)
{
	m_NumofScenarios.SetData(nNum,1);
}
int ScenarioDataMgr::ScenarioNum()
{
	int nRet = 0;
	m_NumofScenarios.GetData(nRet,1);
	return nRet;
}
void ScenarioDataMgr::StartScenario(int nKey)
{
	m_StartScenario.SetData(nKey,1);
}
int ScenarioDataMgr::StartScenario()
{
	int nRet = 0;
	m_StartScenario.GetData(nRet,1);
	return nRet;
}
ScenarioInfo* ScenarioDataMgr::Find(CString strKey)
{
	strKey.TrimLeft();
	strKey.TrimRight();
	POSITION pos = m_InfoList.GetHeadPosition();
	ScenarioInfo* pInfo = NULL;
	CString strID;
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
        strID = pInfo->GetID();
		strID.TrimLeft();
		strID.TrimRight();
		if(strID.CompareNoCase(strKey)==0)
		{
			break;
		}
	}
	return pInfo;
}
int ScenarioDataMgr::LookUpKey(CString strAncestName)
{
	int iKey = 0 ;
	strAncestName.TrimLeft();
	strAncestName.TrimRight();
	POSITION pos = m_InfoList.GetHeadPosition();
	ScenarioInfo* pInfo = NULL;
	CString strTemp;
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
        strTemp = pInfo->GetAncestName();
		strTemp.TrimLeft();
		strTemp.TrimRight();
		if(strTemp.CompareNoCase(strAncestName)==0)
		{	
			iKey = pInfo->GetKey();
			break;
		}
	}
	return iKey;
}

BOOL ScenarioDataMgr::ReadInfo(CStdioFile &file)
{
	CString strTemp;
	CString strID;
	ScenarioInfo* pInfo = NULL;
	BOOL bEnd = file.ReadString(strTemp);
	
	while(bEnd)
	{
		if(!strTemp.IsEmpty())
		{
			if(ReadRawData(file,strTemp))
			{
				break;
			}

			strID = PickupID(strTemp);
			if(strID.IsEmpty())
			{
				pInfo = GetBase();
			}
			else
			{
				pInfo = Find(strID);
			}
			if(pInfo == NULL)
			{
				return FALSE;
			}
			else
			{
				pInfo->Read(file,strTemp);
			}
		}
		bEnd = file.ReadString(strTemp);
		
	}
	return TRUE;
}

ScenarioInfo* ScenarioDataMgr::GetBase()
{
	ScenarioInfo *pInfo = NULL;
	CString strAncest;
	POSITION pos = m_InfoList.GetHeadPosition();
	while(pos)
	{
		pInfo = m_InfoList.GetNext(pos);
        strAncest = pInfo->GetAncestPath();
		if(strAncest.IsEmpty())
			break;
	}
	return pInfo;
}

CString ScenarioDataMgr::PickupID(CString strData)
{
	CString strRet;
	strRet.Empty();
	int nStart = strData.Find(_T("--"));
	int nEnd = 0;
	if(nStart != -1)
	{
		nStart = nStart + 2;
		nEnd = strData.Find(_T("--"),nStart);
		if(nEnd != -1)
		{
			strRet = strData.Mid(nStart,nEnd-nStart);
		}
	}
	return strRet;
}

BOOL ScenarioDataMgr::ReadRawData(CStdioFile &file,CString strKey)
{
	CString strID = m_rawDataSet.GetID();
	strID.TrimLeft();
    strID.TrimRight();
	if(strID.CompareNoCase(strKey) == 0)
	{
		m_rawDataSet.Read(file);
		return TRUE;
	}
	return FALSE;
}

RawDataSet& ScenarioDataMgr::GetRawData()
{
	return m_rawDataSet;
}
