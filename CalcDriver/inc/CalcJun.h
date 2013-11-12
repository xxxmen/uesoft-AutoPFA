// CalcJun.h: interface for the CalcJun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUN_H__8A7A11AE_8DC5_4601_8415_A6153DB1F10D__INCLUDED_)
#define AFX_CALCJUN_H__8A7A11AE_8DC5_4601_8415_A6153DB1F10D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcTable.h"

class AFX_EXT_CLASS CalcJun  
{
public:
	virtual ostream& Write(ostream& CalcOut)=0;
	CalcJun();
	virtual ~CalcJun();
	friend ostream& operator<< (ostream &CalcOut,CalcJun &ref);

public:
	void PipeID(ListImp<StrArray<1> >& list);
	void CurveData(const ListImp<StrArray<2> >& ref);
	void Name(CString strName);
	void ID(int nValue);
	void Key(int nValue);
	void InEle(double dValue);
	void OutEle(double dValue);
	void DesignFactor(double dValue);
	void InitGuessType(int nValue);
	void InitGuess(double dValue);
	void SpecialMark(int nValue);

	CString Name();
	int ID();
	int Key();
	double InEle();
	double OutEle();
	double DesignFactor();
	int InitGuessType();
	double InitGuess();
	int SpecialMark();
	ListImp<StrArray<1> >& PipeID();
	ListImp<StrArray<2> >& CurveData();

protected:
	CString m_strName;
	int m_nTypeID;				//节点类型标记ID
	int m_nKey;					//节点元件编号
	double m_dInEle;			//节点入口标高
	double m_dOutEle;			//节点出口标高
	double m_dDesignFactor;		//损失设计因子
	int    m_nInitGuessType;	//初始化猜测压力类型（0：压头；1压力）
	double m_dInitGuess;		//初始化猜测值
	int    m_nSpecialMark;		//1.节点的特定条件0:正常，1：关闭：2：打开没有控制3：忽略
	PipeIDList m_PipeID;		//
	CalcTable<2> m_CurveData;
protected:
//	ostream& WriteOption(ostream& CalcOut);
//	ostream& WriteJun(ostream& CalcOut);
};

#endif // !defined(AFX_CALCJUN_H__8A7A11AE_8DC5_4601_8415_A6153DB1F10D__INCLUDED_)
