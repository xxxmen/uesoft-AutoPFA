// AreaChangeData.cpp: implementation of the AreaChangeData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AreaChangeData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AreaChangeData::AreaChangeData()
{
	AppendArray();
}

AreaChangeData::~AreaChangeData()
{

}

JunctionData* AreaChangeData::Creator()
{
	AreaChangeData *pData = new AreaChangeData;
	return pData;
}

CString AreaChangeData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,1,-1,0,0,0,None");
}

void AreaChangeData::InitExtra(CString strData)
{
	strData = m_TypeID.InitData(strData);
	strData = m_Dir.InitData(strData);
	strData = m_Angle.InitData(strData);
	strData = m_K.InitData(strData);
	strData = m_BasisArea.InitData(strData);
}

void AreaChangeData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(5);
	array.SetAt(0,&m_TypeID.Data());
	array.SetAt(1,&m_Dir.Data());
	array.SetAt(2,&m_Angle.Data());
	array.SetAt(3,&m_K.Data());
	array.SetAt(4,&m_BasisArea.Data());
	m_RowArray.Append(array);
}
/*------------------------------------------*/
CString AreaChangeData::Type()
{
	return m_TypeID.GetData();
}

void AreaChangeData::Type(CString strValue)
{
	m_TypeID.SetData(strValue);
}
/*------------------------------------------*/
CString AreaChangeData::Dir()
{
	return m_Dir.GetData();
}

void AreaChangeData::Dir(CString strValue)
{
	m_Dir.SetData(strValue);
}
/*------------------------------------------*/
CString AreaChangeData::Angle()
{
	return m_Angle.GetData();
}

void AreaChangeData::Angle(CString strValue)
{
	m_Angle.SetData(strValue);
}
/*------------------------------------------*/
CString AreaChangeData::K()
{
	return m_K.GetData();
}

void AreaChangeData::K(CString strValue)
{
	m_K.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> AreaChangeData::BasisArea()
{
	return m_BasisArea.GetArray();
}

void AreaChangeData::BasisArea(StrArray<3>& array)
{
	m_BasisArea.SetArray(array);
}


