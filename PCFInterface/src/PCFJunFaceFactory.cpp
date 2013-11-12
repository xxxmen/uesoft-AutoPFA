// PCFJunFaceFactory.cpp: implementation of the PCFJunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJunFaceFactory.h"
#include "PCFBendFace.h"
#include "PCFValveFace.h"
#include "PCFBranchFace.h"
#include "PCFTeeFace.h"
#include "PCFCapFace.h"
#include "PCFReduceFace.h"
#include "PCFAssignFlowFace.h"
#include "PCFPumpDataFace.h"
#include "PCFReserviorFace.h"
#include "PCFAssignPressFace.h"
#include "PCFSurgeFace.h"
#include "PCFGasAccumFace.h"
#include "PCFLiquidAccumFace.h"
#include "PCFSprayFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJunFaceFactory::PCFJunFaceFactory()
{
	Register(24,PCFSurgeFace::Creator);
	Register(1,PCFBranchFace::Creator);
	Register(5,PCFReduceFace::Creator);
	Register(6,PCFBendFace::Creator);
	Register(7,PCFTeeFace::Creator);
	Register(8,PCFValveFace::Creator);
	Register(11,PCFCapFace::Creator);
	Register(3,PCFAssignFlowFace::Creator);
	Register(17,PCFPumpDataFace::Creator);
	Register(2,PCFReserviorFace::Creator);
	Register(4,PCFAssignPressFace::Creator);
	Register(22,PCFGasAccumFace::Creator);
	Register(23,PCFLiquidAccumFace::Creator);
	Register(16,PCFSprayFace::Creator);	
}

PCFJunFaceFactory::~PCFJunFaceFactory()
{

}

PCFJunFaceFactory* PCFJunFaceFactory::Instance()
{
	static PCFJunFaceFactory factory;
	return &factory;
}