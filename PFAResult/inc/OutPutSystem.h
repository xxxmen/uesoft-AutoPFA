// OutPutSystem.h: interface for the OutPutSystem.h class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUTSYSTEM_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_)
#define AFX_OUTPUTSYSTEM_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PipeOutShow.h"
#include "JunOutShow.h"
#include "RowObject.h"
typedef CArray<PipeOutShow,PipeOutShow> PipeOutArray;
typedef CArray<JunOutShow,JunOutShow> JunOutArray;

class AFX_EXT_CLASS OutPutSystem 
{
public:

	CString Read(CString InData, TCHAR chSeparator);


	void  Read(LPCTSTR filename);
	void static InitData(CString InData,CString str[50],TCHAR chSeparator = _T(','));
 	 void InitOutPutSystem();

	PipeOutArray& GetPipeOutArray();
	JunOutArray& GetJunOutArray();
	CString  GetOutData(CString strTemp);

public:

	OutPutSystem();
	virtual ~OutPutSystem();
	
protected:
private:
	CString   m_PipeKey;
	CString   m_PipeKeyArray[50];
    CString   m_PipeId;
	CString   m_PipeIdArray[50];
    CString   m_PipeUnit;
	CString   m_PipeUnitArray[50];
	CString   m_PipeName;
	CString   m_PipeNameArray[50];

	CString   m_JunKey;
	CString   m_JunKeyArray[50];
	CString   m_JunId;
	CString   m_JunIdArray[50];
	CString   m_JunUnit;
	CString   m_JunUnitArray[50];
	CString   m_JunName;
	CString   m_JunNameArray[50];
	UnitTypeID m_PipeTypeId[50];
	UnitTypeID m_JunTypeId[50];
	
	PipeOutArray  m_PipeOutArray;
	JunOutArray  m_JunOutArray;
	JunOutArray  m_JunTranOutArray;

	
};

#endif // !defined(AFX_OUTPUTSYSTEM_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_)
