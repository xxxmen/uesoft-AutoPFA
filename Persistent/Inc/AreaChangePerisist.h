// AreaChangePerisist.h: interface for the AreaChangePerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREACHANGEPERISIST_H__8BB43A3D_424D_442C_9543_2E42743561AA__INCLUDED_)
#define AFX_AREACHANGEPERISIST_H__8BB43A3D_424D_442C_9543_2E42743561AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS AreaChangePerisist : public Junperisist  
{
public:
	static Junperisist* CreatAreaChange();
	AreaChangePerisist();
	virtual ~AreaChangePerisist();

public:
	CString Type();
	void Type(CString strValue);
	CString Dir();
	void Dir(CString strValue);
	CString Angle();
	void Angle(CString strValue);
	CString K();
	void K(CString strValue);
	StrArray<3>& BasisArea();
	void BasisArea(const StrArray<3>& strValue);

private:
	CString m_Type;			    //异径管类型（0：圆锥，1：圆柱，2：用户定义）
	CString m_Dir;				//（1：收缩，2：扩张）
	CString m_Angle;			//角度
	CString m_K;				//K系数值
	StrArray<3> m_BasisArea;	//损失模型的面积引用



};

/*------------------------------------------*/
inline CString AreaChangePerisist::Type()
{
	return m_Type;
}
inline void AreaChangePerisist::Type(CString strValue)
{
	m_Type = strValue;
}
/*------------------------------------------*/
inline CString AreaChangePerisist::Dir()
{
	return m_Dir;
}
inline void AreaChangePerisist::Dir(CString strValue)
{
	m_Dir = strValue;
}
/*------------------------------------------*/
inline CString AreaChangePerisist::Angle()
{
	return m_Angle;
}
inline void AreaChangePerisist::Angle(CString strValue)
{
	m_Angle = strValue;
}
/*------------------------------------------*/
inline CString AreaChangePerisist::K()
{
	return m_K;
}
inline void AreaChangePerisist::K(CString strValue)
{
	m_K = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& AreaChangePerisist::BasisArea()
{
	return m_BasisArea;
}
inline void AreaChangePerisist::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea = strValue;
}
#endif // !defined(AFX_AREACHANGEPERISIST_H__8BB43A3D_424D_442C_9543_2E42743561AA__INCLUDED_)
