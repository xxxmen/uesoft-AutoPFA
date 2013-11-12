// BrachData.cpp: implementation of the BrachData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BrachData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BrachData::BrachData()
{
	AppendArray();
}

BrachData::~BrachData()
{

}

JunctionData* BrachData::Creator()
{
	BrachData *pData = new BrachData;
	return pData;
}

CString BrachData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,8,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,None,None,0,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None");
}

void BrachData::InitExtra(CString strData)
{
	strData = m_linkPipeK.InitData(strData,PipeNum());
	strData = m_ImposeFlow.InitData(strData);
	if ( !isImpFile )
	{
		strData = m_FthSourceTempture.InitData( strData ) ;
		strData = m_FthUnknow.InitData( strData ) ;
	}
	strData = m_EleUnit.InitData(strData);
	if ( !isImpFile )
	{
		RowObjectFace<2> FthUnknowTempture;
		strData = FthUnknowTempture.InitData( strData ) ;
	}
	strData = m_TranData.ValueTypeData().InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
}

void BrachData::AppendArray()
{
	RowArrayRef array;
	if ( isImpFile )
	{
		array.SetSize(18);
		array.SetAt(0,&m_linkPipeK.Data());
		array.SetAt(1,&m_ImposeFlow.Data());
		array.SetAt(2,&m_EleUnit.Data());
		array.SetAt(3,&m_TranData.ValueTypeData().Data());
		array.SetAt(4,&m_TranData.SpecialData().Data());
		array.SetAt(5,&m_TranData.Repeat1Data().Data());
		array.SetAt(6,&m_TranData.Repeat2Data().Data());
		array.SetAt(7,&m_TranData.TransTypeData().Data());
		array.SetAt(8,&m_TranData.TranTriger1Data().Data());
		array.SetAt(9,&m_TranData.TranTriger2Data().Data());
		array.SetAt(10,&m_TranData.m_Trans1Table.UnkownData().Data());
		array.SetAt(11,&m_TranData.m_Trans1Table.NumData().Data());
		array.SetAt(12,&m_TranData.m_Trans1Table.UnitData().Data());
		array.SetAt(13,&m_TranData.m_Trans1Table.DataData().Data());
		array.SetAt(14,&m_TranData.m_Trans2Table.UnkownData().Data());
		array.SetAt(15,&m_TranData.m_Trans2Table.NumData().Data());
		array.SetAt(16,&m_TranData.m_Trans2Table.UnitData().Data());
		array.SetAt(17,&m_TranData.m_Trans2Table.DataData().Data());
	} 
	else
	{
		array.SetSize(19);
		array.SetAt(0,&m_linkPipeK.Data());
		array.SetAt(1,&m_ImposeFlow.Data());
		array.SetAt(2,&m_FthSourceTempture.Data());
		array.SetAt(3,&m_EleUnit.Data());
		array.SetAt(4,&m_TranData.ValueTypeData().Data());
		array.SetAt(5,&m_TranData.SpecialData().Data());
		array.SetAt(6,&m_TranData.Repeat1Data().Data());
		array.SetAt(7,&m_TranData.Repeat2Data().Data());
		array.SetAt(8,&m_TranData.TransTypeData().Data());
		array.SetAt(9,&m_TranData.TranTriger1Data().Data());
		array.SetAt(10,&m_TranData.TranTriger2Data().Data());
		array.SetAt(11,&m_TranData.m_Trans1Table.UnkownData().Data());
		array.SetAt(12,&m_TranData.m_Trans1Table.NumData().Data());
		array.SetAt(13,&m_TranData.m_Trans1Table.UnitData().Data());
		array.SetAt(14,&m_TranData.m_Trans1Table.DataData().Data());
		array.SetAt(15,&m_TranData.m_Trans2Table.UnkownData().Data());
		array.SetAt(16,&m_TranData.m_Trans2Table.NumData().Data());
		array.SetAt(17,&m_TranData.m_Trans2Table.UnitData().Data());
		array.SetAt(18,&m_TranData.m_Trans2Table.DataData().Data());
	}
	
	m_RowArray.Append(array);
}


ListImp<StrArray<4> > BrachData::PipeInfo()
{
	return Combi<1,3>(PipeID(),m_linkPipeK.GetData());
}
void BrachData::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<3> > list2;
	Divided<1,3>(list1,list2,strValue);
	m_linkPipeK.SetData(list2);
}

/*------------------------------------------*/
CString BrachData::DistanceUnit()
{
	return m_EleUnit.GetData();
}
void BrachData::DistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> BrachData::ImposeFlow()
{
	return m_ImposeFlow.GetArray();
}
void BrachData::ImposeFlow(const StrArray<3>& strValue)
{
	m_ImposeFlow.SetArray(strValue);
}