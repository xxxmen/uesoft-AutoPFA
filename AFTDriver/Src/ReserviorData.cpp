// ReserviorData.cpp: implementation of the ReserviorData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ReserviorData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ReserviorData::ReserviorData()
{
	AppendArray();
}

ReserviorData::~ReserviorData()
{

}

JunctionData* ReserviorData::Creator()
{
	ReserviorData *pData = new ReserviorData;
	return pData;
}

CString ReserviorData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,5,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,None,1,None,0,None,0,None,0,0,0,0,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None");
}

void ReserviorData::InitExtra(CString strData)
{
	strData = m_linkPipeK.InitData(strData,PipeNum());
	strData = m_EleOrDepth.InitData(strData);
	strData = m_SurfacePress.InitData(strData);
	strData = m_Teamperature.InitData(strData);
	strData = m_Density.InitData(strData);
	strData = m_UnKown.InitData(strData);

	if (!isImpFile)
	{
		
		strData = m_Fth2_1.InitData(strData);
		RowObjectFace<3> FthTemp;
		strData = FthTemp.InitData(strData);
		CString strReu;
		CString temp;
		FthTemp.GetData( temp, 1 );//fth文件里面只有标高,这里只取第1个值(.按常理是有一个入口标高和出口标高 )
		strReu = temp;strReu += _T( "," );
		FthTemp.GetData( temp, 1 );
		strReu += temp;strReu += _T( "," );
		FthTemp.GetData( temp, 2 );
		strReu += temp;
//		InEle(strReu);
		m_EleArray.InitData(strReu);
		strData = m_Fth2.InitData(strData);
	}
	strData = m_EleOrDepthType.InitData(strData);
	strData = m_TranData.ValueTypeData().InitData(strData);

	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	if(!isImpFile)
		strData = m_Fth3.InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
}

void ReserviorData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(22);
	array.SetAt(0,&m_linkPipeK.Data());
	array.SetAt(1,&m_EleOrDepth.Data());
	array.SetAt(2,&m_SurfacePress.Data());
	array.SetAt(3,&m_Teamperature.Data());
	array.SetAt(4,&m_Density.Data());
	array.SetAt(5,&m_UnKown.Data());
	array.SetAt(6,&m_EleOrDepthType.Data());
	array.SetAt(7,&m_TranData.ValueTypeData().Data());
	array.SetAt(8,&m_TranData.SpecialData().Data());
	array.SetAt(9,&m_TranData.Repeat1Data().Data());
	array.SetAt(10,&m_TranData.Repeat2Data().Data());
	array.SetAt(11,&m_TranData.TransTypeData().Data());
	array.SetAt(12,&m_TranData.TranTriger1Data().Data());
	array.SetAt(13,&m_TranData.TranTriger2Data().Data());
	array.SetAt(14,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(15,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(16,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(17,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(18,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(19,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(20,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(21,&m_TranData.m_Trans2Table.DataData().Data());
	m_RowArray.Append(array);
}


/*------------------------------------------*/
ListImp<StrArray<6> > ReserviorData::PipeInfo()
{
	return Combi<1,5>(PipeID(),m_linkPipeK.GetData());
}
void ReserviorData::PipeInfo(const ListImp<StrArray<6> >& strValue)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<5> > list2;
	Divided<1,5>(list1,list2,strValue);
	m_linkPipeK.SetData(list2);
}
/*------------------------------------------*/
StrArray<2> ReserviorData::EleOrDepth()
{
	return m_EleOrDepth.GetArray();
}
void ReserviorData::EleOrDepth(const StrArray<2>& strValue)
{
	m_EleOrDepth.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> ReserviorData::SurfacePress()
{
	return m_SurfacePress.GetArray();
}
void ReserviorData::SurfacePress(const StrArray<2>& strValue)
{
	m_SurfacePress.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> ReserviorData::Teamperature()
{
	return m_Teamperature.GetArray();
}
void ReserviorData::Teamperature(const StrArray<2>& strValue)
{
	m_Teamperature.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> ReserviorData::Density()
{
	return m_Density.GetArray();
}
void ReserviorData::Density(const StrArray<2>& strValue)
{
	m_Density.SetArray(strValue);
}
/*------------------------------------------*/
CString ReserviorData::EleOrDepthType()
{
	return m_EleOrDepthType.GetData();
}
void ReserviorData::EleOrDepthType(CString strValue)
{
	m_EleOrDepthType.SetData(strValue);
}