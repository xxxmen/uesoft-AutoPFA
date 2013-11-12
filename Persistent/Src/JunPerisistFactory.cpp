// JunPerisistFactory.cpp: implementation of the JunPerisistFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunPerisistFactory.h"
#include "AssignFlowPerisist.h"
#include "AssignPressPerisist.h"
#include "AreaChangePerisist.h"
#include "BranchPerisist.h"
#include "BreakerPerisist.h"
#include "CheckPerisist.h"
#include "ControlPerisist.h"
#include "DeadEndPerisist.h"
#include "GasAccumPerisist.h"
#include "GeneralPerisist.h"
#include "LiquidAccumPerisist.h"
#include "PumpPerisist.h"
#include "ReliefPerisist.h"
#include "ReservoirPerisist.h"
#include "SprayPerisist.h"
#include "SurgePerisist.h"
#include "TeeWyePerisist.h"
#include "ValvePerisist.h"
#include "BendPerisist.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunPerisistFactory::JunPerisistFactory()
{
	Register(1,BranchPerisist::CreatBranch);
	Register(2,ReservoirPerisist::CreatReservoir);
	Register(3,AssignFlowPerisist::CreatAssignedFlow);
	Register(4,AssignPressPerisist::CreatAssignedPressure);
	Register(5,AreaChangePerisist::CreatAreaChange);
	Register(6,BendPerisist::CreatBend);
	Register(21,ReliefPerisist::CreatRelief);
	Register(7,TeeWyePerisist::CreatTeeWye);
	Register(8,ValvePerisist::CreatValve);
	Register(9,ControlPerisist::CreatControlValve);
	Register(10,CheckPerisist::CreatCheckValve);
	Register(11,DeadEndPerisist::CreatDeadEnd);
	Register(22,GasAccumPerisist::CreatGasAccumulator);
	Register(24,SurgePerisist::CreatSurge);
	Register(23,LiquidAccumPerisist::CreatLiquidAccum);
	Register(25,BreakerPerisist::CreatBreaker);
	Register(16,SprayPerisist::CreatSpray);
	Register(17,PumpPerisist::CreatPump);
	Register(20,GeneralPerisist::CreatGeneral);
}

JunPerisistFactory::~JunPerisistFactory()
{

}

JunPerisistFactory* JunPerisistFactory::Instance()
{
	static JunPerisistFactory factory;
	return &factory;
}
