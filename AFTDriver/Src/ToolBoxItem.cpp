// ToolBoxItem.cpp: implementation of the ToolBoxItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToolBoxItem.h"
#include "PersistentObj.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ToolBoxItem::ToolBoxItem()
{
}

ToolBoxItem::~ToolBoxItem()
{

}


BOOL ToolBoxItem::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	InitToolsNum(strTemp);
	if(GetToolNum() != 0)
	{
		file.ReadString(strTemp);
		InitTools(strTemp);
		file.ReadString(strTemp);
		InitIcons(strTemp);
		file.ReadString(strTemp);
		InitIconRotation(strTemp);
	}
	else
	{
		m_Tools.RemoveAll();
		m_ToolIcons.RemoveAll();
		m_ToolIconRotation.RemoveAll();
	}
	return TRUE;
}

BOOL ToolBoxItem::Save(CStdioFile &file)
{
	file.WriteString(m_ToolsNum.Save());
	if(GetToolNum() != 0)
	{
		file.WriteString(m_Tools.Save());
		file.WriteString(m_ToolIcons.Save());
		file.WriteString(m_ToolIconRotation.Save());
	}

	return TRUE;
}

void ToolBoxItem::Init()
{
	CString strToolsNum ;
	CString strTools ;
	CString strIcons ;
	CString strIconRotation ;
	CString strNumberOfToolsNotUsed ;
	bool b_isImpFlag = PersistentObj::isImpFile ;
	if ( b_isImpFlag )
	{
		strToolsNum = _T("NumberOfToolsUsed= 19");
		strTools = _T("ToolsUsed=1,2,3,4,5,21,7,8,9,10,11,22,24,23,25,16,17,19,20");
		strIcons = _T("ToolIcons=8,5,24,13,3,2,3,3,6,3,3,6,6,3,3,5,14,2,3");
		strIconRotation = _T("ToolIconRotation=0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
	} 
	else
	{
		strToolsNum = _T("NumberOfToolsUsed= 22");
		strTools = _T("ToolsUsed=1,2,3,4,5,6,7,8,9,10,21,27,11,12,13,14,15,16,17,18,19,20");
		strIcons = _T("ToolIcons=8,5,24,13,3,3,3,3,6,3,3,3,3,3,3,3,4,5,14,2,2,3");
		strIconRotation = _T("ToolIconRotation=0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
	}
	
	InitToolsNum(strToolsNum);
	InitTools(strTools);
	InitIcons(strIcons);
    InitIconRotation(strIconRotation);	
}

void ToolBoxItem::InitToolsNum(CString InData)
{
	m_ToolsNum.InitRow(InData);
}

void ToolBoxItem::InitTools(CString InData)
{
	m_Tools.InitRow(InData);
}

void ToolBoxItem::InitIcons(CString InData)
{
	m_ToolIcons.InitRow(InData);
}

void ToolBoxItem::InitIconRotation(CString InData)
{
	m_ToolIconRotation.InitRow(InData);
}

int ToolBoxItem::GetToolNum()
{
	int nRet = 0;
	m_ToolsNum.GetData(nRet,1);
	return nRet;
}

