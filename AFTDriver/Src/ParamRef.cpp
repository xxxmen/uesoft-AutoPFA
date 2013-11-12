// ParamRef.cpp: implementation of the ParamRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParamRef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ParamRef::ParamRef()
{
	InitArray();
}

ParamRef::~ParamRef()
{

}

BOOL ParamRef::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL ParamRef::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void ParamRef::Init()
{
	CString strArray[15];
	strArray[0] = _T("0");
	strArray[1] = _T("0");
	strArray[2] = _T("0");
	strArray[3] = _T("0");

	if ( isImpFile )
	{
		strArray[4] = _T("0, feet");
	} 
	else
	{
		strArray[4] = _T("0, None");
	}
	
	strArray[5] = _T("1");
	strArray[6] = _T("1");
	strArray[7] = _T("1");
	strArray[8] = _T("1");
	strArray[9] = _T("1");
	strArray[10] = _T("-1");
	strArray[11] = _T("None");
	strArray[12] = _T("None");
	strArray[13] = _T("None");
	strArray[14] = _T("None");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==15);
		m_RowArray.GetAt(i)->ReadChild(strArray[i]);
	}
}

void ParamRef::InitArray()
{
	m_RowArray.SetSize(15);
	m_RowArray.SetAt(0,&m_HGLoRPres);
	m_RowArray.SetAt(1,&m_FlowRate);
	m_RowArray.SetAt(2,&m_LossModel);
	m_RowArray.SetAt(3,&m_EleSpec);
	m_RowArray.SetAt(4,&m_DefaultEle);
	m_RowArray.SetAt(5,&m_PipeDesign);
	m_RowArray.SetAt(6,&m_PipeDesignLoss);
	m_RowArray.SetAt(7,&m_PipeDesignHeatTransfer);
	m_RowArray.SetAt(8,&m_JunDesign);
	m_RowArray.SetAt(9,&m_PumpDesign);
	m_RowArray.SetAt(10,&m_UseLastPipe);
	m_RowArray.SetAt(11,&m_LastMaterial);
	m_RowArray.SetAt(12,&m_LastSize);
	m_RowArray.SetAt(13,&m_LastType);
	m_RowArray.SetAt(14,&DefaultMaterial);
	InitRowHead();
}

void ParamRef::InitRowHead()
{
	SetID("\n[PARAMETER PREFERENCES]");
	CString strArray[15];
	if ( isImpFile )
	{
		strArray[0] = _T("HGL/Pressure=");
		strArray[1] = _T("Flow Rate=");
		strArray[2] = _T("Loss Model=");
		strArray[3] = _T("Elevation Specified=");
		strArray[4] = _T("Default Elevation=");
		strArray[5] = _T("PipeDesign=");
		strArray[6] = _T("PipeDesignLosses=");
		strArray[7] = _T("PipeDesignHeatTransfer=");
		strArray[8] = _T("JctDesign=");
		strArray[9] = _T("PumpDesign=");
		strArray[10] = _T("UseLastPipe=");
		strArray[11] = _T("LastMaterial=");
		strArray[12] = _T("LastSize=");
		strArray[13] = _T("LastType=");
		strArray[14] = _T("DefaultMaterial=");
	} 
	else
	{
		strArray[0] = _T("HGL/Pressure= ");
		strArray[1] = _T("Flow Rate= ");
		strArray[2] = _T("Loss Model= ");
		strArray[3] = _T("Elevation Specified= ");
		strArray[4] = _T("Default Elevation= ");
		strArray[5] = _T("PipeDesign= ");
		strArray[6] = _T("PipeDesignLosses= ");
		strArray[7] = _T("PipeDesignHeatTransfer= ");
		strArray[8] = _T("JctDesign= ");
		strArray[9] = _T("PumpDesign= ");
		strArray[10] = _T("UseLastPipe= ");
		strArray[11] = _T("LastMaterial= ");
		strArray[12] = _T("LastSize= ");
		strArray[13] = _T("LastType= ");
		strArray[14] = _T("DefaultMaterial= ");
	}
	
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==15);
		m_RowArray.GetAt(i)->InitHead(strArray[i]);
	}
}
