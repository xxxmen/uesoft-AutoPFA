// CalcTransFace.cpp: implementation of the CalcTransFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTransFace.h"
#include "CalcTrans.h"
#include "TransControlPerisistent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTransFace::CalcTransFace()
{

}

CalcTransFace::~CalcTransFace()
{

}

ErrorStatus::FileError CalcTransFace::Save(CalcTrans &Data,TransControlPerisistent& model)
{
	Data.StartTime(TransStd(model.StartTime(),model.TimeUnit()));
	Data.StopTime(TransStd(model.StopTime(),model.TimeUnit()));
	Data.Frequency(_atoi(model.Frequency()));
	Data.Cavitation(_atoi(model.Cavitation()));
	Data.VariableR(_atoi(model.VariableR()));
	Data.Artificial(_atoi(model.Artificial()));
	Data.Criteria(strtof(model.Criteria()));
	Data.MinFlow(TransStd(model.MinFlow(),model.MinFlowUnit()));
	Data.TotalSteps(_atoi(model.TotalSteps()));
	
	return ErrorStatus::eFileOK;
}
	
