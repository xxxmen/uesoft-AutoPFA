// MOCTrigerMgr.cpp: implementation of the MOCTrigerMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerMgr.h"
#include "CalcTransData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerMgr::MOCTrigerMgr()
{
	m_nValueType = 0;			
	m_nTranType = 0;			
}

MOCTrigerMgr::~MOCTrigerMgr()
{

}

void MOCTrigerMgr::Read(CalcTransData &transdata)
{
	m_nValueType = transdata.ValueType();			
	m_nTranType = transdata.TranType();
	m_triger1.Repeat(transdata.Repeat1());
	m_triger2.Repeat(transdata.Repeat2());
	m_triger1.Read(transdata.m_Triger1,transdata.m_TranData1);
	m_triger2.Read(transdata.m_Triger2,transdata.m_TranData2);
}

void MOCTrigerMgr::Tran(PFUNTRAN pTran)
{
	m_triger1.Tran(pTran);
	m_triger2.Tran(pTran);	
}
void MOCTrigerMgr::TranRel(PFUNTRAN2 pTran, double d)
{
	if(1== m_nValueType)
	{//瞬变数据使用相对值。
		m_triger1.Tran(pTran,d);
		m_triger2.Tran(pTran,d);
	}
}
void MOCTrigerMgr::Tran(PFUNTRAN2 pTran, double d)
{
	m_triger1.Tran(pTran,d);
	m_triger2.Tran(pTran,d);
}

double MOCTrigerMgr::GetTransY(double dX,double dStmY,double dStart)
{
	double dY = 0;
	double dY1 = 0;
	switch(m_nTranType)
	{
	case 0:
		dY = m_triger1.GetTransY(dX,dStmY);
		break;
	case 1:
		dY = m_triger1.GetTransY(dX,dStmY,dStart);
		break;
	case 2:
		dY = m_triger1.GetTransY(dX,dStmY,dStart);
		dY1 = m_triger2.GetTransY(dX,dStmY,dStart);
		if(m_triger1.IsTriger())
			m_triger2.Triger(FALSE);
		if(m_triger2.IsTriger())
			m_triger1.Triger(FALSE);
		if(m_triger2.IsTriger())
			dY = dY1;
	    break;
	case 3:
		if(!m_triger2.IsTriger())
		{
			dY = m_triger1.GetTransY(dX,dStmY,dStart);
		}
		if(m_triger1.IsTriger())
		{//第一个触发事件已经触发
			dY1 = m_triger2.GetTransY(dX,dStmY,dStart);
			if(m_triger2.IsTriger())
			{//第二个触发事件已经触发使用第二触发事件数据
				dY = dY1;
			}
		}
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
	return dY;
}

void MOCTrigerMgr::Init(MOCComponentMgr &mgr)
{
	m_triger1.Init(mgr);
	m_triger2.Init(mgr);
}

void MOCTrigerMgr::InitFixTrans(MOCComponentMgr &mgr,int nKey,int nEventType)
{
	m_triger1.InitFixTrans(mgr,nKey,nEventType,3);//开始打开
	m_triger2.InitFixTrans(mgr,nKey,nEventType,4);//开始关闭
	Init(mgr);
}

int MOCTrigerMgr::TrigerStatus(double dTime,double dStart)
{
	int nStatus = 0;
	switch(m_nTranType)
	{
	case 0:
		nStatus = 1;
		break;
	case 1:
		if(m_triger1.TrigerStatus(dTime,dStart))
			nStatus = 1;
		break;
	case 2:
		m_triger1.TrigerStatus(dTime,dStart);
		m_triger2.TrigerStatus(dTime,dStart);
		if(m_triger1.IsTriger())
		{
			nStatus = 1;
			m_triger2.Triger(FALSE);
		}
		if(m_triger2.IsTriger())
		{
			nStatus = 2;
			m_triger1.Triger(FALSE);
		}
	    break;
	case 3:
		if(!m_triger2.IsTriger())
		{
			if(m_triger1.TrigerStatus(dTime,dStart))
				nStatus = 1;
		}
		if(m_triger1.IsTriger())
		{//第一个触发事件已经触发
			if(m_triger1.TrigerStatus(dTime,dStart))
				nStatus = 2;
		}
	    break;
	default:
		ASSERT(FALSE);
	    break;
	}
	return nStatus;
}

double MOCTrigerMgr::GetTransY(double dX)
{
	return m_triger1.GetTransY(dX);
}