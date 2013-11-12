// CalcAssignPress.h: interface for the CalcAssignPress class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCASSIGNPRESS_H__670FF0C4_176C_4EBD_A05A_22E8314EF1BA__INCLUDED_)
#define AFX_CALCASSIGNPRESS_H__670FF0C4_176C_4EBD_A05A_22E8314EF1BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcAssignPress : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcAssignPress();
	virtual ~CalcAssignPress();

public:
	void PressType(int nValue);
	void Press(double dValue);
	void PipeInfo(const ListImp<StrArray<4> >& ref);

	int PressType();
	double Press();
	ListImp<StrArray<4> >& PipeInfo();
private:
	CalcTable<4>     m_PipeInfo;
	int              m_nPressType;			//压力类型0：停滞压力1：静止压力
	double			 m_dPress;				//压力

public:
	CalcTransData m_TranData;
};

#endif // !defined(AFX_CALCASSIGNPRESS_H__670FF0C4_176C_4EBD_A05A_22E8314EF1BA__INCLUDED_)
