// SurgeData.cpp: implementation of the SurgeData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SurgeData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SurgeData::SurgeData()
{
	AppendArray();
}

SurgeData::~SurgeData()
{

}

JunctionData* SurgeData::Creator()
{
	SurgeData *pData = new SurgeData;
	return pData;
}

CString SurgeData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,6,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		None,0,None,0,None,0,None,0,-1,-1,0,None,0,-1,0,None,0,None,0,,0,None,0,0,0,None,0,0,None,1,0,feet,None,0,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,-1,0,0,None,1");
}

void SurgeData::InitExtra(CString strData)
{
	strData = m_linkPipeK.InitData(strData,PipeNum());
	strData = m_EleUnit.InitData(strData);
	strData = m_SurgeHeight.InitData(strData);
	strData = m_ConstArea.InitData(strData);
	strData = m_SurfacePress.InitData(strData);
	strData = m_Orifice.InitData(strData);
	strData = m_ShortPipe.InitData(strData);
	strData = m_OneWay.InitData(strData);
	strData = m_Vessel.InitData(strData);
	strData = m_Variable.InitData(strData);
	strData = m_AreaTable.InitData(strData);
	strData = m_InitSurfaceH.InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
	strData = m_CheckValve.InitData(strData);
}

void SurgeData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(26);
	array.SetAt(0,&m_linkPipeK.Data());
	array.SetAt(1,&m_EleUnit.Data());
	array.SetAt(2,&m_SurgeHeight.Data());
	array.SetAt(3,&m_ConstArea.Data());
	array.SetAt(4,&m_SurfacePress.Data());
	array.SetAt(5,&m_Orifice.Data());
	array.SetAt(6,&m_ShortPipe.Data());
	array.SetAt(7,&m_OneWay.Data());
	array.SetAt(8,&m_Vessel.Data());
	array.SetAt(9,&m_Variable.Data());
	array.SetAt(10,&m_AreaTable.UnkownData().Data());
	array.SetAt(11,&m_AreaTable.NumData().Data());
	array.SetAt(12,&m_AreaTable.UnitData().Data());
	array.SetAt(13,&m_AreaTable.DataData().Data());
	array.SetAt(14,&m_InitSurfaceH.Data());
	array.SetAt(15,&m_TranData.TranTriger1Data().Data());
	array.SetAt(16,&m_TranData.TranTriger2Data().Data());
	array.SetAt(17,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(18,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(19,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(20,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(21,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(22,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(23,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(24,&m_TranData.m_Trans2Table.DataData().Data());
	array.SetAt(25,&m_CheckValve.Data());
	m_RowArray.Append(array);
}


/*------------------------------------------*/
ListImp<StrArray<4> > SurgeData::PipeInfo()
{
	return Combi<1,3>(PipeID(),m_linkPipeK.GetData());
}
void SurgeData::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<3> > list2;
	Divided<1,3>(list1,list2,strValue);
	m_linkPipeK.SetData(list2);
}

/*------------------------------------------*/
CString SurgeData::DistanceUnit()
{
	return m_EleUnit.GetData();
}
void SurgeData::DistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> SurgeData::SurgeHeight()
{
	return m_SurgeHeight.GetArray();
}
void SurgeData::SurgeHeight(const StrArray<2>& strValue)
{
	m_SurgeHeight.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> SurgeData::ConstArea()
{
	return m_ConstArea.GetArray();
}
void SurgeData::ConstArea(const StrArray<2>& strValue)
{
	m_ConstArea.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> SurgeData::SurfacePress()
{
	return m_SurfacePress.GetArray();
}
void SurgeData::SurfacePress(const StrArray<2>& strValue)
{
	m_SurfacePress.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> SurgeData::Orifice()
{
	return m_Orifice.GetArray();
}
void SurgeData::Orifice(const StrArray<5>& strValue)
{
	m_Orifice.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<10> SurgeData::ShortPipe()
{
	return m_ShortPipe.GetArray();
}
void SurgeData::ShortPipe(const StrArray<10>& strValue)
{
	m_ShortPipe.SetArray(strValue);
}
/*------------------------------------------*/
CString SurgeData::OneWay()
{
	return m_OneWay.GetData();
}
void SurgeData::OneWay(CString strValue)
{
	m_OneWay.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> SurgeData::Vessel()
{
	return m_Vessel.GetArray();
}
void SurgeData::Vessel(const StrArray<4>& strValue)
{
	m_Vessel.SetArray(strValue);
}

/*------------------------------------------*/
CString SurgeData::Variable()
{
	return m_Variable.GetData();
}
void SurgeData::Variable(CString strValue)
{
	m_Variable.SetData(strValue);
}

/*------------------------------------------*/
StrArray<3> SurgeData::InitSurfaceH()
{
	return m_InitSurfaceH.GetArray();
}
void SurgeData::InitSurfaceH(const StrArray<3>& strValue)
{
	m_InitSurfaceH.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> SurgeData::Check()
{
	return m_CheckValve.GetArray();
}
void SurgeData::Check(const StrArray<5>& strValue)
{
	m_CheckValve.SetArray(strValue);
}
