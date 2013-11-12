// ComponentFactory.cpp: implementation of the ComponentFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ComponentFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


ComponentFactory::ComponentFactory()
{
	Pipe::Instance();
	Branch::Instance();
	Reservoir::Instance();
	AssignedFlow::Instance();
	AssignedPressure::Instance();
	AreaChange::Instance();
	ReliefValve::Instance();
	TeeWye::Instance();
	Valve::Instance();
	ControlValve::Instance();
	CheckValve::Instance();
	DeadEnd::Instance();
	GasAccumulator::Instance();
	Surge::Instance();
	LiquidAccumulator::Instance();
	VacuumBreaker::Instance();
	General::Instance();
	SprayDischarge::Instance();
	Pump::Instance();
	Bend::Instance();
	
	Register(Pipe::m_nTypeID,Pipe::CreatPipe);
	Register(Branch::m_nTypeID,Branch::CreatBranch);
	Register(Reservoir::m_nTypeID,Reservoir::CreatReservoir);
    Register(AssignedFlow::m_nTypeID,AssignedFlow::CreatAssignedFlow);
	Register(AssignedPressure::m_nTypeID,AssignedPressure::CreatAssignedPressure);
	Register(AreaChange::m_nTypeID,AreaChange::CreatAreaChange);
	Register(ReliefValve::m_nTypeID,ReliefValve::CreatReliefValve);
	Register(TeeWye::m_nTypeID,TeeWye::CreatTeeWye);
	Register(Valve::m_nTypeID,Valve::CreatValve);
	Register(ControlValve::m_nTypeID,ControlValve::CreatControlValve);
	Register(CheckValve::m_nTypeID,CheckValve::CreatCheckValve);
	Register(DeadEnd::m_nTypeID,DeadEnd::CreatDeadEnd);
	Register(GasAccumulator::m_nTypeID,GasAccumulator::CreatGasAccumulator);
	Register(Surge::m_nTypeID,Surge::CreatSurge);
	Register(LiquidAccumulator::m_nTypeID,LiquidAccumulator::CreatLiquidAccumulator);
	Register(VacuumBreaker::m_nTypeID,VacuumBreaker::CreatVacuumBreaker);
	Register(General::m_nTypeID,General::CreatGeneral);
	Register(SprayDischarge::m_nTypeID,SprayDischarge::CreatSprayDischarge);
	Register(Pump::m_nTypeID,Pump::CreatPump);
	Register(Bend::m_nTypeID,Bend::CreatBend);
}

ComponentFactory::~ComponentFactory()
{
}


ComponentFactory* ComponentFactory::Instance()
{
	static ComponentFactory factory;
	return &factory;
}

