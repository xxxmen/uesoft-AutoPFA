// PrintFontRef.cpp: implementation of the PrintFontRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrintFontRef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PrintFontRef::PrintFontRef()
{
	InitArray();
}

PrintFontRef::~PrintFontRef()
{

}

BOOL PrintFontRef::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL PrintFontRef::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void PrintFontRef::Init()
{
	CString strArray[4];
	if ( isImpFile )
	{
		strArray[0] = _T(" ");
		strArray[1] = _T("0");
		strArray[2] = _T("0");
		strArray[3] = _T("0");
	} 
	else
	{
		strArray[0] = _T("Arial");
		strArray[1] = _T("8.04");
		strArray[2] = _T("0");
		strArray[3] = _T("0");
	}

	
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==4);
		m_RowArray.GetAt(i)->ReadChild(strArray[i]);
	}
}

void PrintFontRef::InitArray()
{
	m_RowArray.SetSize(4);
	m_RowArray.SetAt(0,&m_FontName);
	m_RowArray.SetAt(1,&m_FontSize);
	m_RowArray.SetAt(2,&m_FontBold);
	m_RowArray.SetAt(3,&m_FontItalic);
	InitRowHead();
}

void PrintFontRef::InitRowHead()
{
	SetID("\n[FONT PREFERENCES]");
	CString strArray[4];
	strArray[0] = _T("Font Name=");
	strArray[1] = _T("Font Size=");
	strArray[2] = _T("Font Bold=");
	strArray[3] = _T("Font Italic=");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==4);
		m_RowArray.GetAt(i)->InitHead(strArray[i]);
	}
}
