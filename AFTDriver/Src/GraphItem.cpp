// GraphItem.cpp: implementation of the GraphItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GraphItem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphItem::GraphItem()
{

}

GraphItem::~GraphItem()
{

}

BOOL GraphItem::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	m_data.InitRow(strTemp);
    file.ReadString(strTemp);
	m_Template.InitRow(strTemp);
	return TRUE;
}

BOOL GraphItem::Save(CStdioFile &file)
{
	file.WriteString(m_data.Save());
	file.WriteString(m_Template.Save());
	return TRUE;
}