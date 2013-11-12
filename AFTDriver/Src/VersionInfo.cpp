// VersionInfo.cpp: implementation of the VersionInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VersionInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

VersionInfo::VersionInfo()
{
	InitArray();
}

VersionInfo::~VersionInfo()
{

}

void VersionInfo::Init()
{
	if ( isImpFile )
	{
		CString strArray[2];
		strArray[0] = _T("Impulse");
		strArray[1] = _T("09030041  'F4.0.000  'aavvvrrr where aa=app#, vvv=version, rrr=revsion (Arrow 2.1c+ = 06021310)");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==2);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	} 
	else
	{
		CString strArray[5];
		strArray[0] = _T("Fathom");
		strArray[1] = _T("01060033");
		strArray[2] = _T("-1");
		strArray[3] = _T("-1");
		strArray[4] = _T("-1");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==5);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
	
}

void VersionInfo::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(2);
		m_RowArray.SetAt(0,&m_AppName);
		m_RowArray.SetAt(1,&m_Version);
	} 
	else
	{
		m_RowArray.SetSize(5);
		m_RowArray.SetAt(0,&m_AppName);
		m_RowArray.SetAt(1,&m_Version);
		m_RowArray.SetAt(2,&m_CstUse);
		m_RowArray.SetAt(3,&m_GscUse);
		m_RowArray.SetAt(4,&m_XtsUse);
	}
	
	InitRowHead();
}

BOOL VersionInfo::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL VersionInfo::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void VersionInfo::InitRowHead()
{
	SetID("\n[APPLICATION]");

	if ( isImpFile )
	{
		CString strArray[2];
		strArray[0] = _T("AppName=");
		strArray[1] = _T("Version=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==2);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	} 
	else
	{
		CString strArray[5];
		strArray[0] = _T("AppName=");
		strArray[1] = _T("Version=");
		strArray[2] = _T("CST Use=");
		strArray[3] = _T("GSC Use=");
		strArray[4] = _T("XTS Use=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==5);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
	
}
