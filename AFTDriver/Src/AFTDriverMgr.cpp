// AFTDriverMgr.cpp: implementation of the AFTDriverMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTDriverMgr.h"
#include "ResourceInstance.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTDriverMgr::AFTDriverMgr()
{
	InitArray();
}

AFTDriverMgr::~AFTDriverMgr()
{

}

BOOL AFTDriverMgr::Read(CStdioFile &file)
{
	//CResourceInstance res;
	BOOL bRet = TRUE;
	CString strID;
	PersistentObj * pObj = NULL;
	CString strTemp;
	strTemp.Empty();
	while(file.ReadString(strTemp))
	{
		strTemp.TrimRight();
		while(strTemp.IsEmpty())
		{
			file.ReadString(strTemp);
			strTemp.TrimRight();
		}
		//AfxMessageBox(strTemp);
		pObj = Find(strTemp);
		if(pObj !=NULL)
		{
			bRet = pObj->Read(file);
			if(!bRet)
			{
				break;
			}
		}
	}
	
	return bRet;
}

BOOL AFTDriverMgr::Save(CStdioFile &file)
{
	BOOL bRet = FALSE;
	PersistentObj * pObj = NULL;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		ASSERT(pObj != NULL);
		bRet = pObj->Save(file);
		
	}
	return bRet;
}


void AFTDriverMgr::InitArray()
{
	m_objArray.SetSize(9);
	m_objArray.SetAt(0,&m_versionInfo);
	m_objArray.SetAt(1,&m_toolBox);
	m_objArray.SetAt(2,&m_workSpace);
	m_objArray.SetAt(3,&m_paramRef);
	m_objArray.SetAt(4,&m_unitRef);
	m_objArray.SetAt(5,&m_modelDataRef);
	m_objArray.SetAt(6,&m_printFontRef);
	m_objArray.SetAt(7,&m_graphSet);
	m_objArray.SetAt(8,&m_scenarioMgr);
	
}

PersistentObj* AFTDriverMgr::Find(CString strMark)
{
	strMark.TrimLeft();
	strMark.TrimRight();
	PersistentObj* pObj = NULL;
	CString strID;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		strID = pObj->GetID();
		strID.TrimLeft();
		strID.TrimRight();
		if(strID.CompareNoCase(strMark)==0)
		{
			return pObj;
		}
	}
	return NULL;
}

void AFTDriverMgr::Init()
{
	PersistentObj * pObj = NULL;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		ASSERT(pObj != NULL);
		pObj->Init();
	}
}
