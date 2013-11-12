// MOCTranData.cpp: implementation of the MOCTranData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTranData.h"
#include "CalcTransData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTranData::MOCTranData()
{
	m_bSpecial = FALSE;
}

MOCTranData::~MOCTranData()
{

}

void MOCTranData::Read(CalcTransData &transdata)
{
	m_bSpecial = transdata.Special();
	m_periodic.Read(transdata.m_Periodic);
	m_trigerMgr.Read(transdata);
}

void MOCTranData::Tran(PFUNTRAN pTran)
{
	m_trigerMgr.Tran(pTran);
	m_periodic.Tran(pTran);
}

void MOCTranData::TranRel(PFUNTRAN2 pTran, double d)
{
	m_trigerMgr.TranRel(pTran,d);
}

void MOCTranData::Tran(PFUNTRAN2 pTran, double d)
{
	m_trigerMgr.Tran(pTran,d);
}
/*---------------------------------------------------
 dX:瞬态数据表第一列的值
 dStmY：稳态与瞬态数据表第二列对应参数的值，当不存在瞬变或瞬态数据表使用相对值使用这个参数
 dStart：瞬变模拟开始时间，当时间为相对值使用
 返回：瞬变当前迭代使用的参数
----------------------------------------------------*/
double MOCTranData::GeTransY(double dX, double dStmY,double dStart)
{
	if(m_bSpecial)
	{//忽略瞬态数据
		return dStmY;
	}
	else
	{
		if(m_periodic.IsSelPeriodic())
		{//选择使用正弦函数
			return m_periodic.GetTransY(dX);
		}
		else
		{//选择使用触发瞬变
			return m_trigerMgr.GetTransY(dX,dStmY,dStart);
		}
	}
}

void MOCTranData::Init(MOCComponentMgr &mgr)
{
	m_trigerMgr.Init(mgr);
}

void MOCTranData::InitFixTrans(MOCComponentMgr &mgr,int nKey,int nEventType)
{
	m_trigerMgr.InitFixTrans(mgr,nKey,nEventType);
}

BOOL MOCTranData::IsIgnoreTrans()
{
	return m_bSpecial;
}

int MOCTranData::TrigerStatus(double dTime,double dStart)
{
	return m_trigerMgr.TrigerStatus(dTime,dStart);
}

double MOCTranData::GeTransY(double dX)
{
	return m_trigerMgr.GetTransY(dX);
}