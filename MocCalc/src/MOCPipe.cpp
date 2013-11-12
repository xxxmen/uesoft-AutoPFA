// MOCPipe.cpp: implementation of the MOCPipe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPipe.h"
#include "CalcPipe.h"
#include "MOCFluid.h"
#include "PipeStmOut.h"
#include "StationOut.h"
#include "CalcFriction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPipe::MOCPipe()
:m_InEnd(OUTJUN)
,m_OutEnd(INJUN)
{
	m_nInJunID = 0;				  
	m_nOutJunID = 0;			
	m_dInDia = 0;			
	m_dLen = 0;			    	
	m_dInitFlow = 0;			
	m_dPipeFactor = 1;	
	m_dFitFactor = 1;
	m_dLocalK = 0;				
	m_nFrictionModel = 0;		
	m_dFriction = 0;				
	m_nSectionNum = 0;			
	m_dInOldPress = 0;
	m_dOutOldPress = 0;
	m_dInOldFlow = 0;
	m_dOutOldFlow = 0;
}

MOCPipe::~MOCPipe()
{

}
double MOCPipe::B()
{
	return m_dB;
}
BOOL MOCPipe::Read(CalcPipe &data)
{
	m_nInJunID = data.InJunID();				  
	m_nOutJunID = data.OutJunID();			
	m_dInDia = data.InDia()*(1-data.InDiaReduce()/100.0);			
	m_dLen = data.Len();
	m_dInitFlow = data.InitFlow();
	int nType = data.InitFlowType();
	if(nType == 2)
	{//流速转化体积流量
		m_dInitFlow = m_dInitFlow * CalcArea();
		nType = 0;
	}
	if(nType == 0)
	{//体积流量转化成质量流量
		m_dInitFlow = MOCFluid::TranQToMass(m_dInitFlow);
	}
	m_dPipeFactor = data.PipeFactor();
	m_dFitFactor = data.FitFactor();
	m_dLocalK = data.LocalK()*data.FitFactor();				
	m_nFrictionModel = data.FrictionModel();		
	m_dFriction = data.Friction();				
	m_nSectionNum = data.SectionNum();			
	m_dB = data.WaveSpeed()/CalcArea();

	return TRUE;
}

double MOCPipe::CalcArea()
{
	return PI*pow(m_dInDia,2)/4;
}

double MOCPipe::FrictionCalc()
{
	CalcFriction calc;
	calc.Dia(m_dInDia);
	calc.FrictionModel(m_nFrictionModel);
	calc.Area(CalcArea());
	calc.Friction(m_dFriction);
	calc.Re(CalcRe());
	calc.V(GetVelocity());
	calc.Q(GetVolumeFlow());
	return calc.CalcF();
}

double MOCPipe::CalcRe()
{
	return fabs(GetVelocity() * m_dInDia/MOCFluid::Viscos());
}
double MOCPipe::GetK(double dF)
{//管道和管件的总阻力系数
	double dK = GetFK(dF) + m_dLocalK*m_dFitFactor;
	return dK;
}
double MOCPipe::CalcR()
{
	double dF = FrictionCalc();
	return CalcR(dF,m_InEnd.OutJunK() + m_OutEnd.InJunK());
}
double MOCPipe::CalcR(double dF,double dEndK,int nSectionNum)
{
	double dK = GetK(dF)/nSectionNum + dEndK;
	return 0.5*dK / pow(CalcArea(),2)/MOCFluid::Density();
}
EndInfo* MOCPipe::GetInEnd()
{
	return &m_InEnd;
}

EndInfo* MOCPipe::GetOutEnd()
{
	return &m_OutEnd;
}

void MOCPipe::InitEndInfo()
{
	double dArea = CalcArea();
	m_InEnd.Area(dArea);
	m_OutEnd.Area(dArea);
	m_InEnd.SetMass(m_dInitFlow);
	m_OutEnd.SetMass(m_dInitFlow);
}

void MOCPipe::CalcStm()
{
	double dR = CalcR();
	double dHPress = GetDeltaG();
	double dCp = m_InEnd.GetPress() + m_dB*m_InEnd.GetMass() - dHPress;
	double dCm = m_OutEnd.GetPress() - m_dB*m_OutEnd.GetMass() + dHPress;
	double dBp = m_dB + dR*fabs(m_InEnd.GetMass());
	double dBm = m_dB + dR*fabs(m_OutEnd.GetMass());
	m_InEnd.SetCpm(dCm);
	m_InEnd.SetBpm(dBm);
	m_OutEnd.SetCpm(dCp);
	m_OutEnd.SetBpm(dBp);
	m_dInOldPress = m_InEnd.GetPress();
	m_dOutOldPress = m_OutEnd.GetPress();
	m_dInOldFlow = m_InEnd.GetMass();
	m_dOutOldFlow = m_OutEnd.GetMass();
}


