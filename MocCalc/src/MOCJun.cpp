// MOCJun.cpp: implementation of the MOCJun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCJun.h"
#include "MOCPipe.h"
#include "MOCFluid.h"
#include "CalcJun.h"
#include "JunStmOut.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCJun::MOCJun()
{
	m_nID = 0;
	m_dInEle = 0;
	m_dOutEle = 0;
	m_dDesignFactor = 0;
	m_dInitGuess = 0;
	m_nSpecialMark = 0;

	m_dInStagPress = 0;
	m_dOutStagPress = 0;
	m_dInStaticPress = 0;
	m_dOutStaticPress = 0;
	m_dInEGL = 0;
	m_dOutEGL = 0;
	m_dInHGL = 0;
	m_dOutHGL = 0;
	m_dLossK = 0;
}

MOCJun::~MOCJun()
{

}

void MOCJun::ReadJun(CalcJun *pData)
{
	ASSERT(pData != NULL);
	m_strName = pData->Name();
	m_nID = pData->ID();
	m_dInEle = pData->InEle();
	m_dOutEle = pData->OutEle();
	m_dDesignFactor = pData->DesignFactor();
	m_dInitGuess = pData->InitGuess();
	if(0==pData->InitGuessType())
	{
		m_dInitGuess = MOCFluid::TranHGLToPress(m_dInitGuess);
	}
	m_nSpecialMark = pData->SpecialMark();
	m_PipeID = pData->PipeID();
	m_CurveData.SetData(pData->CurveData());
}

BOOL MOCJun::InitLinkEnd(MOCPipeMgr &mgr)
{
	StrArray<1> pipeKey;
	EndInfo *pEnd = NULL;
	IteratorPtr<StrArray<1> > ItPtr(m_PipeID.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pipeKey = ItPtr->CurrentItem();
		pEnd = mgr.LookPipeEnd(pipeKey.nData());
		if(pEnd == NULL)
		{
			ASSERT(FALSE);
			return FALSE;
		}
		pEnd->Key(pipeKey.nData());
		m_EndList.AddEnd(pEnd);
	}
	return TRUE;
}

BOOL MOCJun::InitInfo(ListImp<StrArray<4> > &ref)
{
	StrArray<4> Info;
	EndInfo *pEnd = NULL;
	IteratorPtr<StrArray<4> > ItPtr(ref.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		Info = ItPtr->CurrentItem();
		pEnd = m_EndList.Find(Info.nData(0));
		if(pEnd == NULL)
		{
			ASSERT(FALSE);
			return FALSE;
		}
		pEnd->InJunK(Info.fData(2));
		pEnd->OutJunK(Info.fData(1));
		pEnd->SetZ(pEnd->GetZ()+Info.fData(3));
	}
	return TRUE;
}

double MOCJun::BasisArea(int nType, double dValue)
{
	EndInfo *pEnd = NULL;
	switch(nType) {
	case 0:
		pEnd = m_EndList.GetInEnd();
		ASSERT(pEnd != NULL);
		return pEnd->Area();
		break;
	case 1:
		pEnd = m_EndList.GetOutEnd();
		ASSERT(pEnd != NULL);
		return pEnd->Area();
		break;
	case 2:
		return dValue;
		break;
	case 3:
		return PI*pow(dValue,2)/4;
		break;
	default:
		ASSERT(FALSE);
		return 0;
		break;
	}
}

double MOCJun::K(double dCv,double dArea)
{
	if(-0.0000001<dCv && dCv<0.0000001)
	{
		return 1E+31;
	}
	else
	{
		return 1.0 / pow(dCv/dArea/58883.923073822689447,2);
	}
}
double MOCJun::RelToAbs(double dRatio,double dValue)
{
	return dRatio*dValue/100;
}

BOOL MOCJun::InitInOutEle()
{
	m_EndList.SetZ(m_dInEle,m_dOutEle);
	return TRUE;
}

