// OutputRefPersist.cpp: implementation of the OutputRefPersist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutputRefPersist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OutputRefPersist::OutputRefPersist()
{

}

OutputRefPersist::~OutputRefPersist()
{
  
}

void OutputRefPersist::Init()
{
	PipeDataOrder("114,3,7,14,15,130,131,22,17,21,31,8,9,11,12");
	PipeUnitOrder("None,m3/sec,meters/sec,Pascals,Pascals,meters,meters,Pascals,Pascals,Pascals,meters,Pascals,Pascals,Pascals,Pascals");
	JunUnitOrder("None,Pascals,Pascals,Pascals,Pascals,kg/sec,None");
	JunDataOrder("40,1,2,3,4,27,38");

	TranDataOrder( _T("0,29,1,2,3,4,5,6,7,8,9") );
	TranUnitOrder( _T("None,None,Pascals,meters,kg/sec,m3/sec,meters/sec,Pascals,meters,seconds,meters3") );

	MaxMinDataOrder( _T("0,29,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28") );
	MaxMinUnitOrder( _T("None,None,Pascals,seconds,Pascals,seconds,meters,seconds,meters,seconds,kg/sec,seconds,kg/sec,seconds,m3/sec,seconds,m3/sec,seconds,meters/sec,seconds,meters/sec,seconds,Pascals,seconds,Pascals,seconds,meters,seconds,meters,seconds") );
}