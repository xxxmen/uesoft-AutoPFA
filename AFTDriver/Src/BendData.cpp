// BendData.cpp: implementation of the BendData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BendData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BendData::BendData()
{
	AppendArray();
}

BendData::~BendData()
{

}

JunctionData* BendData::Creator()
{
	BendData *pData = new BendData;
	return pData;
}

void BendData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(6);
	array.SetAt(0,&m_bendType.Data());
	array.SetAt(1,&m_angel.Data());
	array.SetAt(2,&m_rD.Data());
	array.SetAt(3,&m_K.Data());
	array.SetAt(4,&m_RestriFlowArea.Data());
	array.SetAt(5,&m_BasisArea.Data());
	m_RowArray.Append(array);
}

void BendData::InitExtra(CString strData)
{
	strData = m_bendType.InitData(strData);
	strData = m_angel.InitData(strData);
	strData = m_rD.InitData(strData);
	strData = m_K.InitData(strData);
	strData = m_RestriFlowArea.InitData(strData);
	strData = m_BasisArea.InitData(strData);
}

CString BendData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,90,-1,-1,0,None,0,0,None");
}

/*------------------------------------------*/
CString BendData::Type()
{
	return m_bendType.GetData();
}
void BendData::Type(CString strValue)
{
	m_bendType.SetData(strValue);
}
/*------------------------------------------*/
CString BendData::Angel()
{
	return m_angel.GetData();
}
void BendData::Angel(CString strValue)
{
	m_angel.SetData(strValue);
}
/*------------------------------------------*/
CString BendData::RD()
{
	return m_rD.GetData();
}
void BendData::RD(CString strValue)
{
	m_rD.SetData(strValue);
}
/*------------------------------------------*/
CString BendData::K()
{
	return m_K.GetData();
}
void BendData::K(CString strValue)
{
	m_K.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> BendData::RestriFlowArea()
{
	return m_RestriFlowArea.GetArray();
}
void BendData::RestriFlowArea(const StrArray<2>& strValue)
{
	m_RestriFlowArea.SetArray(strValue);;
}
/*------------------------------------------*/
StrArray<3> BendData::BasisArea()
{
	return m_BasisArea.GetArray();
}
void BendData::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea.SetArray(strValue);
}