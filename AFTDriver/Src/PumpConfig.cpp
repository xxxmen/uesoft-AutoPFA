// PumpConfig.cpp: implementation of the PumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PumpConfig.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpConfig::PumpConfig()
{

}

PumpConfig::~PumpConfig()
{

}

CString PumpConfig::InitData(CString strData)
{
	strData = m_PressType.InitData(strData);
	strData = m_PressUnit.InitData(strData);
	strData = m_FlowType.InitData(strData);
	strData = m_FlowUnit.InitData(strData);
	strData = m_PowerType.InitData(strData);
	strData = m_PowerUnit.InitData(strData);
	strData = m_Type.InitData(strData);
	strData = m_Num.InitData(strData);
	strData = InitList(strData);
	return strData;
}

int PumpConfig::GetNum()
{
	int iKey=0;
	m_Num.GetData(iKey);
	return abs(iKey);
}
PumpConfigData* PumpConfig::CreatConfigData()
{
	PumpConfigData *pData = new PumpConfigData;
	m_list.AddItem(pData);
	return pData;
}

CString PumpConfig::InitList(CString strData)
{
	PumpConfigData *pData = NULL;
	for(int i=0;i<GetNum();i++)
	{
		pData = CreatConfigData();
		strData = pData->InitData(strData);
		pData->InitObject();
		m_Num.Data().AddChild(pData->GetObject());
	}
	return strData;
}

Iterator<PumpConfigData>* PumpConfig::CreatIterator()const
{
	return m_list.CreatIterator();
}

/*------------------------------------------*/
inline CString PumpConfig::PressType()
{
	return m_PressType.GetData();
}
inline void PumpConfig::PressType(CString strValue)
{
	m_PressType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::PressUnit()
{
	return m_PressUnit.GetData();
}
inline void PumpConfig::PressUnit(CString strValue)
{
	m_PressUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::FlowType()
{
	return m_FlowType.GetData();
}
inline void PumpConfig::FlowType(CString strValue)
{
	m_FlowType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::FlowUnit()
{
	return m_FlowUnit.GetData();
}
inline void PumpConfig::FlowUnit(CString strValue)
{
	m_FlowUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::PowerType()
{
	return m_PowerType.GetData();
}
inline void PumpConfig::PowerType(CString strValue)
{
	m_PowerType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::PowerUnit()
{
	return m_PowerUnit.GetData();
}
inline void PumpConfig::PowerUnit(CString strValue)
{
	m_PowerUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PumpConfig::Type()
{
	return m_Type.GetData();
}
inline void PumpConfig::Type(CString strValue)
{
	m_Type.SetData(strValue);
}

inline void PumpConfig::Num(int nValue)
{
	m_Num.SetData(nValue);
}

