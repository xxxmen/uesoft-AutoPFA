// SprayData.cpp: implementation of the SprayData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SprayData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SprayData::SprayData()
{
	AppendArray();
}

SprayData::~SprayData()
{

}

JunctionData* SprayData::Creator()
{
	SprayData *pData = new SprayData;
	return pData;
}

CString SprayData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,5,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,0,None,0,None,-1,1,5,0,0,0,0,0,0,None,0,1,1,1,None,1,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None");
}

void SprayData::InitExtra(CString strData)
{
// 	if ( !isImpFile )
// 	{
// 		strData = m_linkPipeK.InitData(strData,PipeNum());
// 	}
	strData = m_Type.InitData(strData);
	if ( FALSE == isImpFile )
	{
		RowObjectFace<9> Temp;
		strData = Temp.InitData(strData);//这tfh文件比IMP文件多了9位。
	}
	strData = m_Curve.InitData(strData);
	strData = m_SprayArea.InitData(strData);
	strData = m_KOrCv.InitData(strData);
	strData = m_ExitPress.InitData(strData);	
	strData = m_TranData.ValueTypeData().InitData(strData);
	if ( !isImpFile )
	{
		strData = m_Sparyfth1.InitData(strData);
		strData = m_EleUnit.InitData(strData);
		strData = m_Sparyfth2.InitData(strData);
	}

	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
}

void SprayData::AppendArray()
{
	RowArrayRef array;
	if (isImpFile)
	{
		array.SetSize(20);
		array.SetAt(0,&m_Type.Data());
		array.SetAt(1,&m_Curve.Data());
		array.SetAt(2,&m_SprayArea.Data());
		array.SetAt(3,&m_KOrCv.Data());
		array.SetAt(4,&m_ExitPress.Data());
		array.SetAt(5,&m_TranData.ValueTypeData().Data());
		array.SetAt(6,&m_TranData.SpecialData().Data());
		array.SetAt(7,&m_TranData.Repeat1Data().Data());
		array.SetAt(8,&m_TranData.Repeat2Data().Data());
		array.SetAt(9,&m_TranData.TransTypeData().Data());
		array.SetAt(10,&m_TranData.TranTriger1Data().Data());
		array.SetAt(11,&m_TranData.TranTriger2Data().Data());
		array.SetAt(12,&m_TranData.m_Trans1Table.UnkownData().Data());
		array.SetAt(13,&m_TranData.m_Trans1Table.NumData().Data());
		array.SetAt(14,&m_TranData.m_Trans1Table.UnitData().Data());
		array.SetAt(15,&m_TranData.m_Trans1Table.DataData().Data());
		array.SetAt(16,&m_TranData.m_Trans2Table.UnkownData().Data());
		array.SetAt(17,&m_TranData.m_Trans2Table.NumData().Data());
		array.SetAt(18,&m_TranData.m_Trans2Table.UnitData().Data());
		array.SetAt(19,&m_TranData.m_Trans2Table.DataData().Data());
	}else{
		array.SetSize(24);
		array.SetAt(0,&m_Type.Data());
		array.SetAt(1,&m_Curve.Data());
		array.SetAt(2,&m_SprayArea.Data());
		array.SetAt(3,&m_KOrCv.Data());
		array.SetAt(4,&m_ExitPress.Data());
		array.SetAt(5,&m_linkPipeK.Data());//6.0下管道流向多加入了K系数和管道端口与节点标高		
		array.SetAt(6,&m_EleUnit.Data());//6.0下管道流向多加入了K系数和管道端口与节点标高	
		array.SetAt(7,&m_Sparyfth1.Data());//6.0下多出
		array.SetAt(8,&m_Sparyfth2.Data());//6.0下多出
		array.SetAt(9,&m_TranData.ValueTypeData().Data());
		array.SetAt(10,&m_TranData.SpecialData().Data());
		array.SetAt(11,&m_TranData.Repeat1Data().Data());
		array.SetAt(12,&m_TranData.Repeat2Data().Data());
		array.SetAt(13,&m_TranData.TransTypeData().Data());
		array.SetAt(14,&m_TranData.TranTriger1Data().Data());
		array.SetAt(15,&m_TranData.TranTriger2Data().Data());
		array.SetAt(16,&m_TranData.m_Trans1Table.UnkownData().Data());
		array.SetAt(17,&m_TranData.m_Trans1Table.NumData().Data());
		array.SetAt(18,&m_TranData.m_Trans1Table.UnitData().Data());
		array.SetAt(19,&m_TranData.m_Trans1Table.DataData().Data());
		array.SetAt(20,&m_TranData.m_Trans2Table.UnkownData().Data());
		array.SetAt(21,&m_TranData.m_Trans2Table.NumData().Data());
		array.SetAt(22,&m_TranData.m_Trans2Table.UnitData().Data());
		array.SetAt(23,&m_TranData.m_Trans2Table.DataData().Data());	
	}

	m_RowArray.Append(array);
}
//6.0下管道流向多加入了K系数和管道端口与节点标高
/*------------------------------------------*/
ListImp<StrArray<4> > SprayData::PipeInfo()
{
	return Combi<1,3>(PipeID(),m_linkPipeK.GetData());
}

void SprayData::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<3> > list2;
	Divided<1,3>(list1,list2,strValue);
	m_linkPipeK.SetData(list2);
}
/*------------------------------------------*/
CString SprayData::DistanceUnit()
{
	return m_EleUnit.GetData();
}
void SprayData::DistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}

/*------------------------------------------*/
CString SprayData::Type()
{
	return m_Type.GetData();
}
void SprayData::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
StrArray<13> SprayData::Curve()
{
	return m_Curve.GetArray();
}
void SprayData::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> SprayData::ExitArea()
{
	return m_SprayArea.GetArray();
}
void SprayData::ExitArea(const StrArray<3>& strValue)
{
	m_SprayArea.SetArray(strValue);
}

/*------------------------------------------*/
CString SprayData::KOrCv()
{
	return m_KOrCv.GetData();
}
void SprayData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> SprayData::ExitPress()
{
	return m_ExitPress.GetArray();
}
void SprayData::ExitPress(const StrArray<3>& strValue)
{
	m_ExitPress.SetArray(strValue);
}