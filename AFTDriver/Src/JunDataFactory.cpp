// JunDataFactory.cpp: implementation of the JunDataFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunDataFactory.h"
#include "AreaChangeData.h"
#include "AssignFlowData.h"
#include "AssignPressData.h"
#include "BrachData.h"
#include "BreckerData.h"
#include "CheckValveData.h"
#include "ControlValveData.h"
#include "DeadEndData.h"
#include "GasAccumData.h"
#include "GeneralData.h"
#include "LiquidAccumData.h"
#include "PumpData.h"
#include "ReliefData.h"
#include "ReserviorData.h"
#include "SprayData.h"
#include "SurgeData.h"
#include "TeeWyeData.h"
#include "ValveData.h"
#include "BendData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunDataFactory::JunDataFactory()
{
	Register(1,BrachData::Creator);
	Register(2,ReserviorData::Creator);
	Register(3,AssignFlowData::Creator);
	Register(4,AssignPressData::Creator);
	Register(5,AreaChangeData::Creator);
	Register(6,BendData::Creator);
	Register(21,ReliefData::Creator);
	Register(7,TeeWyeData::Creator);
	Register(8,ValveData::Creator);
	Register(9,ControlValveData::Creator);
	Register(10,CheckValveData::Creator);
	Register(11,DeadEndData::Creator);
	Register(22,GasAccumData::Creator);
	Register(24,SurgeData::Creator);
	Register(23,LiquidAccumData::Creator);
	Register(25,BreckerData::Creator);
	Register(16,SprayData::Creator);
	Register(17,PumpData::Creator);
	Register(20,GeneralData::Creator);
}

JunDataFactory::~JunDataFactory()
{

}

JunDataFactory* JunDataFactory::Instance()
{
	static JunDataFactory factory;
	return &factory;
}
