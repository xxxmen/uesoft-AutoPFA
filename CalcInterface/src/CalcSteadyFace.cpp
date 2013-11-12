// CalcSteadyFace.cpp: implementation of the CalcSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcSteadyFace.h"
#include "CaclSteady.h"
#include "SteadyPersistent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSteadyFace::CalcSteadyFace()
{

}

CalcSteadyFace::~CalcSteadyFace()
{

}



ErrorStatus::FileError CalcSteadyFace::Save(CalcSteady &Data,SteadyPersistent& model)
{
	Data.AnalysisType(_atoi(model.AnalysisType()));
	Data.PresTolType(_atoi(model.PresTolType()));
	Data.PresAbsTol(TransStd(model.PresAbsTol()));
	Data.PresRelTol(strtod(model.PresRelTol()));
	Data.FlowTolType(_atoi(model.FlowTolType()));
	Data.FlowAbsTol(TransStd(model.FlowAbsTol()));
	Data.FlowRelTol(strtod(model.FlowRelTol()));
	Data.MaxIterations(_atoi(model.MaxIterations()));
	Data.FlowRelaxation(strtod(model.FlowRelaxation()));
	Data.PresRelaxation(strtod(model.PresRelaxation()));
	Data.KeepHistory(_atoi(model.KeepHistory()));
	return ErrorStatus::eFileOK;
}