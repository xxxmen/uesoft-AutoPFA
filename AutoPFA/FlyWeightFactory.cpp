// FlyWeightFactory.cpp: implementation of the FlyWeightFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "FlyWeightFactory.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


FlyWeightFactory::FlyWeightFactory()
{
	Register(1,StrFlyWeight::CreatStrFlyWeight);
	Register(2,NumFlyWeight::CreatNumFlyWeight);
	Register(3,PtFlyWeight::CreatPtFlyWeight);
	Register(4,PipeIDFlyWeight::CreatPipeIDFlyWeight);
	Register(12,ArrayFlyWeight<2>::CreatArrayFlyWeight);
	Register(13,ArrayFlyWeight<3>::CreatArrayFlyWeight);
	Register(14,ArrayFlyWeight<4>::CreatArrayFlyWeight);
	Register(15,ArrayFlyWeight<5>::CreatArrayFlyWeight);
	Register(16,ArrayFlyWeight<6>::CreatArrayFlyWeight);
	Register(17,ArrayFlyWeight<7>::CreatArrayFlyWeight);
	Register(18,ArrayFlyWeight<8>::CreatArrayFlyWeight);
	Register(19,ArrayFlyWeight<9>::CreatArrayFlyWeight);
	Register(20,ArrayFlyWeight<10>::CreatArrayFlyWeight);
	Register(21,ArrayFlyWeight<11>::CreatArrayFlyWeight);
	Register(22,ArrayFlyWeight<12>::CreatArrayFlyWeight);
	Register(23,ArrayFlyWeight<13>::CreatArrayFlyWeight);

	Register(32,TableFlyWeight<2>::CreatTableFlyWeight);
	Register(33,TableFlyWeight<3>::CreatTableFlyWeight);
	Register(34,TableFlyWeight<4>::CreatTableFlyWeight);
	Register(35,TableFlyWeight<5>::CreatTableFlyWeight);
	Register(36,TableFlyWeight<6>::CreatTableFlyWeight);
}

FlyWeightFactory::~FlyWeightFactory()
{
}

FlyWeightFactory* FlyWeightFactory::Instance()
{
	static FlyWeightFactory factory;
	return &factory;
}

