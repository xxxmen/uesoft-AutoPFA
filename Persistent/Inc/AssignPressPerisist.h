// AssignPressPerisist.h: interface for the AssignPressPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASSIGNPRESSPERISIST_H__A4126D05_0D0A_410E_96FF_B7D8395F45E4__INCLUDED_)
#define AFX_ASSIGNPRESSPERISIST_H__A4126D05_0D0A_410E_96FF_B7D8395F45E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS AssignPressPerisist : public Junperisist  
{
public:
	static Junperisist* CreatAssignedPressure();
	AssignPressPerisist();
	virtual ~AssignPressPerisist();
public:
	ListImp<StrArray<4> >& PipeInfo();
	ListImp<StrArray<4> >& PipeInfoToStd();
	void PipeInfo(const ListImp<StrArray<4> >& strValue,int nCount);
	void PipeInfo(const ListImp<StrArray<4> >& strValue);
	CString DistanceUnit();
	void DistanceUnit(CString strValue);
	StrArray<3>& Pressure();
	void Pressure(const StrArray<3>& strValue);
private:
	TablePerisist<4> m_PipeInfo;
	CString			 m_DistanceUnit;			//管道端口与节点标高距离单位
	StrArray<3>		 m_Pressure;				//压力类型0：停滞压力1：静止压力\值\单位

public:
	TransDataPersistent m_TransPersistent;

};
/*------------------------------------------*/
inline ListImp<StrArray<4> >& AssignPressPerisist::PipeInfo()
{
	return m_PipeInfo.GetData();
}
inline void AssignPressPerisist::PipeInfo(const ListImp<StrArray<4> >& strValue,int nCount)
{
	m_PipeInfo.SetData(strValue,nCount);
}
inline void AssignPressPerisist::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	m_PipeInfo.SetData(strValue);
}
/*------------------------------------------*/
inline CString AssignPressPerisist::DistanceUnit()
{
	return m_DistanceUnit;
}
inline void AssignPressPerisist::DistanceUnit(CString strValue)
{
	m_DistanceUnit = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& AssignPressPerisist::Pressure()
{
	return m_Pressure;
}
inline void AssignPressPerisist::Pressure(const StrArray<3>& strValue)
{
	m_Pressure = strValue;
}
#endif // !defined(AFX_ASSIGNPRESSPERISIST_H__A4126D05_0D0A_410E_96FF_B7D8395F45E4__INCLUDED_)
