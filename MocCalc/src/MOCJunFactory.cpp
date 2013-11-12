// MOCJunFactory.cpp: implementation of the MOCJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCJunFactory.h"
#include "MOCBrach.h"
#include "MOCReservior.h"
#include "MOCAreaChange.h"
#include "MOCAssignFlow.h"
#include "MOCAssignPress.h"
#include "MOCBrecker.h"
#include "MOCCheck.h"
#include "MOCControl.h"
#include "MOCDeadEnd.h"
#include "MOCRelief.h"
#include "MOCTeeWye.h"
#include "MOCValve.h"
#include "MOCGasAccum.h"
#include "MOCSurge.h"
#include "MOCLiquidAccum.h"
#include "MOCSpray.h"
#include "MOCPump.h"
#include "MOCGeneral.h"
#include "MOCBend.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCJunFactory::MOCJunFactory()
{
	Register(1,MOCBrach::Creator);
	Register(2,MOCReservior::Creator);
	Register(3,MOCAssignFlow::Creator);
	Register(4,MOCAssignPress::Creator);
	Register(5,MOCAreaChange::Creator);
	Register(6,MOCBend::Creator);
	Register(21,MOCRelief::Creator);
	Register(7,MOCTeeWye::Creator);
	Register(8,MOCValve::Creator);
	Register(9,MOCControl::Creator);
	Register(10,MOCCheck::Creator);
	Register(11,MOCDeadEnd::Creator);
	Register(22,MOCGasAccum::Creator);
	Register(24,MOCSurge::Creator);
	Register(23,MOCLiquidAccum::Creator);
	Register(25,MOCBrecker::Creator);
	Register(16,MOCSpray::Creator);
	Register(17,MOCPump::Creator);
	Register(20,MOCGeneral::Creator);
}

MOCJunFactory::~MOCJunFactory()
{

}

MOCJunFactory* MOCJunFactory::Instance()
{
	static MOCJunFactory factory;
	return &factory;
}
