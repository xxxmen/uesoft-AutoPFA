// MOCRelief.h: interface for the MOCRelief class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCRELIEF_H__02D82FF7_33B5_46FE_8337_E1943A24BA79__INCLUDED_)
#define AFX_MOCRELIEF_H__02D82FF7_33B5_46FE_8337_E1943A24BA79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCRelief : public MOCJun  
{
public:
	void Crack(BOOL bCrack);
	int ReliefStatus();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCRelief();
	virtual ~MOCRelief();

private:
	void CalcStm();
	void CalcStmClose();
	void CalcStmOpen(double dKOrCv);
	BOOL InitEndInfo();
	BOOL InitTranData(MOCComponentMgr &mgr);
private:
	void TestStatus();
	BOOL IsCloseTriger();
	BOOL IsCrackTriger();
	void CalcInterValve(double dKOrCv);
	void CalcExitValve(double dKOrCv);
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	void CalcCloseInline();
	void CalcCloseValve();
	double GetCurCv();
	int		 m_nType;							//类型(1:内部安全阀（internal relief）2:出口安全阀（exit relief）3:内嵌安全阀（inline relief）)
	int      m_nLossType;						//损失模型(0：流量系数模型，1：K系数模型3：变流量系数)
	double   m_dKOrCv;						    //K或Cv系数值
	int      m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double   m_dBasisArea;						//面积哦or直径
									            //0. 绝对水头, 2. 水头差,  1、绝对压力, 3、压力差.
	BOOL     m_bDeltaPress;					    //Ture压力差
	double	 m_dCrackPress;				        //破裂的压力
	double   m_dExitPress;					    //出口压力

	double m_dOutFlow;
	BOOL m_bCrack;
	int m_nReliefStatus;

	MOCTranData m_tranData;

	short m_iCalcStatus ;//计算状态:初始状态为-1，大于等于0时为非初始状态，在非初始状态中，
						//关闭状态则为0，打开状态为1
};

#endif // !defined(AFX_MOCRELIEF_H__02D82FF7_33B5_46FE_8337_E1943A24BA79__INCLUDED_)
