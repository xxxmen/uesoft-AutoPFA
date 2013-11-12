// PumpConfigData.cpp: implementation of the PumpConfigData class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PumpConfigData.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpConfigData::PumpConfigData()
{
	m_Object.SetData(_T(""));
	m_Object.SetSeparator(' ');
	m_UnKown.SetData(-9999);
}

PumpConfigData::~PumpConfigData()
{

}

CString PumpConfigData::InitData(CString strData)
{
	strData = m_Name.InitData(strData);
	strData = m_RPM.InitData(strData);
	strData = m_ImpellerDia.InitData(strData);
	strData = m_MaxFlow.InitData(strData);
	strData = m_Curve1.InitData(strData);
	strData = m_ID.InitData(strData);
	strData = m_Curve2.InitData(strData);
	strData = m_Affiniity.InitData(strData);
	strData = m_UnKown.InitData(strData);
	strData = m_Curve3.InitData(strData);
	strData = m_CurveEndFlow.InitData(strData);
	strData = m_BEP.InitData(strData);
	return strData;
}
void PumpConfigData::InitObject()
{
	m_Object.AddChild(m_Name.Data());
	m_Object.AddChild(m_RPM.Data());
	m_Object.AddChild(m_ImpellerDia.Data());
	m_Object.AddChild(m_MaxFlow.Data());
	m_Object.AddChild(m_Curve1.Data());
	m_Object.AddChild(m_ID.Data());
	m_Object.AddChild(m_Curve2.Data());
	m_Object.AddChild(m_Affiniity.Data());
	m_Object.AddChild(m_UnKown.Data());
	m_Object.AddChild(m_Curve3.Data());
	m_Object.AddChild(m_CurveEndFlow.Data());
	m_Object.AddChild(m_BEP.Data());
}


/*------------------------------------------*/
CString PumpConfigData::Name()
{
	return m_Name.GetData();
}
void PumpConfigData::Name(CString strValue)
{
	m_Name.SetData(strValue);
}
/*------------------------------------------*/
CString PumpConfigData::RPM()
{
	return m_RPM.GetData();
}
void PumpConfigData::RPM(CString strValue)
{
	m_RPM.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> PumpConfigData::ImpellerDia()
{
	return m_ImpellerDia.GetArray();
}
void PumpConfigData::ImpellerDia(const StrArray<2>& strValue)
{
	m_ImpellerDia.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpConfigData::MaxFlow()
{
	return m_MaxFlow.GetData();
}
void PumpConfigData::MaxFlow(CString strValue)
{
	m_MaxFlow.SetData(strValue);
}
/*------------------------------------------*/
StrArray<7> PumpConfigData::Curve1()
{
	return m_Curve1.GetArray();
}
void PumpConfigData::Curve1(const StrArray<7>& strValue)
{
	m_Curve1.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpConfigData::ID()
{
	return m_ID.GetData();
}
void PumpConfigData::ID(CString strValue)
{
	m_ID.SetData(strValue);
}
/*------------------------------------------*/
StrArray<7> PumpConfigData::Curve2()
{
	return m_Curve2.GetArray();
}
void PumpConfigData::Curve2(const StrArray<7>& strValue)
{
	m_Curve2.SetArray(strValue);
}
/*------------------------------------------*/
CString PumpConfigData::Affiniity()
{
	return m_Affiniity.GetData();
}
void PumpConfigData::Affiniity(CString strValue)
{
	m_Affiniity.SetData(strValue);
}
/*------------------------------------------*/
StrArray<7> PumpConfigData::Curve3()
{
	return m_Curve3.GetArray();
}
void PumpConfigData::Curve3(const StrArray<7>& strValue)
{
	m_Curve3.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> PumpConfigData::CurveEndFlow()
{
	return m_CurveEndFlow.GetArray();
}
void PumpConfigData::CurveEndFlow(const StrArray<3>& strValue)
{
	m_CurveEndFlow.SetArray(strValue);
}

/*------------------------------------------*/
StrArray<2> PumpConfigData::BEP()
{
	return m_BEP.GetArray();
}
void PumpConfigData::BEP(const StrArray<2>& strValue)
{
	m_BEP.SetArray(strValue);
}










