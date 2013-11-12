// ReliefData.cpp: implementation of the ReliefData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ReliefData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ReliefData::ReliefData()
{
	AppendArray();
}

ReliefData::~ReliefData()
{

}

JunctionData* ReliefData::Creator()
{
	ReliefData *pData = new ReliefData;
	return pData;
}

CString ReliefData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,2,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		2,0,0,None,0,None,-1,1,5,0,0,0,0,0,1,0,0,None,0,None,-1,0,0,None,0,0,None,1,0,seconds,None,None,1,0,seconds,None");
}

void ReliefData::InitExtra(CString strData)
{
	strData = m_Type.InitData(strData);
	strData = m_Curve.InitData(strData);
	strData = m_UnKown.InitData(strData);
	strData = m_CrackExitPress.InitData(strData);
	if ( !isImpFile )
	{
		strData = m_FthRestrictedFlowArea.InitData( strData ) ;
	}
	strData = m_KOrCv.InitData(strData);
	strData = m_BasisArea.InitData(strData);
	strData = m_TranData.ValueTypeData().InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
}

void ReliefData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(16);
	array.SetAt(0,&m_Type.Data());
	array.SetAt(1,&m_Curve.Data());
	array.SetAt(2,&m_UnKown.Data());
	array.SetAt(3,&m_CrackExitPress.Data());
	array.SetAt(4,&m_KOrCv.Data());
	array.SetAt(5,&m_BasisArea.Data());
	array.SetAt(6,&m_TranData.ValueTypeData().Data());
	array.SetAt(7,&m_TranData.SpecialData().Data());
	array.SetAt(8,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(9,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(10,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(11,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(12,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(13,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(14,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(15,&m_TranData.m_Trans2Table.DataData().Data());
	m_RowArray.Append(array);
}


/*------------------------------------------*/
CString ReliefData::Type()
{
	return m_Type.GetData();
}
void ReliefData::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
inline StrArray<13> ReliefData::Curve()
{
	return m_Curve.GetArray();
}
void ReliefData::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}
/*------------------------------------------*/
inline StrArray<5> ReliefData::CrackExitPress()
{
	return m_CrackExitPress.GetArray();
}
inline void ReliefData::CrackExitPress(const StrArray<5>& strValue)
{
	m_CrackExitPress.SetArray(strValue);
}

/*------------------------------------------*/
CString ReliefData::KOrCv()
{
	return m_KOrCv.GetData();;
}
void ReliefData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> ReliefData::BasisArea()
{
	return m_BasisArea.GetArray();;
}
void ReliefData::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea.SetArray(strValue);
}