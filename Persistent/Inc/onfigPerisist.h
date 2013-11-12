// onfigPerisist.h: interface for the ConfigPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONFIGPERISIST_H__80DEAC0E_6395_4F44_9288_0F2B3759233F__INCLUDED_)
#define AFX_ONFIGPERISIST_H__80DEAC0E_6395_4F44_9288_0F2B3759233F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "onfigItemPerisist.h"
#include "Iterator.h"
class AFX_EXT_CLASS ConfigPerisist  
{
public:
	int GetCount();
	Iterator<ConfigItemPerisist>* CreatIterator()const;
	ConfigPerisist();
	virtual ~ConfigPerisist();

public:
	ConfigItemPerisist* GetHead();
	ConfigItemPerisist* CreatConfigItem();
	CString PressType();
	void PressType(CString strValue);
	CString PressUnit();
	void PressUnit(CString strValue);
	CString FlowType();
	void FlowType(CString strValue);
	CString FlowUnit();
	void FlowUnit(CString strValue);
	CString PowerType();
	void PowerType(CString strValue);
	CString PowerUnit();
	void PowerUnit(CString strValue);
	CString Type();
	void Type(CString strValue);

private:
	CString m_strPressType;			    //泵结构压力的类型0：水头1：压力
	CString m_strPressUnit;			    //泵结构压力单位
	CString m_strFlowType;				//泵结构流量参数0：体积流量1：质量流量
	CString m_strFlowUnit;				//泵结构流量单位
	CString m_strPowerType;			    //效率或功率参数0：效率1：功率
	CString m_strPowerUnit;			    //效率或功率参数单位
	CString m_strType;					//泵构造方法0：简单 n：Multiple Configuations泵结构定义选择n作为当前
	ListImp<ConfigItemPerisist> m_list;
};
/*------------------------------------------*/
inline CString ConfigPerisist::PressType()
{
	return m_strPressType;
}
inline void ConfigPerisist::PressType(CString strValue)
{
	m_strPressType = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::PressUnit()
{
	return m_strPressUnit;
}
inline void ConfigPerisist::PressUnit(CString strValue)
{
	m_strPressUnit = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::FlowType()
{
	return m_strFlowType;
}
inline void ConfigPerisist::FlowType(CString strValue)
{
	m_strFlowType = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::FlowUnit()
{
	return m_strFlowUnit;
}
inline void ConfigPerisist::FlowUnit(CString strValue)
{
	m_strFlowUnit = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::PowerType()
{
	return m_strPowerType;
}
inline void ConfigPerisist::PowerType(CString strValue)
{
	m_strPowerType = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::PowerUnit()
{
	return m_strPowerUnit;
}
inline void ConfigPerisist::PowerUnit(CString strValue)
{
	m_strPowerUnit = strValue;
}
/*------------------------------------------*/
inline CString ConfigPerisist::Type()
{
	return m_strType;
}
inline void ConfigPerisist::Type(CString strValue)
{
	m_strType = strValue;
}
#endif // !defined(AFX_ONFIGPERISIST_H__80DEAC0E_6395_4F44_9288_0F2B3759233F__INCLUDED_)
