// Conicalexpansion90Strategy.cpp: implementation of the Conicalexpansion90Strategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "Conicalexpansion90Strategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Conicalexpansion90Strategy::Conicalexpansion90Strategy()
{

}

Conicalexpansion90Strategy::~Conicalexpansion90Strategy()
{

}

ILossCalcStrategy* Conicalexpansion90Strategy::Creator()
{
	static Conicalexpansion90Strategy strategy;
	return &strategy;
}

double Conicalexpansion90Strategy::CalcK(const AreaChangeLossCalc &ref)
{
    double dK = 0;
	if(ref.AreaDown()<=0||ref.Angel()>180)
		return dK;
	double dAreaRatio = ref.AreaUp() / ref.AreaDown();
	dK = ref.BaseArea()*pow(1-dAreaRatio,2);
	return dK;
}
