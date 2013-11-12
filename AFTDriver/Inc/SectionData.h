// SectionData.h: interface for the SectionData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECTIONDATA_H__75D9E280_6798_477D_BCEF_EC699773AA86__INCLUDED_)
#define AFX_SECTIONDATA_H__75D9E280_6798_477D_BCEF_EC699773AA86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class AFX_EXT_CLASS SectionData : public PersistentObj  
{
public:
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	void Init();
	SectionData();
	virtual ~SectionData();
public:
	CString Search();
	void Search(CString strValue);
	CString MaxSections();
	void MaxSections(CString strValue);
	CString MinSections();
	void MinSections(CString strValue);
	CString MaxError();
	void MaxError(CString strValue);
	CString PctIncrement();
	void PctIncrement(CString strValue);
	CString Sort();
	void Sort(CString strValue);
	CString IdealSections();
	void IdealSections(CString strValue);
	CString TimeStep();
	void TimeStep(CString strValue);
private:
	void InitRowHead();
	void InitArray();
	RowObject  m_Search;
	RowObject  m_MaxSections;
	RowObject  m_MinSections;
	RowObject  m_MaxError;
	RowObject  m_PctIncrement;
	RowObject  m_Sort;
	RowObject  m_IdealSections;
	RowObject  m_TimeStep;
};

#endif // !defined(AFX_SECTIONDATA_H__75D9E280_6798_477D_BCEF_EC699773AA86__INCLUDED_)