void MOCPipe::Result(PipeStmOut &out)
{
	out.Key(Key());
	out.SetMassFlow(GetMassFlow());
	out.SetVolumeFlow(GetVolumeFlow());
	out.SetVelocity(GetVelocity());
	out.SetInStagPress(GetInStagPress());
	out.SetOutStagPress(GetOutStagPress());
	out.SetStagPressLoss(GetInStagPress()-GetOutStagPress());
	out.SetInStaticPress(GetInStaticPress());
	out.SetOutStaticPress(GetOutStaticPress());
	out.SetStaticPressLoss(GetInStaticPress()-GetOutStaticPress());
	out.SetHLoss(GetHLoss());
	out.SetGLoss(GetDeltaG());
	out.SetFLoss(GetFLoss(FrictionCalc()));
	out.SetLossFactorF(GetFK(FrictionCalc()));
	out.SetLossFactorT(GetK(FrictionCalc()));
	double InEndHLoss = MOCFluid::TranPressToH(m_InEnd.CalcEndLoss()); 
	double OutEndLoss = MOCFluid::TranPressToH(m_OutEnd.CalcEndLoss());
	out.SetInEGL(m_InEnd.GetEGL()-InEndHLoss);
	out.SetOutEGL(m_OutEnd.GetEGL()+OutEndLoss);
	out.SetInHGL(m_InEnd.GetHGL()-InEndHLoss);
	out.SetOutHGL(m_OutEnd.GetHGL()+OutEndLoss);
}

double MOCPipe::GetMassFlow()
{
	return (m_InEnd.GetMass()+m_OutEnd.GetMass())/2.0;
}

double MOCPipe::GetDeltaG()
{
	return MOCFluid::TranHToPress(m_OutEnd.GetZ()-m_InEnd.GetZ());
}

double MOCPipe::GetVolumeFlow()
{
	return MOCFluid::TranMassToQ(GetMassFlow());
}

double MOCPipe::GetVelocity()
{
	return GetVolumeFlow()/CalcArea();
}

double MOCPipe::GetInStagPress()
{
	return m_InEnd.GetPress() -  m_InEnd.CalcEndLoss();
}

double MOCPipe::GetOutStagPress()
{
	return m_OutEnd.GetPress() + m_OutEnd.CalcEndLoss();   //由于节点的损失在管道里计算了，补偿那部分损失
}

double MOCPipe::GetInStaticPress()
{
	return m_InEnd.GetPress()-m_InEnd.CalcEndLoss()-MOCFluid::CalcPressLoss(m_InEnd.GetMass(),m_InEnd.Area());
}

double MOCPipe::GetOutStaticPress()
{
	return m_OutEnd.GetPress() + m_OutEnd.CalcEndLoss()-MOCFluid::CalcPressLoss(m_OutEnd.GetMass(),m_OutEnd.Area());
}

double MOCPipe::GetHLoss()
{
	return MOCFluid::TranPressToH(GetInStagPress()-GetOutStagPress()-GetDeltaG());
}

double MOCPipe::GetFLoss(double dF)
{//摩擦阻力
	return 0.5*GetK(dF)*MOCFluid::Density()*pow(GetVelocity(),2);
}

double MOCPipe::GetFK(double dF)
{
	return (dF*m_dLen/m_dInDia)*m_dPipeFactor;
}

void MOCPipe::CheckTol(MOCSteady &Steady)
{
	//得到当前计算出的流量和压力
	double dInPress = m_InEnd.GetPress();
	double dOutPress = m_OutEnd.GetPress();
	double dInFlow = m_InEnd.GetMass();
	double dOutFlow = m_OutEnd.GetMass();

	//Add by Liuck [4/28/2009]
	//当存在0流量标记的时候，比如计算盲端和安全阀，上下游流量直接设置为0
	if ( m_InEnd.GetZeroMassFlag() || m_OutEnd.GetZeroMassFlag() )
	{
		m_InEnd.SetMass( 0.0 ) ;
		m_OutEnd.SetMass( 0.0 ) ;
		m_InEnd.SetPress(dInPress);
		m_OutEnd.SetPress(dOutPress);
// 		Steady.CheckPress(dInPress,dInPress);
		Steady.CheckPress(m_dInOldPress,dInPress);
		Steady.CheckPress(m_dOutOldPress,dOutPress);
		return ;
	}

	//检查误差是否符合要求并且使用松弛因子
	Steady.CheckPress(m_dInOldPress,dInPress);
	Steady.CheckPress(m_dOutOldPress,dOutPress);
	Steady.CheckFlow(m_dInOldFlow,dInFlow);
	Steady.CheckFlow(m_dOutOldFlow,dOutFlow);
	//使用松弛因子更新数据
	m_InEnd.SetPress(dInPress);
	m_OutEnd.SetPress(dOutPress);
	m_InEnd.SetMass(dInFlow);
	m_OutEnd.SetMass(dOutFlow);
}

BOOL MOCPipe::InitStation()
{
	return m_stationMgr.Init(this,m_nSectionNum);
}

void MOCPipe::CalcImpulse(MOCTrans &trans)
{
	m_stationMgr.CalcImpulse(trans);
}

void MOCPipe::Result(PipeTranOut &out,int nStep)
{
	StationOut *pOut = out.Creator(nStep);
	m_stationMgr.Result(*pOut,this);
}