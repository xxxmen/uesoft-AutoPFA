// SectionData.cpp: implementation of the SectionData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SectionData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SectionData::SectionData()
{
	InitArray();
}

SectionData::~SectionData()
{

}

void SectionData::InitArray()
{
	m_RowArray.SetSize(8);
	m_RowArray.SetAt(0,&m_Search);
	m_RowArray.SetAt(1,&m_MaxSections);
	m_RowArray.SetAt(2,&m_MinSections);
	m_RowArray.SetAt(3,&m_MaxError);
	m_RowArray.SetAt(4,&m_PctIncrement);
	m_RowArray.SetAt(5,&m_Sort);
	m_RowArray.SetAt(6,&m_IdealSections);
	m_RowArray.SetAt(7,&m_TimeStep);
	InitRowHead();
}

void SectionData::InitRowHead()
{
	SetID("\n[SECTIONING]");
	CString strArray[8];
	strArray[0] = _T("Search=");
	strArray[1] = _T("MaxSections=");
	strArray[2] = _T("MinSections =");
	strArray[3] = _T("MaxError=");
	strArray[4] = _T("PctIncrement=");
	strArray[5] = _T("Sort= ");
	strArray[6] = _T("IdealSections=");
	strArray[7] = _T("TimeStep=");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==8);
		m_RowArray.GetAt(i)->InitHead(strArray[i]);
	}
}

void SectionData::Init()
{
	CString strArray[8];
	strArray[0] = _T("-1");
	strArray[1] = _T("1");
	strArray[2] = _T("1");
	strArray[3] = _T("1");
	strArray[4] = _T(".05");
	strArray[5] = _T("-1");
	strArray[6] = _T("1");
	strArray[7] = _T("0");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==8);
		m_RowArray.GetAt(i)->ReadChild(strArray[i]);
	}
}

BOOL SectionData::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL SectionData::Save(CStdioFile &file)
{
	return SaveData(file);
}

/*------------------------------------------*/
CString SectionData::Search()
{
	CString strValue;
	m_Search.GetData(strValue,1);
	return strValue;
}
void SectionData::Search(CString strValue)
{
	if(!m_Search.SetData(strValue,1))
	{
		m_Search.ReadChild("-1");
		m_Search.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::MaxSections()
{
	CString strValue;
	m_MaxSections.GetData(strValue,1);
	return strValue;
}
void SectionData::MaxSections(CString strValue)
{
	if(!m_MaxSections.SetData(strValue,1))
	{
		m_MaxSections.ReadChild("1");
		m_MaxSections.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::MinSections()
{
	CString strValue;
	m_MinSections.GetData(strValue,1);
	return strValue;
}
void SectionData::MinSections(CString strValue)
{
	if(!m_MinSections.SetData(strValue,1))
	{
		m_MinSections.ReadChild("1");
		m_MinSections.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::MaxError()
{
	CString strValue;
	m_MaxError.GetData(strValue,1);
	return strValue;
}
void SectionData::MaxError(CString strValue)
{
	if(!m_MaxError.SetData(strValue,1))
	{
		m_MaxError.ReadChild("1");
		m_MaxError.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::PctIncrement()
{
	CString strValue;
	m_PctIncrement.GetData(strValue,1);
	return strValue;
}
void SectionData::PctIncrement(CString strValue)
{
	if(!m_PctIncrement.SetData(strValue,1))
	{
		m_PctIncrement.ReadChild("0.05");
		m_PctIncrement.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::Sort()
{
	CString strValue;
	m_Sort.GetData(strValue,1);
	return strValue;
}
void SectionData::Sort(CString strValue)
{
	if(!m_Sort.SetData(strValue,1))
	{
		m_Sort.ReadChild("-1");
		m_Sort.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::IdealSections()
{
	CString strValue;
	m_IdealSections.GetData(strValue,1);
	return strValue;
}
void SectionData::IdealSections(CString strValue)
{
	if(!m_IdealSections.SetData(strValue,1))
	{
		m_IdealSections.ReadChild("1");
		m_IdealSections.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SectionData::TimeStep()
{
	CString strValue;
	m_TimeStep.GetData(strValue,1);
	return strValue;
}
void SectionData::TimeStep(CString strValue)
{
	if(!m_TimeStep.SetData(strValue,1))
	{
		m_TimeStep.ReadChild("0");
		m_TimeStep.SetData(strValue,1);
	}
}