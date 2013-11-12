// CalcAssignFlow.h: interface for the CalcAssignFlow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCASSIGNFLOW_H__2EA86D2A_08BB_4592_93D2_2836EF588C49__INCLUDED_)
#define AFX_CALCASSIGNFLOW_H__2EA86D2A_08BB_4592_93D2_2836EF588C49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcAssignFlow : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcAssignFlow();
	virtual ~CalcAssignFlow();

public:
	void K(double dValue);
	void FlowDir(int nValue);
	void FlowType(int nValue);
	void Flow(double dValue);
	void SelInitPress(int nValue);
	void InitPressType(int nValue);
	void InitPress(double dValue);

	double K();
	int FlowType();
	double Flow();
	int SelInitPress();
	int InitPressType();
	double InitPress();
private:
	double   m_dK;						//损失系数K值
	int      m_nFlowDir;				//0：流体流入，1：流体流出
	int      m_nFlowType;				//流量类型\大小
	double   m_dFlow;				    //流量类型\大小
	int      m_bSelInitPress;           //恒定流量为0的初始化压力（0，没有选，1选中）
	int      m_nInitPressType;			//压力类型（0水头，1：压力）
	double   m_dInitPress;				//初始化压力

public:
	CalcTransData m_TranData;
};

#endif // !defined(AFX_CALCASSIGNFLOW_H__2EA86D2A_08BB_4592_93D2_2836EF588C49__INCLUDED_)
