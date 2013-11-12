// CalcPeriodicFace.cpp: implementation of the CalcPeriodicFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPeriodicFace.h"
#include "CalcPeriodic.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPeriodicFace::CalcPeriodicFace()
{

}

CalcPeriodicFace::~CalcPeriodicFace()
{

}

ErrorStatus::FileError CalcPeriodicFace::Save(CalcPeriodic &Data,StrArray<5> &Model)
{
	Data.Periodic(Model.nData(0));
	Data.Chop(Model.nData(1));
	Data.Frequency(_tcstod(Model.Data(2),'\0'));
	Data.Amplitude(TransStd(Model.Data(3),Model.Data(4)));
	return ErrorStatus::eFileOK;
}