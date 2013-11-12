// JunTransData.cpp: implementation of the JunTransData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunTransData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunTransData::JunTransData()
{

}

JunTransData::~JunTransData()
{

}

/*------------------------------------------*/
CString JunTransData::ValueType()
{
	return m_ValueType.GetData();
}
void JunTransData::ValueType(CString strValue)
{
	m_ValueType.SetData(strValue);
}
/*------------------------------------------*/
CString JunTransData::Special()
{
	return m_Special.GetData();
}
void JunTransData::Special(CString strValue)
{
	m_Special.SetData(strValue);
}
/*------------------------------------------*/
CString JunTransData::Repeat1()
{
	return m_Repeat1.GetData();
}
void JunTransData::Repeat1(CString strValue)
{
	m_Repeat1.SetData(strValue);
}
/*------------------------------------------*/
CString JunTransData::Repeat2()
{
	return m_Repeat2.GetData();
}
void JunTransData::Repeat2(CString strValue)
{
	m_Repeat2.SetData(strValue);
}
/*------------------------------------------*/
CString JunTransData::TranType()
{
	return m_TranType.GetData();
}
void JunTransData::TranType(CString strValue)
{
	m_TranType.SetData(strValue);
}
/*------------------------------------------*/
StrArray<5> JunTransData::Periodic()
{
	return m_Periodic.GetArray();
}
void JunTransData::Periodic(const StrArray<5>& strValue)
{
	m_Periodic.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<8> JunTransData::TranTriger1()
{
	return m_TranTriger1.GetArray();
}
void JunTransData::TranTriger1(const StrArray<8>& strValue)
{
	m_TranTriger1.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<8> JunTransData::TranTriger2()
{
	return m_TranTriger2.GetArray();
}
void JunTransData::TranTriger2(const StrArray<8>& strValue)
{
	m_TranTriger2.SetArray(strValue);
}
/*------------------------------------------*/
CString JunTransData::TranModel()
{
	return m_TranModel.GetData();
}
void JunTransData::TranModel(CString strValue)
{
	m_TranModel.SetData(strValue);
}
/*------------------------------------------*/
CString JunTransData::Speed()
{
	return m_Speed.GetData();
}
void JunTransData::Speed(CString strValue)
{
	m_Speed.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> JunTransData::RotateInertia()
{
	return m_RotateInertia.GetArray();
}
void JunTransData::RotateInertia(const StrArray<2>& strValue)
{
	m_RotateInertia.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> JunTransData::FourQuadrant()
{
	return m_FourQuadrantData.GetArray();
}
void JunTransData::FourQuadrant(const StrArray<3>& strValue)
{
	m_FourQuadrantData.SetArray(strValue);
}
