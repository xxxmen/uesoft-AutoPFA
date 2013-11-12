// CalcJunFactory.cpp: implementation of the CalcJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJunFactory.h"
#include "CalcAreaChange.h"
#include "CalcAssignFlow.h"
#include "CalcAssignPress.h"
#include "CalcBrach.h"
#include "CalcBrecker.h"
#include "CalcCheck.h"
#include "CalcControl.h"
#include "CalcDeadEnd.h"
#include "CalcGasAccum.h"
#include "CalcGeneral.h"
#include "CalcLiquidAccum.h"
#include "CalcPump.h"
#include "CalcRelief.h"
#include "CalcReservior.h"
#include "CalcSpray.h"
#include "CalcSurge.h"
#include "CalcTeeWye.h"
#include "CalcValve.h"
#include "CalcBend.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CalcJunFactory::CalcJunFactory()
{
	Register(1,CalcBrach::Creator);
	Register(2,CalcReservior::Creator);
	Register(3,CalcAssignFlow::Creator);
	Register(4,CalcAssignPress::Creator);
	Register(5,CalcAreaChange::Creator);
	Register(6,CalcBend::Creator);
	Register(21,CalcRelief::Creator);
	Register(7,CalcTeeWye::Creator);
	Register(8,CalcValve::Creator);
	Register(9,CalcControl::Creator);
	Register(10,CalcCheck::Creator);
	Register(11,CalcDeadEnd::Creator);
	Register(22,CalcGasAccum::Creator);
	Register(24,CalcSurge::Creator);
	Register(23,CalcLiquidAccum::Creator);
	Register(25,CalcBrecker::Creator);
	Register(16,CalcSpray::Creator);
	Register(17,CalcPump::Creator);
	Register(20,CalcGeneral::Creator);
}

CalcJunFactory::~CalcJunFactory()
{

}

CalcJunFactory* CalcJunFactory::Instance()
{
	static CalcJunFactory factory;
	return &factory;
}