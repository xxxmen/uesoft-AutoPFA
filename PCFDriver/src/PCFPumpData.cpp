// PCFPumpData.cpp: implementation of the PCFPumpData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPumpData.h"
#include "PCFJun.h"
#include "RowObjectFace.h"
//#include "PersistentObj.h"
#include "RowObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPumpData::PCFPumpData()
{

	InitExtra( GetDefaultData() );
	m_strName = _T("Pump");
	m_nTypeID = 17;
	m_bPFAJun = TRUE;
//	AppendArray();
}

PCFPumpData::~PCFPumpData()
{

}

PCFJun* PCFPumpData::Creator()
{
	PCFPumpData *pData = new PCFPumpData;
	return pData;
}

void PCFPumpData::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

CString PCFPumpData::GetDefaultData()		//泵的初始化数据从节点属性的第52个开始，各个节点属性参考AFT接口文档中的泵
{
	return _T("0,0,1.48,None,0,None,0,None,0,None,0,0,1,0,0,0,0,None,0,0,0,0,meters,0,1,0,0,0,None,0,0,0,0,0,0,0,-1,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,0,0,0,None,-1,0,0,0,0,None,2,0,None,None,None,0,None,-1,0,0,None");
}

void PCFPumpData::InitExtra(CString strData)
{
	
	strData = m_PumpType.InitData(strData);
	strData = m_PumpFlow.InitData(strData);
	strData = m_Config.InitData(strData);
	strData = m_SpeedRatio.InitData(strData);
	strData = m_UnKown3.InitData(strData);
	strData = m_PumpControl.InitData(strData);
	strData = m_ControlApply.InitData(strData);
	strData = m_ViscosCorrection.InitData(strData);
	strData = m_NPSHRefValule.InitData(strData);
	strData = m_PressType.InitData(strData);
	strData = m_SubmergePump.InitData(strData);
	strData = m_TranData.ValueTypeData().InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
	strData = m_TranData.PeriodicData().InitData(strData);
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
	strData = m_ExitCheck.InitData(strData);
	strData = m_TranData.TranModelData().InitData(strData);
	strData = m_TranData.RotateInertiaData().InitData(strData);
	strData = m_TranData.SpeedData().InitData(strData);
	strData = m_PumpSet.InitData(strData);
	strData = m_TranData.FourQuadrantData().InitData(strData);
	strData = m_TranData.m_FourquadTable.InitData(strData);
	strData = m_CloseVel.InitData(strData);
	strData = m_antiReverse.InitData(strData);
	strData = m_ReOpenPress.InitData(strData);
}

