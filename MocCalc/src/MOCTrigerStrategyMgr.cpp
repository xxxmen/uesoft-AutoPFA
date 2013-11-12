// MOCTrigerStrategyMgr.cpp: implementation of the MOCTrigerStrategyMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerStrategyMgr.h"
#include "MOCComponentMgr.h"
#include "MOCTrigerStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerStrategyMgr::MOCTrigerStrategyMgr()
{
	m_factory = MOCTrigerStrategyFactory::Instance();
	m_pMgr = NULL;
	m_nEventType = 0;                
	m_nConditionType = 0;			 
	m_dValue = 0;				
	m_nPort1 = 0;				
	m_nComponentID1 = 0;		
	m_nPort2 = 0;					
	m_nComponentID2 = 0;
	m_dTrigerTime = 0;
	m_bHasTranData = FALSE;
}

MOCTrigerStrategyMgr::~MOCTrigerStrategyMgr()
{

}

/*------------------------------------------------*/
void MOCTrigerStrategyMgr::EventType(int nValue)
{
	m_nEventType = nValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::ConditionType(int nValue)
{
	m_nConditionType = nValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::Value(double dValue)
{
	m_dValue = dValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::Port1(int nValue)
{
	m_nPort1 = nValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::ComponentID1(int nValue)
{
	m_nComponentID1 = nValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::Port2(int nValue)
{
	m_nPort2 = nValue;
}
/*------------------------------------------------*/
void MOCTrigerStrategyMgr::ComponentID2(int nValue)
{
	m_nComponentID2 = nValue;
}

void MOCTrigerStrategyMgr::ModelMgr(MOCComponentMgr *pMgr)
{
	m_pMgr = pMgr;
}

/*------------------------------------------------*/
int MOCTrigerStrategyMgr::ConditionType()
{
	return m_nConditionType;
}
/*------------------------------------------------*/
double MOCTrigerStrategyMgr::Value()
{
	return m_dValue;
}
/*------------------------------------------------*/
int MOCTrigerStrategyMgr::Port1()
{
	return m_nPort1;
}
/*------------------------------------------------*/
int MOCTrigerStrategyMgr::ComponentID1()
{
	return m_nComponentID1;
}
/*------------------------------------------------*/
int MOCTrigerStrategyMgr::Port2()
{
	return m_nPort2;
}
/*------------------------------------------------*/
int MOCTrigerStrategyMgr::ComponentID2()
{
	return m_nComponentID2;
}
double MOCTrigerStrategyMgr::TrigerTime()
{
	return m_dTrigerTime;
}
void MOCTrigerStrategyMgr::TrigerTime(double dValue)
{
	m_dTrigerTime = dValue;
}
void MOCTrigerStrategyMgr::HasTranData(BOOL bHasData)
{
	m_bHasTranData = bHasData;
}
BOOL MOCTrigerStrategyMgr::HasTranData()
{
	return m_bHasTranData;
}

BOOL MOCTrigerStrategyMgr::IsTriger(double dCurTime,double dStartTime)
{
	MOCTrigerStrategy *pStrategy = m_factory->CreatObject(m_nEventType);
	if(pStrategy != NULL)
	{
		return pStrategy->IsTriger(*this,dCurTime,dStartTime);
	}
	return FALSE;
}

MOCJun* MOCTrigerStrategyMgr::LookUpJun(int nKey)
{
	ASSERT(m_pMgr != NULL);
	return m_pMgr->LookUpJun(nKey);
}

MOCPipe* MOCTrigerStrategyMgr::LookUpPipe(int nKey)
{
	ASSERT(m_pMgr != NULL);
	return m_pMgr->LookUpPipe(nKey);
}
