// PCFPumpConfig.cpp: implementation of the PCFPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPumpConfig.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPumpConfig::PCFPumpConfig()
{

}

PCFPumpConfig::~PCFPumpConfig()
{

}

CString PCFPumpConfig::InitData(CString strData)
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

int PCFPumpConfig::GetNum()
{
	int iKey=0;
	m_Num.GetData(iKey);
	return abs(iKey);
}
PCFPumpConfigData* PCFPumpConfig::CreatConfigData()
{
	PCFPumpConfigData *pData = new PCFPumpConfigData;
	m_list.AddItem(pData);
	return pData;
}

CString PCFPumpConfig::InitList(CString strData)
{
	PCFPumpConfigData *pData = NULL;
	for(int i=0;i<GetNum();i++)
	{
		pData = CreatConfigData();
		strData = pData->InitData(strData);
		pData->InitObject();
		m_Num.Data().AddChild(pData->GetObject());
	}
	return strData;
}

Iterator<PCFPumpConfigData>* PCFPumpConfig::CreatIterator()const
{
	return m_list.CreatIterator();
}

/*------------------------------------------*/
inline CString PCFPumpConfig::PressType()
{
	return m_PressType.GetData();
}
inline void PCFPumpConfig::PressType(CString strValue)
{
	m_PressType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::PressUnit()
{
	return m_PressUnit.GetData();
}
inline void PCFPumpConfig::PressUnit(CString strValue)
{
	m_PressUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::FlowType()
{
	return m_FlowType.GetData();
}
inline void PCFPumpConfig::FlowType(CString strValue)
{
	m_FlowType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::FlowUnit()
{
	return m_FlowUnit.GetData();
}
inline void PCFPumpConfig::FlowUnit(CString strValue)
{
	m_FlowUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::PowerType()
{
	return m_PowerType.GetData();
}
inline void PCFPumpConfig::PowerType(CString strValue)
{
	m_PowerType.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::PowerUnit()
{
	return m_PowerUnit.GetData();
}
inline void PCFPumpConfig::PowerUnit(CString strValue)
{
	m_PowerUnit.SetData(strValue);
}
/*------------------------------------------*/
inline CString PCFPumpConfig::Type()
{
	return m_Type.GetData();
}
inline void PCFPumpConfig::Type(CString strValue)
{
	m_Type.SetData(strValue);
}

inline void PCFPumpConfig::Num(int nValue)
{
	m_Num.SetData(nValue);
}

