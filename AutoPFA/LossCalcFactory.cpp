// LossCalcFactory.cpp: implementation of the LossCalcFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "LossCalcFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include "ConicalContraction45Strategy.h"
#include "ConicalContraction90Strategy.h"
#include "Conicalexpansion90Strategy.h"
#include "ConicalExpansionStrategy.h"
#include "AbruptContractionStrategy.h"
#include "AbruptExpansionStrategy.h"

LossCalcFactory::LossCalcFactory()
{
	Register(1,ConicalExpansion45Strategy::Creator);
	Register(2,Conicalexpansion90Strategy::Creator);
	Register(3,ConicalContraction45Strategy::Creator);
	Register(4,ConicalContraction90Strategy::Creator);
	Register(5,AbruptExpansionStrategy::Creator);
	Register(6,AbruptContractionStrategy::Creator);
}

LossCalcFactory::~LossCalcFactory()
{

}

LossCalcFactory* LossCalcFactory::Instance()
{
	static LossCalcFactory factory;
	return &factory;
}
