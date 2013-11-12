// CalcJunFaceFactory.cpp: implementation of the CalcJunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJunFaceFactory.h"
#include "CalcAreaChangeFace.h"
#include "CalcAssignFlowFace.h"
#include "CalcAssignPressFace.h"
#include "CalcBranchFace.h"
#include "CalcBreakerFace.h"
#include "CalcCheckFace.h"
#include "CalcControlFace.h"
#include "CalcDeadEndFace.h"
#include "CalcLiquidAccumFace.h"
#include "CalcGasAccumFace.h"
#include "CalcGeneralFace.h"
#include "CalcPumpFace.h"
#include "CalcReliefFace.h"
#include "CalcReserviorFace.h"
#include "CalcSprayFace.h"
#include "CalcSurgeFace.h"
#include "CalcTeeWyeFace.h"
#include "CalcValveFace.h"
#include "CalcBendFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcJunFaceFactory::CalcJunFaceFactory()
{
	Register(1,CalcBranchFace::Creator);
	Register(2,CalcReserviorFace::Creator);
	Register(3,CalcAssignFlowFace::Creator);
	Register(4,CalcAssignPressFace::Creator);
	Register(5,CalcAreaChangeFace::Creator);
	Register(6,CalcBendFace::Creator);
	Register(21,CalcReliefFace::Creator);
	Register(7,CalcTeeWyeFace::Creator);
	Register(8,CalcValveFace::Creator);
	Register(9,CalcControlFace::Creator);
	Register(10,CalcCheckFace::Creator);
	Register(11,CalcDeadEndFace::Creator);
	Register(22,CalcGasAccumFace::Creator);
	Register(24,CalcSurgeFace::Creator);
	Register(23,CalcLiquidAccumFace::Creator);
	Register(25,CalcBreakerFace::Creator);
	Register(16,CalcSprayFace::Creator);
	Register(17,CalcPumpFace::Creator);
	Register(20,CalcGeneralFace::Creator);
}

CalcJunFaceFactory::~CalcJunFaceFactory()
{

}

CalcJunFaceFactory* CalcJunFaceFactory::Instance()
{
	static CalcJunFaceFactory factory;
	return &factory;
}
