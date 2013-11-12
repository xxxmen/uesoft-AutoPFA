// PumpData.cpp: implementation of the PumpData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PumpData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpData::PumpData()
{
	AppendArray();
}

PumpData::~PumpData()
{

}

JunctionData* PumpData::Creator()
{
	PumpData *pData = new PumpData;
	return pData;
}

CString PumpData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,14,0,0,0,0,None,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,0,None,0,None,0,None,0,None,0,0,1,0,0,0,0,None,0,0,0,0,meters,0,1,0,0,0,None,0,0,0,0,0,0,0,-1,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,0,0,0,None,-1,0,0,0,0,None,2,0,None,None,None,0,None,-1,0,0,None");
}
void PumpData::InitExtra(CString strData)
{
	strData = m_PumpType.InitData(strData);
	strData = m_PumpFlow.InitData(strData);
	if (!isImpFile)
		strData = m_Fth1.InitData(strData);
	strData = m_Config.InitData(strData);
	strData = m_SpeedRatio.InitData(strData);
	strData = m_UnKown3.InitData(strData);
	if (isImpFile)
	{
		strData = m_ViscosCorrection.InitData(strData);
	}else{
		strData = m_Fth2.InitData(strData);              //6.0下粘度修正项位置改放了8项未知值
		strData.Insert(2,_T("0,"));                          //泵控制中的控制点参数类型6.0下没有，得补上   
	}
	strData = m_PumpControl.InitData(strData);
	strData = m_ControlApply.InitData(strData);
	strData = m_NPSHRefValule.InitData(strData);
	strData = m_PressType.InitData(strData);

	if (isImpFile)
	{
		strData = m_SubmergePump.InitData(strData);
	}else{
		int flage;		//标志值，用来为后面表格数量作判断
		m_SubmergePump.InitData(_T("0,0,0,None,"));        //补上潜水泵相应四项
		strData = m_ViscosCorrection.InitData(strData);//6.下粘度修正项改放在潜水泵选择项的位置0
		//以下为6.0下瞬变数据前多出28项（根据表行数有变化）
		strData = m_Fth3.InitData(strData); 
		strData = m_Fth4.InitData(strData); 
		strData = m_Fth5.InitData(strData); 
		strData = m_Fth6.InitData(strData); 
		strData = m_Fth7.InitData(strData); 
		strData = m_Fth8.InitData(strData); 
		strData = m_Fth9.InitData(strData); 
		strData = m_Fth10.InitData(strData); 
		m_Fth9.GetData(flage);
		strData = m_FthBefTwoRowArray.InitData(strData,2*flage);
		strData = m_Fth11.InitData(strData); 
		strData = m_Fth12.InitData(strData); 
		strData = m_Fth13.InitData(strData); 
		m_Fth11.GetData(flage);
		strData = m_FthAftTwoRowArray.InitData(strData,2*flage);

		strData = m_PumpSet.InitData(strData);         //并串联泵改放在这
		strData = m_Impeller.InitData(strData);        //多出的叶轮修正值
	}
	strData = m_TranData.ValueTypeData().InitData(strData);
	strData = m_TranData.SpecialData().InitData(strData);
	strData = m_TranData.Repeat1Data().InitData(strData);
	strData = m_TranData.Repeat2Data().InitData(strData);
	strData = m_TranData.TransTypeData().InitData(strData);
 	if (isImpFile)
 	{
		strData = m_TranData.PeriodicData().InitData(strData);
	}else{	
		strData = m_TranData.PeriodicData().InitData(_T("0,0,-1,0,None,"));//补上3.0下多出的未知五项
	}
	strData = m_TranData.TranTriger1Data().InitData(strData);
	strData = m_TranData.TranTriger2Data().InitData(strData);
	strData = m_TranData.m_Trans1Table.InitData(strData);
	strData = m_TranData.m_Trans2Table.InitData(strData);
	strData = m_ExitCheck.InitData(strData);
	//以下的就只有3.0才会有的数据,6.0要读的话得加上下面的话，但并串联泵(第5位)不能重设
	//	strData = _T("0,475,lbm-ft2,1760,4,0,0,0,None,2,0,None,, ,0,feet/sec,-1,0,0,feet");//补上后面没有的两个面板数据
	if (isImpFile)
	{
		strData = m_TranData.TranModelData().InitData(strData);
		strData = m_TranData.RotateInertiaData().InitData(strData);
		strData = m_TranData.SpeedData().InitData(strData);
		strData = m_PumpSet.InitData(strData);         //并串联泵改放在这
		strData = m_TranData.FourQuadrantData().InitData(strData);
		strData = m_TranData.m_FourquadTable.InitData(strData);
		strData = m_CloseVel.InitData(strData);
		strData = m_antiReverse.InitData(strData);
		strData = m_ReOpenPress.InitData(strData);
	}
}

void PumpData::AppendArray()
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
CString PumpData::PumpType()
{
	return m_PumpType.GetData();
}
void PumpData::PumpType(CString strValue)
{
	m_PumpType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PumpData::PumpFlow()
{
	return m_PumpFlow.GetArray();
}
void PumpData::PumpFlow(const StrArray<3>& strValue)
{
	m_PumpFlow.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpData::SpeedRatio()
{
	return m_SpeedRatio.GetData();
}
void PumpData::SpeedRatio(CString strValue)
{
	m_SpeedRatio.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> PumpData::PumpControl()
{
	return m_PumpControl.GetArray();
}
void PumpData::PumpControl(const StrArray<4>& strValue)
{
	m_PumpControl.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpData::ControlApply()
{
	return m_ControlApply.GetData();
}
void PumpData::ControlApply(CString strValue)
{
	m_ControlApply.SetData(strValue);
}
/*------------------------------------------*/
CString PumpData::PressType()
{
	return m_PressType.GetData();
}
void PumpData::PressType(CString strValue)
{
	m_PressType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> PumpData::SubmergePump()
{
	return m_SubmergePump.GetArray();
}
void PumpData::SubmergePump(const StrArray<4>& strValue)
{
	m_SubmergePump.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpData::ExitCheck()
{
	return m_ExitCheck.GetData();
}
void PumpData::ExitCheck(CString strValue)
{
	m_ExitCheck.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> PumpData::CloseVel()
{
	return m_CloseVel.GetArray();
}
void PumpData::CloseVel(const StrArray<2>& strValue)
{
	m_CloseVel.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpData::AntiReverse()
{
	return m_antiReverse.GetData();
}
void PumpData::AntiReverse(CString strValue)
{
	m_antiReverse.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PumpData::ReOpenPress()
{
	return m_ReOpenPress.GetArray();
}
void PumpData::ReOpenPress(const StrArray<3>& strValue)
{
	m_ReOpenPress.SetArray(strValue);
}

/*------------------------------------------*/
inline CString PumpData::PumpSet()
{
	return m_PumpSet.GetData();
}
inline void PumpData::PumpSet(CString strValue)
{
	m_PumpSet.SetData(strValue);
}