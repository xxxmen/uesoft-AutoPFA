// ReservoirPerisist.h: interface for the ReservoirPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESERVOIRPERISIST_H__D0A6D0C2_4063_42AF_9312_4FFDBE452FF9__INCLUDED_)
#define AFX_RESERVOIRPERISIST_H__D0A6D0C2_4063_42AF_9312_4FFDBE452FF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS ReservoirPerisist : public Junperisist  
{
public:
	static Junperisist* CreatReservoir();
	ReservoirPerisist();
	virtual ~ReservoirPerisist();
public:
	ListImp<StrArray<6> >& PipeInfoToStd();
	ListImp<StrArray<6> >& PipeInfo();
	void PipeInfo(const ListImp<StrArray<6> >& strValue,int nCount);
	void PipeInfo(const ListImp<StrArray<6> >& strValue);
	StrArray<2>& EleOrDepth();
	void EleOrDepth(const StrArray<2>& strValue);
	StrArray<2>& SurfacePress();
	void SurfacePress(const StrArray<2>& strValue);
	StrArray<2>& Teamperature();
	void Teamperature(const StrArray<2>& strValue);
	StrArray<2>& Density();
	void Density(const StrArray<2>& strValue);
	CString EleOrDepthType();
	void EleOrDepthType(CString strValue);
private:
	TablePerisist<6>m_PipeInfo;
	StrArray<2>		m_EleOrDepthUnit;            //0未知\管道标高或深度单位
	StrArray<2>		m_SurfacePress;				 //表面压力值\单位
	StrArray<2>		m_Teamperature;			     //流体温度\单位
	StrArray<2>		m_Density;					 //流体密度\单位
	CString			m_EleOrDepthType;			 //管道与水库连接点标高或深度

public:
	TransDataPersistent m_TransPersistent;
};
/*------------------------------------------*/
inline ListImp<StrArray<6> >& ReservoirPerisist::PipeInfo()
{
	return m_PipeInfo.GetData();
}
inline void ReservoirPerisist::PipeInfo(const ListImp<StrArray<6> >& strValue,int nCount)
{
	m_PipeInfo.SetData(strValue,nCount);
}
inline void ReservoirPerisist::PipeInfo(const ListImp<StrArray<6> >& strValue)
{
	m_PipeInfo.SetData(strValue);
}
/*------------------------------------------*/
inline StrArray<2>& ReservoirPerisist::EleOrDepth()
{
	return m_EleOrDepthUnit;
}
inline void ReservoirPerisist::EleOrDepth(const StrArray<2>& strValue)
{
	m_EleOrDepthUnit = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& ReservoirPerisist::SurfacePress()
{
	return m_SurfacePress;
}
inline void ReservoirPerisist::SurfacePress(const StrArray<2>& strValue)
{
	m_SurfacePress = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& ReservoirPerisist::Teamperature()
{
	return m_Teamperature;
}
inline void ReservoirPerisist::Teamperature(const StrArray<2>& strValue)
{
	m_Teamperature = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& ReservoirPerisist::Density()
{
	return m_Density;
}
inline void ReservoirPerisist::Density(const StrArray<2>& strValue)
{
	m_Density = strValue;
}
/*------------------------------------------*/
inline CString ReservoirPerisist::EleOrDepthType()
{
	return m_EleOrDepthType;
}
inline void ReservoirPerisist::EleOrDepthType(CString strValue)
{
	m_EleOrDepthType = strValue;
}
#endif // !defined(AFX_RESERVOIRPERISIST_H__D0A6D0C2_4063_42AF_9312_4FFDBE452FF9__INCLUDED_)
