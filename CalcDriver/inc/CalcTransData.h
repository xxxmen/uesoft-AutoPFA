// CalcTransData.h: interface for the CalcTransData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTRANSDATA_H__03896490_6ACD_4B78_8519_C51C18213DF1__INCLUDED_)
#define AFX_CALCTRANSDATA_H__03896490_6ACD_4B78_8519_C51C18213DF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcPeriodic.h"
#include "CalcTable.h"
#include "CalcTriger.h"

class AFX_EXT_CLASS CalcTransData  
{
public:
	CalcTransData();
	virtual ~CalcTransData();
public:
	int ValueType();
	BOOL Special();
	BOOL Repeat1();
	BOOL Repeat2();
	int TranType();
	void ValueType(int nValue);
	void Special(int nValue);
	void Repeat1(int nValue);
	void Repeat2(int nValue);
	void TranType(int nValue);
	friend ostream& operator<< (ostream &CalcOut,CalcTransData &ref);

private:
	int m_nValueType;				//1、0:绝对值，1：相对恒定流的值
	int m_bSpecial;					//2、0：瞬态特别条件选中“没有”，1：瞬态特别条件选“忽略瞬态数据”（针对具体节点特别条件多于2个分别查看特别条件对应的数字）
	int m_bRepeat1;					//3、0：第一次瞬变重复没选中，-1选中：
	int m_bRepeat2;					//4、0：第二次瞬变重复没选中，-1选中：
	int m_nTranType;				//5、0:时间，1：单个事件，2：两个事件循环3：两个连续事件
public:
	CalcPeriodic m_Periodic;
	CalcTriger   m_Triger1;
	CalcTriger   m_Triger2;
	TransTable m_TranData1;
	TransTable m_TranData2;

};

#endif // !defined(AFX_CALCTRANSDATA_H__03896490_6ACD_4B78_8519_C51C18213DF1__INCLUDED_)
