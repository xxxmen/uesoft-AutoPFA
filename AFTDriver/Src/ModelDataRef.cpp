// ModelDataRef.cpp: implementation of the ModelDataRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModelDataRef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ModelDataRef::ModelDataRef()
{
	InitArray();
}

ModelDataRef::~ModelDataRef()
{

}

BOOL ModelDataRef::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL ModelDataRef::Save(CStdioFile &file)
{
	return SaveRow(file);
}

void ModelDataRef::Init()
{
	CString strArray[20];
	strArray[0] = _T("14,1,10,7,9,11,13,28,40,0,4,5,6,35,37");
	strArray[1] = _T("15,2,9,5,6,3,101,102,103,105,107,108,109,110,111,112");
	strArray[2] = _T("10,2,9,5,6,3,103,108,109,118,119");
	strArray[3] = _T("17,2,9,5,6,3,101,102,103,104,106,109,112,113,114,115,116,117");
	strArray[4] = _T("15,2,9,5,6,3,102,103,105,108,111,112,113,114,115,116");
	strArray[5] = _T("9,2,9,5,6,3,102,105,103,104");
	strArray[6] = _T("9,2,9,5,6,3,102,105,103,104");
	strArray[7] = _T("19,2,9,5,6,3,101,106,107,102,103,104,105,110,112,113,114,115,116,117");
	strArray[8] = _T("19,2,9,5,6,3,101,102,103,104,105,114,115,116,107,107,109,110,112,113");
	strArray[9] = _T("15,2,9,5,6,3,101,106,102,103,104,105,110,111,108,109");
	strArray[10] = _T("5,2,9,5,6,3");
	strArray[11] = _T("18,2,9,5,6,3,102,108,107,103,104,110,112,114,115,116,117,118,119");
	strArray[12] = _T("22,2,9,5,6,3,101,102,105,103,110,111,115,106,107,118,121,124,125,126,127,128,129");
	strArray[13] = _T("5,2,9,5,6,3");
	strArray[14] = _T("10,2,9,5,6,3,101,102,103,104,105");
	strArray[15] = _T("17,2,9,5,6,3,101,106,107,108,0,102,103,104,105,112,113,111");
	strArray[16] = _T("19,2,9,5,6,3,101,0,0,102,103,104,105,106,107,108,109,110,111,112");
	strArray[17] = _T("7,2,9,5,6,3,102,103");
	strArray[18] = _T("22,2,9,5,6,3,102,104,105,106,116,107,108,109,110,111,112,113,114,115,117,120,121");
	strArray[19] = _T("12,2,9,5,6,3,111,102,103,104,106,105,108");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==20);
		m_RowArray.GetAt(i)->ReadChild(strArray[i]);
	}
}

void ModelDataRef::InitArray()
{
	m_RowArray.SetSize(20);
	m_RowArray.SetAt(0,&m_PipeParam);
	m_RowArray.SetAt(1,&m_Branch);
	m_RowArray.SetAt(2,&m_Reservoir);
	m_RowArray.SetAt(3,&m_AssignedFlow);
	m_RowArray.SetAt(4,&m_AssignedPress);
	m_RowArray.SetAt(5,&m_AreaChange);
	m_RowArray.SetAt(6,&m_ReliefValve);
	m_RowArray.SetAt(7,&m_TeeWye);
	m_RowArray.SetAt(8,&m_Valve);
	m_RowArray.SetAt(9,&m_ControlValve);
	m_RowArray.SetAt(10,&m_CheckValve);
	m_RowArray.SetAt(11,&m_DeadEnd);
	m_RowArray.SetAt(12,&m_GasAccumulator);
	m_RowArray.SetAt(13,&m_Surge);
	m_RowArray.SetAt(14,&m_LiquidAccum);
	m_RowArray.SetAt(15,&m_VacuumBreaker);
	m_RowArray.SetAt(16,&m_SprayDischarge);
	m_RowArray.SetAt(17,&m_Pump);
	m_RowArray.SetAt(18,&m_Volume);
	m_RowArray.SetAt(19,&m_General);
	InitRowHead();
}


void ModelDataRef::InitRowHead()
{
	SetID("\n[MODEL DATA PREFERENCES]");
	CString strArray[20];
	strArray[0] = _T("Pipe Parameters= ");
	strArray[1] = _T("Junction Parameters(1)=");
	strArray[2] = _T("Junction Parameters(2)=");
	strArray[3] = _T("Junction Parameters(3)=");
	strArray[4] = _T("Junction Parameters(4)=");
	strArray[5] = _T("Junction Parameters(5)=");
	strArray[6] = _T("Junction Parameters(7)=");
	strArray[7] = _T("Junction Parameters(8)=");
	strArray[8] = _T("Junction Parameters(9)=");
	strArray[9] = _T("Junction Parameters(10)=");
	strArray[10] = _T("Junction Parameters(11)=");
	strArray[11] = _T("Junction Parameters(16)=");
	strArray[12] = _T("Junction Parameters(17)=");
	strArray[13] = _T("Junction Parameters(19)=");
	strArray[14] = _T("Junction Parameters(20)=");
	strArray[15] = _T("Junction Parameters(21)=");
	strArray[16] = _T("Junction Parameters(22)=");
	strArray[17] = _T("Junction Parameters(23)=");
	strArray[18] = _T("Junction Parameters(24)=");
	strArray[19] = _T("Junction Parameters(25)=");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==20);
		m_RowArray.GetAt(i)->InitHead(strArray[i]);
	}
}
