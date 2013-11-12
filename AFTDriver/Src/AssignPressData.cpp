// AssignPressData.cpp: implementation of the AssignPressData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AssignPressData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AssignPressData::AssignPressData()
{
	AppendArray();
}

AssignPressData::~AssignPressData()
{

}

JunctionData* AssignPressData::Creator()
{
	AssignPressData *pData = new AssignPressData;
	return pData;
}

CString AssignPressData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,13,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,None,None,0,0,0,0,0,0,0,-1,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None");
}

void AssignPressData::InitExtra(CString strData)
{
	strData = m_linkPipeK.InitData(strData,PipeNum());
	strData = m_Press.InitData(strData);
	if(!isImpFile)
	{
		strData = m_Fth2.InitData(strData);
		strData.Replace(_T("NA"),_T("1"));//这里好象是没有用了。
	}
	strData = m_EleUnit.InitData(strData);
	strData = m_TranData.ValueTypeData().InitData(strData);
	if ( FALSE == isImpFile)
	{
		RowObjectFace<2> Temp;
		strData = Temp.InitData(strData);//这tfh文件比IMP文件多了两位。
	}
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	if ( TRUE == isImpFile )
	{	
		strData = m_TranData.PeriodicData().InitData(strData);
	}
	else
	{
		m_TranData.PeriodicData().InitData(strData);
//		RowObjectFace<2> Temp;
//		strData = Temp.InitData(strData);		
	}

// 	if (!isImpFile)
// 	{
// 		strData.Insert(0,_T("0"));
// 		strData.Insert(1,_T(","));
// 		strData.Insert(2,_T("0"));
// 		strData.Insert(3,_T(","));
// 		strData.Insert(4,_T("MPa"));
// 		strData.Insert(5,_T(","));
// 	}
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
}

void AssignPressData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(19);
	array.SetAt(0,&m_linkPipeK.Data());
	array.SetAt(1,&m_Press.Data());
	array.SetAt(2,&m_EleUnit.Data());
	array.SetAt(3,&m_TranData.ValueTypeData().Data());
	array.SetAt(4,&m_TranData.SpecialData().Data());
	array.SetAt(5,&m_TranData.Repeat1Data().Data());
	array.SetAt(6,&m_TranData.Repeat2Data().Data());
	array.SetAt(7,&m_TranData.TransTypeData().Data());
	array.SetAt(8,&m_TranData.PeriodicData().Data());
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
	m_RowArray.Append(array);
}



/*------------------------------------------*/
ListImp<StrArray<4> > AssignPressData::PipeInfo()
{
	return Combi<1,3>(PipeID(),m_linkPipeK.GetData());
}

void AssignPressData::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<3> > list2;
	Divided<1,3>(list1,list2,strValue);
	m_linkPipeK.SetData(list2);
}
/*------------------------------------------*/
CString AssignPressData::DistanceUnit()
{
	return m_EleUnit.GetData();
}
void AssignPressData::DistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> AssignPressData::Pressure()
{
	return m_Press.GetArray();
}
void AssignPressData::Pressure(const StrArray<3>& strValue)
{
	m_Press.SetArray(strValue);
}