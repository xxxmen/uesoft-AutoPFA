// MOCSpray.cpp: implementation of the MOCSpray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCSpray.h"
#include "MOCFluid.h"
#include "CalcSpray.h"
#include "LocalRStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCSpray::MOCSpray()
{
	m_nHoleNum = 0;
	m_nLossType = 0;
	m_dExitArea = 0;					
	m_dKOrCv = 0;					    
	m_dExitPress = 0;
	m_dOutFlow = 0;
}

MOCSpray::~MOCSpray()
{

}

MOCJun* MOCSpray::Creator()
{
	MOCSpray *pData = new MOCSpray;
	return pData;
}

BOOL MOCSpray::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcSpray *pSprayData = dynamic_cast<CalcSpray*>(pData);
	ASSERT(pSprayData != NULL);
	m_nHoleNum = pSprayData->HoleNum();
	m_nLossType = pSprayData->LossType();
	m_dExitArea = pSprayData->ExitArea()*m_nHoleNum;					
	m_dKOrCv = pSprayData->KOrCv();					    
	m_dExitPress = pSprayData->ExitPress();
	if(0==pSprayData->ExitPressType())
		m_dExitPress = MOCFluid::TranHGLToPress(m_dExitPress);
	m_tranData.Read(pSprayData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dKOrCv);
	return TRUE;
}

BOOL MOCSpray::InitEndInfo()
{
	double dArea = SprayBasisArea();
	if(m_nLossType == 0)
	{
		m_dLossK = TranDcToK(m_dKOrCv,dArea/m_dExitArea);
	}
	if(m_nLossType == 1)
	{
		m_dKOrCv = TranKfToK(m_dKOrCv*m_nHoleNum,dArea);
		m_tranData.Tran(TranKfToK,dArea/m_nHoleNum);
		m_dLossK = m_dKOrCv;
	}

	StrArray<4> Info;
	EndInfo *pEnd = NULL;
	IteratorPtr<StrArray<4> > ItPtr(m_PipeInfo.CreatIterator());
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
		
		m_dLossK = Info.fData(2); 
	}

	return InitInOutEle();
}

void MOCSpray::CalcStm()
{
	CalcStm(m_dKOrCv);
}

void MOCSpray::CalcStm(double dKOrCv)
{
	if(m_nLossType==0)
	{//将喷嘴的流量系数转化成K系数
		double dArea = SprayBasisArea();
		dKOrCv = TranDcToK(dKOrCv,dArea/m_dExitArea);
	}
	m_EndList.KStrategy(m_dExitPress,dKOrCv,SprayBasisArea(),m_dOutFlow);
}
double MOCSpray::TranKfToK(double dKf,double dBasisArea)
{
	double dK = 0;
	dK = 2*MOCFluid::Density()*pow(dBasisArea,2)/pow(dKf,2);
	return dK/1000000;//兆帕
}

double MOCSpray::TranDcToK(double dDc,double dRatio)
{
	return 1/pow(dDc/dRatio,2);
}

double MOCSpray::SprayBasisArea()
{
	EndInfo *pEnd = GetInEnd();
	if(pEnd == NULL)
	{
		pEnd = GetOutEnd();
		ASSERT(pEnd != NULL);
	}
	return pEnd ->Area();
}



void MOCSpray::UpdataEnd()
{
	UpdataOneEnd();
	double dMass = fabs(m_EndList.GetInMass()-m_EndList.GetOutMass());

	double dArea;
	double dStaticPress;
	dArea = SprayBasisArea();
	dStaticPress = m_dExitPress-MOCFluid::CalcPressLoss(dMass,dArea);
	UpdataPress(m_dExitPress,dStaticPress,m_dOutEle,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
}

BOOL MOCSpray::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	return TRUE;
}

void MOCSpray::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dK = m_tranData.GeTransY(dTime,m_dKOrCv,trans.StartTime());
	dK = GetK(dK);//k= -1 表示无穷大
	CalcStm(dK);
}

double MOCSpray::GetOutVolumeFlow()
{
	return MOCFluid::TranMassToQ(m_dOutFlow);
}

void MOCSpray::Result(JunTranOut &out, int nStep)
{
	JunOut *pOut = out.Creator(nStep);
	pOut->SetTime(nStep*MOCFluid::SetpTime());
	pOut->SetSprayMassFlow(m_dOutFlow);
	pOut->SetSprayVolumeFlow(GetOutVolumeFlow());
}
