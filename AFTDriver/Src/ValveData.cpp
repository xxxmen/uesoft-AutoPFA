// ValveData.cpp: implementation of the ValveData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ValveData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ValveData::ValveData()
{
	AppendArray();
}

ValveData::~ValveData()
{

}

JunctionData* ValveData::Creator()
{
	ValveData *pData = new ValveData;
	return pData;
}

CString ValveData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,0,None,0,None,-1,1,5,0,0,0,0,0,0,0,None,-1,0,0,None,1,0,0,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,0");
}

void ValveData::InitExtra(CString strData)
{
	strData = m_Type.InitData(strData);
	strData = m_Curve.InitData(strData);
	strData = m_ExitPress.InitData(strData);
	if(!isImpFile)
		strData = m_Fth2.InitData(strData);
	strData = m_KOrCv.InitData(strData);//应该是在K值以前有4项值

	strData = m_BasisArea.InitData(strData);
	strData = m_UnKown.InitData(strData);
	strData = m_TranData.ValueTypeData().InitData(strData);
	if(!isImpFile)
		strData = m_Fth3.InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
	strData = m_UnKown3.InitData(strData);
}

void ValveData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(22);
	array.SetAt(0,&m_Type.Data());
	array.SetAt(1,&m_Curve.Data());
	array.SetAt(2,&m_ExitPress.Data());
	array.SetAt(3,&m_KOrCv.Data());
	array.SetAt(4,&m_BasisArea.Data());
	array.SetAt(5,&m_UnKown.Data());
	array.SetAt(6,&m_TranData.ValueTypeData().Data());
	array.SetAt(7,&m_TranData.SpecialData().Data());
	array.SetAt(8,&m_TranData.Repeat1Data().Data());
	array.SetAt(9,&m_TranData.Repeat2Data().Data());
	array.SetAt(10,&m_TranData.TransTypeData().Data());
	array.SetAt(11,&m_TranData.TranTriger1Data().Data());
	array.SetAt(12,&m_TranData.TranTriger2Data().Data());
	array.SetAt(13,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(14,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(15,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(16,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(17,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(18,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(19,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(20,&m_TranData.m_Trans2Table.DataData().Data());
	array.SetAt(21,&m_UnKown3.Data());
	m_RowArray.Append(array);
}

/*------------------------------------------*/
CString ValveData::Type()
{
	return m_Type.GetData();
}
void ValveData::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
StrArray<13> ValveData::Curve()
{
	return m_Curve.GetArray();
}
void ValveData::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> ValveData::ExitPress()
{
	return m_ExitPress.GetArray();
}
void ValveData::ExitPress(const StrArray<3>& strValue)
{
	m_ExitPress.SetArray(strValue);
}

/*------------------------------------------*/
CString ValveData::KOrCv()
{
	return m_KOrCv.GetData();
}
void ValveData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> ValveData::BasisArea()
{
	return m_BasisArea.GetArray();
}
void ValveData::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea.SetArray(strValue);
}