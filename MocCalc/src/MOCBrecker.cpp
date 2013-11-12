// MOCBrecker.cpp: implementation of the MOCBrecker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCBrecker.h"
#include "MOCFluid.h"
#include "CalcBrecker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCBrecker::MOCBrecker()
{
	m_nType = 0;			           
	m_dOrificeInCdA = 0;		        
	m_dOrificeOutCdA = 0;			     
	m_dInterMediateCdA = 0;			    
	m_nMediateActivationType = 0;		
	m_dMediateActivation = 0;          
	m_dCrackPress = 0;				     						
	m_nConnectPipe = 0;	
	m_bClose = TRUE;
}

MOCBrecker::~MOCBrecker()
{

}

MOCJun* MOCBrecker::Creator()
{
	MOCBrecker *pData = new MOCBrecker;
	return pData;
}

BOOL MOCBrecker::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcBrecker *pBreckerData = dynamic_cast<CalcBrecker*>(pData);
	ASSERT(pBreckerData != NULL);
	m_nType = pBreckerData->Type();			           
	m_dOrificeInCdA = pBreckerData->OrificeInCdA();		        
	m_dOrificeOutCdA = pBreckerData->OrificeOutCdA();			     
	m_dInterMediateCdA = pBreckerData->InterMediateCdA();			    
	m_nMediateActivationType = pBreckerData->MediateActivationType();		
	m_dMediateActivation = pBreckerData->MediateActivation();          
	m_dCrackPress = pBreckerData->CrackPress();
	if(0==pBreckerData->CrackPressType())
		m_dCrackPress = MOCFluid::TranHGLToPress(m_dCrackPress);				
	m_nConnectPipe = pBreckerData->ConnectPipe();
	m_GasPropety.Read(*pBreckerData);
	return TRUE;
}

BOOL MOCBrecker::InitEndInfo()
{
	return InitInOutEle();
}

void MOCBrecker::CalcStm()
{
	m_EndList.BranchStrategy(0);
}

void MOCBrecker::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCBrecker::CalcImpulse(MOCTrans &trans, double dTime)
{
	if(!m_bClose||IsCrack())
	{
		m_EndList.BreakerJunStrategy(m_nType,m_GasPropety,m_dOrificeInCdA,m_dOrificeOutCdA);
		CheckIsClose();
	}
	else
	{
		m_EndList.BranchStrategy(0);
	}
}

BOOL MOCBrecker::IsCrack()
{
	if((m_EndList.Sc()/m_EndList.Sb())<m_dCrackPress)
	{
		m_bClose = FALSE;
		if(m_GasPropety.GasPress()<m_dCrackPress)
		{//如果外界气体压力小于破裂压力检测系统内部有气体才破裂
			CheckIsClose();
		}
	}
	return !m_bClose;
}

void MOCBrecker::CheckIsClose()
{
	double dGasMass = m_GasPropety.GasMolMass();
	if(-1E-8<dGasMass&&dGasMass<1E-8)
		m_bClose = TRUE;
}
