// persistentObj.cpp: implementation of the persistentObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PersistentObj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool PersistentObj::isImpFile = TRUE;
PersistentObj::PersistentObj()
{
}

PersistentObj::PersistentObj(const PersistentObj &ref)
{
	m_strID = ref.m_strID;
}

PersistentObj& PersistentObj::operator=(const PersistentObj &ref)
{
	//ÅÐ¶Ï×Ô¸³Öµ
	if(this == &ref)
		return *this;
	m_strID = ref.m_strID;
	return *this;
}
PersistentObj::~PersistentObj()
{

}

BOOL PersistentObj::ReadMark(CStdioFile &file)
{
	CString strTemp;
	strTemp.Empty();
	CString strData;
	while(strTemp.IsEmpty())
	{
		file.ReadString(strTemp);
		strTemp.TrimLeft();
		if(strTemp.IsEmpty())
		{
			strData+=_T("\n");
		}
		else
		{
			strData += strTemp;
		}
	}
	SetID(strData);
	return TRUE;
}

BOOL PersistentObj::SaveMark(CStdioFile &file)
{
	file.WriteString(m_strID);
	return TRUE;
}

BOOL PersistentObj::SaveRow(CStdioFile &file)
{
	SaveMark(file);
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		RowObject *pObject = m_RowArray.GetAt(i);
		ASSERT(pObject != NULL);
		file.WriteString(pObject->Save());
	}
	return TRUE;
}

BOOL PersistentObj::ReadData(CStdioFile &file)
{
	BOOL bRet = TRUE;
	CString strTemp;
	RowObject row;
	RowObject* pRow = NULL;
	strTemp.Empty();
	file.ReadString(strTemp);
	while(!strTemp.IsEmpty())
	{
		row.InitRow(strTemp);
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			pRow = m_RowArray.GetAt(i);
			ASSERT(pRow != NULL);
			if(row.GetData().CompareNoCase(pRow->GetData())==0)
			{
				*pRow = row;
				break;
			}
		}
		file.ReadString(strTemp);
		strTemp.TrimLeft();
		strTemp.TrimRight();
	//	AfxMessageBox(strTemp);
	}
	return bRet;
}

BOOL PersistentObj::SaveData(CStdioFile &file)
{
	BOOL bRet = TRUE;
	int nNum = 0;
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		RowObject *pObject = m_RowArray.GetAt(i);
		if(pObject->HasChild())
		{
			nNum++;
			if(1==nNum)
			{
				SaveMark(file);
			}
			file.WriteString(pObject->Save());
		}
		ASSERT(pObject != NULL);
	}
	return bRet;
}

void PersistentObj::InsertSub(CString strSub)
{
	m_strID.TrimRight();
	m_strID.TrimRight(']');
	m_strID +=strSub +_T("]\n");
}

void PersistentObj::ChangeSub(CString strSub)
{
	int nIndex = m_strID.Find(_T(" -- "));
	if(nIndex != -1)
	{
		m_strID = m_strID.Left(nIndex);
		m_strID +=strSub +_T("]\n");
	}
}

