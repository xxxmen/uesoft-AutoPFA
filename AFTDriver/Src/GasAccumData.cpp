// GasAccumData.cpp: implementation of the GasAccumData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasAccumData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasAccumData::GasAccumData()
{
	AppendArray();
}

GasAccumData::~GasAccumData()
{

}

JunctionData* GasAccumData::Creator()
{
	GasAccumData *pData = new GasAccumData;
	return pData;
}

CString GasAccumData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,6,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		-1,0,None,0,-1,-1,0,None,0,-1,0,None,0,None,0,,0,None,0,0,0,None,-1,-1,0,0,None");
}

void GasAccumData::InitExtra(CString strData)
{
	strData = m_Polytropic.InitData(strData);
	strData = m_InitVolume.InitData(strData);
	strData = m_Orifice.InitData(strData);
	strData = m_ShortPipe.InitData(strData);
	strData = m_InitPress.InitData(strData);
	strData = m_MaxVolume.InitData(strData);
    strData = m_MinVolume.InitData(strData);
	strData = m_GasVolume.InitData(strData);
}

void GasAccumData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(8);
	array.SetAt(0,&m_Polytropic.Data());
	array.SetAt(1,&m_InitVolume.Data());
	array.SetAt(2,&m_Orifice.Data());
	array.SetAt(3,&m_ShortPipe.Data());
	array.SetAt(4,&m_InitPress.Data());
	array.SetAt(5,&m_MaxVolume.Data());
	array.SetAt(6,&m_MinVolume.Data());
	array.SetAt(7,&m_GasVolume.Data());
	m_RowArray.Append(array);
}


/*------------------------------------------*/
CString GasAccumData::Polytropic()
{
	return m_Polytropic.GetData();
}
void GasAccumData::Polytropic(CString strValue)
{
	m_Polytropic.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> GasAccumData::InitVolume()
{
	return m_InitVolume.GetArray();
}
void GasAccumData::InitVolume(const StrArray<2>& strValue)
{
	m_InitVolume.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> GasAccumData::Orifice()
{
	return m_Orifice.GetArray();
}
void GasAccumData::Orifice(const StrArray<5>& strValue)
{
	m_Orifice.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<10> GasAccumData::ShortPipe()
{
	return m_ShortPipe.GetArray();
}
void GasAccumData::ShortPipe(const StrArray<10>& strValue)
{
	m_ShortPipe.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<4> GasAccumData::InitPress()
{
	return m_InitPress.GetArray();
}
void GasAccumData::InitPress(const StrArray<4>& strValue)
{
	m_InitPress.SetArray(strValue);
}
/*------------------------------------------*/
CString GasAccumData::MaxVolume()
{
	return m_MaxVolume.GetData();
}
void GasAccumData::MaxVolume(CString strValue)
{
	m_MaxVolume.SetData(strValue);
}
/*------------------------------------------*/
CString GasAccumData::MinVolume()
{
	return m_MinVolume.GetData();
}
void GasAccumData::MinVolume(CString strValue)
{
	m_MinVolume.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> GasAccumData::GasVolume()
{
	return m_GasVolume.GetArray();
}
void GasAccumData::GasVolume(const StrArray<3>& strValue)
{
	m_GasVolume.SetArray(strValue);
}