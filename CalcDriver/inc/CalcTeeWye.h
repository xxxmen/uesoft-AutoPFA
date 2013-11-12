// CalcTeeWye.h: interface for the CalcTeeWye class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTEEWYE_H__07FE31B0_6905_4568_BF95_4C6E94DF3A06__INCLUDED_)
#define AFX_CALCTEEWYE_H__07FE31B0_6905_4568_BF95_4C6E94DF3A06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcTeeWye : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcTeeWye();
	virtual ~CalcTeeWye();
public:
	void Angle(double dValue);
	void Model(int nValue);
	void Type(int nValue);

	double Angle();
	int Model();
	int Type();
private:
	double m_dAngle;			//角度
	int    m_nModel;			//损失模型类型（1：简单模型2：详细模型）
	int    m_nType;			    //类型（0，锐边直三通1，圆边直三通2，面积改变3，对称）

};

#endif // !defined(AFX_CALCTEEWYE_H__07FE31B0_6905_4568_BF95_4C6E94DF3A06__INCLUDED_)
