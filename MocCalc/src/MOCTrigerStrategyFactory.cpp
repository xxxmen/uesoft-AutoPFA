// MOCTrigerStrategyFactory.cpp: implementation of the MOCTrigerStrategyFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerStrategyFactory.h"
#include "MOCTrigerAbsTimeStrategy.h"
#include "MOCTrigerCheckStateStrategy.h"
#include "MOCTrigerControlStateStrategy.h"
#include "MOCTrigerJunEGLDiffStrategy.h"
#include "MOCTrigerJunStagDiffStrategy.h"
#include "MOCTrigerJunHGLDiffStrategy.h"
#include "MOCTrigerJunStagStrategy.h"
#include "MOCTrigerJunStaticDiffStrategy.h"
#include "MOCTrigerPipeEGLDiffStrategy.h"
#include "MOCTrigerPipeEGLStrategy.h"
#include "MOCTrigerPipeHGLDiffStrategy.h"
#include "MOCTrigerPipeHGLStrategy.h"
#include "MOCTrigerPipeMassStrategy.h"
#include "MOCTrigerPipeStagDiffStrategy.h"
#include "MOCTrigerPipeStagStrategy.h"
#include "MOCTrigerPipeStaticDiffStrategy.h"
#include "MOCTrigerPipeVelStrategy.h"
#include "MOCTrigerPipeVolumeStrategy.h"
#include "MOCTrigerReliefStateStrategy.h"
#include "MOCTrigerRelTimeStrategy.h"
#include "MOCTrigerSpeedStrategy.h"
#include "MOCTrigerSpryVolumeStrategy.h"
#include "MOCTrigerSurgeGLStrategy.h"
#include "MOCTrigerSurgeLiquidHStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerStrategyFactory::MOCTrigerStrategyFactory()
{
	Register(0,MOCTrigerAbsTimeStrategy::Creator);
	Register(1,MOCTrigerPipeStagStrategy::Creator);
	Register(2,MOCTrigerJunStagStrategy::Creator);
	Register(3,MOCTrigerPipeMassStrategy::Creator);
	Register(4,MOCTrigerPipeVolumeStrategy::Creator);
	Register(5,MOCTrigerPipeHGLStrategy::Creator);
	Register(6,MOCTrigerPipeEGLStrategy::Creator);
	Register(7,MOCTrigerSpeedStrategy::Creator);
	Register(8,MOCTrigerCheckStateStrategy::Creator);
	Register(9,MOCTrigerReliefStateStrategy::Creator);
	Register(10,MOCTrigerControlStateStrategy::Creator);
	Register(11,MOCTrigerJunStaticDiffStrategy::Creator);
	Register(12,MOCTrigerJunStagDiffStrategy::Creator);
	Register(13,MOCTrigerJunHGLDiffStrategy::Creator);
	Register(14,MOCTrigerJunEGLDiffStrategy::Creator);
	Register(15,MOCTrigerPipeStaticDiffStrategy::Creator);
	Register(16,MOCTrigerPipeStagDiffStrategy::Creator);
	Register(17,MOCTrigerPipeHGLDiffStrategy::Creator);
	Register(18,MOCTrigerPipeEGLDiffStrategy::Creator);
	Register(19,MOCTrigerSpryVolumeStrategy::Creator);
	Register(20,MOCTrigerSurgeGLStrategy::Creator);
	Register(21,MOCTrigerSurgeLiquidHStrategy::Creator);
	Register(22,MOCTrigerPipeVelStrategy::Creator);
	Register(23,MOCTrigerRelTimeStrategy::Creator);
}

MOCTrigerStrategyFactory::~MOCTrigerStrategyFactory()
{

}

MOCTrigerStrategyFactory* MOCTrigerStrategyFactory::Instance()
{
	static MOCTrigerStrategyFactory factory;
	return &factory;
}