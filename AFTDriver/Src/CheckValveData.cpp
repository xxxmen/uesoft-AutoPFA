// heckValveData.cpp: implementation of the CheckValveData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CheckValveData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CheckValveData::CheckValveData()
{
	AppendArray();
}

CheckValveData::~CheckValveData()
{

}

JunctionData* CheckValveData::Creator()
{
	CheckValveData *pData = new CheckValveData;
	return pData;
}

CString CheckValveData::GetDefaultData()
{
	return _T(",9,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,None,0,None,-1,1,5,0,0,0,0,0,0,0,0,None,-1,0,0,None,0,0,None,1,0,seconds,None,None,1,0,seconds,None,0,feet/sec");
}

void CheckValveData::InitExtra(CString strData)
{
	strData = m_Curve.InitData(strData);
	strData = m_UnKown.InitData(strData);
	if ( isImpFile )
	{
		strData = m_ReOpenPress.InitData(strData);
		strData = m_KOrCv.InitData(strData);
		strData = m_BasisArea.InitData(strData);
		strData = m_TranData.ValueTypeData().InitData(strData);
		strData = m_TranData.SpecialData().InitData(strData);
		strData = m_TranData.m_Trans1Table.InitData(strData);
		strData = m_TranData.m_Trans2Table.InitData(strData);
	    strData = m_CloseVel.InitData(strData);
	} 
	else
	{
		strData = m_FthRestrictedArea.InitData( strData ) ;	
		strData = m_KOrCv.InitData(strData);
		strData = m_BasisArea.InitData(strData);
		strData = m_FthUnknown.InitData( strData ) ;
		strData = m_ReOpenPress.InitData(strData);
		strData = m_TranData.ValueTypeData().InitData(strData);
		strData = m_TranData.SpecialData().InitData(strData);
		strData = m_TranData.m_Trans1Table.InitData(strData);
		strData = m_TranData.m_Trans2Table.InitData(strData);
	    strData = m_CloseVel.InitData(strData);
		
	}

}

void CheckValveData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(16);
	array.SetAt(0,&m_Curve.Data());
	array.SetAt(1,&m_UnKown.Data());
	array.SetAt(2,&m_ReOpenPress.Data());
	array.SetAt(3,&m_KOrCv.Data());
	array.SetAt(4,&m_BasisArea.Data());
	array.SetAt(5,&m_TranData.ValueTypeData().Data());
	array.SetAt(6,&m_TranData.SpecialData().Data());
	array.SetAt(7,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(8,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(9,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(10,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(11,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(12,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(13,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(14,&m_TranData.m_Trans2Table.DataData().Data());
	array.SetAt(15,&m_CloseVel.Data());
	m_RowArray.Append(array);
}

/*------------------------------------------*/
StrArray<13> CheckValveData::Curve()
{
	return m_Curve.GetArray();
}
void CheckValveData::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> CheckValveData::ReOpenPress()
{
	return m_ReOpenPress.GetArray();
}
void CheckValveData::ReOpenPress(const StrArray<3>& strValue)
{
	m_ReOpenPress.SetArray(strValue);
}
/*------------------------------------------*/
CString CheckValveData::KOrCv()
{
	return m_KOrCv.GetData();
}
void CheckValveData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> CheckValveData::BasisArea()
{
	return m_BasisArea.GetArray();
}
void CheckValveData::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> CheckValveData::CloseVel()
{
	return m_CloseVel.GetArray();
}
void CheckValveData::CloseVel(const StrArray<2>& strValue)
{
	m_CloseVel.SetArray(strValue);
}