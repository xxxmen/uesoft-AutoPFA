// MOCTranData.h: interface for the MOCTranData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRANDATA_H__4A12117A_DA66_499B_90C5_ADC1247B4525__INCLUDED_)
#define AFX_MOCTRANDATA_H__4A12117A_DA66_499B_90C5_ADC1247B4525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCPeriodic.h"
#include "MOCTrigerMgr.h"

class CalcTransData;

class MOCTranData  
{
public://泵访问瞬变数据有其特殊性，所以提供一些接口。其他元件主要使用GeTransY的到瞬变数据
	BOOL IsIgnoreTrans();
	int TrigerStatus(double dTime,double dStart);//0:没有触发1：第一事件触发2：第二事件触发
	double GeTransY(double dX);
public:
	void InitFixTrans(MOCComponentMgr &mgr,int nKey,int nEventType);
	void Init(MOCComponentMgr &mgr);
	double GeTransY(double dX,double dStmY,double dStart);
	void Tran(PFUNTRAN2 pTran, double d);
	void TranRel(PFUNTRAN2 pTran, double d);
	void Tran(PFUNTRAN pTran);
	void Read(CalcTransData& transdata);
	MOCTranData();
	virtual ~MOCTranData();

private:
	BOOL m_bSpecial;					//是否忽略瞬态数据
	MOCPeriodic m_periodic;
	MOCTrigerMgr m_trigerMgr;
};

#endif // !defined(AFX_MOCTRANDATA_H__4A12117A_DA66_499B_90C5_ADC1247B4525__INCLUDED_)
