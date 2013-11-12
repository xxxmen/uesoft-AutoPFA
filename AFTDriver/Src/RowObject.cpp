// RowObject.cpp: implementation of the RowObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RowObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RowObject::RowObject()
{
	m_chSeparator = _T(',');
}

RowObject::RowObject(const RowObject &ref)
{
    m_strData = ref.m_strData;
	m_chSeparator = ref.m_chSeparator;
	RowObject temp;
	for(int i=0;i<ref.m_child.GetSize();i++)
	{
		temp = ref.m_child.GetAt(i);
		m_child.SetAtGrow(i,temp);
	}
}

RowObject& RowObject::operator=(const RowObject &ref)
{
	if(this == &ref)
	return *this;
	RowObject temp;
	m_child.RemoveAll();

    m_strData = ref.m_strData;
	m_chSeparator = ref.m_chSeparator;
	for(int i=0;i<ref.m_child.GetSize();i++)
	{
		temp = ref.m_child.GetAt(i);
		m_child.SetAtGrow(i,temp);
	}
	return *this;
}

RowObject::~RowObject()
{
	
}



CString RowObject::Read(CString InData, TCHAR chSeparator)
{
	InData.TrimLeft();
	int nIndex = InData.Find(chSeparator);
	if(nIndex != -1)
	{
		//如果找到分割符号，保存分割符号前面的字符及分割符号
		m_strData = InData.Left(nIndex);
		m_chSeparator = chSeparator;
		InData.Delete(0,nIndex);//删除分割符号前面的字符
		InData.SetAt(0,' ');//分割符号设置为空
	}
	else
	{
		//如果没找到分割符号，保存分割符号前面的字符及增加换行符号
		InData.TrimRight();
		m_strData = InData;
        InData.Empty();
		m_chSeparator = _T('\n');
	}
	return InData;
}

void RowObject::AddChild(RowObject &ref)
{
	m_child.Add(ref);
}

void RowObject::SetChild(int index,RowObject &ref)
{
	m_child.SetAtGrow(index-1,ref);
}
//循环读分割符号前字符保存到子对象中
void RowObject::ReadChild(CString InData, TCHAR chSeparator)
{
	while(!InData.IsEmpty())
	{
		RowObject object;
		InData = object.Read(InData,chSeparator);
		m_child.Add(object);
	}
}

//将对象数据连接成一串字符
CString RowObject::Save()
{
	CString strSave;
	if(m_chSeparator != _T(' '))
	{
		strSave += m_strData + m_chSeparator;
	}
	else
	{
		strSave += m_strData;
	}
	for(int i=0;i<m_child.GetSize();i++)
	{
		strSave += m_child.GetAt(i).Save();
	}
	return strSave;
}


void RowObject::InitRow(CString InData)
{
	RemoveAll();
	ReadChild(Read(InData,_T('=')));
}


void RowObject::InitHead(CString InData)
{
	RemoveAll();
	Read(InData,_T('='));
}
/*-----------------------------------------------*/
BOOL RowObject::GetData(int &nData,int nIndex)
{
	CString strData;
	if(GetData(strData,nIndex))
	{
		nData = _ttoi(strData);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}
BOOL RowObject::GetData(double &dData,int nIndex)
{
	CString strData;
	if(GetData(strData,nIndex))
	{
		dData = _tcstod(strData , '\0');
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL RowObject::GetData(CString &strData,int nIndex)
{
	if(nIndex < 0 || nIndex > m_child.GetSize())
	{
		return FALSE;
	}
	else
	{
		CString strTemp;
		if(nIndex == 0)
		{
			strTemp = m_strData;
		}
		else
		{
			RowObject &temp = m_child.GetAt(nIndex-1);
			strTemp = temp.GetData();
		}
		strData = strTemp;
		return TRUE;
	}
}
BOOL RowObject::GetData(long &nData,int nIndex)
{
	CString strData;
	if(GetData(strData,nIndex))
	{
		nData = _ttol(strData);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL RowObject::SetData(int nData,int nIndex)
{
	CString strData;
	strData.Format(_T("%d"),nData);
	if(SetData(strData,nIndex))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}
BOOL RowObject::SetData(double dData,int nIndex)
{
    CString strData;
	strData.Format(_T("%f"),dData);
	if(SetData(strData,nIndex))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
BOOL RowObject::SetData(CString strData,int nIndex)
{
	if(nIndex < 0 || nIndex > m_child.GetSize())
	{
		return FALSE;
	}
	else
	{
		if(nIndex == 0)
		{
			SetData(strData);
		}
		else
		{
			RowObject &temp = m_child.GetAt(nIndex-1);
			temp.SetData(strData);
			m_child.SetAt(nIndex-1,temp);
		}
		return TRUE;
	}
}

TCHAR RowObject::GetSeparator(int nIndex)
{
	if(nIndex < 0 || nIndex > m_child.GetSize())
	{
		return ',';
	}
	else
	{
		if(nIndex == 0)
		{
			return GetSeparator();
		}
		else
		{
			RowObject &temp = m_child.GetAt(nIndex-1);
			return temp.GetSeparator();
		}
	}
}

BOOL RowObject::SetSeparator(TCHAR chSeparator,int nIndex)
{
	if(nIndex < 0 || nIndex > m_child.GetSize())
	{
		return FALSE;
	}
	else
	{
		if(nIndex == 0)
		{
			SetSeparator(chSeparator);
		}
		else
		{
			RowObject &temp = m_child.GetAt(nIndex-1);
			temp.SetSeparator(chSeparator);
			m_child.SetAt(nIndex-1,temp);
		}
		return TRUE;
	}
}
BOOL RowObject::SetData(long nData,int nIndex)
{
	CString strData;
	strData.Format(_T("%d"),nData);
	if(SetData(strData,nIndex))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/*------------------------------------------------*/
void RowObject::RemoveAll()
{
	m_strData.Empty();
	m_chSeparator = ' ';
	m_child.RemoveAll();
	m_child.FreeExtra();
}

BOOL RowObject::HasChild()
{
	if(m_child.GetSize()==0)
	{
		return FALSE;
	}
	else
	{
		CString strTemp = m_child.GetAt(0).GetData();
		if(strTemp.IsEmpty())
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
}

CString RowObject::ReadChild(CString InData, int nNum, TCHAR chSeparator)
{
	if(nNum == 0)
		return InData;
	int i = 0;
	while(!InData.IsEmpty()&&i<nNum)
	{
		RowObject object;
		InData = object.Read(InData,chSeparator);
		m_child.Add(object);
		i++;
	}
	return InData;
}

CString RowObject::Read(CString InData, int nNum, TCHAR chSeparator)
{
	if(nNum == 0)
	{
		m_strData.Empty();
		m_chSeparator = ' ';
	}
	else
	{
		RemoveAll();
		InData = Read(InData,chSeparator);
		nNum--;
		if(nNum >0)
		{
			InData = ReadChild(InData,nNum,chSeparator);
		}
	}
	return InData;
}

int RowObject::GetChildNum()
{
	return m_child.GetSize();
}
