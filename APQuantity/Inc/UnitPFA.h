// UnitPFA.h: interface for the UnitPFA class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNITPFA_H__372FFF0D_1E51_45A5_A46B_D32CBA1884B2__INCLUDED_)
#define AFX_UNITPFA_H__372FFF0D_1E51_45A5_A46B_D32CBA1884B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PFAQheader.h"
using namespace std;

class UnitPFA  
{
public:
	UnitPFA();
	UnitPFA( const UeStdString& strName,double dRate,double dDelta = 0 );
	virtual ~UnitPFA();

public:
	double GetRate() const
	{
		return m_dRate;
	}
	const UeStdString& GetUnitString() const
	{
		return m_UnitString;
	}
	double GetDelta() const
	{
		return m_dDelta;
	}

	BOOL SetUnitString(UeStdString& strDefault);

private:
	UeStdString m_UnitString;//单位字符串
	double m_dRate;//与该物理量系统默认单位之间的转换率
	double m_dDelta;//由于有些单位之间并不是一个线性比例关系，所以加了这个参数

};

#endif // !defined(AFX_UNITPFA_H__372FFF0D_1E51_45A5_A46B_D32CBA1884B2__INCLUDED_)