void MOCJun::CalcStm32()
{
	if(JunStatus() ==1)
	{//节点关闭
	    m_EndList.DeadStrategy();
	}
	else if(JunStatus() ==2)
	{//节点总打开无无控制（check,controlValve,ReliefValve,pump）
		CalcStm();
	}
	else
	{
		CalcStm();
	}
}
void MOCJun::CalcImpulse32(MOCTrans &trans,double dTime)
{
	if(JunStatus() ==2)
	{//节点总打开无无控制（check,controlValve,ReliefValve）
		CalcStm();
	}
	else if(JunStatus() ==3)
	{//忽略节点特性(gasAccum,surge,liquid,breaker)
		m_EndList.BranchStrategy(0);
	}
	else
	{
		CalcImpulse(trans,dTime);
	}
}
void MOCJun::Result(JunStmOut &out)
{
	double dOutEndMass = m_EndList.GetOutMass();
	double dInEndMass = m_EndList.GetInMass();
	UpdataEnd();
	CalculateK();
	out.Key(Key());
	out.Type(m_nID);
	out.SetInStagPress(m_dInStagPress);
	out.SetOutStagPress(m_dOutStagPress);
	out.SetInStaticPress(m_dInStaticPress);
	out.SetOutStaticPress(m_dOutStaticPress);
	out.SetGLoss(MOCFluid::TranHToPress(m_dOutEle-m_dInEle));
	out.SetInMassFlow(dOutEndMass-dInEndMass);
//	out.SetInMassFlow(dInEndMass-dOutEndMass);
	out.SetInVolumeFlow(MOCFluid::TranMassToQ(dOutEndMass-dInEndMass));
	out.SetThruMassFlow(dOutEndMass);
	out.SetThruVolumeFlow(MOCFluid::TranMassToQ(dOutEndMass));
	out.SetLossK(m_dLossK);
	out.SetInEGL(m_dInEGL);
	out.SetOutEGL(m_dOutEGL);
	out.SetInHGL(m_dInHGL);
	out.SetOutHGL(m_dOutHGL);
}
void MOCJun::UpdataEnd(EndInfo *pEnd,double &dStagPress,double &dStaticPress,double &dStagEGL,double &dStaticHGL)
{
	ASSERT(pEnd != NULL);
	dStagPress = pEnd->GetStagPress();
	dStaticPress = pEnd->GetStaticPress();
	dStagEGL = pEnd->GetEGL();
	dStaticHGL = pEnd->GetHGL();
}

void MOCJun::UpdataPress(double dStag,double dStatic,double dZ,double &dStagPress,double &dStaticPress,double &dStagEGL,double &dStaticHGL)
{
	dStagPress = dStag;
	dStaticPress = dStatic;
	dStagEGL = GetEGLorHGL(dStagPress,dZ);
	dStaticHGL = GetEGLorHGL(dStaticPress,dZ);
}
void MOCJun::UpdataTwoEnd()
{
	EndInfo *pEnd = m_EndList.GetInEnd(); 
	if(pEnd != NULL)
	{
		UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
	}
	pEnd = m_EndList.GetOutEnd();
	if(pEnd != NULL)
	{
		UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
	}
}

void MOCJun::UpdataOneEnd()
{
	EndInfo *pEnd = m_EndList.GetInEnd(); 
	if(pEnd != NULL)
	{
		UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
		return;	
	}
	pEnd = m_EndList.GetOutEnd();
	if(pEnd != NULL)
	{
		UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
	}
}

double MOCJun::GetEGLorHGL(double dPress, double dZ)
{
	return MOCFluid::TranPressToHGL(dPress)+dZ;
}

BOOL MOCJun::InitTranData(MOCComponentMgr &mgr)
{
	return TRUE;
}

double MOCJun::GetK(double dK)
{
	if(dK < 0)
	{
		return 1E+31;
	}
	else
	{
		return dK*m_dDesignFactor;
	}
}

EndInfo* MOCJun::GetInEnd()
{
	return m_EndList.GetInEnd();
}
EndInfo* MOCJun::GetOutEnd()
{
	return m_EndList.GetOutEnd();
}

int MOCJun::JunStatus()
{
	return m_nSpecialMark;
}

void MOCJun::Result(JunTranOut &out, int nStep)
{//派生类根据需要重栽

}

CString MOCJun::Name()
{
	return m_strName;
}

void MOCJun::CalculateK()
{

}