// MOCTeeWye.cpp: implementation of the MOCTeeWye class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTeeWye.h"
#include "CalcTeeWye.h"
#include "BrachJunStrategy.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTeeWye::MOCTeeWye()
{
	m_dAngle = 0;		
	m_nModel = 0;			
	m_nType  = 0;
}

MOCTeeWye::~MOCTeeWye()
{

}

MOCJun* MOCTeeWye::Creator()
{
	MOCTeeWye *pData = new MOCTeeWye;
	return pData;
}

BOOL MOCTeeWye::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcTeeWye *pTeeWyeData = dynamic_cast<CalcTeeWye*>(pData);
	ASSERT(pTeeWyeData != NULL);
	m_dAngle = pTeeWyeData->Angle()/180.0*PI;		
	m_nModel = pTeeWyeData->Model();			
	m_nType  = pTeeWyeData->Type();
	m_PipeID = pData->PipeID();
	
	return TRUE;
}

BOOL MOCTeeWye::InitEndInfo()
{
	EndInfo *pEnd = NULL;
	double PipeId[3];
	int Index = 0;
	m_PipeID.ToDuoble(PipeId,Index);
	IteratorPtr<EndInfo> ItPtr(m_EndList.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		pEnd->SetPipeID(PipeId);
	}
	return InitInOutEle();
}

void MOCTeeWye::CalcStm()
{
	if(m_nModel == 2)
		CalcStmSimple();
	else
		CalcStmDetail();
}

void MOCTeeWye::CalcStmSimple()
{
	m_EndList.BranchStrategy(0);
}

void MOCTeeWye::CalcStmDetail()
{
	double Angle = m_dAngle;
	EndInfo *pAcEnd = NULL;//主入口
	EndInfo *pEnd = NULL;
	EndInfo *pAstEnd = NULL; //直口
	EndInfo *pAsEnd = NULL;  //分支
	double KcsLoss = 0;   
	double KcstLoss = 0;     //分之和直口阻力损失
	IteratorPtr<EndInfo> ItPtr(m_EndList.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		int PipeId[3];
		pEnd->GetPipeId(PipeId);
		if(pEnd->Key() == PipeId[0])
			pAcEnd = pEnd;
		if (pEnd->Key() == PipeId[1])
			pAstEnd = pEnd;
		if (pEnd->Key() == PipeId[2])
			pAsEnd = pEnd;
	}
	if(pAsEnd==NULL ||pAcEnd==NULL ||pAstEnd == NULL)
	{
		ASSERT(FALSE);
		return;
	}
	if (pAcEnd->GetMass() == 0 || pAsEnd->GetMass()==0 || pAstEnd->GetMass()==0)
	{
		m_EndList.BranchStrategy(0);
		return;
	}
	if (fabs(fabs(pAstEnd->GetMass())-fabs(pAcEnd->GetMass())-fabs(pAsEnd->GetMass())) < 0.1)
	{
		m_EndList.BranchStrategy(0);
		if (pAstEnd->GetEmunDir()==INJUN)     //pAst为入口且为分流的情况
		{
			KcsLoss = LossKcs(pAstEnd,pAsEnd,Angle)*m_dDesignFactor;
			KcstLoss = Losskcst(pAsEnd,pAcEnd,pAstEnd,Angle)*m_dDesignFactor;
		}
		else
		{
			KcsLoss = ConvergeLossKcs(pAstEnd,pAsEnd,pAcEnd,Angle)*m_dDesignFactor;
			KcstLoss= ConvergeLosskcst(pAsEnd,pAstEnd,Angle)*m_dDesignFactor;
		}
		double dDen = MOCFluid::Density();
		double DeltPress = 0.5*KcsLoss*dDen*pow(pAstEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAsEnd,pAsEnd->GetPress()-DeltPress);
		double AstDeltPress = 0.5*KcstLoss*dDen*pow(pAstEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAcEnd,pAcEnd->GetPress()-AstDeltPress);
	}	
	if (fabs(fabs(pAsEnd->GetMass())-fabs(pAcEnd->GetMass())-fabs(pAstEnd->GetMass())) < 0.1)
	{
		m_EndList.BranchStrategy(0);
		if (pAsEnd->GetEmunDir()==INJUN)     //pAs为入口且为分流的情况
		{
			KcsLoss = LossKcs(pAsEnd,pAcEnd,Angle)*m_dDesignFactor;
			KcstLoss = LossKcs(pAsEnd,pAstEnd,Angle)*m_dDesignFactor;
		}
		else
		{
			KcsLoss = ConvergeLossKcs(pAcEnd,pAsEnd,pAstEnd,Angle)*m_dDesignFactor;
			KcstLoss= KcsLoss;
		}
		double dDen = MOCFluid::Density();
		double DeltPress = 0.5*KcsLoss*dDen*pow(pAsEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAcEnd,pAcEnd->GetPress()-DeltPress);
		double AstDeltPress = 0.5*KcstLoss*dDen*pow(pAsEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAstEnd,pAstEnd->GetPress()-AstDeltPress);
	}
	if (fabs(fabs(pAcEnd->GetMass())-fabs(pAstEnd->GetMass())-fabs(pAsEnd->GetMass())) < 0.1)
	{
		m_EndList.BranchStrategy(0);
		if (pAcEnd->GetEmunDir()==INJUN)     //pAc为入口且为分流的情况
		{
			KcsLoss = LossKcs(pAcEnd,pAsEnd,Angle)*m_dDesignFactor;
			KcstLoss = Losskcst(pAsEnd,pAstEnd,pAcEnd,Angle)*m_dDesignFactor;
		}
		else
		{
			KcsLoss = ConvergeLossKcs(pAcEnd,pAsEnd,pAstEnd,Angle)*m_dDesignFactor;
			KcstLoss= ConvergeLosskcst(pAsEnd,pAcEnd,Angle)*m_dDesignFactor;
		}
		double dDen = MOCFluid::Density();
		double DeltPress = 0.5*KcsLoss*dDen*pow(pAcEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAsEnd,pAsEnd->GetPress()-DeltPress);
		double AstDeltPress = 0.5*KcstLoss*dDen*pow(pAcEnd->GetVelocity(),2);
		m_EndList.StagPressStrategy(*pAstEnd,pAstEnd->GetPress()-AstDeltPress);
	}
}

