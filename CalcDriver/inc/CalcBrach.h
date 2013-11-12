// CalcBrach.h: interface for the CalcBrach class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBRACH_H__6C749375_60B8_48A0_9725_1E420D4799DF__INCLUDED_)
#define AFX_CALCBRACH_H__6C749375_60B8_48A0_9725_1E420D4799DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcBrach : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcBrach();
	virtual ~CalcBrach();

public:
	void ImposeFlowType(int nValue);
	void ImposeFlow(double dValue);
	void PipeInfo(const ListImp<StrArray<4> >& ref);

	int ImposeFlowType();
	double ImposeFlow();
	ListImp<StrArray<4> >& PipeInfo();

private:
	CalcTable<4>     m_PipeInfo;
	int		         m_nImposeFlowType;				//流量类型（0：体积流量，1：质量流量）
	double		     m_dImposeFlow;				    //流量值

public:
	CalcTransData m_TranData;
};

#endif // !defined(AFX_CALCBRACH_H__6C749375_60B8_48A0_9725_1E420D4799DF__INCLUDED_)
