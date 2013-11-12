// BreckerData.cpp: implementation of the BreckerData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BreckerData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BreckerData::BreckerData()
{
	AppendArray();
}

BreckerData::~BreckerData()
{

}

JunctionData* BreckerData::Creator()
{
	BreckerData *pData = new BreckerData;
	return pData;
}

CString BreckerData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		1,1,atm,-1,None,-1,None,0,0,None,0,28.97,1.4,70,deg. F,1,atm,0,lbm,0,0,-1,None,0,0,None");
}

void BreckerData::InitExtra(CString strData)
{
	strData = m_CrackPress.InitData(strData);
	strData = m_OrificeInCdA.InitData(strData);
	strData = m_OrificeOutCdA.InitData(strData);
	strData = m_LiquidTemp.InitData(strData);
	strData = m_GasProperty.InitData(strData);
	strData = m_ConnectPipe.InitData(strData);
	strData = m_ValveType.InitData(strData);
	strData = m_InterMediateCdA.InitData(strData);
	strData = m_MediateActivation.InitData(strData);
}

void BreckerData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(9);
	array.SetAt(0,&m_CrackPress.Data());
	array.SetAt(1,&m_OrificeInCdA.Data());
	array.SetAt(2,&m_OrificeOutCdA.Data());
	array.SetAt(3,&m_LiquidTemp.Data());
	array.SetAt(4,&m_GasProperty.Data());
	array.SetAt(5,&m_ConnectPipe.Data());
	array.SetAt(6,&m_ValveType.Data());
	array.SetAt(7,&m_InterMediateCdA.Data());
	array.SetAt(8,&m_MediateActivation.Data());
	m_RowArray.Append(array);
}



/*------------------------------------------*/
StrArray<3> BreckerData::CrackPress()
{
	return m_CrackPress.GetArray();
}
void BreckerData::CrackPress(const StrArray<3>& strValue)
{
	m_CrackPress.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> BreckerData::OrificeInCdA()
{
	return m_OrificeInCdA.GetArray();
}
void BreckerData::OrificeInCdA(const StrArray<2>& strValue)
{
	m_OrificeInCdA.SetArray(strValue);;
}
/*------------------------------------------*/
StrArray<2> BreckerData::OrificeOutCdA()
{
	return m_OrificeOutCdA.GetArray();
}
void BreckerData::OrificeOutCdA(const StrArray<2>& strValue)
{
	m_OrificeOutCdA.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> BreckerData::LiquidTemp()
{
	return m_LiquidTemp.GetArray();
}
void BreckerData::LiquidTemp(const StrArray<3>& strValue)
{
	m_LiquidTemp.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<9> BreckerData::GasProperty()
{
	return m_GasProperty.GetArray();
}
void BreckerData::GasProperty(const StrArray<9>& strValue)
{
	m_GasProperty.SetArray(strValue);
}
/*------------------------------------------*/
CString BreckerData::ConnectPipe()
{
	return m_ConnectPipe.GetData();
}
void BreckerData::ConnectPipe(CString strValue)
{
	m_ConnectPipe.SetData(strValue);
}
/*------------------------------------------*/
CString BreckerData::ValveType()
{
	return m_ValveType.GetData();
}
void BreckerData::ValveType(CString strValue)
{
	m_ValveType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> BreckerData::InterMediateCdA()
{
	return m_InterMediateCdA.GetArray();
}
void BreckerData::InterMediateCdA(const StrArray<2>& strValue)
{
	m_InterMediateCdA.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> BreckerData::MediateActivation()
{
	return m_MediateActivation.GetArray();
}
void BreckerData::MediateActivation(const StrArray<3>& strValue)
{
	m_MediateActivation.SetArray(strValue);
}