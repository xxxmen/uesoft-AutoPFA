// MOCCalcMgr.h: interface for the MOCCalcMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCALCMGR_H__D18E40A7_CD0E_46E8_A3E1_48833E25623B__INCLUDED_)
#define AFX_MOCCALCMGR_H__D18E40A7_CD0E_46E8_A3E1_48833E25623B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCSteady.h"
#include "MOCTrans.h"

class CalcDriverMgr;
class MOCComponentMgr;
class PFAOutModel;
class TransOutModel;
class SteadyOutModel;

class MOCCalcMgr  
{
public:
	void Calc(MOCComponentMgr &mgr,PFAOutModel &model);
	BOOL Read(CalcDriverMgr &data);
	MOCCalcMgr();
	virtual ~MOCCalcMgr();


private:
	void CalcImpulse(MOCComponentMgr &mgr,TransOutModel &model);
	void CalcStm(MOCComponentMgr &mgr,SteadyOutModel &model);
	int m_AnalysisType;			//计算分析类型数字标记：0：瞬态分析，1：稳态分析
	MOCSteady m_MOCSteady;
	MOCTrans  m_MOCTrans;
};

#endif // !defined(AFX_MOCCALCMGR_H__D18E40A7_CD0E_46E8_A3E1_48833E25623B__INCLUDED_)