double MOCTeeWye::ConvergeLosskcst(EndInfo *pAsEnd,EndInfo *pAcEnd,double Angle)
{
	double k = 0;
	double q = pAsEnd->GetMass()/pAcEnd->GetMass();
	return 1-pow((1-q),2)-2*pAcEnd->Area()/pAsEnd->Area()*pow(q,2)*cos(Angle);
}

double MOCTeeWye::ConvergeLossKcs(EndInfo *pAcEnd,EndInfo *pAsEnd,EndInfo *pAstEnd,double Angle)
{
	double k = 0;
	if (pow(pAcEnd->Area(),2)/pow(pAsEnd->Area(),2)*pAsEnd->GetMass()/pAcEnd->GetMass() > 0.8)
		k = 0.9;
	else
		k = 1.0;
	double q = pAsEnd->GetMass()/pAcEnd->GetMass();
	return k*(1+pow(q*pAcEnd->Area()/pAsEnd->Area(),2)-2*pAcEnd->Area()/pAstEnd->Area()*pow((1-q),2)-2*pAcEnd->Area()/pAsEnd->Area()*pow(q,2)*cos(Angle));
}

double MOCTeeWye::LossKcs(EndInfo *pAcEnd,EndInfo *pAsEnd,double Angle)
{
	double k = 0;
	if(pAsEnd->GetMass() == 0 || pAcEnd->GetMass()==0)
		return 0;
	if (pAsEnd->Area()/pAcEnd->Area() <= 0.35)
	{
		if (fabs(pAsEnd->GetMass()/pAcEnd->GetMass()) <= 0.4)
			k = 1.1-0.7*fabs(pAsEnd->GetMass()/pAcEnd->GetMass());
		else
			k = 0.85;
	}
	else
	{
		if (fabs(pAsEnd->GetMass()/pAcEnd->GetMass()) <= 0.6)
			k = 1.0-0.6*fabs(pAsEnd->GetMass()/pAcEnd->GetMass());
		else
			k = 0.6;
	}
	return k*(1+pow((pAsEnd->GetVelocity()/pAcEnd->GetVelocity()),2)-2*pAsEnd->GetVelocity()/pAcEnd->GetVelocity()*cos(Angle));
}

double MOCTeeWye::Losskcst(EndInfo *pAsEnd,EndInfo *pAstEnd,EndInfo *pAcEnd,double Angle)
{
	double k = 0.4;
	if(pAsEnd->GetMass() == 0 || pAcEnd->GetMass()==0 ||pAstEnd->GetMass()==0)
		return 0;
	if (pAsEnd->Area()/pAcEnd->Area() <= 0.4)
		k = 0.4;
	else
	{
		if (fabs(pAsEnd->GetMass()/pAcEnd->GetMass()) <= 0.5)
			k = 2.0*(2.0*(pAsEnd->GetMass()/pAcEnd->GetMass())-1);
		else
			k = 0.3*(2.0*(pAsEnd->GetMass()/pAcEnd->GetMass())-1);
	}
	return k*pow(pAsEnd->GetMass()/pAcEnd->GetMass(),2);
}


void MOCTeeWye::UpdataEnd()
{
	UpdataOneEnd();
}

void MOCTeeWye::CalcImpulse(MOCTrans &trans, double dTime)
{
	CalcStm();
}
