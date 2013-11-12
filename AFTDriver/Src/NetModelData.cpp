// NetModelData.cpp: implementation of the NetModelData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NetModelData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NetModelData::NetModelData()
{
	m_objArray.SetSize(8);
	m_objArray.SetAt(0,&m_settingData);
	m_objArray.SetAt(1,&m_sectionData);
	m_objArray.SetAt(2,&m_tranControlData);
	m_objArray.SetAt(3,&m_fluidData);
	m_objArray.SetAt(4,&m_outRefData);
	m_objArray.SetAt(5,&m_visualRef);
    m_objArray.SetAt(6,&m_pipeMgr);
	m_objArray.SetAt(7,&m_junMgr);
}

NetModelData::~NetModelData()
{

}

void NetModelData::Init()
{
	PersistentObj * pObj = NULL;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		ASSERT(pObj != NULL);
		pObj->Init();
	}
}

void NetModelData::SetIDSub(CString strMark,CString strName,CString strAncest)
{
	CString strSub =" -- "+strMark+" -- "+strName;
	if(!strAncest.IsEmpty())
	{
		m_settingData.InsertSub(strSub);
		m_sectionData.InsertSub(strSub);
		m_tranControlData.InsertSub(strSub);
		m_fluidData.InsertSub(strSub);
		m_outRefData.InsertSub(strSub);
		m_visualRef.InsertSub(strSub);
	}
	m_pipeMgr.InsertSub(strSub);
	m_junMgr.InsertSub(strSub);
}

BOOL NetModelData::Save(CStdioFile &file)
{
	BOOL bRet = FALSE;
	PersistentObj * pObj = NULL;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		ASSERT(pObj != NULL);
		bRet = pObj->Save(file);
		if(!bRet)
		{
			break;
		}
	}
	return bRet;
}

BOOL NetModelData::Read(CStdioFile &file, CString strMark)
{
	PersistentObj *pObj = NULL;
	CString strID;
	for(int i=0;i<m_objArray.GetSize();i++)
	{
		pObj = m_objArray.GetAt(i);
		ASSERT(pObj != NULL);
		strID = pObj->GetID();
		strID.TrimLeft();
        strID.TrimRight();
		if(strID.CompareNoCase(strMark) == 0)
		{
			pObj->Read(file);
// 			if(i==4)
// 			{
// 				AfxMessageBox(m_outRefData.GetPipeUnitOrder());
// 			}
			return TRUE;
		}
		
	}
	return FALSE;
}






