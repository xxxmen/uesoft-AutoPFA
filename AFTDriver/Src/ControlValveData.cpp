// introlValveData.cpp: implementation of the CintrolValveData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ControlValveData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlValveData::ControlValveData()
{
	AppendArray();
}

ControlValveData::~ControlValveData()
{

}

JunctionData* ControlValveData::Creator()
{
	ControlValveData *pData = new ControlValveData;
	return pData;
}

CString ControlValveData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,6,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,0,1,0,None,0,0,1,0,None,2,0,,,,0,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,None,1,0,seconds,None,0,0,None,0,-1,0,0");
}     

void ControlValveData::InitExtra(CString strData)
{
	strData = m_ControlSet.InitData(strData);
	if ( !isImpFile )
	{
		strData = m_FthUnknown.InitData( strData ) ;
	}
	strData = m_UnKown.InitData(strData);
	strData = m_ModelType.InitData(strData);
	if ( m_ModelType.GetData() == _T("-1") )
	{
		m_ModelType.SetData( _T("0") );
		strData = m_KOrCv.InitData( strData );
		m_KOrCv.SetData(_T("0"));
	} 
	else
	{
		strData = m_KOrCv.InitData(strData);
	}
	
	strData = m_UnKown4.InitData(strData);
	strData = m_DataUnitNum.InitData(strData);
	strData = m_KOrCvNum.InitData(strData);
	strData = m_KOrCvData.UnitData().InitData(strData,DataUnitNum());
	strData = m_KOrCvData.DataData().InitData(strData,KOrCvNum());
	if ( isImpFile )
	{
		strData = m_FailTranData.ValueTypeData().InitData(strData);
		strData = m_TranData.ValueTypeData().InitData(strData);
		strData = m_TranData.Repeat1Data().InitData(strData);
		strData = m_TranData.Repeat2Data().InitData(strData);
		strData = m_TranData.TransTypeData().InitData(strData);
		strData = m_TranData.TranTriger1Data().InitData(strData);
		strData = m_TranData.TranTriger2Data().InitData(strData);
		strData = m_TranData.m_Trans1Table.InitData(strData);
		strData = m_FailTranData.m_Trans1Table.InitData(strData);
		strData = m_FailTranData.m_Trans2Table.InitData(strData);
		strData = m_UnKown5.InitData(strData);
		strData = m_failAction.InitData(strData);
	}
	else
	{
		strData = m_FthUnknown1.InitData( strData );
		strData = m_FthAssert1.InitData( strData );
		strData = m_FthAssert2.InitData( strData );
		if ( m_FthAssert1.GetData() == _T("-1") )
		{
			m_FthAssert1.SetData( _T("1") );
		}
		if ( m_FthAssert2.GetData() == _T("-1") )
		{
			m_FthAssert2.SetData( _T("1") );
		}
		strData.Insert( 0,m_FthAssert1.GetData() );
		strData.Insert( 1,_T(",") );
		strData.Insert( 2,m_FthAssert2.GetData() );
		strData.Insert( 3,_T(",") );
		strData = m_failAction.InitData(strData);
	}
	
}

void ControlValveData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(30);
	array.SetAt(0,&m_ControlSet.Data());
	array.SetAt(1,&m_UnKown.Data());
	array.SetAt(2,&m_ModelType.Data());
	array.SetAt(3,&m_KOrCv.Data());
	array.SetAt(4,&m_UnKown4.Data());
	array.SetAt(5,&m_DataUnitNum.Data());
	array.SetAt(6,&m_KOrCvNum.Data());
	array.SetAt(7,&m_KOrCvData.UnitData().Data());
	array.SetAt(8,&m_KOrCvData.DataData().Data());
	array.SetAt(9,&m_FailTranData.ValueTypeData().Data());
	array.SetAt(10,&m_TranData.ValueTypeData().Data());
	array.SetAt(11,&m_TranData.Repeat1Data().Data());
	array.SetAt(12,&m_TranData.Repeat2Data().Data());
	array.SetAt(13,&m_TranData.TransTypeData().Data());
	array.SetAt(14,&m_TranData.TranTriger1Data().Data());
	array.SetAt(15,&m_TranData.TranTriger2Data().Data());
	array.SetAt(16,&m_TranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(17,&m_TranData.m_Trans1Table.NumData().Data());
	array.SetAt(18,&m_TranData.m_Trans1Table.UnitData().Data());
	array.SetAt(19,&m_TranData.m_Trans1Table.DataData().Data());
	array.SetAt(20,&m_FailTranData.m_Trans1Table.UnkownData().Data());
	array.SetAt(21,&m_FailTranData.m_Trans1Table.NumData().Data());
	array.SetAt(22,&m_FailTranData.m_Trans1Table.UnitData().Data());
	array.SetAt(23,&m_FailTranData.m_Trans1Table.DataData().Data());
	array.SetAt(24,&m_FailTranData.m_Trans2Table.UnkownData().Data());
	array.SetAt(25,&m_FailTranData.m_Trans2Table.NumData().Data());
	array.SetAt(26,&m_FailTranData.m_Trans2Table.UnitData().Data());
	array.SetAt(27,&m_FailTranData.m_Trans2Table.DataData().Data());
	array.SetAt(28,&m_UnKown5.Data());
	array.SetAt(29,&m_failAction.Data());
	m_RowArray.Append(array);

}

int ControlValveData::KOrCvNum()
{
	int iKey=0;
	m_KOrCvNum.GetData(iKey);
	return abs(iKey);
}
int ControlValveData::DataUnitNum()
{
	int iKey=1;
	m_DataUnitNum.GetData(iKey);
	return abs(iKey);
}


/*------------------------------------------*/
StrArray<5> ControlValveData::ControlSet()
{
	return m_ControlSet.GetArray();
}
void ControlValveData::ControlSet(const StrArray<5>& strValue)
{
	m_ControlSet.SetArray(strValue);
}
/*------------------------------------------*/
CString ControlValveData::ModelType()
{
	return m_ModelType.GetData();
}
void ControlValveData::ModelType(CString strValue)
{
	m_ModelType.SetData(strValue);
}
/*------------------------------------------*/
CString ControlValveData::KOrCv()
{
	return m_KOrCv.GetData();
}
void ControlValveData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> ControlValveData::FailAction()
{
	return m_failAction.GetArray();
}
void ControlValveData::FailAction(const StrArray<4>& strValue)
{
	m_failAction.SetArray(strValue);
}

/*------------------------------------------*/
StrArray<3> ControlValveData::KOrCvUnit()
{
	return m_KOrCvData.Unit();
}
void ControlValveData::KOrCvUnit(const StrArray<3>& strValue)
{
	m_KOrCvData.Unit(strValue);
}

ListImp<StrArray<3> > ControlValveData::KOrCvData()
{
	return m_KOrCvData.Data();
}

void ControlValveData::KOrCvData(const ListImp<StrArray<3> >& strValue)
{
	m_KOrCvData.Data(strValue);
	m_KOrCvNum.SetData(strValue.GetCount());
	m_DataUnitNum.SetData(2);
}