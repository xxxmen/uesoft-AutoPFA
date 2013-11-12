// PCFJunFactory.cpp: implementation of the PCFJunFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJunFactory.h"
#include "PCFElbow.h"
#include "PCFBend.h"
#include "PCFCap.h"
#include "PCFCoupling.h"
#include "PCFCross.h"
#include "PCFElbow.h"
#include "PCFFBlind.h"
#include "PCFFilter.h"
#include "PCFFlange.h"
#include "PCFGasket.h"
#include "PCFInstrument.h"
#include "PCFLJSE.h"
#include "PCFReduce.h"
#include "PCFSetOnTee.h"
#include "PCFSupport.h"
#include "PCFTee.h"
#include "PCFTrap.h"
#include "PCFValve.h"
#include "PCFWeld.h"
#include "PCFAssignFlow.h"
#include "PCFPumpData.h"
#include "PCFReservior.h"
#include "PCFAssignPress.h"
#include "PCFSurge.h"
#include "PCFGasAccum.h"
#include "PCFLiquidAccum.h"
#include "PCFSpray.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJunFactory::PCFJunFactory()
{
 	Register(_T("ELBOW"), PCFElbow::Creator);
 	Register(_T("BEND"), PCFBend::Creator);
 	Register(_T("CAP"),PCFCap::Creator);
 	Register(_T("COUPLING"),PCFCoupling::Creator);
 	Register(_T("ELBOW"),PCFElbow::Creator);
 	Register(_T("CROSS"),PCFCross::Creator);
 	Register(_T("FLANGE-BLIND"),PCFFBlind::Creator);
 	Register(_T("FILTER"),PCFFilter::Creator);
 	Register(_T("FLANGE"),PCFFlange::Creator);
 	Register(_T("GASKET"),PCFGasket::Creator);
 	Register(_T("INSTRUMENT"),PCFInstrument::Creator);
 	Register(_T("LAPJOINT-STUBEND"),PCFLJSE::Creator);
 	Register(_T("REDUCER-CONCENTRIC"),PCFReduce::Creator);
	Register(_T("REDUCER-CONCENTRIC"),PCFReduce::Creator);
 	Register(_T("TEE-SET-ON"),PCFSetOnTee::Creator);
 	Register(_T("SUPPORT"),PCFSupport::Creator);
 	Register(_T("TEE"),PCFTee::Creator);
 	Register(_T("TRAP"),PCFTrap::Creator);
 	Register(_T("VALVE"),PCFValve::Creator);
 	Register(_T("WELD"),PCFWeld::Creator);
	Register(_T("ASSIGNFLOW"),PCFAssignFlow::Creator);
	Register(_T("PUMP"),PCFPumpData::Creator);
	Register(_T("RESERVIOR"),PCFReservior::Creator);
	Register(_T("ASSIGNPRESS"),PCFAssignPress::Creator);
	Register(_T("SURGE"),PCFSurge::Creator);
	Register(_T("GASACCUM"),PCFGasAccum::Creator);
	Register(_T("LIQUIDACCUM"),PCFLiquidAccum::Creator);
	Register(_T("SPRAY"),PCFSpray::Creator);
}

PCFJunFactory::~PCFJunFactory()
{

}

PCFJunFactory* PCFJunFactory::Instance()
{
	static PCFJunFactory factory;
	return &factory;
}
