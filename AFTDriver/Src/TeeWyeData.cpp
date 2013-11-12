// TeeWyeData.cpp: implementation of the TeeWyeData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TeeWyeData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TeeWyeData::TeeWyeData()
{
	AppendArray();
}

TeeWyeData::~TeeWyeData()
{

}

JunctionData* TeeWyeData::Creator()
{
	TeeWyeData *pData = new TeeWyeData;
	return pData;
}

CString TeeWyeData::GetDefaultData()
{
	return _T(",,9,1,,0,2805,1380,-1,0,3,-1,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,90,-1,2");
}

void TeeWyeData::InitExtra(CString strData)
{
	strData = m_Type.InitData(strData);
	strData = m_Angle.InitData(strData);
	strData = m_arrangement.InitData(strData);
	strData = m_LossModel.InitData(strData);
}

void TeeWyeData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(4);
	array.SetAt(0,&m_Type.Data());
	array.SetAt(1,&m_Angle.Data());
	array.SetAt(2,&m_arrangement.Data());
	array.SetAt(3,&m_LossModel.Data());
	m_RowArray.Append(array);
}
/*------------------------------------------*/
CString TeeWyeData::Type()
{
	return m_Type.GetData();
}

void TeeWyeData::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
CString TeeWyeData::Angle()
{
	return m_Angle.GetData();
}

void TeeWyeData::Angle(CString strValue)
{
	m_Angle.SetData(strValue);
}
/*------------------------------------------*/
CString TeeWyeData::Arrangement()
{
	return m_arrangement.GetData();
}

void TeeWyeData::Arrangement(CString strValue)
{
	m_arrangement.SetData(strValue);
}
/*------------------------------------------*/
CString TeeWyeData::Model()
{
	return m_LossModel.GetData();
}

void TeeWyeData::Model(CString strValue)
{
	m_LossModel.SetData(strValue);
}