void PCFPumpData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(47);
	array.SetAt(0,&m_PumpType.Data());
	array.SetAt(1,&m_PumpFlow.Data());
	array.SetAt(2,&m_Config.m_PressType.Data());
	array.SetAt(3,&m_Config.m_PressUnit.Data());
	array.SetAt(4,&m_Config.m_FlowType.Data());
	array.SetAt(5,&m_Config.m_FlowUnit.Data());
	array.SetAt(6,&m_Config.m_PowerType.Data());
	array.SetAt(7,&m_Config.m_PowerUnit.Data());
	array.SetAt(8,&m_Config.m_Type.Data());
	array.SetAt(9,&m_Config.m_Num.Data());
	array.SetAt(10,&m_SpeedRatio.Data());
	array.SetAt(11,&m_UnKown3.Data());
	array.SetAt(12,&m_PumpControl.Data());
	array.SetAt(13,&m_ControlApply.Data());
	array.SetAt(14,&m_ViscosCorrection.Data());
	array.SetAt(15,&m_NPSHRefValule.Data());
    array.SetAt(16,&m_PressType.Data());
	array.SetAt(17,&m_SubmergePump.Data());
	array.SetAt(18,&m_TranData.ValueTypeData().Data());
	array.SetAt(19,&m_TranData.SpecialData().Data());
	array.SetAt(20,&m_TranData.Repeat1Data().Data());
	array.SetAt(21,&m_TranData.Repeat2Data().Data());
	array.SetAt(22,&m_TranData.TransTypeData().Data());
	array.SetAt(23,&m_TranData.PeriodicData().Data());
	array.SetAt(24,&m_TranData.TranTriger1Data().Data());
	array.SetAt(25,&m_TranData.TranTriger2Data().Data());
	array.SetAt(26,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(27,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(28,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(29,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(30,&m_TranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(31,&m_TranData.m_Trans2Table.NumData().Data());
	array.SetAt(32,&m_TranData.m_Trans2Table.UnitData().Data());
	array.SetAt(33,&m_TranData.m_Trans2Table.DataData().Data());
	array.SetAt(34,&m_ExitCheck.Data());
	array.SetAt(35,&m_TranData.TranModelData().Data());
	array.SetAt(36,&m_TranData.RotateInertiaData().Data());
	array.SetAt(37,&m_TranData.SpeedData().Data());
	array.SetAt(38,&m_PumpSet.Data());
	array.SetAt(39,&m_TranData.FourQuadrantData().Data());
	array.SetAt(40,&m_TranData.m_FourquadTable.UnkownData().Data());
	array.SetAt(41,&m_TranData.m_FourquadTable.NumData().Data());
	array.SetAt(42,&m_TranData.m_FourquadTable.UnitData().Data());
	array.SetAt(43,&m_TranData.m_FourquadTable.DataData().Data());
	array.SetAt(44,&m_CloseVel.Data());
	array.SetAt(45,&m_antiReverse.Data());
	array.SetAt(46,&m_ReOpenPress.Data());
	m_RowArray.Append(array);
}


/*------------------------------------------*/
CString PCFPumpData::PumpType()
{
	return m_PumpType.GetData();
}
void PCFPumpData::PumpType(CString strValue)
{
	m_PumpType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFPumpData::PumpFlow()
{
	return m_PumpFlow.GetArray();
}
void PCFPumpData::PumpFlow(const StrArray<3>& strValue)
{
	m_PumpFlow.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFPumpData::SpeedRatio()
{
	return m_SpeedRatio.GetData();
}
void PCFPumpData::SpeedRatio(CString strValue)
{
	m_SpeedRatio.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> PCFPumpData::PumpControl()
{
	return m_PumpControl.GetArray();
}
void PCFPumpData::PumpControl(const StrArray<4>& strValue)
{
	m_PumpControl.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFPumpData::ControlApply()
{
	return m_ControlApply.GetData();
}
void PCFPumpData::ControlApply(CString strValue)
{
	m_ControlApply.SetData(strValue);
}
/*------------------------------------------*/
CString PCFPumpData::PressType()
{
	return m_PressType.GetData();
}
void PCFPumpData::PressType(CString strValue)
{
	m_PressType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> PCFPumpData::SubmergePump()
{
	return m_SubmergePump.GetArray();
}
void PCFPumpData::SubmergePump(const StrArray<4>& strValue)
{
	m_SubmergePump.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFPumpData::ExitCheck()
{
	return m_ExitCheck.GetData();
}
void PCFPumpData::ExitCheck(CString strValue)
{
	m_ExitCheck.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFPumpData::CloseVel()
{
	return m_CloseVel.GetArray();
}
void PCFPumpData::CloseVel(const StrArray<2>& strValue)
{
	m_CloseVel.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFPumpData::AntiReverse()
{
	return m_antiReverse.GetData();
}
void PCFPumpData::AntiReverse(CString strValue)
{
	m_antiReverse.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFPumpData::ReOpenPress()
{
	return m_ReOpenPress.GetArray();
}
void PCFPumpData::ReOpenPress(const StrArray<3>& strValue)
{
	m_ReOpenPress.SetArray(strValue);
}

/*------------------------------------------*/
inline CString PCFPumpData::PumpSet()
{
	return m_PumpSet.GetData();
}
inline void PCFPumpData::PumpSet(CString strValue)
{
	m_PumpSet.SetData(strValue);
}