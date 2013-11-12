// JunFaceFactory.cpp: implementation of the JunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunFaceFactory.h"
#include "AFTAreaChangeFace.h"
#include "AFTAssignFlowFace.h"
#include "AFTAssignPressFace.h"
#include "AFTBranchFace.h"
#include "AFTBreakerFace.h"
#include "AFTCheckFace.h"
#include "AFTControlFace.h"
#include "AFTDeadEndFace.h"
#include "AFTGasAccumFace.h"
#include "AFTGeneralFace.h"
#include "AFTLiquidAccumFace.h"
#include "AFTPumpFace.h"
#include "AFTReliefFace.h"
#include "AFTReserviorFace.h"
#include "AFTSprayFace.h"
#include "AFTSurgeFace.h"
#include "AFTTeeWyeFace.h"
#include "AFTValveFace.h"
#include "AFTBendFace.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunFaceFactory::JunFaceFactory()
{
	Register(1,AFTBranchFace::Creator);
	Register(2,AFTReserviorFace::Creator);
	Register(3,AFTAssignFlowFace::Creator);
	Register(4,AFTAssignPressFace::Creator);
	Register(5,AFTAreaChangeFace::Creator);
	Register(6,AFTBendFace::Creator);
	Register(21,AFTReliefFace::Creator);
	Register(7,AFTTeeWyeFace::Creator);
	Register(8,AFTValveFace::Creator);
	Register(9,AFTControlFace::Creator);
	Register(10,AFTCheckFace::Creator);
	Register(11,AFTDeadEndFace::Creator);
	Register(22,AFTGasAccumFace::Creator);
	Register(24,AFTSurgeFace::Creator);
	Register(23,AFTLiquidAccumFace::Creator);
	Register(25,AFTBreakerFace::Creator);
	Register(16,AFTSprayFace::Creator);
	Register(17,AFTPumpFace::Creator);
	Register(20,AFTGeneralFace::Creator);
}

JunFaceFactory::~JunFaceFactory()
{

}

JunFaceFactory* JunFaceFactory::Instance()
{
	static JunFaceFactory factory;
	return &factory;
}
