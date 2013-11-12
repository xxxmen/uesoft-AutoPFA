// MOCCheck.h: interface for the MOCCheck class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCHECK_H__C656B9D0_1827_4017_80A2_FC8B0F38628B__INCLUDED_)
#define AFX_MOCCHECK_H__C656B9D0_1827_4017_80A2_FC8B0F38628B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCCheck : public MOCJun  
{
public:
	void Close(BOOL bClose);
	int CheckStatus();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCCheck();
	virtual ~MOCCheck();

private:
	void CalcStm();
	void CalcStmK(double dK);
	void CalcStmCv(double dCv);
	BOOL InitEndInfo();
	void UpdataEnd();
	BOOL InitTranData(MOCComponentMgr &mgr);

private:
	void TestStatus();
	BOOL IsCloseTriger();
	BOOL IsReOpenTriger();
	void CalcImpulse(MOCTrans &trans,double dTime);
	int    m_nLossType;						    //损失模型0：流量系数模型，1：K系数模型			                                           
	double m_dKOrCv;					        //K或Cv系数值
    int    m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double m_dBasisArea;						//面积哦or直径
	double m_dReOpenPress;					    //压力值	
	double m_dCloseVel;					        //关闭阀门的最小正向速度\速度单位

	BOOL m_bClose;                              //迅速打开和关闭
	int m_nCheckStatus;                         //0:打开，1：关闭，3：开始打开，4：开始关闭
	
	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCCHECK_H__C656B9D0_1827_4017_80A2_FC8B0F38628B__INCLUDED_)
