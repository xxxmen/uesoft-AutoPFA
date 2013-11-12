// AssignFlowData.cpp: implementation of the AssignFlowData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AssignFlowData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AssignFlowData::AssignFlowData()
{
	AppendArray();
}

AssignFlowData::~AssignFlowData()
{

}

JunctionData* AssignFlowData::Creator()
{
	AssignFlowData *pData = new AssignFlowData;
	return pData;
}

CString AssignFlowData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,24,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,None,0,0,0,0,0,0,0,0,0,-1,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,0,0,0,None");
}

void AssignFlowData::InitExtra(CString strData)
{
	strData = m_Flow.InitData(strData);
	strData = m_FlowDir.InitData(strData);
// 	if ( !isImpFile )
// 	{
// 		strData = m_FthUnknown1.InitData( strData ) ;
// 	}//这个可能是以前的错误的需求。若有问题再查原因。Modify wenzk
	strData = m_K.InitData(strData);
	if ( FALSE == isImpFile )
	{
		RowObjectFace<5> temp;
		strData = temp.InitData(strData);//这里多5个字段。先用局部变量读出来，等做保存FTH 的时候再做处理。
	}
	strData = m_TranData.ValueTypeData().InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	if ( TRUE == isImpFile )
	{	
		strData = m_TranData.PeriodicData().InitData(strData);
	}

	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
	if ( isImpFile )
	{
		strData = m_InitPress.InitData(strData);
		//FTH文件比IMP文件最后面少了三个字段。
	}
	
}

void AssignFlowData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(20);
	array.SetAt(0,&m_Flow.Data());
	array.SetAt(1,&m_FlowDir.Data());
	array.SetAt(2,&m_K.Data());
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
	array.SetAt(19,&m_InitPress.Data());
	m_RowArray.Append(array);
}

/*------------------------------------------*/
StrArray<3> AssignFlowData::Flow()
{
	return m_Flow.GetArray();
}
void AssignFlowData::Flow(const StrArray<3>& strValue)
{
	m_Flow .SetArray(strValue);
}

/*------------------------------------------*/
CString AssignFlowData::FlowDir()
{
	return m_FlowDir.GetData();
}
void AssignFlowData::FlowDir(CString strValue)
{
	m_FlowDir.SetData(strValue);
}
/*------------------------------------------*/
CString AssignFlowData::K()
{
	return m_K.GetData();
}
void AssignFlowData::K(CString strValue)
{
	m_K.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> AssignFlowData::InitPress()
{
	return m_InitPress.GetArray();
}
void AssignFlowData::InitPress(const StrArray<4>& strValue)
{
	m_InitPress.SetArray(strValue);
}