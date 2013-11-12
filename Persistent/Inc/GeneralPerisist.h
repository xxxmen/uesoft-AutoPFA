// GeneralPerisist.h: interface for the GeneralPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERALPERISIST_H__C0C79D01_1DC1_4F2B_B4F7_58821F7E0343__INCLUDED_)
#define AFX_GENERALPERISIST_H__C0C79D01_1DC1_4F2B_B4F7_58821F7E0343__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"

class AFX_EXT_CLASS GeneralPerisist : public Junperisist  
{
public:
	static Junperisist* CreatGeneral();
	GeneralPerisist();
	virtual ~GeneralPerisist();

public:
	CString Type();
	void Type(CString strValue);
	StrArray<13>& Curve();
	void Curve(const StrArray<13>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3>& BasisArea();
	void BasisArea(const StrArray<3>& strValue);
private:
	CString		m_Type;							//类型(0)
	StrArray<13>m_Curve;						//损失模型曲线。
	CString		m_KOrCv;						//K或Cv系数值
	StrArray<3> m_BasisArea;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
												//值/单位

};
/*------------------------------------------*/
inline CString GeneralPerisist::Type()
{
	return m_Type;
}
inline void GeneralPerisist::Type(CString strValue)
{
	m_Type = strValue;
}
/*------------------------------------------*/
inline StrArray<13>& GeneralPerisist::Curve()
{
	return m_Curve;
}
inline void GeneralPerisist::Curve(const StrArray<13>& strValue)
{
	m_Curve = strValue;
}

/*------------------------------------------*/
inline CString GeneralPerisist::KOrCv()
{
	return m_KOrCv;
}
inline void GeneralPerisist::KOrCv(CString strValue)
{
	m_KOrCv = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& GeneralPerisist::BasisArea()
{
	return m_BasisArea;
}
inline void GeneralPerisist::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea = strValue;
}
#endif // !defined(AFX_GENERALPERISIST_H__C0C79D01_1DC1_4F2B_B4F7_58821F7E0343__INCLUDED_)
