// MOCComponentMgr.cpp: implementation of the MOCComponentMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCComponentMgr.h"
#include "CaclDriverMgr.h"
#include "ComponentStmOutMgr.h"
#include "ComponentTranOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCComponentMgr::MOCComponentMgr()
{

}

MOCComponentMgr::~MOCComponentMgr()
{

}

BOOL MOCComponentMgr::Read(CalcDriverMgr &data)
{
	if(!m_PipeMgr.Read(data.GetPipeMgr()))
	{
		return FALSE;
	}
	if(!m_JunMgr.Read(data.GetJunMgr()))
	{
		return FALSE;
	}
	return TRUE;
}

BOOL MOCComponentMgr::InitComponentNet()
{
	m_PipeMgr.InitPipeEnd();//初始设置管道端口流量猜想
	return m_JunMgr.InitLinkInfo(m_PipeMgr);//与管道端口建立连接并设置端口信息。
}

void MOCComponentMgr::CalcStm(MOCSteady &Steady)
{
	m_PipeMgr.CalcStm();
	m_JunMgr.CalcStm();
	m_PipeMgr.CheckTol(Steady);
}


void MOCComponentMgr::CalcImpulse(MOCTrans &trans,double dTime)
{
	m_PipeMgr.CalcImpulse(trans);
	m_JunMgr.CalcImpulse(trans,dTime);	
}

void MOCComponentMgr::Result(ComponentStmOutMgr &out)
{
	m_PipeMgr.Result(out.PipeOutMgr());
	m_JunMgr.Result(out.JunOutMgr());
}

void MOCComponentMgr::Result(ComponentTranOutMgr &out,int nStep)
{
	m_PipeMgr.Result(out.PipeOutMgr(),nStep);
	m_JunMgr.Result(out.JunOutMgr(),nStep);
}

BOOL MOCComponentMgr::InitTransModel()
{
	if(m_PipeMgr.InitStation()
		&&m_JunMgr.InitTranData(*this))
	{
		return TRUE;
	}
	return FALSE;
}

MOCJun* MOCComponentMgr::LookUpJun(int nKey)
{
	return m_JunMgr.LookUp(nKey);
}

MOCPipe* MOCComponentMgr::LookUpPipe(int nKey)
{
	return m_PipeMgr.LookUp(nKey);
}
